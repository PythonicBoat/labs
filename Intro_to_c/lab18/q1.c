/*
WAP to read roll number, name, gender and marks data of n number of students  from user and store them in a file. If the file previously exists, add the information of n students
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int roll_number;
        char name[SIZE];
        char gender[SIZE];
        float marks;
        printf("Enter the roll number: ");
        scanf("%d", &roll_number);
        printf("Enter the name: ");
        scanf("%s", name);
        printf("Enter the gender : ");
        scanf("%s", gender);
        printf("Enter the marks: ");
        scanf("%f", &marks);
        fprintf(fp, "%d %s %s %.2f\n", roll_number, name, gender, marks);
    }
    fclose(fp);
    return 1;
}
