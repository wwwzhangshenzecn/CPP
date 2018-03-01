#include<string>
#include<iostream>

#define OK 1
#define ERROR 0
#define STADE int

using namespace std;

/******************单链表*************************/

/*
	简介：哈尔滨工程大学上机实验--单链表的基本上运算
	时间：2018/2/12
	作者：张泽
*/

struct Student { // 学生结构体
	string number; //学生学号
	Student *next; // 指向下一个结点指针
} ;

STADE ClearList(Student *H){
	/*
		func:置空单链表
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
		func:求表的长度
	*/
	Student *r = H->next,*p;
	int count =0; //计数器
	while (!r) count++,r = r->next;  //计数循环
	return count;
}

Student* GetNode(Student *H,string num){
	/*
		func:取单链表的结点
		return : 若不没有关键词，则返回空
	*/
	Student *r=H->next; 
	while(r->number != num && r->next != NULL) //找到结点
		r = r->next;

	return r;
}

STADE InsertList(Student *H,Student *key){
	/*
		func:插入运算，插入到链尾
	*/
	Student *r = H->next;
	while(!r->next) r= r->next;  //找到链尾
	r->next = key;
	return OK;
}

STADE DeleteLNode(Student *H,string num){
	/*
		func:删除单链表中的关键词的结点
	*/
	Student *p=H,*r =H->next;
	while(!r && r->number!= num){ //找到关键词结点
		p =r;
		r = r->next;
	}

	p->next = r->next; // 取出结点r
	free(r); //释放结点

	return OK;
}


STADE CreateNHList(Student *H,string *num,int n){
	/*
		func:建立不带头结点的单链表--头插法建表
	*/
	Student *r,*p;
	p=NULL;
	r=(Student *)malloc(sizeof(Student)); // 申请空间
	if(!r) return  ERROR; //申请空间失败
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
		func:建立带头节点单链表--尾插法建表
	*/
	Student *r,*p=H;
	r=(Student *)malloc(sizeof(Student)); // 申请空间
	if(!r) return  ERROR; //申请空间失败
	for(int i=0;i<n;i++){
		r->number =num[i];
		p->next = r; //尾插
		p = r;
	}
	r=NULL;
	free(r);
	return OK;
}

STADE PrintHList(Student *H){
	/*
		func:输出带头结点的单链表
	*/
	Student *r=H->next;
	while(!r){
		cout<<r->number<<endl;
	}

	return OK;
}

















