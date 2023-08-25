// wap to calculate the difference between 2 time periods use 24hr clock

#include <stdio.h>

typedef struct time {
    int hour, minute, second;
} time;

void main() {
    time t1, t2;
    printf("Enter the time 1 : ");
    scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second);
    printf("Enter the time 2 : ");
    scanf("%d %d %d", &t2.hour, &t2.minute, &t2.second);
    int diff = (t2.hour - t1.hour) * 3600 + (t2.minute - t1.minute) * 60 + (t2.second - t1.second);
    printf("The difference is %d seconds", diff);
}
