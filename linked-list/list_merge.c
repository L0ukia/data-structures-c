#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NumberOfNodes 20
#define NilValue -1

typedef int ListElementType;
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer Next;
} NodeType;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateList(ListPointer *List);
bool EmptyList(ListPointer List);
void Insert(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void TraverseLinked(ListPointer List, NodeType Node[]);

void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList, NodeType Node[], ListPointer *FreePtr);

int main() {
    ListPointer List1, List2, FinalList, FreePtr;
    NodeType Node[NumberOfNodes];
    int n1, n2, i;
    ListElementType item;

    InitializeStoragePool(Node, &FreePtr);
    CreateList(&List1);
    CreateList(&List2);
    CreateList(&FinalList);

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 1: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 1: ");
        scanf("%d", &item);
        Insert(&List1, Node, &FreePtr, NilValue, item);
    }

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS 2: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS 2: ");
        scanf("%d", &item);
        Insert(&List2, Node, &FreePtr, NilValue, item);
    }

    printf("1 list\n");
    TraverseLinked(List1, Node);

    printf("2 list\n");
    TraverseLinked(List2, Node);

    concat_list(List1, List2, &FinalList, Node, &FreePtr);

    printf("Merged list\n");
    TraverseLinked(FinalList, Node);

    return 0;
}

void concat_list(ListPointer List, ListPointer BList, ListPointer *FinalList, NodeType Node[], ListPointer *FreePtr) {
    ListPointer curr;


    curr = List;
    while (curr != NilValue) {
        Insert(FinalList, Node, FreePtr, NilValue, Node[curr].Data);
        curr = Node[curr].Next;
    }

    curr = BList;
    while (curr != NilValue) {
        Insert(FinalList, Node, FreePtr, NilValue, Node[curr].Data);
        curr = Node[curr].Next;
    }
}

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr) {
    int i;
    for (i = 0; i < NumberOfNodes - 1; i++) {
        Node[i].Next = i + 1;
        Node[i].Data = -1;
    }
    Node[NumberOfNodes - 1].Next = NilValue;
    Node[NumberOfNodes - 1].Data = -1;
    *FreePtr = 0;
}

void CreateList(ListPointer *List) {
    *List = NilValue;
}

bool EmptyList(ListPointer List) {
    return (List == NilValue);
}

void Insert(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item) {
    ListPointer TempPtr;
    if (*FreePtr != NilValue) {
        TempPtr = *FreePtr;
        *FreePtr = Node[*FreePtr].Next;
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
    ListPointer CurrPtr;
    if (EmptyList(List)) {
        printf("EMPTY LIST\n");
    } else {
        CurrPtr = List;
        while (CurrPtr != NilValue) {
            printf("%d ", Node[CurrPtr].Data);
            CurrPtr = Node[CurrPtr].Next;
        }
        printf("\n");
    }
}
