#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* --- Δήλωση ΑΤΔ Στοίβας με προσαρμοσμένο τύπο δεδομένων --- */
#define StackLimit 50

typedef struct {
    int price;
    char size;
} StackElementType;

typedef struct {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

void CreateStack(StackType *Stack);
bool EmptyStack(StackType Stack);
bool FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

/* Συνάρτηση επιπέδου εφαρμογής που τυπώνει από τη βάση προς την κορυφή */
void PrintStack(StackType *s);

int main() {
    StackType box, out_box;
    int n, i;
    StackElementType item;
    char search_size;
    bool found = false;

    CreateStack(&box);
    CreateStack(&out_box);

    printf("Give number of items ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Give the items to store\n");
        for (i = 0; i < n; i++) {
            printf("Give price ");
            scanf("%d", &item.price);
            while(getchar() != '\n'); // Καθαρισμός buffer

            printf("Give size ");
            scanf("%c", &item.size);
            while(getchar() != '\n'); // Καθαρισμός buffer

            Push(&box, item);
        }
    }

    printf("Items in the box\n");
    PrintStack(&box);

    printf("What size do you want? ");
    scanf("%c", &search_size);
    while(getchar() != '\n'); // Καθαρισμός buffer

    // 2a & 2b. Διαδικασία Αναζήτησης
    while (!EmptyStack(box)) {
        Pop(&box, &item);
        if (item.size == search_size) {
            found = true;
            break; // Βρέθηκε, σταματάμε την αναζήτηση (το στοιχείο πωλείται/χάνεται)
        } else {
            Push(&out_box, item); // Όσα δε ταιριάζουν μπαίνουν στην out_box
        }
    }

    if (found) {
        printf("Found the size %c\n", search_size);
    } else {
        printf("Not Found the size %c\n", search_size);
    }

    // Εμφάνιση των στοιβών όπως έχουν διαμορφωθεί μετά την αναζήτηση
    printf("Items in the box\n");
    PrintStack(&box);

    printf("Items out of the box\n");
    PrintStack(&out_box);

    // 2c. Αποκατάσταση της αρχικής στοίβας (χωρίς αυτό που "πουλήθηκε")
    while (!EmptyStack(out_box)) {
        Pop(&out_box, &item);
        Push(&box, item);
    }

    printf("Items in the box\n");
    PrintStack(&box);

    printf("Items out of the box\n");
    PrintStack(&out_box);

    return 0;
}

/* * Η PrintStack χρησιμοποιεί μια προσωρινή στοίβα (temp) για να αναστρέψει
 * τα στοιχεία, μετράει το πλήθος τους, και έπειτα τα επαναφέρει τυπώνοντάς
 * τα. Έτσι επιτυγχάνεται εκτύπωση από τη βάση προς την κορυφή.
 */
void PrintStack(StackType *s) {
    StackType temp;
    StackElementType item;
    int count = 0;

    CreateStack(&temp);

    // Αδειάζουμε τη στοίβα s στη temp μετρώντας ταυτόχρονα το πλήθος
    while (!EmptyStack(*s)) {
        Pop(s, &item);
        Push(&temp, item);
        count++;
    }

    printf("plithos sto stack %d\n", count);

    // Τυπώνουμε τα στοιχεία καθώς τα επιστρέφουμε στην αρχική στοίβα
    while (!EmptyStack(temp)) {
        Pop(&temp, &item);
        printf("%c, %d\n", item.size, item.price);
        Push(s, item);
    }
}

/* --- Υλοποίηση ΑΤΔ Στοίβας --- */
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

