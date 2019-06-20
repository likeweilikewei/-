#pragma once
/*
�Զ����±���¼��
*/
#include<algorithm>

using namespace std;

int bridge(int* t, int n, int* T);
int bridge_top_down(int* t, int n);

int bridge_top_down(int* t, int n)
{
	//�������鱣���м���,T[i]��Ӧi���˹��ӵ���Сʱ��
	int* T = new int[n + 1];
	//��ʼ������Ϊδ����
	for (int i = 0; i < n + 1; i++)
		T[i] = -1;
	return bridge(t, n, T);
}

int bridge(int* t, int  n, int* T)
{
	if (t == nullptr || n <= 0)
		return 0;
	//����Ѿ��������ֱ�ӷ���
	if (T[n] != -1)
		return T[n];
	//ֱ�ӷ��ص����
	if (n == 1)
	{
		T[n] = t[0];
		return T[n];
	}
	if (n == 2)
	{
		T[n] = t[1];
		return T[n];
	}
	//������㣬Ȼ���������
	T[n] = min(bridge(t,n-1,T) + t[0] + t[n - 1], bridge(t,n-2,T) + t[0] + t[n - 1] + 2 * t[1]);
	return T[n];
}
