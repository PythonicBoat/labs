// Define a structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element to the stack
void push(struct Stack* stack, int data) {
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    struct Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

// Function to display the stack elements
void display(struct Stack* stack) {
    struct Node* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = NULL;
    int option, element;

    do {
        printf("Main Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter element to be pushed into the stack: ");
                scanf("%d", &element);
                push(stack, element);
                break;
            case 2:
                element = pop(stack);
                if (element != -1)
                    printf("%d deleted from Stack\n", element);
                else
                    printf("Stack is empty\n");
                break;
            case 3:
                if (isEmpty(stack))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            case 4:
                printf("Stack: ");
                display(stack);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while(option != 5);

    return 0;
}
