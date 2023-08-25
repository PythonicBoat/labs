// wap to store a student's information like roll no, name, gender and marks of an educational institute and display all the data using structure

#include <stdio.h>

struct student {
    int roll_no;
    char name[50];
    char gender;
    float marks[3];
};

void main() {
    struct student s;

    printf("Enter the student's roll number: ");
    scanf("%d", &s.roll_no);

    printf("Enter the student's name: ");
    scanf("%s", s.name);

    printf("Enter the student's gender (M/F): ");
    scanf("%c", &s.gender);

    printf("Enter the student's marks: ");
    scanf("%f", &s.marks);

    printf("\nStudent Information:\n");
    printf("Roll Number: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Gender: %c\n", s.gender);
    printf("Marks: %.2f %.2f %.2f\n", s.marks[0], s.marks[1], s.marks[2]);  
}
