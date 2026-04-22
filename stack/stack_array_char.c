
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define StackLimit 50
typedef char StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

/* --- Κυρίως Πρόγραμμα --- */
int main() {
    StackType s;
    char ch, topChar;
    bool isCorrect = true;

    CreateStack(&s);
    printf("Enter string:\n");

    /* Διαβάζουμε το πρώτο τμήμα (x) του αλφαριθμητικού */
    while (true) {
        scanf("%c", &ch);
        while(getchar() != '\n'); /* Ακριβής εντολή εκφώνησης */

        if (ch == 'C' || ch == '#') {
            break;
        }
        Push(&s, ch);
    }

    if (ch == '#') {
        /* Αν η είσοδος τελειώσει χωρίς να βρεθεί το 'C' */
        isCorrect = false;
    } else {
        /* Διαβάζουμε το δεύτερο τμήμα (y) μετά το 'C' */
        while (true) {
            scanf("%c", &ch);
            while(getchar() != '\n');

            if (ch == '#') {
                break;
            }

            if (isCorrect) {
                if (!EmptyStack(s)) {
                    Pop(&s, &topChar);
                    if (ch != topChar) {
                        isCorrect = false;
                    }
                } else {
                    /* Η στοίβα άδειασε αλλά υπάρχουν ακόμα χαρακτήρες στο y */
                    isCorrect = false;
                }
            }
        }
    }

    /* Για να είναι συμμετρικό (xCy), πρέπει η στοίβα να έχει αδειάσει πλήρως */
    if (!EmptyStack(s)) {
        isCorrect = false;
    }

    /* Εμφάνιση αποτελέσματος */
    if (isCorrect) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    return 0;
}

/* --- Υλοποίηση ΑΤΔ Στοίβας (αν χρειάζεται να τα ενσωματώσετε) --- */
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
    } else {
        printf("Full Stack\n");
    }
}

void Pop(StackType *Stack, StackElementType *Item) {
    if (!EmptyStack(*Stack)) {
        *Item = Stack->Element[Stack->Top];
        Stack->Top--;
    } else {
        printf("Empty Stack\n");
    }
}
