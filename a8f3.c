#include <stdio.h>
#include <stdlib.h>

#define QueueLimit 100

typedef int QueueElementType;

typedef struct {
	int Front, Rear;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
boolean SearchQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main (){
    QueueType aQueue;
    CreateQ(&aQueue);
    int item;

    for(int i = 3; i <= QueueLimit ; i = i+3){
        AddQ(&aQueue, i);
    }

    TraverseQ(aQueue);
    printf("Give the search value: ");
    scanf("%d", &item);
    SearchQ(&aQueue, item);
    TraverseQ(aQueue);
    return 0;
}
boolean SearchQ(QueueType *Queue, QueueElementType Item){
    boolean found = FALSE;
    int index;
    index = (*Queue).Front;
    do {
        if((*Queue).Element[index] == Item){
            found = TRUE;
            printf("Found\n");
        }
        else{
            RemoveQ(Queue, &(*Queue).Element[index]);
        }
    }while(!found);
    return found;
}

void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}


void CreateQ(QueueType *Queue)

{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)

{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)

{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)

{
	if(!EmptyQ(*Queue))
	{
		*Item = Queue ->Element[Queue -> Front];
		Queue ->Front  = (Queue ->Front + 1) % QueueLimit;
	}
	else
		printf("Empty Queue");
}

void AddQ(QueueType *Queue, QueueElementType Item)

{
    int NewRear;

	if(!FullQ(*Queue))
	{
		NewRear = (Queue ->Rear + 1) % QueueLimit;
		Queue ->Element[Queue ->Rear] = Item;
		Queue ->Rear = NewRear;
	}
	else
		printf("Full Queue");
}
