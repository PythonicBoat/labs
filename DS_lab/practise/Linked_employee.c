#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char name[100];
  int emp_id;
  float salary;
  char location[100];
  struct Node* next;
} Node;

Node* insert_at_end(Node* head, char name[100], int emp_id, float salary, char location[100]) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  strcpy(new_node->name, name);
  new_node->emp_id = emp_id;
  new_node->salary = salary;
  strcpy(new_node->location, location);
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    return head;
  }

  Node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
  return head;
}

void display_employee_records(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("Employee Name: %s\n", current->name);
    printf("Employee ID: %d\n", current->emp_id);
    printf("Employee Salary: %.2f\n", current->salary);
    printf("Employee Location: %s\n\n", current->location);
    current = current->next;
  }
}

void delete_duplicate_employee_records(Node* head) {
  Node* current = head;
  while (current != NULL) {
    Node* next_node = current->next;
    while (next_node != NULL) {
      if (current->emp_id == next_node->emp_id) {
        current->next = next_node->next;
        free(next_node);
        next_node = current->next;
      } else {
        next_node = next_node->next;
      }
    }

    current = current->next;
  }
}

void group_employee_records_by_location(Node* head) {
  char location_map[100][100];
  int location_count = 0;

  Node* current = head;
  while (current != NULL) {
    char* location = current->location;

    int i = 0;
    while (i < location_count) {
      if (strcmp(location, location_map[i]) == 0) {
        break;
      }

      i++;
    }

    if (i == location_count) {
      strcpy(location_map[location_count], location);
      location_count++;
    }

    current = current->next;
  }

  for (int i = 0; i < location_count; i++) {
    printf("Employee Records at %s:\n", location_map[i]);
    display_employee_records(head);
  }
}

int main() {
  Node* head = NULL;

  head = insert_at_end(head, "John Doe", 1, 100000, "New York");
  head = insert_at_end(head, "Jane Doe", 2, 110000, "New York");
  head = insert_at_end(head, "Peter Parker", 3, 120000, "California");
  head = insert_at_end(head, "Mary Jane Watson", 4, 130000, "California");

  printf("Displaying all employee records:\n");
  display_employee_records(head);

  printf("Deleting duplicate employee records:\n");
  delete_duplicate_employee_records(head);

  printf("Displaying all employee records after deleting duplicate records:\n");
  display_employee_records(head);

  printf("Grouping employee records by location:\n");
  group_employee_records_by_location(head);

  return 0;
}
