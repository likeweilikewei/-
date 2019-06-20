#pragma once
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int value(int n, int capacity, vector<int>values, vector<int>weights)
/*
自底向上求01背包问题的解，n:物品个数，capacity:背包容量，values:每个物品的价值，weights:每个物品的重量
时间空间复杂度都是O(n*capacity)
*/
{
	//直接返回的情况
	if (n <= 0 || capacity <= 0 || values.size() <= 0 || weights.size() == 0 || weights.size() != values.size())
		return 0;
	//申请一个二维数组，长度为n，宽度为capacity,i,j表示物品个数为前i个时候，容量为j时的最大价值
	vector<vector<int>>results(n+1, vector<int>(capacity+1, 0));

	//遍历所有情况
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			//如果当前物品大于当前背包容量，则results[i][j]=result[i-1][j]
			if (weights[i] > j)
				results[i][j] = results[i - 1][j];
			else
				//分为第i个物品放不放
				results[i][j] = max(results[i - 1][j], results[i - 1][j - weights[i]] + values[i]);
		}
	}
	cout << "values:" << endl;
	for (int i = 0; i <= n; i++)
		cout << setw(5) << values[i];
	cout << endl;
	cout << "weights:" << endl;
	for (int i = 0; i <= n; i++)
		cout << setw(5) << weights[i];
	cout << endl;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= capacity; j++)
		{
			cout <<setw(5)<< results[i][j];
		}
		cout << endl;
	}
	return results[n][capacity];
}

int value_optimize(int n, int capacity, vector<int>values, vector<int>weights)
/*
自底向上动态规划优化版本
时间复杂度O(n*capacity),空间复杂度O(capacity)
计算results[i][j]=max(results[i-1][j],results[i-1][j-weights[i]]+values[i])
其实只存储了i-1情况下容量为j和j-weights[i]的情况，
如果令物品数从1开始循环，这样就可以得得到少一个物品的所有容量的情况，
但是容量只能从capacity开始循环，因为如果从1开始循环，计算下一个容量时候，前一个容量计算已经覆盖了results，因为results不全是i-1物品的情况
*/
{
	//直接返回的情况
	if (n <= 0 || capacity <= 0 || values.size() == 0 || weights.size() == 0 || values.size() != weights.size())
		return 0;

	//申请一个一维数组，存放少一个物品时候所有容量对应的最大价值
	vector<int>results(capacity + 1,0);

	//物品只能从小到大开始循环
	for (int i = 1; i <= n; i++)
	{
		//容量只能从大开始循环，为了不污染少一个物品的所有容量的情况
		for (int j = capacity; j >= 1; j--)
		{
			//如果当前物品容量大于总容量，直接放弃当前物品,不改变results
			//否则改变
			if (weights[i] <= j)
				results[j] = max(results[j], results[j - weights[i]] + values[i]);
		}
	}
	return results[capacity];
}
