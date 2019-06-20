// 钢条切割.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
给定钢条各长度收益，给定长度，求最大收益
*/

#include <iostream>
#include<time.h>
#include"recursion.h"
#include"top_down_dynamic_programming.h"
#include"down_top_dynamic_programming.h"

using namespace std;

int main()
{
	//表示下标对应的长度的收益
	int p[] = {0,1,5,8,9,10,17,17,20,24,30};
	//数组有效数字长度
	int len = 10;
	//钢条长度
	int n = 15;
	//计时
	clock_t start, end;

	//递归版本
	start = clock();
	int result1 = cut(p, len,n);
	end = clock();
	printf("%d len max profit is %d, recursion cost: %f seconds.\n", n, result1, (double)(end - start) / CLOCKS_PER_SEC);

	//自顶向下备忘录法
	start = clock();
	int result2 = cut_top_down_dp(p, len, n);
	end = clock();
	printf("%d len max profit is %d, top down cost: %f seconds.\n", n, result2, (double)(end - start) / CLOCKS_PER_SEC);

	//自顶向下备忘录法
	start = clock();
	int result3 = cut_down_top_dp(p, len, n);
	end = clock();
	printf("%d len max profit is %d, down top cost: %f seconds.\n", n, result3, (double)(end - start) / CLOCKS_PER_SEC);
}

