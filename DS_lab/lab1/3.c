// Write a program to create a structure to store n Employees information including Emp-id, Name, Designation, basic_salary, hra%, da%  as data members. Display the information of employees with gross salary. Use array of structure.  

// Sample Input	Sample Output
// Enter no.of employees: 2
// Enter employee 1 information:
// Suchismita 
// Professor
// 10000
// 15%
// 45%
// Enter employee 2 information:
// Sarita 
// Professor
// 20000
// 10%
// 35%
// 	Employee Information:

// Name: Suchismita 
// Designation: Professor
// Basic Salary:10000
// HRA %: 15%
// DA %: 45%
// Gross Salary: 14500

// Name: Sarita
// Designation: Professor
// Basic Salary: 20000
// HRA %: 10%
// DA %: 35%
// Gross Salary: 29000

#include <stdio.h>

struct stu {
    char name[20];
    char desig[20];
    int basic;
    int hra;
    int da;
    int gross;
};

int main() {
    int n;
    printf("Enter no.of employees: ");
    scanf("%d", &n);
    struct stu s[n];
    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);
        scanf("%s", s[i].name);
        scanf("%s", s[i].desig);
        scanf("%d", &s[i].basic);
        scanf("%d", &s[i].hra);
        scanf("%d", &s[i].da);
        s[i].gross = s[i].basic + s[i].basic * s[i].hra / 100 + s[i].basic * s[i].da / 100;
    }
    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s\n", s[i].name);
        printf("Designation: %s\n", s[i].desig);
        printf("Basic Salary: %d\n", s[i].basic);
        printf("HRA %%: %d%%\n", s[i].hra);
        printf("DA %%: %d%%\n", s[i].da);
        printf("Gross Salary: %d\n", s[i].gross);
    }
    return 0;
}

