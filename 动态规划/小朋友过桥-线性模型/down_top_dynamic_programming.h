#pragma once
/*自底向上动态规划解决小朋友过桥*/

#include<algorithm>

using namespace std;

int bridge_down_top(int* t, int n);

int bridge_down_top(int* t, int n)
{
	if (n <= 0||t==nullptr)
		return 0;

	//申请数组存储中间结果
	int* T = new int[n + 1];
	T[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			T[i] = t[0];
		else if (i == 2)
			T[i] = t[1];
		else
			T[i] = min(T[i - 1] + t[0] + t[i - 1], T[i - 2] + t[0] + t[i - 1] + 2 * t[1]);
	}
	return T[n];
}
