#include "down_top_dynamic_programming.h"
/*
转化为01背包求解
最简单的想法是：考虑到第i种物品最多选V/c[i]件，于是可以把第i种物品转换为V/c[i]件费用及价值均不变的物品，然后求解这个01背包问题。但是这样完全没有改进时间复杂度，但这毕竟给了我们将完全背包转换为01背包问题的思路：将一种物品拆成多件物品

O(VN)的算法
这个算法使用一维数组，先看伪代码：

for i = 1 ... N
	for v = 0 ... V
		f[v] = max{f[v], f[v-cost] + weight}

你会发现，这个伪代码与01背包的伪代码只有v的循环次序不同而已。为什么这样一改就行呢？
首先，想想为什么01背包问题中要按照v=V...0的逆序来循环。
这是因为要保证第i次循环中的状态f[i][v]是由状态f[i-1][v-c[i]]递推而来。
换句话说，这正是为了保证每件物品只选一次，保证在考虑“选入第i件物品”这件策略时，
依据的是一个绝无已经选入第i件物品的子结果f[i-1][v-c[i]]。而现在完全背包的特点恰好是每种物品可选无限件，
所以在考虑“加选一件dii种物品”这种策略时，却正需要一个可能已选入第i种物品的子结果f[i][c-v[i]],
所以就可以并且必须采用v=0...V的顺序循环
*/

int bag(int n, int capacity, vector<int> values, vector<int> weights)
/*自底向上动态规划*/
{
	//直接退出的情况
	if (n <= 0 || capacity <= 0 || values.size() == 0 || weights.size() == 0 || weights.size() != values.size())
		return 0;
	//申请一个中间结果集，results[j]表示前i种物品下，容量最多为j时候的最大价值
	vector<int>results(capacity + 1, 0);
	//开始循环遍历
	for (int i = 0; i <= n; i++)
	{
		//必须从小到大，因为后一个容量需要在前一个容量的基础上，同为前i中物品，适应完全背包中的物品可以有多个
		//j可以从weights[i]开始，因为不足当前物品的话只需要跳到下一个容量就好
		for (int j = weights[i]; j <= capacity; j++)
		{
			results[j] = max(results[j], results[j - weights[i]] + values[i]);
		}
	}
	return results[capacity];
}
