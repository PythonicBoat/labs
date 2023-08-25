// wap to calculate cgpa of a student taking user input

#include<stdio.h>

int main()
{
    int n;
    float cgpa, sum=0;
    printf("Enter the number of subjects: ");
    scanf("%d", &n);
    int marks[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter the marks of subject %d: ", i+1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    cgpa = sum/n;
    printf("The cgpa of the student is: %f", cgpa);
    return 0;
}
