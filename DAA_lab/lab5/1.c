#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void displayMenu() {
    printf("Menu:\n");
    printf("1. Read Data\n");
    printf("2. Create a Min-heap based on the age\n");
    printf("3. Create a Max-heap based on the weight\n");
    printf("4. Display weight of the youngest person\n");
    printf("5. Insert a new person into the Min-heap\n");
    printf("6. Delete the oldest person\n");
    printf("7. Exit\n");
}

int getUserInput() {
    int option;
    printf("Enter your choice: ");
    scanf("%d", &option);
    return option;
}

int getNumberofStudents() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    return n;
}

struct person* readData(int n) {
    struct person* students = (struct person*)malloc(n * sizeof(struct person));
    for (int i = 0; i < n; i++) {
        students[i].name = (char*)malloc(50 * sizeof(char));
        printf("Enter details for student %d (id name age height weight): ", i + 1);
        scanf("%d %s %d %d %d", &students[i].id, students[i].name, &students[i].age, &students[i].height, &students[i].weight);
    }
    return students;
}

void swap(struct person* a, struct person* b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyMin(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void buildMinHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);
}

void heapifyMax(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void buildMaxHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);
}

struct person findMinAgePerson(struct person arr[], int n) {
    struct person minAgePerson = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].age < minAgePerson.age) {
            minAgePerson = arr[i];
        }
    }
    return minAgePerson;
}

void insertIntoMinHeap(struct person arr[], int* n, struct person newPerson) {
    (*n)++;
    int i = *n - 1;
    arr[i] = newPerson;

    while (i != 0 && arr[(i - 1) / 2].age > arr[i].age) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMaxAgePerson(struct person arr[], int* n) {
    if (*n <= 0)
        return;
    if (*n == 1) {
        (*n)--;
        return;
    }

    arr[0] = arr[*n - 1];
    (*n)--;
    heapifyMin(arr, *n, 0);
}

int main() {
    struct person* students = NULL;
    int n = 0;
    int heapSize = 0;
    struct person* minHeap = NULL;
    struct person* maxHeap = NULL;

    while (true) {
        displayMenu();
        int option = getUserInput();

        switch (option) {
            case 1:
                n = getNumberofStudents();
                students = readData(n);
                heapSize = n;
                minHeap = (struct person*)malloc(n * sizeof(struct person));
                maxHeap = (struct person*)malloc(n * sizeof(struct person));
                memcpy(minHeap, students, n * sizeof(struct person));
                memcpy(maxHeap, students, n * sizeof(struct person));
                break;
            case 2:
                buildMinHeap(minHeap, heapSize);
                printf("Min-heap created based on age.\n");
                break;
            case 3:
                buildMaxHeap(maxHeap, heapSize);
                printf("Max-heap created based on weight.\n");
                break;
            case 4:
                if (heapSize > 0) {
                    struct person youngestPerson = findMinAgePerson(minHeap, heapSize);
                    printf("Weight of the youngest person: %d\n", youngestPerson.weight);
                } else {
                    printf("Heap is empty.\n");
                }
                break;
            case 5: {
                struct person newPerson;
                newPerson.name = (char*)malloc(50 * sizeof(char));
                printf("Enter details for the new person (id name age height weight): ");
                scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                insertIntoMinHeap(minHeap, &heapSize, newPerson);
                printf("New person inserted into the Min-heap.\n");
                break;
            }
            case 6:
                deleteMaxAgePerson(minHeap, &heapSize);
                printf("Oldest person deleted from the Min-heap.\n");
                break;
            case 7:
                printf("Exiting program.\n");
                free(students);
                free(minHeap);
                free(maxHeap);
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}