#include<iostream>
#define MaxSize 100
using namespace std;

/*
	Author:zz
	Time:2018/2/15
	Describe:
		一.顺序栈
			1.顺序栈C语言描述
			2.基本运算的算法————置空栈，判空栈，出战，读栈顶，输出栈，判栈满
		二.链栈
			1.链栈的C语言描述
			2.基本运算的算法————置空栈、判空战、进栈、出栈、读栈顶
		三.循环队列
			1.循环队列的C语言描述
			2.基本运算的算法————置空栈、判空栈、进队、出队、读队头元素、输出循环队列
		四、链队列
			1.链队列的C语言描述
			2.基本运算的算法————置空栈、判空栈、进队、出队、读队头元素
*/


/* *************************顺序栈**************************** */
/*
		1.顺序栈C语言描述
		2.基本运算的算法————置空栈，判空栈，出栈，读栈顶，输出栈，判栈满
*/
//sequence stack
typedef int ElemType;
typedef struct {
	ElemType element[MaxSize]; // element
	int top; //the stack pointer
}Stack;

void InitSatck(Stack *S){
	/*
		func:initial the stack
	*/
	S=(Stack *)malloc(sizeof(Stack)); // apply for the space 
	S->top =-1; //the pointer is -1
}

bool IsemptyStack(Stack *S){
	/*
		func: Determine whether an empty stack is available
	*/
	return (S->top==-1);
}

ElemType PopStack(Stack *S){
	/*
		func:out of the stack
	*/
	ElemType c=S->element[S->top]; //get the element
	S->top--; // the pointer minus 1
	return c;
}

void PushStack(Stack *S,ElemType key){
	/*
		func:Push a element into the stack
	*/
	if(!IsFullStack){
		S->top++;
		S->element[S->top] =key;
	}

}

ElemType ReadStack(Stack *S ){
	/*
		func:Read the top of the stack
	*/
	return S->element[S->top];
}

void PrintSatck(Stack *S){
	/*
		func:Print the stack form the top to button
	*/
	int i=0;
	for(i=S->top;i>-1;i--)
		cout<<S->element<<"  ";
	cout<<endl;
}

int IsFullStack(Stack *S){
	/*
		Determine whether the stack is full
	*/
	if(S->top >= MaxSize)
		return 1;
	else
		return 0;
}

/* **********************Chain-Stack***************************** */
/*
	1.链栈的C语言描述
	2.基本运算的算法————置空栈、判空战、进栈、出栈、读栈顶
*/


typedef struct node{ //the struct of node
	ElemType data; //the element
	node *next; //the pointer
};

typedef struct{
	node *top; // the top pointer
}CStack; // chain -stack struct

CStack* InitCStack(){ 
	/*
		func:Initial the chain-stack
	*/
	CStack *S=(CStack *)malloc(sizeof(CStack)); //apply for the space
	return S;
}

bool IsEmptyCStack(CStack *S){
	/*
		func:Determine whether an empty stack is available
	*/
	return S->top == NULL;
}

void PushCStack(CStack *S,ElemType key){
	/*
		func:Push a element into stack
	*/
	node *n=(node *)malloc(sizeof(node));//apply for the space
	n->data=key;
	n->next=S->top;
	S->top=n; //reset the top pointer
}

node* PopCStack(CStack *S){
	/*
		func:Out of the stack
	*/
	if(IsEmptyCStack) exit; // the stack is empty,exit the programe

	node *temp=S->top; //Get the element node
	S->top=S->top->next; // the top pointer move to the next node
	temp->next=NULL;
	return temp;
}

ElemType ReadCStack(CStack *S){
	/*
		func:Read the top element
	*/
	return S->top->data;
}



/* ************************循环队列**************************** */
/*
	1.循环队列的C语言描述
	2.基本运算的算法————置空栈、判空栈、进队、出队、读队头元素、输出循环队列
*/