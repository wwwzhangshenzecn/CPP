#include<iostream>
#include<stack>
using namespace std;
#define M 6
#define N 5
/*
	Author:ZZ
	Time:2018/2/21

	Describle:
		�Թ����⣺ �����̱����ϻ�ʵ�飨���ݽṹ����pdf ��16ҳ
				��������ѧ��һ���������⡣����ѧ�Ұ�һֻ�����һ���޶��ǵĴ���ӵ���ڴ����룬
			�����������ҵ����ڳ������Թ������úܶ��ϰ���ֹ����ǰ�У��Թ�Ψһ�ĳ��ڴ���һ��
			���ң����������ҵ����ڡ�
				�����֮���Թ������ǽ���Ӳ�֪������ϰ���ͨ�����ҵ���·�����⣬�������õ��Թ�
			���£�
				�Թ�������Χǽ������䴦��Ϊ��ͨ������ÿ�������ĸ���ͨ���򣬷ֱ�Ϊ���������ϡ�
			�������Ͻ�Ϊ��ڣ����½�Ϊ���ڡ��Թ���һ����ڣ�һ�����ڡ�
				��Ƴ�������Թ������һ��ͨ·��

	Require��
		1.����Թ��Ĵ洢�ṹ��
		2.���ͨ·�Ĵ洢�ṹ��
		3.������ͨ·���㷨��
		4.����Թ���ʾ��ͨ·����ʾ��ʽ
		5.���룺�Թ�����ڼ����ڿ��ڳ������趨���Ӽ������롣
		6.������Թ�����ڡ����ڼ�ͨ··����

	Thinking��
		1.��ÿ������8����̽���򣨶������ϡ����ϡ����ϡ�����������������������Ӧ����޸ĳ���
		2.��������е�ͨ·��
		3.��������̵�ͨ·?
*/
stack<int >sx,sy;
void FindMaze(int **maze,int x,int y);
int flag=0;
int **maze; //the maze
int i_x;int i_y; //the enter coordinate
int o_x;int o_y; //the exit coordinate
void InitMaze(){
	maze=(int **)malloc(sizeof(int *)*(N+1));//��̬�����ά����
	for(int i=0;i<N+1;i++)
		*(maze+i)=( int *)malloc(sizeof(int )*(M+1));
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			maze[i][j]=0;
	maze[0][3]=1;maze[0][4]=1;
	maze[1][0]=1;maze[1][5]=1;//�����ϰ�
	maze[2][4]=1;maze[2][3]=1;maze[2][5]=1;
	maze[3][1]=1;maze[3][2]=1;
	maze[4][4]=1;
	
}
void Maze(){
	/*
		func:solute the maze-question
			input the enter's coordinate and the exit's coordinate
	*/
	
	InitMaze();
	cout<<"����5*6�Թ����Թ���ʾͼΪ(0Ϊ���ϰ���1Ϊ�ϰ���)��"<<endl;
	cout<<"000110"<<endl;
	cout<<"100001"<<endl;
	cout<<"000111"<<endl;
	cout<<"011000"<<endl;
	cout<<"000010"<<endl;
	int x,y;cout<<"Please input the enter coordinate(x,y):";
	cin>>x>>y;
	int ex,ey;cout<<"Please input the entx coordinate(ex,ey):";
	cin>>ex>>ey;
	if(ex>4||ey>5) ex=4,ey=5;
	maze[x][y]=0;
	maze[ex][ey]=2;
	cout<<"("<<ex<<","<<ey<<")"<<endl;
	FindMaze(maze,x,y);
	
}

void FindMaze(int **maze,int x,int y){
	int i=x,j=y;
	if(maze[i][j] ==0){
		sx.push(x),sy.push(y);
		maze[i][j]=1;
		if(i+1 < 5&& flag==0){ 
			FindMaze(maze,i+1,j); //down
		if(!sx.empty())
				sx.pop(),sy.pop();
		}
		if(j+1<6&&flag==0){ 
			FindMaze(maze,i,j+1); //right
			if(!sx.empty())
				sx.pop(),sy.pop();
		}
		if(j-1>=0&&flag==0){ 
			FindMaze(maze,i,j-1); //left
		if(!sx.empty())
				sx.pop(),sy.pop();
		}
		if(i-1>=0&&flag==0){	
			FindMaze(maze,i-1,j); //up
			if(!sx.empty())
				sx.pop(),sy.pop();
		}
		
	}
	else
		if(maze[i][j]==2){
			cout<<"�Թ�·�������ʾ��(��Ϊx����Ϊy)"<<endl;
			while(!sx.empty()){
				cout<<"("<<sx.top()<<","<<sy.top()<<")"<<endl;
				maze[sx.top()][sy.top()]=5;
				sx.pop(),sy.pop();
			}
			cout<<"�Թ���ʾ·��Ϊ��5����·�ߣ���"<<endl;
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++)
					cout<<maze[i][j];
				cout<<endl;
			}
			//InitMaze();
			flag=1;
		}
		else
			if(maze[i][j]==1)
				sx.push(x),sy.push(y);
}

