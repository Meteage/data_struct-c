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
	s->top--;
	*e = s->data[s->top];
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
int push(Stack *s,ElemType e){
	Stack *p = (Stack*)malloc(sizeof(Stack));
	if(p == NULL) return 0;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return 1;
}

int pop(Stack *s,ElemType *e){
	if(s->next == NULL) return 0;
	Stack *p = s->next;
	*e = p->data;
	s->next = p->next;
	free(p);
	return 1;
}

void freeStack(Stack *s){
	Stack *p = s->next;
	while(p!=NULL){
		s->next = p->next;
		free(p);
		p = s->next;
	}
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

//栈式虚拟机
char *expr = "92/2+46*-";

typedef enum {
	LEFT_PARE,RIGHT_PARE,
	ADD,SUB,MUL,DIV,MOD,
	EOS,NUM
} ContentType;

int getToken(char c){
	switch (c)
	{
	case '(':
		return LEFT_PARE;	
	case ')':
		return RIGHT_PARE;
	case '+':
		return ADD;
	case '-':
		return SUB;
	case '*':
		return MUL;
	case '/':
		return DIV;
	case '%':
		return MOD;
	case '\0':
		return EOS;
	default:
		return NUM;
	}
}

//输入后缀表达式，返回执行结果
int eval(const char *expr){
	int token = 0;
	Stack *s = initStack();
	ElemType op1,op2;
	ElemType result = 0;
	//获取字符
	while(*expr != '\0'){
		//判断是什么类型
		token = getToken(*expr);
		//遇到数字压栈
		if(token == NUM){
			push(s,*expr - '0');
		}
		else{
		//遇到操作符连续弹两次，并进行运算
			pop(s,&op2);
			pop(s,&op1);

			switch (token)
			{
			case ADD:
				push(s,op1 + op2);
				break;
			case SUB:
				push(s,op1 - op2);
				break;
			case MUL:
				push(s,op1 * op2);
				break;
			case DIV:
				push(s,op1 / op2);
				break;
			case MOD:
				push(s,op1 % op2);
				break;
			default:
				break;
			}
		}

		expr++;
	}

	pop(s,&result);

	return result;
}

int main(int argc,char const * agrv){
	Stack *s = initStack();
	ElemType e;
	for(int i=0;i<6;i++)push(s,i);
	list(s);
	pop(s,&e);
	list(s);
	freeStack(s);
	list(s);
	push(s,1);
	list(s);

	printf("eval's result:%d\n",eval(expr));

	return 0;
}