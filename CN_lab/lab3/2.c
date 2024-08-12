#include <stdio.h>
#include <string.h>

#define START_BYTE 0x7E
#define END_BYTE 0x7E
#define ESCAPE_BYTE 0x7D

void byteStuffing(const char* input, char* stuffed, int inputLength) {
    int i, j = 0;
    stuffed[j++] = START_BYTE;

    for (i = 0; i < inputLength; i++) {
        if (input[i] == START_BYTE || input[i] == END_BYTE || input[i] == ESCAPE_BYTE) {
            stuffed[j++] = ESCAPE_BYTE;
            stuffed[j++] = input[i] ^ 0x20;
        } else {
            stuffed[j++] = input[i];
        }
    }

    stuffed[j++] = END_BYTE;
    stuffed[j] = '\0';
}

void byteUnstuffing(const char* stuffed, char* unstuffed, int stuffedLength) {
    int i = 1, j = 0;

    while (i < stuffedLength - 1) {
        if (stuffed[i] == ESCAPE_BYTE) {
            unstuffed[j++] = stuffed[++i] ^ 0x20;
        } else {
            unstuffed[j++] = stuffed[i];
        }
        i++;
    }

    unstuffed[j] = '\0';
}

int main() {
    char input[] = "Hello World!";
    int inputLength = strlen(input);
    char stuffed[256];
    char unstuffed[256];

    byteStuffing(input, stuffed, inputLength);
    printf("Stuffed: ");
    for (int i = 0; i < strlen(stuffed); i++) {
        printf("%02X ", (unsigned char)stuffed[i]);
    }
    printf("\n");

    byteUnstuffing(stuffed, unstuffed, strlen(stuffed));
    printf("Unstuffed: %s\n", unstuffed);

    return 0;
}
