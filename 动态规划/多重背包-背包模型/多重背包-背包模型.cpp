// 多重背包-背包模型.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include"down_top_dynamic_programming.h"

using namespace std;

int main()
{
	//物品总数
	int product_cout = 0;
	//背包综容量
	int capacity = 0;
	//保存每个物品的价值
	vector<int>values(1, 0);
	//保存每个物品的容量
	vector<int>weights(1, 0);
	//保存每个物品的可用数量
	vector<int>numbers(1, 0);

	//输入物品总数
	cout << "input product count." << endl;
	while (cin >> product_cout)
	{
		if (product_cout > 0)
			break;
		cout << "product count <=0,input again." << endl;
	}
	//输入背包总容量
	cout << "input all weight:" << endl;
	while (cin >> capacity)
	{
		if (capacity > 0)
			break;
		cout << "all weight <=0." << endl;
	}
	//输入所有物品的价值
	for (int i = 1; i <= product_cout; i++)
	{
		cout << "input values of products " << i << endl;
		int tmp;
		cin >> tmp;
		values.push_back(tmp);
	}
	//输入所有物品的容量
	for (int i = 1; i <= product_cout; i++)
	{
		cout << "input weight of products " << i << endl;
		int tmp;
		cin >> tmp;
		weights.push_back(tmp);
	}
	//输入所有物品的可用数量
	for (int i = 1; i <= product_cout; i++)
	{
		cout << "input numbers of products " << i << endl;
		int tmp;
		cin >> tmp;
		numbers.push_back(tmp);
	}

	//自底向上动态规划
	int result = bag(product_cout, capacity, values, weights,numbers);
	cout << "down top bag result:" << result << endl;
}

