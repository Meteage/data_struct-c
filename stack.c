#include <stdio.h>
#include <stdlib.h>
#define STACK_ARRAY 0

#ifndef STACK_ARRAY
//堆栈线性表实现
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
	ElemType *data;
	int top;
} Stack;

Stack *initStack(){
	Stack * s = (Stack *)malloc(sizeof(Stack));
	s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
	s->top = 0;
	return s;
}

int push(Stack *s,ElemType e){
	if(s->top >= MAXSIZE -1) return 0;
	s->data[s->top] = e;
	s->top++;
	return 1;
}

int pop(Stack *s,ElemType *e){
	if(s->top == 0) return 0;
	*e = s->data[s->top];
	s->top--;
	return 1;
}

void list(Stack *s){
	int i=0;
	while (i<s->top)
	{
		printf("%d ",s->data[i]);
		i++;
	}
	printf("\n");
}

#endif

#ifdef STACK_ARRAY
//堆栈链式实现
typedef int ElemType;

typedef struct stack{
	ElemType data;
	struct stack *next;
} Stack;

Stack *initStack(){
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->data = 0;
	s->next = NULL;
	return s;
}

//头插法
void push(Stack *s,ElemType e){
	Stack *p = (Stack*)malloc(sizeof(Stack));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

int pop(Stack *s,ElemType *e){
	if(s->next == NULL) return 0;
	Stack *p = s->next;
	*e = p->data;
	s->next = p->next;
	free(p);
	return 1;
}

void list(Stack *s){
	Stack *p = s->next;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

#endif

int main(int argc,char const * agrv){
	Stack *s = initStack();
	ElemType e;
	for(int i=0;i<6;i++)push(s,i);
	list(s);
	pop(s,&e);
	list(s);

	return 0;
}