#include <stdio.h>
#include <stdlib.h>

typedef int QueueElementType;

typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;

void TraverseQ(QueueType Queue);
void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

int main(){
  QueueType AQueue;
  QueuePointer CurPtr,PredPtr;
  int number,m,i,j;
  CreateQ(&AQueue);
  printf("DWSE TO PLITHOS TWN FYLAKISMENWN: ");
  scanf("%d",&number);
  for(i=1; i<=number; i++){
    AddQ(&AQueue, i);
  }
  TraverseQ(AQueue);
  printf("DWSE TON ARITHMO TOU KYKLOU EKTELESIS: ");
  scanf("%d",&m);
  CurPtr = AQueue.Front;
  j=1;

  while (j < number) {
    for(i=1; i<m; i++){
      PredPtr = CurPtr;
      CurPtr = CurPtr->Next;
    }
    printf("EXECUTION %d\n",CurPtr->Data);
    PredPtr = CurPtr;
    CurPtr = CurPtr->Next;

    j=j+1;
  }
  printf("SURVIVAL %d",CurPtr->Data);
  return 0;

}

void CreateQ(QueueType *Queue)

{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)

{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)

{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
    
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)

{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Rear->Next = Queue->Front;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%d ", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}
