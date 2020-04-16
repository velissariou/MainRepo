#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int StackElementType;

typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);

int main() {
  StackPointer AStack;
  StackElementType AnItem;
  int n,i;
  char str[40];
  boolean found = TRUE;
  CreateStack(&AStack);
  printf("EISAGETE MIA PARASTASI: ");
  scanf("%s",str);
  for(i = 0; i<strlen(str); i++)
  {
    if(str[i]=='{' || str[i]=='(' || str[i] == '[')
      Push(&AStack, str[i]);
    else if (str[i]=='}' || str[i]==')' || str[i] == ']')
    {
      if(EmptyStack(AStack)){
        found=FALSE;
        break;
      }
      else
      {
        Pop(&AStack, &AnItem);
        if(str[i]=='}' && AnItem!='{')
        {
          found=FALSE;
          break;
        }else if(str[i]==')' && AnItem!='(')
        {
          found=FALSE;
          break;
        }if(str[i]==']' && AnItem!='[')
        {
          found=FALSE;
          break;
        }
      }
    }
  }
  if(found==FALSE || !(EmptyStack(AStack))){
    printf("WRONG\n");
  }else printf("CORRECT\n");
  return 0;
}

void CreateStack(StackPointer *Stack)

{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)

{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)

{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)

{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}
