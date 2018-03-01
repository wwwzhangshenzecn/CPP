#include<iostream>
using namespace std;
#define MAX_SIZE 100
/*
	Time：2018/2/14
	Author:zz
	Describe:
		设有编号1，2，......,n的n（n>0）个人围成一个圈，每个人持有一个密码m。
		从第一个人开始报数，报到m是停止报数，报到m的人出圈，再从他的下一个人起重新报数
		，报到m是停止计数，报m的出圈，....，如此下去，直到所有人全部出圈为止。当任意给
		定n和m后，设计算法求n个人出圈的次序。
	Demand:
		1.建立模型，确定存储结构
		2.对任意n个人，密码为m，实现约瑟夫环问题。
		3.除权的顺序可以是依次，也可以用一个数组存储。
	Think：1.采用顺序存储结构如何实现约瑟夫环问题？
		2.如果每个人次有的密码不同，是如何实现约瑟夫环问题？

	Example：
		有n=9个人： 1 2 3 4 5 6 7 8 9
		m=5
		出圈顺序：5，1，7，4，3，6，9，2，8

*/

typedef struct Josephus{ //the struct of the sequence list
	int *data;  // the holded's number
	int *Yes;	//Yes =1 means that it is still in cricle
	int length; //the lenght of the sequence list
};

void JosephusCricle(){
	/*
		func:Solute the Josephus-Cricle question.
	*/
	int n,m;
	cout<<"The Josepuhus-Cricle Question."<<endl;
	cout<<"Please input n(0<n<100):"<<" ";cin>>n;
	cout<<"Please input m(0<m<100):"<<" ";cin>>m;
	
	Josephus *J=(Josephus *)malloc(sizeof(Josephus));
	J->data=(int *)malloc(n*sizeof(int));
	J->Yes=(int *)malloc(n*sizeof(int));
	J->length=n;
	J->data[0]=-1;
	J->Yes[0]=-1;

	for(int i=1;i<=n;i++) {
		J->data[i]=i;
		J->Yes[i]=1; //reset the holder's number
	}
	int j=1,count=0,key=0;
	while(count < n){
		if(J->Yes[j] == 1 && key < m)
			key++;
		if(key == m&&J->Yes[j] == 1){
			key=0,J->Yes[j] =0,printf("%4d",J->data[j]),count++;
			if(count%10 == 0) cout<<endl;
		}
		j++;
		if(j==n+1) j=1;
		
	}
	cout<<endl;
}
/*
int main(){
	JosephusCricle();
	return 0;
}
*/