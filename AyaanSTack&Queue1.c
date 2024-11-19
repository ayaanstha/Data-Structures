#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;
struct Node* front = NULL;
struct Node* rear = NULL;


void display(struct Node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}




void push(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->link = top;
    top = new_node;
    printf("%d pushed to stack\n", value);
}


void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    top = top->link;
    printf("%d popped from stack\n", temp->data);
    free(temp);
}




void enqueue(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->link = NULL;

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->link = new_node;
        rear = new_node;
    }
    printf("%d enqueued to queue\n", value);
}


void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;
    front = front->link;

    if (front == NULL) {
        rear = NULL;
    }

    printf("%d dequeued from queue\n", temp->data);
    free(temp);
}


int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue to Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to stack: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Stack: ");
                display(top);
                break;

            case 4:
                printf("Enter value to enqueue to queue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 5:
                dequeue();
                break;

            case 6:
                printf("Queue: ");
                display(front);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
