#include <stdio.h>
#include <string.h>

int main() {
    int i = 0, count = 0;
    char databits[75];
    char stuffedbits[100]; 
    int j = 0; 

    printf("Enter data bits: ");
    scanf("%s", databits);

    printf("Bits before stuffing: %s\n", databits);

    for (i = 0; i < strlen(databits); i++) {
        stuffedbits[j++] = databits[i];
        if (databits[i] == '1') {
            count++;
            if (count == 5) {
                stuffedbits[j++] = '0'; 
                count = 0;
            }
        } else {
            count = 0; 
        }
    }
    stuffedbits[j] = '\0'; 

    printf("Bits after stuffing: %s\n", stuffedbits);

    return 0;
}