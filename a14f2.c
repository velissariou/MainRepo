#include <stdio.h>
#include <stdlib.h>
#define StackLimit 50

typedef int StackElementType;

typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);

int main() {
    int maxMemory, currentMemory;
    StackType aStack;
    StackElementType a;
    printf("Please enter maximum memory address: ");
    scanf("%d", &maxMemory);
    CreateStack(&aStack);

    while(a!= 0) {
        printf("Please enter the next relative memory address: ");
        scanf("%d", &a);
        if(a!= 0) {
            Push(&aStack, a);
        }
    }
    printf("Please enter the current memory address: ");
    scanf("%d", &currentMemory);
    while(!EmptyStack(aStack) || currentMemory < 0 || currentMemory > maxMemory) {
        a = aStack.Element[aStack.Top];
        currentMemory = currentMemory + a;
        Pop(&aStack, &a);
        if(currentMemory < 0 || currentMemory > maxMemory) {
            printf("Access Violation Exception at address %d" ,currentMemory);
            break;
        }
        printf("Executing instruction: %d\n", currentMemory);

    }
}

void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;
}

boolean EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)

{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)

{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

