#include<iostream>
#include<queue>
using namespace std;
/*
	Author:zz
	Time:2018/2/24
	Describle:火车重排问题
		一、问题描述
				一列货运列车共有n节车厢，每节车厢将停放在不同的车站。假定n个车站
			的编号分别为1~n，即货运列车按照第n站至第1站的次序经过这些车站。为了便于从
			列车上卸掉相应的车厢，车厢的编号应与车站的编号相同，这样，在每个车站只要
			卸掉最后一节车厢。所以给定任意次序的车厢，必须重新排列他们。
				车厢的重排工作可以通过转轨站完成。在转轨站有一个入轨，一个出轨和K
			个缓冲轨，缓冲轨位于入轨和出轨之间。假定缓冲轨按先进先出的方式运作，设计
			算法解决火车车厢重排问题。
		二、基本要求：
			1.设计存储结构表示n个车厢，k个缓冲轨以及入轨和出轨。
			2.设计并实现车厢重排算法。
			3.分析算法的时间性能。
		三、思考
			如果缓冲轨按后进先出的方式工作，即用栈表示缓冲轨，应如何解决火车车厢重排问题？
		
*/
#define N 100
#define K 10
typedef struct TrainStation{
	int *Enter;
	queue<int > *Q;
	int *Exit;
};
void Train(){
	TrainStation *T=(TrainStation *)malloc(sizeof(TrainStation));
	T->Enter=(int *)malloc(sizeof(int )*N);
	T->Exit=(int *)malloc(sizeof(int )*N);
	T->Q=(queue<int> *)malloc(sizeof(queue<int> )*K);

	for(int i=1;i<N+1;i++)
		T->Enter[i]=i;

	int k; // 缓冲轨
	
}


