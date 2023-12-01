// #include <stdio.h>
// #include <stdlib.h>

// typedef struct Node {
//     int data;
//     struct Node *next;
// } Node;

// typedef struct Queue {
//     Node *front;
//     Node *rear;
// } Queue;

// void enqueue(Queue *q, int data) {
//     Node *newNode = (Node *)malloc(sizeof(Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (q->rear == NULL) {
//         // If the queue is empty, set both front and rear to the new node
//         q->front = q->rear = newNode;
//     } else {
//         // Otherwise, add the new node to the rear and update the rear pointer
//         q->rear->next = newNode;
//         q->rear = newNode;
//     }
// }

// int dequeue(Queue *q) {
//     if (q->front == NULL) {
//         // If the queue is empty, return an indicator (e.g., -1) to signify an error
//         return -1;
//     }

//     int data = q->front->data;
//     Node *temp = q->front;

//     if (q->front == q->rear) {
//         // If there is only one element, set both front and rear to NULL
//         q->front = q->rear = NULL;
//     } else {
//         // Otherwise, update the front pointer to the next node
//         q->front = q->front->next;
//     }

//     free(temp);
//     return data;
// }

// void display(Queue *q) {
//     Node *current = q->front;
//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

// int main() {
//     Queue q = {NULL, NULL};
    

//     enqueue(&q, 10);
//     enqueue(&q, 20);
//     enqueue(&q, 30);

//     display(&q);

//     printf("Dequeued: %d\n", dequeue(&q));
//     printf("Dequeued: %d\n", dequeue(&q));

//     display(&q);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Queue initializeQueue() {
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

Queue enqueue(Queue q, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. The queue is full.\n");
        return q;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (q.front == NULL) {
        // If the queue is empty, set both front and rear to the new node
        q.front = q.rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear pointer
        q.rear->next = newNode;
        q.rear = newNode;
    }

    return q;
}

Queue dequeue(Queue q) {
    if (q.front == NULL) {
        // If the queue is empty, return the same queue
        printf("The queue is empty. Cannot dequeue.\n");
        return q;
    }

    Node *temp = q.front;
    q.front = q.front->next;
    free(temp);

    if (q.front == NULL) {
        // If the last element is dequeued, set rear to NULL
        q.rear = NULL;
    }

    return q;
}

void display(Queue q) {
    Node *current = q.front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q = initializeQueue();

    q = enqueue(q, 10);
    q = enqueue(q, 20);
    q = enqueue(q, 30);

    display(q);

    q = dequeue(q);
    q = dequeue(q);

    display(q);

    q = enqueue(q, 40);
    display(q);

    return 0;
}
