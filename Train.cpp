#include<iostream>
#include<queue>
using namespace std;
/*
	Author:zz
	Time:2018/2/24
	Describle:����������
		һ����������
				һ�л����г�����n�ڳ��ᣬÿ�ڳ��Ὣͣ���ڲ�ͬ�ĳ�վ���ٶ�n����վ
			�ı�ŷֱ�Ϊ1~n���������г����յ�nվ����1վ�Ĵ��򾭹���Щ��վ��Ϊ�˱��ڴ�
			�г���ж����Ӧ�ĳ��ᣬ����ı��Ӧ�복վ�ı����ͬ����������ÿ����վֻҪ
			ж�����һ�ڳ��ᡣ���Ը����������ĳ��ᣬ���������������ǡ�
				��������Ź�������ͨ��ת��վ��ɡ���ת��վ��һ����죬һ�������K
			������죬�����λ�����ͳ���֮�䡣�ٶ�����찴�Ƚ��ȳ��ķ�ʽ���������
			�㷨����𳵳����������⡣
		��������Ҫ��
			1.��ƴ洢�ṹ��ʾn�����ᣬk��������Լ����ͳ��졣
			2.��Ʋ�ʵ�ֳ��������㷨��
			3.�����㷨��ʱ�����ܡ�
		����˼��
			�������찴����ȳ��ķ�ʽ����������ջ��ʾ����죬Ӧ��ν���𳵳����������⣿
		
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

	int k; // �����
	
}


