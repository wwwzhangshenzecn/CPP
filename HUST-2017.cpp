#include<iostream>
using namespace std;
/*
	华中科技大学计算机系2017年复试上机试题
*/
void func1(){
	char C;
	cin>>C;
	int move=(int )C;
	int k=0;
	for(int n=0;n<move-65+1;n++){
		for(int j=0;j<n;j++)cout<<" ";
		int temp=move-n;
		for(int i=65;i<=2*temp-65;i++){
			if(i<=temp) 
				cout<<(char )i;
			else
				if(i>temp)
					cout<<(char )(temp*2-i);
		}
		for(int j=0;j<n;j++)cout<<" ";
		cout<<endl;
	}
}
#include<string>
#include<string.h>
string func2(string S){
	/*
		Time:2018/2/26 11:03
	*/
	string new_s="";
	int *a=(int *)malloc((S.size()/2+1)*sizeof(int));
	if(S.size()%2==1) 
		S=S+"0";
	for(int i=0;i<S.size();i=i+2){
		a[i/2]=(S[i]-'0')*10+(S[i+1]-'0')+32;
		new_s=new_s+(char )a[i/2];
	}
	return new_s;
	/*
		11:13
	*/
}

void func3_1(string A,int *a,int length){
	int count=A.size();
	for(int i=length-1;i>=0;i--){
		if(count>0)
			a[i]=A[count-1]-'0',count--;
		else
			a[i]=0;
	}
}
void func3(string A,string B){
	string C="";
	int flag=0;
	int length=(A.size()>B.size()?A.size():B.size());
	int *a=new int[length];
	func3_1(A,a,length);
	int *b=new int[length];
	func3_1(B,b,length);
	int *c=new int[length+1];
	for(int i=0;i<length+1;i++)
		c[i]=0;
	for(int i=length-1;i>=0;i--){
		c[i+1]=(a[i]+b[i]+flag)%10;
		if(a[i]+b[i]+flag>=10)
			flag=1;
		else
			flag=0;
	}
	c[0]=flag;
	if(c[0]==1)cout<<c[0];
	for(int i=1;i<length+1;i++)
		cout<<c[i];
	cout<<endl;
}
