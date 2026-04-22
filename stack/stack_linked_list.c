#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*ΑΤΔ ΣΤΟΙΒΑ (StackADT.h / StackADT.c)*/

typedef int StackElementType;

typedef struct StackNode *StackPointer;

typedef struct StackNode {
    StackElementType Data;
    StackPointer     Next;
} StackNode;

void CreateStack(StackPointer *Stack) {
    *Stack = NULL;
}

bool EmptyStack(StackPointer Stack) {
    return (Stack == NULL);
}

void Push(StackPointer *Stack, StackElementType Item) {
    StackPointer TempPtr;
    TempPtr = (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item) {
    StackPointer TempPtr;
    if (EmptyStack(*Stack)) {
        printf("EMPTY Stack\n");
    } else {
        TempPtr  = *Stack;
        *Item    = TempPtr->Data;
        *Stack   = TempPtr->Next;
        free(TempPtr);
    }
}

/*εμφάνιση στοίβας (δεν τροποποιεί τον ΑΤΔ)*/

void TraverseStack(StackPointer Stack) {
    StackPointer Current = Stack;
    if (EmptyStack(Stack)) {
        printf("EMPTY Stack\n");
        return;
    }
    while (Current != NULL) {
        printf("%d ", Current->Data);
        Current = Current->Next;
    }
    printf("\n");
}

/*ΚΥΡΙΩΣ ΠΡΟΓΡΑΜΜΑ*/

int main() {
    int N, i;
    int *arr;
    int maxVal;
    StackPointer     Stack;
    StackElementType pos;

    /* Δημιουργία κενής στοίβας */
    CreateStack(&Stack);

    /* Διάβασμα πλήθους αριθμών */
    printf("PLITHOS ARITHMWN: ");
    scanf("%d", &N);

    /* Δυναμική δέσμευση πίνακα */
    arr = (int *)malloc(N * sizeof(int));

    /* Διάβασμα αριθμών */
    for (i = 0; i < N; i++) {
        printf("DWSE TON %do ARITHMO: ", i + 1);
        scanf("%d", &arr[i]);
    }

    /* Εύρεση μεγαλύτερου */
    maxVal = arr[0];
    for (i = 1; i < N; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    for (i = N - 1; i >= 0; i--) {
        if (arr[i] == maxVal) {
            Push(&Stack, i + 1);
        }
    }

    /* Εμφάνιση αποτελεσμάτων */
    printf("O megalyteros arithmos einai: %d\n", maxVal);
    printf("kai brisketai stis theseis:\n");

    /* Εξαγωγή και εκτύπωση θέσεων από στοίβα με Pop */
    while (!EmptyStack(Stack)) {
        Pop(&Stack, &pos);
        printf("%d ", pos);
    }
    printf("\n");

    free(arr);
    return 0;
}
