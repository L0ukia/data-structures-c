#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QueueLimit 10

typedef int QueueElementType;

typedef struct {
    int Front;
    int Rear;
    int Count;
    QueueElementType Element[QueueLimit];
} QueueType;

void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);
void PrintStats(QueueType Queue);

int main() {
    QueueType myQueue;
    QueueElementType anItem;
    int i;

    printf("a\n");
    CreateQ(&myQueue);
    for (i = 0; i < 10; i++) {
        AddQ(&myQueue, i);
    }
    TraverseQ(myQueue);
    PrintStats(myQueue);

    printf("b\n");
    AddQ(&myQueue, 10);
    TraverseQ(myQueue);
    PrintStats(myQueue);

    printf("c\n");
    RemoveQ(&myQueue, &anItem);
    printf("Removed item: %d\n", anItem);
    TraverseQ(myQueue);
    PrintStats(myQueue);

    printf("d\n");
    AddQ(&myQueue, 25);
    TraverseQ(myQueue);
    PrintStats(myQueue);

    printf("e\n");
    AddQ(&myQueue, 200);
    TraverseQ(myQueue);
    PrintStats(myQueue);

    printf("f\n");
    while (!EmptyQ(myQueue)) {
        RemoveQ(&myQueue, &anItem);
        TraverseQ(myQueue);
        printf("Removed item: %d ", anItem);
        PrintStats(myQueue);
    }

    return 0;
}


void CreateQ(QueueType *Queue) {
    Queue->Front = 0;
    Queue->Rear = 0;
    Queue->Count = 0;
}

bool EmptyQ(QueueType Queue) {
    return (Queue.Count == 0);
}

bool FullQ(QueueType Queue) {
    return (Queue.Count == QueueLimit);
}

void AddQ(QueueType *Queue, QueueElementType Item) {
    if (!FullQ(*Queue)) {
        Queue->Element[Queue->Rear] = Item;
        Queue->Rear = (Queue->Rear + 1) % QueueLimit;
        Queue->Count++;
    } else {
        printf("Full Queue\n");
    }
}

void RemoveQ(QueueType *Queue, QueueElementType *Item) {
    if (!EmptyQ(*Queue)) {
        *Item = Queue->Element[Queue->Front];
        Queue->Front = (Queue->Front + 1) % QueueLimit;
        Queue->Count--;
    } else {
        printf("Queue is Empty!\n");
    }
}

void TraverseQ(QueueType Queue) {
    int i, index;
    if (EmptyQ(Queue)) {
        printf("Queue: Empty Queue");
    } else {
        printf("Queue: ");
        index = Queue.Front;
        for (i = 0; i < Queue.Count; i++) {
            printf("%d ", Queue.Element[index]);
            index = (index + 1) % QueueLimit;
        }
    }
    printf("\n");
}

void PrintStats(QueueType Queue) {
    printf("Front= %d, Rear= %d, Count= %d\n", Queue.Front, Queue.Rear, Queue.Count);
}
