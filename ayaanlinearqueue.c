#include <stdio.h>
#include <stdlib.h> // Needed for exit()

#define MAX 50
int queue_array[MAX];
int rear = -1;
int front = -1;

// Function to display the queue
void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is:\n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);
        printf("\n");
    }
}

// Function to insert an element into the queue
void insert() {
    int add_item;
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1)
            front = 0;
        printf("Insert the element in queue:\n");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

// Function to delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return;
    } else {
        printf("Deleted item is: %d\n", queue_array[front]);
        front = front + 1;
    }
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
