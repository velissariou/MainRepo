#include <stdio.h>
#include <stdlib.h>

typedef enum {
    FALSE, TRUE
} boolean;

typedef char BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;

struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
int BSTLevel(BinTreePointer Root, BinTreeElementType Item);

int main(){
  BinTreePointer ARoot;
  int level;
  CreateBST(&ARoot);
  BSTInsert(&ARoot, 'P');
  BSTInsert(&ARoot, 'R');
  BSTInsert(&ARoot, 'O');
  BSTInsert(&ARoot, 'C');
  BSTInsert(&ARoot, 'E');
  BSTInsert(&ARoot, 'D');
  BSTInsert(&ARoot, 'U');

  level=BSTLevel(ARoot, 'P');
  printf("Level of P:%d\n", level);
  level=BSTLevel(ARoot, 'R');
  printf("Level of R:%d\n", level);
  level=BSTLevel(ARoot, 'O');
  printf("Level of O:%d\n", level);
  level=BSTLevel(ARoot, 'C');
  printf("Level of C:%d\n", level);
  level=BSTLevel(ARoot, 'E');
  printf("Level of E:%d\n", level);
  level=BSTLevel(ARoot, 'D');
  printf("Level of D:%d\n", level);
  level=BSTLevel(ARoot, 'U');
  printf("Level of U:%d\n", level);


}

int BSTLevel(BinTreePointer Root, BinTreeElementType Item){
  BinTreePointer LocPtr;
  int level;
  LocPtr = Root;
  level = 1;
  while(!EmptyBST(LocPtr))
  {
    if(Item < LocPtr->Data)
    {
      level = level +1;
      LocPtr = LocPtr->LChild;
    }
    else if(Item > LocPtr->Data)
    {
      level = level +1;
      LocPtr = LocPtr->RChild;
    }
    else
      return level;
  }
  return -1;
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
