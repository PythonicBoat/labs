#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>

// Define constants and variables
char ssid[] = "Wokwi-GUEST";  // WiFi SSID
char pass[] = "";             // WiFi Password

char auth[] = "kM5BDmik-SfM6Pj-3uzVgpawFRqskrWF";  // Blynk auth token

#define DHTPIN 15             // Pin for DHT22 sensor
#define DHTTYPE DHT22         // DHT22 (AM2302)
DHT dht(DHTPIN, DHTTYPE);

const String WEATHER_API_KEY = "6333a48606a948a5ab2171347242708";
const String WEATHER_API_URL = "http://api.weatherapi.com/v1/current.json";

void setup() {
  Serial.begin(9600);         // Initialize serial communication
  dht.begin();                // Initialize DHT sensor

  // Initialize Wi-Fi connection
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);
  Serial.println("Connected to Blynk!");
}

void loop() {
  Blynk.run();               // Run Blynk connection

  // Measure local weather conditions
  float local_temp = dht.readTemperature();
  float local_humidity = dht.readHumidity();
  
  if (isnan(local_temp) || isnan(local_humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Fetch weather data from API
  float api_temp, api_humidity;
  if (fetchWeatherFromAPI(api_temp, api_humidity)) {
    // Send data to Blynk
    Blynk.virtualWrite(V1, local_temp);        // Local temperature
    Blynk.virtualWrite(V2, local_humidity);    // Local humidity
    Blynk.virtualWrite(V3, api_temp);          // API temperature
    Blynk.virtualWrite(V4, api_humidity);      // API humidity

    Serial.println("Reported to Blynk Dashboard");
  } else {
    Serial.println("Failed to fetch data from WeatherAPI");
  }

  delay(10000);  // Wait 10 seconds before the next loop
}

bool fetchWeatherFromAPI(float &temp, float &humidity) {
  if (WiFi.status() == WL_CONNECTED) {  // Check Wi-Fi connection
    HTTPClient http;
    String url = WEATHER_API_URL + "?key=" + WEATHER_API_KEY + "&q=Bhubaneshwar";
    http.begin(url);
    int httpCode = http.GET();

    if (httpCode > 0) {  // Check the returning code
      String payload = http.getString();
      // Parse the JSON response
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);
      temp = doc["current"]["temp_c"];
      humidity = doc["current"]["humidity"];
      http.end();
      return true;
    } else {
      Serial.println("Error in HTTP request");
      http.end();
      return false;
    }
  } else {
    Serial.println("WiFi Disconnected");
    return false;
  }
}
