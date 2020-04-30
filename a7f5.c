#include <stdio.h>
#include <stdlib.h>

typedef char BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
BinTreeElementType MinBSTValue(BinTreePointer Root);
BinTreeElementType MaxBSTValue(BinTreePointer Root);

int main(){
  BinTreeElementType min, max;
  BinTreePointer ARoot;
  CreateBST(&ARoot);
  BSTInsert(&ARoot, 'P');
  BSTInsert(&ARoot, 'R');
  BSTInsert(&ARoot, 'O');
  BSTInsert(&ARoot, 'C');
  BSTInsert(&ARoot, 'E');
  BSTInsert(&ARoot, 'D');
  BSTInsert(&ARoot, 'U');
  if(!EmptyBST(ARoot)){
    min = MinBSTValue(ARoot);
    max = MaxBSTValue(ARoot);
    printf("Min value = %c\n", min);
    printf("Max value = %c\n", max);
  }
}

BinTreeElementType MinBSTValue(BinTreePointer Root) {
  BinTreePointer current;
  current = Root;
  while (current->LChild!= NULL) {
    current = current->LChild;
  }
  return current->Data;
}

BinTreeElementType MaxBSTValue(BinTreePointer Root) {
  BinTreePointer current;
  current = Root;
  while (current->RChild!= NULL) {
    current = current->RChild;
  }
  return current->Data;
}



void CreateBST(BinTreePointer *Root)

{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)

{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)

{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;
        if (Item < LocPtr->Data)
            LocPtr = LocPtr ->LChild;
        else if (Item > LocPtr ->Data)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %c EINAI HDH STO DDA\n", Item);
    else {
        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        LocPtr ->Data = Item;
        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            *Root = LocPtr;
        else if (Item < Parent ->Data)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}
