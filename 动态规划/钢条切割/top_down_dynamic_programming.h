#pragma once
/*自顶向下备忘录法
运用递归，但是不是每次都计算，判断当数组中没有存储结果时候
计算并存入数组中，否则直接返回
但是递归也有额外开销
*/
#include<algorithm>
#include<limits>

using namespace std;

int cut(int p[], int len, int n, int result[]);
int cut_top_down_dp(int p[], int len, int n);

int cut_top_down_dp(int p[], int len, int n)
{
	//申请数组保存子问题结果，因为要保存n的子问题结果，因此需要n+1大小的数组
	int* results = new int[n + 1];
	//初始化数组为最小整数，表示未访问，这里不用-1是因为看收益也可能为负
	for (int i = 0; i < n + 1; i++)
		results[i] = INT_MIN;
	return cut(p, len, n, results);
}

int cut(int p[], int len, int n, int result[])
{
	if (n <= 0)
		return 0;
	//结果存在直接返回
	if (result[n] != INT_MIN)
		return result[n];
	
	int max_value = INT_MIN;
	//第一部分的长度不能超过n，也不能超过len
	int first = (n <= len) ? n : len;
	//将问题分解为小问题
	for (int i = 1; i <= first; i++)
	{
		max_value = max(max_value, p[i] + cut(p, len, n - i, result));
	}
	result[n] = max_value;
	return max_value;
}
