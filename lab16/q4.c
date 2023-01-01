// wap to store 2 values (feets and inches) to add two distances using structures

#include <stdio.h>

struct Distance {
    int feet;
    int inches;
};

struct Distance d;

void main() {
    struct Distance d1, d2, d3;
    printf("Enter the first distance in feet and inches: ");
    scanf("%d %d", &d1.feet, &d1.inches);
    printf("Enter the second distance in feet and inches: ");
    scanf("%d %d", &d2.feet, &d2.inches);
    d3.feet = d1.feet + d2.feet;
    d3.inches = d1.inches + d2.inches;
    if (d3.inches >= 12) {
        d3.feet += 1;
        d3.inches -= 12;
    }
    printf("Sum of distances = %d feet %d inches", d3.feet, d3.inches);
}
