// 动态规划.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*斐波那契数列f(1)=1,f(2)=1*/

#include <iostream>
#include<time.h>
#include"recursion.h"
#include"top_down_dynamic_programming.h"
#include"down_top_dynamic_programming.h"

using namespace std;

int main()
{
	//cpu1s运行的时钟周期数，1000表示一个时钟周期是1ms
	//cout << CLOCKS_PER_SEC << endl;;
	clock_t start, end;
	int n = 30;
	//得到当前在第几个时钟周期
	start = clock();
	//cout << start << endl;
	int result1 = fib_recursion(n);
	end = clock();
	//cout << end << endl;
	//得到时钟周期数，换算成秒
	printf("%d fibonacci result is: %d, recursion cost time: %f seconds.\n", n, result1, (double)(end - start) / CLOCKS_PER_SEC);
	start = clock();
	int result2 = fib_top_down_dp(n);
	end = clock();
	printf("%d fibonacci result is: %d, top down cost time: %f seconds.\n", n, result2, (double)(end - start) / CLOCKS_PER_SEC);

	/*自底向上动态规划*/
	start = clock();
	int result3 = fib_down_top_dp(n);
	end = clock();
	printf("%d fibonacci result is: %d, down to top cost time: %f seconds.\n", n, result3, (double)(end - start) / CLOCKS_PER_SEC);

	/*自底向上动态规划，空间优化*/
	start = clock();
	int result4 = fib_down_to_top_dp_optimize(n);
	end = clock();
	printf("%d fibonacci result is: %d, down to top optimize cost time: %f seconds.\n", n, result4, (double)(end - start) / CLOCKS_PER_SEC);

}

