#include<iostream>
#include<stdio.h>
using namespace std;

#define Max_Length 100
#define OK 1
#define FALSE 0
#define Max_Size

/* ******************************顺序表及顺序表基本操作********************************************  */
//顺表表数据结构
typedef struct Stu{
	double *num; //学生学号
	int Length; //顺序表长度
	int Size;//顺序表的空间大小
}Stu;

//建立空的顺序表
int InitList(Stu *L){
	/*
	func：初始化顺序表
	parameter：L 顺序表
	*/
	L->num = (double *)malloc(Max_Length *sizeof(double)); // 申请空间
	if(L->num) exit(-2); //分配空间失败
	L->Length = 0; //初始化长度为0
	L->Size = 0; // 大小初始化为0
	return 1;
}
	
//顺序表表长
int LengthList(Stu *L){
	/*
	func:顺序表表长
	parameter: L 顺序表
	return : int 
	*/	
	if(L) // 检查合法性
		return 0;  //顺序表不存在
	else
		return L->Length; //直接返回顺序表表长
}

//取顺序表的结点
double GetListNode(Stu *L,int key){
	if(key > L->Length || key < 1) return -1; //非法位置
	return L->num[key-1];
}

//定位运算
int CList(Stu *L,double x){
	int i=0;
	while(L->num[i] != x && i<L->Length ) i++; // 查找关键值
	if(i > L->Length) 
		return -1;  //未找到关键值，返回-1
	else 
		return i+1; //找到关键值，并返回位置
}

//插入运算
int InsertList(Stu *L,double x,int n){
	/*
	func:插入顺序表，若插入位置大于表长+1，则默认查到最后
	parameter： x 为关键值  n 为插入位置
	return： 1 插入成功  0 插入失败
	*/
	
	if(n < 1) return 0; //插入位置为0或负数，插入失败
	if(n >= L->Length+1){
		L->num[L->Length+1] = x;
		}
	else{ // 插入位置为表中
		int m = L->Length - n +1; //表尾结点需要移动个数
		int i=0;
		for(i=0;i<m;i++){
			int temp = L->Length -1 - i;
			L->num[temp+1] = L->num[temp];
		}
	}
	L->Length+=1; //插入成功，长度加1
	return 1;
}

//删除运算
int deleteList(Stu *L,int n){
	/*
	*/
	if(n > L->Length || n< 1) return 0; //删除位置非法，返回0
	for(int i=n-1;i< L->Length;i++){
		L->num[i] = L->num[i+1];
	}
	L->Length -=1;//删除成功，长度减1
	return 1;//

}

//建立顺序表
int Createlist(Stu *L,int a[],int n){
	/*
	*/
	if(n > Max_Length) return 0; //空间不够，失败，返回0
	for(int i=0;i<n;i++)
		L->num[i] = a[i];
	L->Length = n; //长度赋值
	return 1; //建立成功，返回1
}

//输出顺序表
void PrintList(Stu *L){
	for(int i=0;i< L->Length;i++)
		cout<<L->num[i]<<"   ";  //依次输出顺序表结点
	cout <<endl;
}


/* *****************************链表及链表基本操作********************************************  */




