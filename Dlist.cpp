#include<string>
#include<iostream>

#define OK 1
#define ERROR 0
#define STADE int

using namespace std;

/******************������*************************/

/*
	��飺���������̴�ѧ�ϻ�ʵ��--������Ļ���������
	ʱ�䣺2018/2/12
	���ߣ�����
*/

struct Student { // ѧ���ṹ��
	string number; //ѧ��ѧ��
	Student *next; // ָ����һ�����ָ��
} ;

STADE ClearList(Student *H){
	/*
		func:�ÿյ�����
	*/
	Student *r = H->next,*p;
	while(!r){
		p = r;
		free(p);
		r->next;
	}

	return OK;
} 

STADE LenghtList(Student *H){
	/*
		func:���ĳ���
	*/
	Student *r = H->next,*p;
	int count =0; //������
	while (!r) count++,r = r->next;  //����ѭ��
	return count;
}

Student* GetNode(Student *H,string num){
	/*
		func:ȡ������Ľ��
		return : ����û�йؼ��ʣ��򷵻ؿ�
	*/
	Student *r=H->next; 
	while(r->number != num && r->next != NULL) //�ҵ����
		r = r->next;

	return r;
}

STADE InsertList(Student *H,Student *key){
	/*
		func:�������㣬���뵽��β
	*/
	Student *r = H->next;
	while(!r->next) r= r->next;  //�ҵ���β
	r->next = key;
	return OK;
}

STADE DeleteLNode(Student *H,string num){
	/*
		func:ɾ���������еĹؼ��ʵĽ��
	*/
	Student *p=H,*r =H->next;
	while(!r && r->number!= num){ //�ҵ��ؼ��ʽ��
		p =r;
		r = r->next;
	}

	p->next = r->next; // ȡ�����r
	free(r); //�ͷŽ��

	return OK;
}


STADE CreateNHList(Student *H,string *num,int n){
	/*
		func:��������ͷ���ĵ�����--ͷ�巨����
	*/
	Student *r,*p;
	p=NULL;
	r=(Student *)malloc(sizeof(Student)); // ����ռ�
	if(!r) return  ERROR; //����ռ�ʧ��
	for(int i=0;i<n;i++){
	
		r->number = num[i];
		r->next = p;
		p=r;
	}
	H=r;
	r=NULL;
	free(r);
	return OK;
}

STADE CreateHList(Student *H,string *num,int n){
	/*
		func:������ͷ�ڵ㵥����--β�巨����
	*/
	Student *r,*p=H;
	r=(Student *)malloc(sizeof(Student)); // ����ռ�
	if(!r) return  ERROR; //����ռ�ʧ��
	for(int i=0;i<n;i++){
		r->number =num[i];
		p->next = r; //β��
		p = r;
	}
	r=NULL;
	free(r);
	return OK;
}

STADE PrintHList(Student *H){
	/*
		func:�����ͷ���ĵ�����
	*/
	Student *r=H->next;
	while(!r){
		cout<<r->number<<endl;
	}

	return OK;
}

















