#include<iostream>
#include<stack>
using namespace std;
#define M 6
#define N 5
/*
	Author:ZZ
	Time:2018/2/21

	Describle:
		迷宫问题： 哈工程本科上机实验（数据结构）。pdf 第16页
				这是心理学的一个经典问题。心理学家把一只老鼠从一个无顶盖的大盒子的入口处放入，
			让老鼠自行找到出口出来。迷宫中设置很多障碍阻止老鼠前行，迷宫唯一的出口处有一块
			奶酪，吸引老鼠找到出口。
				简而言之，迷宫问题是解决从不知了许多障碍的通道中找到出路的问题，本题设置的迷宫
			如下：
				迷宫四周设围墙：无填充处，为可通处。设每个点有四个可通方向，分别为东、西、南、
			北。左上角为入口，右下角为出口。迷宫有一个入口，一个出口。
				设计程序求解迷宫问题的一条通路。

	Require：
		1.设计迷宫的存储结构。
		2.设计通路的存储结构。
		3.设计求解通路的算法。
		4.设计迷宫显示和通路的显示方式
		5.输入：迷宫、入口及出口可在程序中设定，从键盘输入。
		6.输出：迷宫、入口、出口及通路路劲。

	Thinking：
		1.若每个点有8个试探方向（东、东南、、南、西南、西、西北、北、东北），应如何修改程序？
		2.如何求所有的通路？
		3.如何求得最短的通路?
*/
stack<int >sx,sy;
void FindMaze(int **maze,int x,int y,int k);
int flag=0;
int **maze; //the maze
int i_x;int i_y; //the enter coordinate
int o_x;int o_y; //the exit coordinate
void InitMaze(){
	maze=(int **)malloc(sizeof(int *)*(N+1));//动态申请二维数组
	for(int i=0;i<N+1;i++)
		*(maze+i)=( int *)malloc(sizeof(int )*(M+1));
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			maze[i][j]=0;
	maze[0][3]=1;maze[0][4]=1;
	maze[1][0]=1;maze[1][5]=1;//设置障碍
	maze[2][4]=1;maze[2][3]=1;maze[2][5]=1;
	maze[3][1]=1;maze[3][2]=0;
	maze[4][4]=1;
	
}
void Maze(){
	/*
		func:solute the maze-question
			input the enter's coordinate and the exit's coordinate
	*/
	
	InitMaze();
	cout<<"走入5*6迷宫，迷宫显示图为(0为无障碍，1为障碍物)："<<endl;
	cout<<"000110"<<endl;
	cout<<"100001"<<endl;
	cout<<"000111"<<endl;
	cout<<"010000"<<endl;
	cout<<"000010"<<endl;
	int x,y;cout<<"Please input the enter coordinate(x,y):";
	cin>>x>>y;
	int ex,ey;cout<<"Please input the entx coordinate(ex,ey):";
	cin>>ex>>ey;
	if(ex>4||ey>5) ex=4,ey=5;
	maze[x][y]=0;
	maze[ex][ey]=2;
	FindMaze(maze,x,y,1);
}

void FindMaze(int **maze,int x,int y,int k){
	int i=x,j=y;
	if(maze[i][j] ==0){
		sx.push(x),sy.push(y);
		maze[i][j]=1;
 		if(i+1 < 5&& (k+3)!=5){ 
			FindMaze(maze,i+1,j,3); //down
			if(!sx.empty())
				sx.pop(),sy.pop();
			
		}
		if(j+1<6&& (k+1)!=5){ 
			FindMaze(maze,i,j+1,1); //right
			if(!sx.empty())
				sx.pop(),sy.pop();
			
		}
		if(i-1>=0&& (k+2)!=5){	
			FindMaze(maze,i-1,j,2); //up
			if(!sx.empty())
				sx.pop(),sy.pop();
			
		}
		if(j-1>=0&& (k+4)!=5){ 
			FindMaze(maze,i,j-1,4); //left
			if(!sx.empty())
				sx.pop(),sy.pop();
			
		}
		maze[i][j]=0;
	}
	else
		if(maze[i][j]==2){
			int m[N][M]={0};
			m[0][3]=1;m[0][4]=1;
			m[1][0]=1;m[1][5]=1;//设置障碍
			m[2][4]=1;m[2][3]=1;maze[2][5]=1;
			m[3][1]=1;m[3][2]=0;
			m[4][4]=1;
			sx.push(x),sy.push(y);
			stack<int >EX=sx,EY=sy;
			cout<<"迷宫路线坐标表示：(竖为x，横为y)"<<endl;
			while(!EX.empty()){
				cout<<"("<<EX.top()<<","<<EY.top()<<")"<<endl;
				m[EX.top()][EY.top()]=5;
				EX.pop(),EY.pop();
			}
			cout<<"迷宫显示路线为（5代表路线）："<<endl;
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++)
					cout<<m[i][j];
				cout<<endl;
			}
			//InitMaze();
			flag=1;
			maze[sx.top()][sy.top()]=2;
			cout<<endl;
			cout<<endl;
		}
		else
			if(maze[i][j]==1)
				sx.push(x),sy.push(y);
}


