#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to check if the list is empty
int isEmpty(struct Node* head) {
    return head == NULL;
}

// Function to insert at the beginning of the circular linked list
void insert_Beg(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (isEmpty(*head)) {
        newNode->next = newNode;  // Points to itself if the list is empty
        *head = newNode;
    } else {
        struct Node* temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newNode;   // Last node now points to the new node
        newNode->next = *head;  // New node points to the head
        *head = newNode;        // Update head to the new node
    }
}

// Function to insert at the end of the circular linked list
void insert_End(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (isEmpty(*head)) {
        newNode->next = newNode;  // Points to itself if the list is empty
        *head = newNode;
    } else {
        struct Node* temp = *head;

        // Traverse to the last node
        while (temp->next != *head) {
            temp = temp->next;
        }

        temp->next = newNode;  // Last node points to the new node
        newNode->next = *head; // New node points to the head
    }
}

// Function to insert at a specific position in the circular linked list
void insert_Pos(struct Node** head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        insert_Beg(head, data);  // If position is 1, insert at the beginning
    } else {
        struct Node* temp = *head;
        int count = 1;

        // Traverse to the node before the desired position
        while (temp->next != *head && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (count == pos - 1) {
            newNode->next = temp->next;  // New node points to the next node
            temp->next = newNode;        // Previous node points to the new node
        } else {
            printf("Position out of range.\n");
        }
    }
}

// Function to delete from the beginning of the circular linked list
void delete_Beg(struct Node** head) {
    if (isEmpty(*head)) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == *head) {  // Only one node in the list
        *head = NULL;
        free(temp);
    } else {
        struct Node* last = *head;

        // Traverse to the last node
        while (last->next != *head) {
            last = last->next;
        }

        *head = temp->next;  // Update head to the next node
        last->next = *head;  // Last node points to the new head
        free(temp);
    }
}

// Function to delete from the end of the circular linked list
void delete_End(struct Node** head) {
    if (isEmpty(*head)) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == *head) {  // Only one node in the list
        *head = NULL;
        free(temp);
    } else {
        struct Node* prev = NULL;

        // Traverse to the last node
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = *head;  // Second last node points to the head
        free(temp);
    }
}

// Function to delete a node from a specific position in the circular linked list
void delete_Pos(struct Node** head, int pos) {
    if (isEmpty(*head) || pos < 1) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    struct Node* temp = *head;

    if (pos == 1) {
        delete_Beg(head);  // If position is 1, delete from the beginning
        return;
    }

    struct Node* prev = NULL;
    int count = 1;

    // Traverse to the node at the desired position
    while (temp->next != *head && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count == pos) {
        prev->next = temp->next;
        if (temp == *head) {  // If the node to delete is the head
            *head = temp->next;
        }
        free(temp);
    } else {
        printf("Position out of range.\n");
    }
}

// Function to display the circular linked list
void printList(struct Node* head) {
    if (isEmpty(head)) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

// Main function with menu options
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at beginning: ");
                scanf("%d", &data);
                insert_Beg(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                insert_End(&head, data);
                break;
            case 3:
                printf("Enter the data and position to insert: ");
                scanf("%d %d", &data, &pos);
                insert_Pos(&head, data, pos);
                break;
            case 4:
                delete_Beg(&head);
                break;
            case 5:
                delete_End(&head);
                break;
            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &pos);
                delete_Pos(&head, pos);
                break;
            case 7:
                printf("Circular Linked List: ");
                printList(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
