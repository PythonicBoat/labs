// wap to store n employees data with employee name, gender, designation , department, basic pay using structures calculate the gross pay for the employee using the following formula hra = 25% of gross pay da = 75% of basic pay gross pay = basic pay + hra + da

#include <stdio.h>

struct Employee {
  char name[100], gender[10], designation[100], department[100];
  float basicPay;
};

void main() {
  struct Employee employees[100];
  int n;

  printf("Enter the number of employees: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("\nEnter the name, gender, designation, department, and basic pay for employee %d: ", i+1);
    scanf("%s %s %s %s %f", employees[i].name, employees[i].gender, employees[i].designation, employees[i].department, &employees[i].basicPay);
  }

  for (int i = 0; i < n; i++) {
    float hra = 0.25 * employees[i].basicPay;
    float da = 0.75 * employees[i].basicPay;
    float grossPay = employees[i].basicPay + hra + da;
    printf("\nGross pay for %s: %.2f", employees[i].name, grossPay);
  }
}
