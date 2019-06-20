// 0-1背包-背包模型.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include"down_top_dynamic_programming.h"

using namespace std;

int main()
{
	//物品数，容量
	int products_count, capacity;
	//价值,第一个物品对应下标1
	vector<int>values(1, 0);
	//重量
	vector<int>weights(1, 0);

	//输入物品数和容量
	cout << "input products count:" << endl;
	while (cin >> products_count)
	{
		if (products_count > 0)
			break;
		cout << "products count <=0,input again." << endl;
	}
	//输入容量
	cout << "input all capacity:" << endl;
	while (cin >> capacity)
	{
		if (capacity > 0)
			break;
		cout << "capacity <=0,input again." << endl;
	}
	//输入每个物品的价值
	for (int i = 1; i <= products_count; i++)
	{
		cout << "input value of products " << i << endl;
		int tmp;
		cin >> tmp;
		values.push_back(tmp);
	}
	//输入每个物品的容量
	for (int i = 1; i <= products_count; i++)
	{
		cout << "input weight of products " << i << endl;
		int tmp;
		cin >> tmp;
		weights.push_back(tmp);
	}

	//自底向上动态规划
	int result = value(products_count, capacity, values, weights);
	cout << "down to top result:" << result << endl;

	//自底向上动态规划的空间优化
	int result2 = value_optimize(products_count, capacity, values, weights);
	cout << "down to top optimize result:" << result2 << endl;
}
