#pragma once
/*
备忘录法还是利用了递归，上面算法不管怎样，计算fib（6）的时候最后还是要计算出
fib（1），fib（2），fib（3）……,那么何不先计算出fib（1），fib（2），fib（3）……,呢？
这也就是动态规划的核心，先计算子问题，再由子问题计算父问题。
递归有函数的开销，因此还可以优化
时间复杂度O(n)，空间复杂度O(n)
*/

int fib_down_top_dp(int n)
{
	int* results = new int[n + 1];
	results[0] = 0;
	results[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		results[i] = results[i - 1] + results[i - 2];
	}
	return results[n];
}

/*对空间复杂度进一步压缩，没有必要保存所有的子结果，只需要保存最近的三个就可以了
*/

int fib_down_to_top_dp_optimize(int n)
/*自底向上动态规划，空间复杂度优化*/
{
	int result_i_2 = 0;
	int result_i_1 = 1;
	int result_i;
	for (int i = 2; i <= n; i++)
	{
		result_i = result_i_1 + result_i_2;
		result_i_2 = result_i_1;
		result_i_1 = result_i;
	}
	return result_i;
}