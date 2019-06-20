#include "down_top_dynamic_programming.h"
/*
多重背包问题

题目
有N种物品和一个容量为V的背包。第i种物品最多有n[i]件，每件费用是c[i]，价值是w[i]。
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大

思路
多重背包问题的思路跟完全背包的思路非常类似，只是k的取值是有限制的，因为每件物品的数量是有限制的，
状态转移方程为：

dp[i][v] = max{dp[i - 1][v - k * c[i]] + w[i] | 0 <=k <= n[i],dp[i-1][v]}
*/

int bag(int n, int capacity, vector<int> values, vector<int> weights, vector<int> numbers)
{
	//直接返回的情况
	if (n <= 0 || capacity <= 0 || values.size() != weights.size() || values.size() != numbers.size() || values.size() == 0)
		return 0;

	//申请一个存放二维数组的中间结果，results[i][j]表示前i个物品在容量最大为j下的最大价值
	vector<vector<int>>results(n+1, vector<int>(capacity+1, 0));

	//开始遍历
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			//遍历放k个物品
			for (int k = 0; k <= numbers[i]; k++)
			{
				//如果空间放不下物品i，则直接跳过
				if (weights[i] * k > j)
					break;
				//因为是假设前k-1个都试过了，现在尝试放第k个
				results[i][j] = max(results[i][j], results[i - 1][j - k * weights[i]] + k * values[i]);
			}
		}
	}
	return results[n][capacity];
}
