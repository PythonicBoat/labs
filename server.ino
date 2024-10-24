#include <ESP8266WiFi.h>
#include <DHT.h>
#include <BlynkSimpleEsp8266.h> 
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h> 

#define BLYNK_PRINT Serial
#define DHTPIN 15 // GPIO15 for DHT22 sensor
#define DHTTYPE DHT22

char ssid[] = "Wokwi-GUEST"; // Your WiFi SSID
char pass[] = ""; // Your WiFi Password
char auth[] = "kM5BDmik-SfM6Pj-3uzVgpawFRqskrWF"; // Blynk Auth Token

const char* weatherApiKey = "6333a48606a948a5ab2171347242708";
const char* weatherApiUrl = "http://api.weatherapi.com/v1/current.json";

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
BlynkTimer timer;

float apiTemp = 0;
float apiHumidity = 0;
String prevWeather = "";

void fetchWeatherFromApi() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = String(weatherApiUrl) + "?key=" + weatherApiKey + "&q=Bhubaneshwar";
    http.begin(client, url);
    
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);

      apiTemp = doc["current"]["temp_c"];
      apiHumidity = doc["current"]["humidity"];
    } else {
      Serial.println("Failed to fetch data from WeatherAPI");
    }
    http.end();
  } else {
    Serial.println("Not connected to WiFi");
  }
}

void sendDataToBlynk() {
  float localTemp = dht.readTemperature();
  float localHumidity = dht.readHumidity();

  if (isnan(localTemp) || isnan(localHumidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  String message = String("{\"local_temp\":") + localTemp + ",\"local_humidity\":" + localHumidity +
                   ",\"api_temp\":" + apiTemp + ",\"api_humidity\":" + apiHumidity + "}";
  
  if (message != prevWeather) {
    Serial.println("Updated!");

    Blynk.virtualWrite(V1, localTemp);
    Blynk.virtualWrite(V2, localHumidity);
    if (apiTemp != 0) {
      Blynk.virtualWrite(V3, apiTemp);
    }
    if (apiHumidity != 0) {
      Blynk.virtualWrite(V4, apiHumidity);
    }

    Serial.println("Reporting to Blynk Dashboard: " + message);
    prevWeather = message;
  } else {
    Serial.println("No change");
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  Blynk.begin(auth, ssid, pass);

  timer.setInterval(10000L, sendDataToBlynk);
}

void loop() {
  Blynk.run();
  timer.run();
}
