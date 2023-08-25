// wap to store n books data such as title, author, publication, price using structures and display all the information of a particular book

#include <stdio.h>

struct Book {
    char title[50], author[50], publication[50];
    float price;
};

void main() {
    struct Book books[100];
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for book %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("Publication: ");
        scanf("%s", books[i].publication);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    int book_index;
    printf("Enter the index of the book to display: ");
    scanf("%d", &book_index+1);

    if (book_index >= 0 && book_index < n) {
        printf("Title: %s\n", books[book_index].title);
        printf("Author: %s\n", books[book_index].author);
        printf("Publication: %s\n", books[book_index].publication);
        printf("Price: %.2f\n", books[book_index].price);
    } else
        printf("Invalid book index.\n");
}
