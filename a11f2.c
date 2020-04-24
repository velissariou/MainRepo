#include <stdio.h>
#include <stdlib.h>
#define StackLimit 20

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
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);
void TraverseStack(StackType Stack);
StackType FilterStack(StackType Stack , StackElementType Item);


int main() {
    int plithos, i;
    StackElementType item, delItem;
    StackType MyStack;
    printf("Dwse to plithos twn stoixeiwn: ");
    scanf("%d" , &plithos);
    CreateStack(&MyStack);
    for(i = 1; i <= plithos ; i++) {
        printf("Dwse to %d o stoixeio: " , i);
        scanf("%d" , &item);
        Push(&MyStack, item);
    }
    printf("Dwse to stoixeio gia diagrafi: ");
    scanf("%d" , &delItem);
    TraverseStack(MyStack);
    MyStack = FilterStack(MyStack, delItem);
    TraverseStack(MyStack);
    return 0;
}

StackType FilterStack(StackType Stack, StackElementType Item) {
    StackType TempStack;
    CreateStack(&TempStack);
    StackElementType item;

    while(item != Item) {
        item = Stack.Element[Stack.Top];
        Pop(&Stack, &item);
        if(item != Item) {
            Push(&TempStack, item);
        }
        TraverseStack(Stack);
        TraverseStack(TempStack);
    }
    while(!EmptyStack(TempStack)) {
        item = TempStack.Element[Stack.Top];
        Pop(&TempStack, &item);
        Push(&Stack, item);
        TraverseStack(TempStack);
        TraverseStack(Stack);

    }
    return Stack;

}


void CreateStack(StackType *Stack)

{
    Stack -> Top = -1;

}

boolean EmptyStack(StackType Stack)

{
    return (Stack.Top == -1);
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

{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}

void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0;i<=Stack.Top;i++) {
        printf("%d, ",Stack.Element[i]);
    }
    printf("\n");
}
