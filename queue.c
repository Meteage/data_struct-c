#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 4

typedef int ElemType;

typedef struct {
	ElemType * data;
	int front;
	int rear;
	int is_full;
} Queue;

Queue * initQueue(){
	Queue *q = (Queue*)malloc(sizeof(Queue));
	q->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	q->front = 0;
	q->rear = 0;
	q->is_full = 0;
	return q;
}

int deQueue(Queue *q,ElemType *e){
	if(q->front == q->rear && !q->is_full) return 0;
	*e = q->data[q->front];
	q->front = (q->front+1)%MAXSIZE;
	q->is_full = 0;
	return 1;
}

int enQueue(Queue *q,ElemType e){
	if(q->is_full) return 0;
	q->data[q->rear] = e;
	q->rear = (q->rear+1)%MAXSIZE;
	q->is_full = (q->front == q->rear);
	return 1;
}
void listQueue(Queue *q){
	for(int i=0;i<MAXSIZE;i++){
		printf("%d ",q->data[i]);
	}
}

int main(){
	Queue *q = initQueue();
	ElemType *e;
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
	enQueue(q,4);
	deQueue(q,e);
	enQueue(q,5);

	listQueue(q);
	printf("e:%d\n",*e);

	return 0;
}