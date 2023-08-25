#include <stdio.h>

typedef struct date {
    int dd, mm, yy;
} date;

int daysOfMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void flipLeap(){
    if(daysOfMonths[2] == 29)
        daysOfMonths[2] = 28;
    else
        daysOfMonths[2] = 29;
    return;
}

int circularMod(int d, int m, int n){
    return ((d + m - 1) % n) + 1; 
}

date nextDate(date d) {
    // gives tomorrrow's date
    date next;
    int daysOfMonth = daysOfMonths[d.mm];
    next.dd = circularMod(d.dd, 1, daysOfMonth);   //adds single day
    next.yy = d.yy + ((d.mm + ((d.dd + 1)/(daysOfMonth+1))) / 12);
    next.mm = circularMod(d.mm, (d.dd+1)/(daysOfMonth+1), 12);
    return next;
}

date nextMonth(date d) {
    date next;
    int daysOfMonth = daysOfMonths[d.mm];
    next.dd = circularMod(d.dd, 0, daysOfMonth);
    next.mm = circularMod(d.mm, 1, 12); // adds single month
    next.yy = d.yy + ((d.mm + 1) / 12);
    return next;
}

date nextYear(date d) {
    date next;
    next.dd = d.dd;
    next.mm = d.mm;
    next.yy = d.yy + 1;
    return next;
}

date addDays(date d, int days) {
    date next;
    int daysOfMonth = daysOfMonths[d.mm];
    next.dd = circularMod(d.dd, days, daysOfMonth);
    next.yy = d.yy + ((d.mm + ((d.dd + days)/(daysOfMonth+1))) / 12);
    next.mm = circularMod(d.mm, (d.dd+days)/(daysOfMonth+1), 12);
    return next;
}

date addMonths(date d, int months) {
    date next;
    int daysOfMonth = daysOfMonths[d.mm];
    next.dd = circularMod(d.dd, 0, daysOfMonth);
    next.mm = circularMod(d.mm, months, 12); 
    next.yy = d.yy + ((d.mm + months) / 12);
    return next;
}

date addYears(date d, int years) {
    date next;
    next.dd = d.dd;
    next.mm = d.mm;
    next.yy = d.yy + years;
    return next;
}

char *monthName(date d) {
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return months[d.mm - 1];
}

void displayDate(date d) {
    printf("%d-%d-%02d", d.dd, d.mm, d.yy);
}

void displayDate2(date d) {
    printf("%d-%d-%02d", d.mm, d.dd, d.yy);
}

void main() {
    date d;
    printf("Enter date (dd mm yy): ");
    scanf("%d %d %d", &d.dd, &d.mm, &d.yy);
    if(d.yy % 4 == 0 && d.yy % 100 != 0 || d.yy % 400 == 0)
        flipLeap();
    printf("\nNext date: ");
    displayDate(nextDate(d));
    printf("\nNext month: ");
    displayDate(nextMonth(d));
    printf("\nNext year: ");
    displayDate(nextYear(d));
    printf("\nAdd days: ");
    displayDate(addDays(d, 5));
    printf("\nAdd months: ");
    displayDate(addMonths(d, 5));
    printf("\nAdd years: ");
    displayDate(addYears(d, 5));
    printf("\nMonth name: %s", monthName(d));
    printf("\nDisplay date: ");
    displayDate2(d);
}
