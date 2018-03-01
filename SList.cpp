#include<iostream>
#include<stdio.h>
using namespace std;

#define Max_Length 100
#define OK 1
#define FALSE 0
#define Max_Size

/* ******************************˳���˳����������********************************************  */
//˳������ݽṹ
typedef struct Stu{
	double *num; //ѧ��ѧ��
	int Length; //˳�����
	int Size;//˳���Ŀռ��С
}Stu;

//�����յ�˳���
int InitList(Stu *L){
	/*
	func����ʼ��˳���
	parameter��L ˳���
	*/
	L->num = (double *)malloc(Max_Length *sizeof(double)); // ����ռ�
	if(L->num) exit(-2); //����ռ�ʧ��
	L->Length = 0; //��ʼ������Ϊ0
	L->Size = 0; // ��С��ʼ��Ϊ0
	return 1;
}
	
//˳����
int LengthList(Stu *L){
	/*
	func:˳����
	parameter: L ˳���
	return : int 
	*/	
	if(L) // ���Ϸ���
		return 0;  //˳�������
	else
		return L->Length; //ֱ�ӷ���˳����
}

//ȡ˳���Ľ��
double GetListNode(Stu *L,int key){
	if(key > L->Length || key < 1) return -1; //�Ƿ�λ��
	return L->num[key-1];
}

//��λ����
int CList(Stu *L,double x){
	int i=0;
	while(L->num[i] != x && i<L->Length ) i++; // ���ҹؼ�ֵ
	if(i > L->Length) 
		return -1;  //δ�ҵ��ؼ�ֵ������-1
	else 
		return i+1; //�ҵ��ؼ�ֵ��������λ��
}

//��������
int InsertList(Stu *L,double x,int n){
	/*
	func:����˳���������λ�ô��ڱ�+1����Ĭ�ϲ鵽���
	parameter�� x Ϊ�ؼ�ֵ  n Ϊ����λ��
	return�� 1 ����ɹ�  0 ����ʧ��
	*/
	
	if(n < 1) return 0; //����λ��Ϊ0����������ʧ��
	if(n >= L->Length+1){
		L->num[L->Length+1] = x;
		}
	else{ // ����λ��Ϊ����
		int m = L->Length - n +1; //��β�����Ҫ�ƶ�����
		int i=0;
		for(i=0;i<m;i++){
			int temp = L->Length -1 - i;
			L->num[temp+1] = L->num[temp];
		}
	}
	L->Length+=1; //����ɹ������ȼ�1
	return 1;
}

//ɾ������
int deleteList(Stu *L,int n){
	/*
	*/
	if(n > L->Length || n< 1) return 0; //ɾ��λ�÷Ƿ�������0
	for(int i=n-1;i< L->Length;i++){
		L->num[i] = L->num[i+1];
	}
	L->Length -=1;//ɾ���ɹ������ȼ�1
	return 1;//

}

//����˳���
int Createlist(Stu *L,int a[],int n){
	/*
	*/
	if(n > Max_Length) return 0; //�ռ䲻����ʧ�ܣ�����0
	for(int i=0;i<n;i++)
		L->num[i] = a[i];
	L->Length = n; //���ȸ�ֵ
	return 1; //�����ɹ�������1
}

//���˳���
void PrintList(Stu *L){
	for(int i=0;i< L->Length;i++)
		cout<<L->num[i]<<"   ";  //�������˳�����
	cout <<endl;
}


/* *****************************���������������********************************************  */




