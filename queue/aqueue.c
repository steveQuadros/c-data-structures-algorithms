#include <stdio.h>
#include <stdlib.h>

/**
 * Circular array implementation of queue
 *
 */

#define N 5

typedef struct Queue {
    int front;
    int rear;
    int items[N];
} Queue;

Queue *CreateQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int Empty(Queue *q) {
    return q->front == -1;
}

int Full(Queue *q) {
    return q->front == (q->rear + 1) % N;
}

int Dequeue(Queue *q) {
    int dequeued = q->items[q->front];
    int next = (q->front + 1) % N;
    q->front = next;
    // if (next == )
    return dequeued;
}
void Enqueue(Queue *q, int d) {
    if (Full(q)) {
        printf("Full %d\n", d);
        return;
    }
    if (Empty(q)) {
        q->front = 0, q->rear = 0;
        printf("In empty if %d %d\n", q->front, q->rear);
        q->items[0] = d;
        return;
    }

    int next = (q->rear + 1) % N;
    q->items[next] = d;
    q->rear = next;
    return;
}

void Print(Queue *q) {
    int count = (q->rear + N - q->front) % N + 1;
    for(int i = 0; i < count; i++) {
        int idx = (q->front + i) % N;
        printf("<- %d ", q->items[idx]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Queue *q = CreateQueue();
    // printf("Queue should be empty, true? %d\n", Empty(q));

    Enqueue(q, 5);
    Enqueue(q, 10);
    Enqueue(q, 234);
    Enqueue(q, 4);
    Enqueue(q, 34);

    Print(q);
    // printf("q %d - %d - %d - %d - %d\n",
    //     q->items[0], q->items[1],
    //     q->items[2],q->items[3], q->items[4]);

    printf("Dequeue should return 5: %d\n", Dequeue(q));
    Print(q);
    printf("Dequeue should return 10: %d\n", Dequeue(q));
    Print(q);

    Enqueue(q, 1000);
    Enqueue(q, 1001);
    Print(q);
    // printf("q %d - %d - %d - %d - %d\n",
    //     q->items[2], q->items[3],
    //     q->items[4],q->items[0], q->items[4]);

    // printf("Queue should be full, true?", Full(q));
    return 0;
}