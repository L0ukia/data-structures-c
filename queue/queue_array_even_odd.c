#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QueueLimit 20

typedef int QueueElementType;

typedef struct {
    int Front;
    int Rear;
    QueueElementType Element[QueueLimit];
} QueueType;


void CreateQ(QueueType *Queue);
bool EmptyQ(QueueType Queue);
bool FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);

void TraverseQ(QueueType Queue);
void RotateQ(QueueType *Queue, int numDeletions);


int main() {
    QueueType evenQ, oddQ;
    int k_even, k_odd, i;

    CreateQ(&evenQ);
    CreateQ(&oddQ);

    for (i = 0; i < QueueLimit; i++) {
        if (i % 2 == 0) {
            AddQ(&evenQ, i);
        } else {
            AddQ(&oddQ, i);
        }
    }

    printf("EvenQueue\n");
    TraverseQ(evenQ);
    printf("OddQueue\n");
    TraverseQ(oddQ);


    printf("Give number of items = ");
    scanf("%d", &k_even);
    RotateQ(&evenQ, k_even);
    printf("EvenQueue\n");
    TraverseQ(evenQ);

    printf("Give number of items = ");
    scanf("%d", &k_odd);
    RotateQ(&oddQ, k_odd);
    printf("OddQueue\n");
    TraverseQ(oddQ);

    return 0;
}

void RotateQ(QueueType *Queue, int numDeletions) {
    QueueElementType tempItem;
    int i;

    for (i = 0; i < numDeletions; i++) {
        if (!EmptyQ(*Queue)) {
            RemoveQ(Queue, &tempItem);
            AddQ(Queue, tempItem);
        }
    }
}

void CreateQ(QueueType *Queue) {
    Queue->Front = 0;
    Queue->Rear = 0;
}

bool EmptyQ(QueueType Queue) {
    return (Queue.Front == Queue.Rear);
}

bool FullQ(QueueType Queue) {
    return (Queue.Front == ((Queue.Rear + 1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item) {
    if (!EmptyQ(*Queue)) {
        *Item = Queue->Element[Queue->Front];
        Queue->Front = (Queue->Front + 1) % QueueLimit;
    } else {
        printf("Empty Queue\n");
    }
}

void AddQ(QueueType *Queue, QueueElementType Item) {
    if (!FullQ(*Queue)) {
        Queue->Element[Queue->Rear] = Item;
        Queue->Rear = (Queue->Rear + 1) % QueueLimit;
    } else {
        printf("Full Queue\n");
    }
}

void TraverseQ(QueueType Queue) {
    int current;
    if (!EmptyQ(Queue)) {
        current = Queue.Front;
        while (current != Queue.Rear) {
            printf("%d ", Queue.Element[current]);
            current = (current + 1) % QueueLimit;
        }
        printf("\n");
    } else {
        printf("Empty Queue\n");
    }
}
