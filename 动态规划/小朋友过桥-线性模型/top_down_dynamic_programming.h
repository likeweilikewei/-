#pragma once
/*
自顶向下备忘录法
*/
#include<algorithm>

using namespace std;

int bridge(int* t, int n, int* T);
int bridge_top_down(int* t, int n);

int bridge_top_down(int* t, int n)
{
	//申请数组保存中间结果,T[i]对应i个人过河的最小时间
	int* T = new int[n + 1];
	//初始化数组为未访问
	for (int i = 0; i < n + 1; i++)
		T[i] = -1;
	return bridge(t, n, T);
}

int bridge(int* t, int  n, int* T)
{
	if (t == nullptr || n <= 0)
		return 0;
	//如果已经计算过则直接返回
	if (T[n] != -1)
		return T[n];
	//直接返回的情况
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
	//否则计算，然后存入结果集
	T[n] = min(bridge(t,n-1,T) + t[0] + t[n - 1], bridge(t,n-2,T) + t[0] + t[n - 1] + 2 * t[1]);
	return T[n];
}
