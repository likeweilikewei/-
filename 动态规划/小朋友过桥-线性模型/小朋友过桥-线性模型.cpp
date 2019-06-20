// 小朋友过桥-线性模型.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
题目：在一个夜黑风高的晚上，有n（n <= 50）个小朋友在桥的这边，现在他们需要过桥，
但是由于桥很窄，每次只允许不大于两人通过，他们只有一个手电筒，
所以每次过桥的两个人需要把手电筒带回来，i号小朋友过桥的时间为T[i]，
两个人过桥的总时间为二者中时间长者。问所有小朋友过桥的总时间最短是多少。

输入：

两行数据：第一行为小朋友个数n

                   第二行有n个数，用空格隔开，分别是每个小朋友过桥的时间。

输出：

一行数据：所有小朋友过桥花费的最少时间。
*/

#include <iostream>
#include<algorithm>
#include<time.h>
#include"recursion.h"
#include"top_down_dynamic_programming.h"
#include"down_top_dynamic_programming.h"

using namespace std;

int main()
{
	cout << "please input numbers of children:" << endl;
	int number;
	while (cin >> number)
	{
		if (number <= 0)
			cout << "number <=0." << endl;
		else
			break;
	}
	
	//申请数组存放每个人的过桥耗时
	int* times = new int[number];
	for (int i = 0; i < number; i++)
	{
		cin >> times[i];
		if (times[i] <= 0)
			throw "ERROR:times <=0.";
	}

	//升序排列
	sort(times, times + number);
	//for (int i = 0; i < number; i++)
	//	cout << times[i] << endl;

	clock_t start, end;
	//递归实现
	start = clock();
	int result1 = bridge_recursion(times, number);
	end = clock();
	printf("%d children through bridge,recursion cost:%d,time cost:%f seconds.\n", number, result1, (double)(end - start) / CLOCKS_PER_SEC);

	//自顶向下备忘录法
	start = clock();
	int result2 = bridge_top_down(times, number);
	end = clock();
	printf("%d children through bridge,top down cost:%d,time cost:%f seconds.\n", number, result2, (double)(end - start) / CLOCKS_PER_SEC);

	//自底向上动态规划
	start = clock();
	int result3 = bridge_down_top(times, number);
	end = clock();
	printf("%d children through bridge,down top cost:%d,time cost:%f seconds.\n", number, result3, (double)(end - start) / CLOCKS_PER_SEC);

}


