#include <stdlib.h>
#include <stdio.h>
#define QueueLimit 20

typedef int QueueElementType;


typedef struct {
	int Front, Rear, randomOdds, randomEvens;
	QueueElementType Element[QueueLimit];
} QueueType;

typedef enum {FALSE, TRUE} boolean;

void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
boolean FullQ(QueueType Queue);
void RemoveQ(QueueType *Queue, QueueElementType *Item);
void AddQ(QueueType *Queue, QueueElementType Item);
void TraverseQ(QueueType Queue);

int main() {
    QueueElementType evenItem, oddItem;
    QueueType OddQueue, EvenQueue;
    CreateQ(&OddQueue);
    CreateQ(&EvenQueue);
    int i, j, randomEvens, randomOdds;
    for(i=0; i<QueueLimit; i++) {

        j = rand()% QueueLimit + 1;
        if(j%2==0){
            AddQ(&EvenQueue, j);
        }else{
            AddQ(&OddQueue, j);
        }
    }
    printf("Size of Even Queue: %d\n", EvenQueue.Rear - EvenQueue.Front);
    TraverseQ(EvenQueue);

    printf("Size of Odd Queue: %d\n", OddQueue.Rear - OddQueue.Front);
    TraverseQ(OddQueue);

    randomEvens = rand() % (EvenQueue.Rear - EvenQueue.Front+1);
    printf("Random number of items: %d\n", randomEvens);
    for(i=0; i<randomEvens; i++){
       evenItem = EvenQueue.Element[EvenQueue.Front];
       AddQ(&EvenQueue, evenItem) ;
       RemoveQ(&EvenQueue, &evenItem);
    }

    printf("Size of Even Queue: %d\n", EvenQueue.Rear - EvenQueue.Front);
    TraverseQ(EvenQueue);

    randomOdds = rand() % (OddQueue.Rear - OddQueue.Front+1);
    printf("Random number of items: %d\n", randomOdds);
    for(i=0; i<randomOdds; i++){
       oddItem = EvenQueue.Element[OddQueue.Front];
       RemoveQ(&OddQueue, &oddItem);
       AddQ(&OddQueue, oddItem) ;
    }
    printf("Size of Odd Queue: %d\n", OddQueue.Rear - OddQueue.Front);
    TraverseQ(OddQueue);
}


void CreateQ(QueueType *Queue)
/*  ����������:  ���������� ��� ���� ����.
    ����������:  ���� ����
*/
{
	Queue->Front = 0;
	Queue->Rear = 0;
}

boolean EmptyQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ����.
   ����������: True �� � ���� ����� ����, False �����������
*/
{
	return (Queue.Front == Queue.Rear);
}

boolean FullQ(QueueType Queue)
/* �������:    ��� ����.
   ����������: ������� �� � ���� ����� ������.
   ����������: True �� � ���� ����� ������, False �����������
*/
{
	return ((Queue.Front) == ((Queue.Rear +1) % QueueLimit));
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* �������:    ��� ����.
   ����������: ������� �� �������� Item ��� ��� ������ ���� ��� �����
                �� � ���� ��� ����� ����.
   ����������: �� �������� Item ��� ��� ������������� ����.
   ������:     ������ ����� ���� �� � ���� ����� ����
*/
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
/* �������:    ��� ���� Queue ��� ��� �������� Item.
   ����������: ��������� �� �������� Item ���� ���� Queue
                �� � ���� ��� ����� ������.
   ����������: ��� ������������� ����.
   ������:     ������ ������� ����� �� � ���� ����� ������
*/
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

void TraverseQ(QueueType Queue) {
	int current;
	current = Queue.Front;
	while (current != Queue.Rear) {
        printf("%d ", Queue.Element[current]);
		current = (current + 1) % QueueLimit;
	}
	printf("\n");
}



