#include<stdio.h>

// Function declarations (prototypes)
void enqueue(int data);
void dequeue();
void peek();
void printQueue();
int isfull();
int isempty();
int currentSize();

// Global variables
int queue[100], maxsize, front = -1, rear = -1;

void main() {
    int num_elements, item, delete_choice;

    // Ask the user for the size of the queue
    printf("Enter the size of the queue: ");
    scanf("%d", &maxsize);

    // Ask the user for the number of elements to insert
    printf("Enter the number of elements you want to insert: ");
    scanf("%d", &num_elements);

    // Enqueue the elements entered by the user
    for (int i = 0; i < num_elements; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &item);
        enqueue(item);
    }

    // Ask the user if they want to delete an element from the queue
    printf("Do you want to delete an element from the queue? (1 for Yes, 0 for No): ");
    scanf("%d", &delete_choice);

    if (delete_choice == 1) {
        dequeue();  // Remove an element from the queue
    }

    // Print the current queue and its state
    printQueue();

    // Check if the queue is empty or full
    if (isempty()) {
        printf("The queue is empty.\n");
    } else {
        printf("The queue is not empty.\n");
    }

    if (isfull()) {
        printf("The queue is full.\n");
    } else {
        printf("The queue is not full.\n");
    }

    // Exit the program
    printf("Exiting...\n");
}

// Function to check if the queue is full
int isfull() {
    if (currentSize() == maxsize) {
        return 1; // Queue is full
    }
    return 0; // Queue is not full
}

// Function to check if the queue is empty
int isempty() {
    if (front == -1 || front > rear) {
        return 1; // Queue is empty
    }
    return 0; // Queue is not empty
}

// Function to get the current number of elements in the queue
int currentSize() {
    if (isempty()) {
        return 0;
    }
    return rear - front + 1;
}

// Function to insert an element into the queue
void enqueue(int data) {
    if (isfull()) {
        printf("Queue is full. Cannot insert element %d.\n", data);
        return;
    }

    if (front == -1) { // If it's the first element being inserted
        front = 0;
    }

    rear = rear + 1;
    queue[rear] = data;
}

// Function to remove an element from the queue
void dequeue() {
    if (isempty()) {
        printf("Queue is empty. Cannot delete an element.\n");
        return;
    }

    int dequeuedItem = queue[front];
    printf("Dequeued element: %d\n", dequeuedItem);

    // After dequeue, if front surpasses rear, the queue becomes empty
    front = front + 1;

    // Reset front and rear to -1 if the queue becomes empty
    if (front > rear) {
        front = rear = -1;
    }
}

// Function to display the front element of the queue
void peek() {
    if (isempty()) {
        printf("Queue is empty. No front element.\n");
        return;
    }

    printf("Front element of the queue is: %d\n", queue[front]);
}

// Function to print the current state of the queue
void printQueue() {
    if (isempty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
