#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NumberOfNodes 10
#define StackLimit 50
#define NilValue -1

typedef struct {
    int AM;
    float Vathmos;
} ListElementType;

typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer Next;
} NodeType;

typedef int StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
bool FullList(ListPointer FreePtr);
void Insert(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack);

int main() {
    ListPointer AList, FreePtr;
    NodeType Node[NumberOfNodes];
    StackType MinStack;
    ListElementType Student;
    float minGrade;
    int i, tempAM;

    InitializeStoragePool(Node, &FreePtr);

    CreateList(&AList);

    printf("Question C\n");
    printf("Storage Pool\n");
    printAll(AList, FreePtr, Node);

    printf("Question D\n");
    printf("Linked list\n ");
    TraverseLinked(AList, Node);

    printf("Question E\n");
    for (i = 1; i <= 5; i++) {
        printf("DWSE AM GIA EISAGWGH STH LISTA: ");
        scanf("%d", &Student.AM);
        printf("DWSE VATHMO GIA EISAGWGH STH LISTA: ");
        scanf("%f", &Student.Vathmos);
        Insert(&AList, Node, &FreePtr, NilValue, Student);
    }

    printf("Question F\n");
    printf("Storage pool\n");
    printAll(AList, FreePtr, Node);

     printf("Question G\n");
    printf("Linked list\n");
    TraverseLinked(AList, Node);

    printf("Question H\n");
    if (EmptyList(AList)) printf("Empty List\n"); else printf("Not an Empty List\n");

    printf("Question I\n");
    if (FullList(FreePtr)) printf("Full List\n"); else printf("Not a Full List\n");

    CreateStack(&MinStack);
    minGrade = FindMins(AList, Node, &MinStack);

    printf("Question J");
    printf("\nMin value=%.2f\n", minGrade);
    printf("AM with min grade are: ");
    while (!EmptyStack(MinStack)) {
        Pop(&MinStack, &tempAM);
        printf("%d ", tempAM);
    }
    printf("\n");

    printf("Question K\n");
    printf("\n");
    TraverseStack(MinStack);

    printf("\nQuestion L\n");
    printf("Storage pool\n");
    printAll(AList, FreePtr, Node);

    printf("Question Ì\n");
    printf("Linked list\n");
    TraverseLinked(AList, Node);

    return 0;
}

float FindMins(ListPointer List, NodeType Node[NumberOfNodes], StackType *Stack) {
    ListPointer CurrPtr;
    float min;

    if (EmptyList(List)) return 0.0;

    CurrPtr = List;
    min = Node[CurrPtr].Data.Vathmos;
    CurrPtr = Node[CurrPtr].Next;
    while (CurrPtr != NilValue) {
        if (Node[CurrPtr].Data.Vathmos < min) {
            min = Node[CurrPtr].Data.Vathmos;
        }
        CurrPtr = Node[CurrPtr].Next;
    }

    CurrPtr = List;
    while (CurrPtr != NilValue) {
        if (Node[CurrPtr].Data.Vathmos == min) {
            Push(Stack, Node[CurrPtr].Data.AM);
        }
        CurrPtr = Node[CurrPtr].Next;
    }

    return min;
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr) {
    for (int i = 0; i < NumberOfNodes - 1; i++) {
        Node[i].Next = i + 1;
        Node[i].Data.AM = -1; Node[i].Data.Vathmos = -1.0;
    }
    Node[NumberOfNodes - 1].Next = NilValue;
    Node[NumberOfNodes - 1].Data.AM = -1; Node[NumberOfNodes - 1].Data.Vathmos = -1.0;
    *FreePtr = 0;
}

void CreateList(ListPointer *List) {
    *List = NilValue;
}

bool EmptyList(ListPointer List) {
    return (List == NilValue);
}

bool FullList(ListPointer FreePtr) {
    return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]) {
    *P = *FreePtr;
    if (!FullList(*FreePtr))
        *FreePtr = Node[*FreePtr].Next;
}

void Insert(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item) {
    ListPointer TempPtr;
    GetNode(&TempPtr, FreePtr, Node);
    if (TempPtr != NilValue) {
        Node[TempPtr].Data = Item;
        if (PredPtr == NilValue) {
            Node[TempPtr].Next = *List;
            *List = TempPtr;
        } else {
            Node[TempPtr].Next = Node[PredPtr].Next;
            Node[PredPtr].Next = TempPtr;
        }
    } else printf("Full List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[]) {
    ListPointer CurrPtr = List;
    if (EmptyList(List)) printf("Empty List ...\n");
    else {
        while (CurrPtr != NilValue) {
            printf("(%d:<%d, %.1f> -> %d) ", CurrPtr, Node[CurrPtr].Data.AM, Node[CurrPtr].Data.Vathmos, Node[CurrPtr].Next);
            CurrPtr = Node[CurrPtr].Next;
        }
        printf("\n");
    }
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]) {
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    for (int i = 0; i < NumberOfNodes; i++) {
        printf("(%d:<%d,%.1f>->%d) ", i, Node[i].Data.AM, Node[i].Data.Vathmos, Node[i].Next);
    }
    printf("\n");
}

void CreateStack(StackType *Stack) {
    Stack->Top = -1;
}

bool EmptyStack(StackType Stack) {
    return (Stack.Top == -1);
}

bool FullStack(StackType Stack) {
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item) {
    if (!FullStack(*Stack)) {
        Stack->Top++;
        Stack->Element[Stack->Top] = Item;
    } else printf("Full Stack...\n");
}

void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack->Element[Stack->Top];
        Stack->Top--;
    } else printf("Empty Stack...\n");
}

void TraverseStack(StackType Stack) {
    if (EmptyStack(Stack))
        printf("plithos sto stack 0\n");
    else {
        printf("plithos sto stack %d: ", Stack.Top + 1);
        for (int i = 0; i <= Stack.Top; i++)
            printf("%d ", Stack.Element[i]);
        printf("\n");
    }
}
