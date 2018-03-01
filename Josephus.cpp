#include<iostream>
using namespace std;
#define MAX_SIZE 100
/*
	Time��2018/2/14
	Author:zz
	Describe:
		���б��1��2��......,n��n��n>0������Χ��һ��Ȧ��ÿ���˳���һ������m��
		�ӵ�һ���˿�ʼ����������m��ֹͣ����������m���˳�Ȧ���ٴ�������һ���������±���
		������m��ֹͣ��������m�ĳ�Ȧ��....�������ȥ��ֱ��������ȫ����ȦΪֹ���������
		��n��m������㷨��n���˳�Ȧ�Ĵ���
	Demand:
		1.����ģ�ͣ�ȷ���洢�ṹ
		2.������n���ˣ�����Ϊm��ʵ��Լɪ�����⡣
		3.��Ȩ��˳����������Σ�Ҳ������һ������洢��
	Think��1.����˳��洢�ṹ���ʵ��Լɪ�����⣿
		2.���ÿ���˴��е����벻ͬ�������ʵ��Լɪ�����⣿

	Example��
		��n=9���ˣ� 1 2 3 4 5 6 7 8 9
		m=5
		��Ȧ˳��5��1��7��4��3��6��9��2��8

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