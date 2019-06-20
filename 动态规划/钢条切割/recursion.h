#pragma once
/*递归版本

将n长度钢条分为1+n-1,2+n-2,3+n-3,...,n-1+1,n+0这n个子问题
前半段收益已知，就将问题转化为更小规模的子问题

递归版本将产生大量的重复子问题
*/
#include<limits>
#include<algorithm>

using namespace std;

int cut(int p[],int len, int n)
/*求n长度的切割后的最大收益，p是价格表*/
{
	//当n等于0，收益为0
	if (n <= 0)
		return 0;
	int max_value = INT_MIN;
	//第一部分最长长度，不能超过n,也不能超过数组长度
	int first = (n <= len) ? n : len;
	//将长度为n的问题分解为n个子问题,第一部分的长度为i
	for (int i = 1; i <= first; i++)
	{
		max_value = max(max_value, p[i] + cut(p, len, n - i));
	}
	return max_value;
}
