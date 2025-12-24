#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert();
void delete();
void display();
void search();

int main() {
    int choice;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

void insert() {
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted!\n");
}

void delete() {
    struct Node *temp;
    int value;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted!\n");
        return;
    }

    temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Value not found!\n");
    } else {
        struct Node *del = temp->next;
        temp->next = del->next;
        free(del);
        printf("Node deleted!\n");
    }
}

void display() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search() {
    struct Node *temp = head;
    int value, pos = 1;

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value not found!\n");
}

