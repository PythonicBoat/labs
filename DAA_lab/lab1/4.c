#include <stdio.h>

void EXCHANGE(int* p, int* q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int* p1, int p2) {
    if (p2 <= 1) {
        return; // No rotation needed if there's one or no element
    }

    // Save the last element that will be moved to the front
    int last_element = p1[p2 - 1];

    // Move each element one position to the right
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }

    // Place the last element at the first position
    p1[0] = last_element;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int p2 = 3;
    
    ROTATE_RIGHT(arr, p2);
    
    // Print the array to see the result
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    // Output should be: 3 1 2 4 5
    
    return 0;
}
