#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*ΤΡΟΠΟΠΟΙΗΣΗ: τύπος στοιχείου ουράς*/
typedef struct {
    char FirstName[15];
    char LastName[15];
    int  Phone;
    int  TicketType;   /* 0=ολόκληρο, 1=μισό */
} QueueElementType;

/*ΑΤΔ ΟΥΡΑ (QueueADT.h / QueueADT.c) - ΑΝΑΛΛΟΙΩΤΟΣ*/

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode {
    QueueElementType Data;
    QueuePointer     Next;
} QueueNode;

typedef struct
 {
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

void CreateQ(QueueType *Queue)
{
    Queue->Front = NULL;
    Queue->Rear  = NULL;

}

bool EmptyQ(QueueType Queue) {

    return (Queue.Front == NULL);

}

void AddQ(QueueType *Queue, QueueElementType Item) {
    QueuePointer TempPtr;
    TempPtr = (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;

    if (Queue->Front == NULL)
        Queue->Front = TempPtr;

    else

        Queue->Rear->Next = TempPtr;

    Queue->Rear = TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
{
    QueuePointer TempPtr;
    if (EmptyQ(*Queue))
        {
        printf("EMPTY Queue\n");
    }
    else
     {
        TempPtr      = Queue->Front;
        *Item        = TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);

        if (Queue->Front == NULL)
        Queue->Rear = NULL;
    }
}

/* εμφάνιση ουράς*/
void TraverseQ(QueueType Queue)
{
    QueuePointer Current;
    if (EmptyQ(Queue))
        {
        printf("EMPTY QUEUE\n");
        return;
    }
    Current = Queue.Front;

    while (Current != NULL)
     {
        printf("%s, %s, %d, %d\n",
               Current->Data.FirstName,
               Current->Data.LastName,
               Current->Data.Phone,
               Current->Data.TicketType);
        Current = Current->Next;
    }
}

/*ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ*/

int main()
 {
    QueueType WaitingQueue;
    QueueElementType passenger, removed;
    int N, freeSeats, i;

    /* Δημιουργία κενής ουράς αναμονής */
    CreateQ(&WaitingQueue);

    /* Εισαγωγή πλήθους ατόμων */
    printf("DWSE TO PLITHOS TWN ATOMWN: ");
    scanf("%d", &N);

    /* Εισαγωγή στοιχείων κάθε ατόμου και AddQ στην ουρά */
    for (i = 0; i < N; i++)
        {
        printf("DWSE ONOMA ");
        scanf("%s", passenger.FirstName);
        printf("DWSE EPITHETO ");
        scanf("%s", passenger.LastName);
        printf("DWSE THLEFWNO ");
        scanf("%d", &passenger.Phone);
        printf("DWSE TYPOS EISITHRIOY(0=olokliro, 1=miso): ");
        scanf("%d", &passenger.TicketType);
        AddQ(&WaitingQueue, passenger);
    }

    /* Εμφάνιση αρχικής ουράς αναμονής */
    printf("Initial Queue\n");
    TraverseQ(WaitingQueue);

    /* Εισαγωγή αριθμού ελεύθερων θέσεων */
    printf("DWSTE ARITHMO ELEUTHERWN THESEWN: ");
    scanf("%d", &freeSeats);

    /* Διαγραφή αντίστοιχου πλήθους επιβατών από την ουρά (RemoveQ) */
    for (i = 0; i < freeSeats; i++)
        {
        if (!EmptyQ(WaitingQueue))
        {
            RemoveQ(&WaitingQueue, &removed);
        }
    }

    /* Εμφάνιση τελικής ουράς αναμονής */
    printf("Final Queue\n");
    TraverseQ(WaitingQueue);



    return 0;
}
