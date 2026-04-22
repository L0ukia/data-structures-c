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
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);

void delete_list_every_second_element(ListPointer *List, NodeType Node[], ListPointer *FreePtr);

int main() {
    ListPointer AList, FreePtr;
    NodeType Node[NumberOfNodes];
    int n, i;
    ListElementType item;

    InitializeStoragePool(Node, &FreePtr);
    CreateList(&AList);

    printf("DWSE TON PLH8OS TWN STOIXEIWN THS LISTAS: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("DWSE TON ARI8MO GIA EISAGWGH STH ARXH THS LISTAS: ");
        scanf("%d", &item);
        Insert(&AList, Node, &FreePtr, NilValue, item);
    }

    printf("Initial List\n");
    TraverseLinked(AList, Node);

    delete_list_every_second_element(&AList, Node, &FreePtr);

    printf("Final List\n");
    TraverseLinked(AList, Node);

    return 0;
}

void delete_list_every_second_element(ListPointer *List, NodeType Node[], ListPointer *FreePtr) {
    ListPointer curr, temp;

    if (EmptyList(*List)) return;

    curr = *List;
    while (curr != NilValue && Node[curr].Next != NilValue) {
        Delete(List, Node, FreePtr, curr);

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
    }
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr) {
    ListPointer TempPtr;
    if (!EmptyList(*List)) {
        if (PredPtr == NilValue) {
            TempPtr = *List;
            *List = Node[TempPtr].Next;
        } else {
            TempPtr = Node[PredPtr].Next;
            if (TempPtr != NilValue) {
                Node[PredPtr].Next = Node[TempPtr].Next;
            } else return;
        }
        Node[TempPtr].Next = *FreePtr;
        *FreePtr = TempPtr;
    }
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
