#include<iostream>
using namespace std;

/*
	author:zz
	time:2018/2/13 
	func:用有序的单链表表示集合，实现集合的交、并和差运算
	基本要求：
	1.对集合中的元素，用有序单链表进行存储。
	2.实现交、并和差运算，不另外申请存储空间
	3.充分利用单链表的有序性，算法有较好的时间性能
	思考：
	如果表示结合的单链表是无序的，用如何实现集合的交、并和差运算？

	实验用例：数字集合
	例如：	A={1,2,3,4,5,6,7,8,9} B={1,3,5,7,9，10}
			AUB={1,2,3,4,5,6,7,8,9，10}
			A∩B={1，3，5，7，9}
			A-B={2,4,6,8}
*/

struct Set{
	int data; //元素
	Set *next;
};


void CreateLsit(Set *A,int *d,int n){
	/*
		function：建立有序单链表
	*/
	Set *a=A,
		*r; 
	a->next=NULL;
	for(int i=n-1;i>=0;i--){
		r=(Set *)malloc(sizeof(Set));// apply for a secondary space 
		r->data = d[i];
		r->next = a->next;
		a->next = r;
		r=NULL;
		free(r);
	}
}

void  Union(Set *A,Set *B){
	/*
		func:the Union of A and B,and equal to C
	*/
	
	Set *a=A->next,*b=B->next;
	
	while(a && b){
		if(a->data == b->data)
			cout<<a->data<<"  ",a=a->next,b=b->next; //element of Union
		while(a && a->data < b->data)
			a=a->next; // the next node of a of set
		while(b && A->data > b->data)
			b=b->next; // the next node of b of set
	} 
	cout<<endl;
}

void Intersection(Set *A,Set *B){
	/*
		func:the Intersection of A and B ,and return C
	*/
	Set *a=A->next,*b=B->next;

	while(a &&b){
		if(a->data > b->data )
			cout<<b->data<<"  ",b=b->next; //get the element and b is the next node of the set b
		if(a->data < b->data )	
			cout<<a->data<<"  ",a=a->next; //get the element and a is the next node if the set a
		if(a->data == b->data )
			cout<<a->data<<"  ",a=a->next,b=b->next; //get the element , both of a and b id the next
	}
	if(!a) // a is empty
		while(b)
			cout<<b->data<<"  ",b=b->next;
	else
		while(a) //b is empty
			cout<<a->data<<"  ",a=a->next;

	cout<<endl;
}

void Substract(Set *A,Set *B){
	/*
		func:the substract of A and B,and equal to C
	*/
	Set *a=A->next,*b=B->next;

	while(a){ //a is no empty
		while(b && b->data < a->data)
			b=b->next;
		if(b==NULL || b->data >a->data)
			cout<<a->data <<"  ";
		a=a->next;
	}
	cout<<endl;
}

void PrintList(Set *A){
	/*
		func:print the set A
	*/
	Set *a=A->next;
	while(a)
		cout <<a->data<<"  ",a=a->next;
	cout<<endl;
}

/*

int main(){
	int a[]={1,2,3,4,5,6,7,8,9};
	int b[]={1,3,5,7,9,10};
	int c[]={0};
	Set *A=(Set *)malloc(sizeof(Set));
	Set *B=(Set *)malloc(sizeof(Set));
	Set *C=(Set *)malloc(sizeof(Set));
	CreateLsit(A,a,9);
	CreateLsit(B,b,6);
	CreateLsit(C,c,1);

	Union(A,B);
	
	Substract(A,B);

	Intersection(A,B);

	return 0;
}

*/