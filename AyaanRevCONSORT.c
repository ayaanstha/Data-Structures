#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end of the linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to reverse the linked list
void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev and current one step forward
        current = next;
    }
    *head = prev; // Update head to the new first element
}

// Function to concatenate two linked lists
void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}

// Function to sort the linked list using Bubble Sort
void sortList(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;  // No need to sort if the list is empty or has only one element
    }

    struct Node* i;
    struct Node* j;
    int temp;

    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap the data between the nodes
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Main function to demonstrate reverse, concatenate, and sort
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into list1
    append(&list1, 5);
    append(&list1, 3);
    append(&list1, 8);
    append(&list1, 1);
    printf("List 1: ");
    printList(list1);

    // Insert elements into list2
    append(&list2, 6);
    append(&list2, 2);
    append(&list2, 7);
    printf("List 2: ");
    printList(list2);

    // Concatenate list2 to list1
    concatenate(&list1, list2);
    printf("After concatenating list2 to list1: ");
    printList(list1);

    // Sort list1
    sortList(&list1);
    printf("After sorting list1: ");
    printList(list1);

    // Reverse list1
    reverse(&list1);
    printf("After reversing list1: ");
    printList(list1);

    return 0;
}
