#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define StackLimit 20

typedef int StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);

int main() {
    StackType s, tempS;
    StackElementType x, dummy;
    int n, i;

    CreateStack(&s);
    for (i = 0; i < 15; i++) {
        Push(&s, i * 10);
    }

    printf("plithos sto stack %d\n", s.Top + 1);
    TraverseStack(s);

    printf("Give nth element (n<=6) ");
    scanf("%d", &n);

    Pop(&s, &dummy);
    Pop(&s, &x);
    printf("\nQuestion a: x=%d\n", x);
    printf("plithos sto stack %d\n", s.Top + 1);
    TraverseStack(s);

    Pop(&s, &dummy);
    Pop(&s, &x);
    Push(&s, x);
    Push(&s, dummy);
    printf("\nQuestion b: x=%d\n", x);
    printf("plithos sto stack %d\n", s.Top + 1);
    TraverseStack(s);

    for (i = 1; i <= n; i++) {
        Pop(&s, &x);
    }
    printf("\nQuestion c: x=%d\n", x);
    printf("plithos sto stack %d\n", s.Top + 1);
    TraverseStack(s);

    CreateStack(&tempS);
    for (i = 1; i <= n; i++) {
        Pop(&s, &x);
        Push(&tempS, x);
    }
    while (!EmptyStack(tempS)) {
        Pop(&tempS, &dummy);
        Push(&s, dummy);
    }
    printf("\nQuestion d: x=%d\n", x);
    printf("plithos sto stack %d\n", s.Top + 1);
    TraverseStack(s);

    CreateStack(&tempS);
    while (!EmptyStack(s)) {
        Pop(&s, &x);
        Push(&tempS, x);
    }
    while (!EmptyStack(tempS)) {
        Pop(&tempS, &dummy);
        Push(&s, dummy);
    }
    printf("\nQuestion e: x=%d\n", x);
    printf("plithos sto stack %d\n", s.Top + 1);
    TraverseStack(s);

    CreateStack(&tempS);
    while (!EmptyStack(s)) {
        Pop(&s, &dummy);
        Push(&tempS, dummy);
    }
    for(i=1; i<=3; i++) {
        Pop(&tempS, &x);
    }
    Push(&s, x);
    CreateStack(&s);
    for (i = 0; i < 10; i++) Push(&s, i * 10);

    printf("\nQuestion f: x=%d\n", x);
    printf("plithos sto stack %d\n", s.Top + 1);
    TraverseStack(s);

    while (!EmptyStack(s)) {
        Pop(&s, &x);
    }
    printf("\nQuestion g: x=%d\n", x);
    printf("plithos sto stack %d\n", s.Top + 1);
    TraverseStack(s);

    return 0;
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
    }
}

void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack->Element[Stack->Top];
        Stack->Top--;
    }
}

void TraverseStack(StackType Stack) {
    int i;
    if (EmptyStack(Stack)) {

    } else {
        for (i = 0; i <= Stack.Top; i++) {
            printf("%d ", Stack.Element[i]);
        }
    }
    printf("\n");
}
