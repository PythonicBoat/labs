// Define a struct person as follows: 
// struct person
// {
// 	int id;
// 	char *name;
// 	int age;
// 	int height;
// 	int weight;
// }; 
// Write a menu driven program to read the data of ‘n’ students from a file and store them in a dynamically allocated array of struct person. Implement the min-heap or max-heap and its operations based on the menu options. 

// Sample Input/Output:
// MAIN MENU (HEAP)
// 1. Read Data
// 2. Create a Min-heap based on the age
// 3. Create a Max-heap based on the weight
// 4. Display weight of the youngest person
// 5. Insert a new person into the Min-heap
// 6. Delete the oldest person
// 7. Exit

// Enter option: 1 
// Id	Name			Age   Height	   Weight(pound)
// 0	Adarsh Hota	            39	77		231
// 1	Levi Maier		56	77		129
// 2	Priya Kumari	            63	78		240
// 3	Dorothy Helton	47	72		229
// 4	Florence Smith	24	75		171
// 5	Erica Anyan	            38	73		102
// 6	Norma Webster	23	75		145

// Enter option: 4
// Weight of youngest student: 65.77 kg

// Note#: Other menu choices are similarly verified.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void readData(struct person *p, int n)
{
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("File not found\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d %s %d %d %d", &p[i].id, p[i].name, &p[i].age, &p[i].height, &p[i].weight);
    }
    fclose(fp);
}

void createMinHeap(struct person *p, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && p[j].age < p[(j - 1) / 2].age)
        {
            struct person temp = p[j];
            p[j] = p[(j - 1) / 2];
            p[(j - 1) / 2] = temp;
            j = (j - 1) / 2;
        }
    }
}

void createMaxHeap(struct person *p, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && p[j].weight > p[(j - 1) / 2].weight)
        {
            struct person temp = p[j];
            p[j] = p[(j - 1) / 2];
            p[(j - 1) / 2] = temp;
            j = (j - 1) / 2;
        }
    }
}

void displayWeightOfYoungest(struct person *p, int n)
{
    printf("Weight of youngest student: %.2f kg\n", p[0].weight * 0.453592);
}

void insertPerson(struct person *p, int *n)
{
    struct person newPerson;
    printf("Enter the id, name, age, height and weight of the new person: ");
    scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
    p[*n] = newPerson;
    (*n)++;
    createMinHeap(p, *n);
}

void deleteOldestPerson(struct person *p, int *n)
{
    p[0] = p[*n - 1];
    (*n)--;
    createMinHeap(p, *n);
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct person *p = (struct person *)malloc(n * sizeof(struct person));
    readData(p, n);
    int choice;
    do
    {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            readData(p, n);
            break;
        case 2:
            createMinHeap(p, n);
            break;
        case 3:
            createMaxHeap(p, n);
            break;
        case 4:
            displayWeightOfYoungest(p, n);
            break;
        case 5:
            insertPerson(p, &n);
            break;
        case 6:
            deleteOldestPerson(p, &n);
            break;
        case 7:
            break;
        default:
            printf("Invalid option\n");
        }
    } while (choice != 7);
    free(p);
    return 0;
}
    