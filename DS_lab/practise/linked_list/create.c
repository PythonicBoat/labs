#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}* start=NULL;

void create(int item) {
    struct node *new = (sizeof(struct node));

    new -> data = item;
    new -> next = NULL;

    if (start == NULL) {
        start = new; 
    } else {
        struct node *temp = start;
        while (temp-> next != NULL) {
        temp = temp -> next;
    }
}

9