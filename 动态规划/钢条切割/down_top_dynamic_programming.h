#pragma once
/*
自底向上的动态规划
*/
#include<limits>
#include<algorithm>

using namespace std;

int cut_down_top_dp(int p[], int len, int n)
{
	if (n <= 0)
		return 0;

	//动态申请存放中间结果的数组
	int* result = new int[n + 1];
	result[0] = 0;
	result[1] = p[1];
	for (int i = 2; i <= n; i++)
	{
		//将长度i分为两部分时候，第一部分最大长度
		int first = (i <= len) ? i : len;
		//保存结果
		int max_value = INT_MIN;
		//将长度i分解为i个子问题
		for (int j = 1; j <= first; j++)
		{
			max_value = max(max_value, p[j] + result[i-j]);
		}
		result[i] = max_value;
	}
	return result[n];
}
