// if there is a union named abc having 3 members character a, int N, double c (i) assign user input and display the values (ii) assign all together and display the values

// #include <stdio.h>

// union abc {
//     char a;
//     int N;
//     double c;
// };

// int main() {
//     union abc myUnion;

//     myUnion.a = 'A';
//     myUnion.N = 212;
//     myUnion.c = 3.14;

//     printf("a = %c, N = %d, c = %lf\n", myUnion.a, myUnion.N, myUnion.c);

//     return 0;
// }


#include <stdio.h>

union abc {
    char a;
    int N;
    double c;
};

int main() {
    union abc myUnion;

    printf("Enter a character: ");
    scanf("%c", &myUnion.a);
    printf("You entered: %c\n", myUnion.a);

    printf("Enter an integer: ");
    scanf("%d", &myUnion.N);
    printf("You entered: %d\n", myUnion.N);

    printf("Enter a double: ");
    scanf("%lf", &myUnion.c);
    printf("You entered: %lf\n", myUnion.c);

    return 0;
}
