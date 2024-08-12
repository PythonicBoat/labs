// Byte Extraction 

#include <stdio.h>

typedef unsigned char BYTE;

int main() {
    unsigned int value = 0x11223344; // 4 bytes 
    BYTE a,b,c,d; // to store byte by byte value
    
    // extracting byte by byte 
    a = (value&0xFF); 
    b = ((value>>8)&0xFF); 
    c = ((value>>16)&0xFF);
    d = ((value>>24)&0xFF);

    printf("a = %02X\n", a);
    printf("b = %02X\n", b);
    printf("c = %02X\n", c);
    printf("d = %02X\n", d);
}