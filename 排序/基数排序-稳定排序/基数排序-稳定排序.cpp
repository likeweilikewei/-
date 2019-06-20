// 基数排序-稳定排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
最佳情况：T(n) = O(n * d)
最差情况：T(n) = O(n * d)
平均情况：T(n) = O(n * d)
空间复杂度O(n+k)
k:桶的个数
d:数据位数
基数排序有两种方法：

MSD 从高位开始进行排序
LSD 从低位开始进行排序
基数排序 vs 计数排序 vs 桶排序

这三种排序算法都利用了桶的概念，但对桶的使用方法上有明显差异：

基数排序：根据键值的每位数字来分配桶
计数排序：每个桶只存储单一键值
桶排序：每个桶存储一定范围的数值

第一步
以LSD为例，假设原来有一串数值如下所示：
73, 22, 93, 43, 55, 14, 28, 65, 39, 81
首先根据个位数的数值，在走访数值时将它们分配至编号0到9的桶子中：
0
1 81
2 22
3 73 93 43
4 14
5 55 65
6
7
8 28
9 39
第二步
接下来将这些桶子中的数值重新串接起来，成为以下的数列：
81, 22, 73, 93, 43, 14, 55, 65, 28, 39
接着再进行一次分配，这次是根据十位数来分配：
0
1 14
2 22 28
3 39
4 43
5 55
6 65
7 73
8 81
9 93
第三步
接下来将这些桶子中的数值重新串接起来，成为以下的数列：
14, 22, 28, 39, 43, 55, 65, 73, 81, 93
这时候整个数列已经排序完毕；如果排序的对象有三位数以上，则持续进行以上的动作直至最高位数为止。

基数排序适用于：
 *  (1)数据范围较小，建议在小于1000
 *  (2)每个数值都要大于等于0的整数
*/

#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

int MaxBit(const vector<int>& values)
/*求最大位数*/
{
	if (values.empty())
		return 0;
	int d = 1;
	int p = 10;
	for (int i = 0; i < values.size(); i++)
	{
		while (values[i] >= p)
		{
			p *= 10;
			++d;
		}
	}
	return d;
}

void RadixSort(vector<int>& values)
{
	if (values.empty())
		return;
	int n = values.size();
	//申请排序好的目标数组
	vector<int>values_sorted(n, 0);
	//申请每个个位数字的10个桶，这里必须清空计数器
	vector<int>counts(10, 0);
	//得到最大位数
	int d = MaxBit(values);
	//控制取哪一位
	int radix = 1;
	//lsd最低位优先
	for (int i = 1; i <= d; i++)
	{
		//这里清空计数器
		counts.clear();
		//先按当前位数统计每个桶
		for (int j = 0; j < n; j++)
			counts[(values[j] / radix) % 10]++;
		//将桶里面的数据累加，得到排名
		for (int j = 1; j < 10; j++)
			counts[j] += counts[j - 1];
		//从数组尾部开始得到排序后的数组，也是为了保证稳定性
		for (int j = n - 1; j >= 0; j--)
			values_sorted[--counts[(values[j] / radix) % 10]] = values[j];
		//最后将控制位乘以10
		radix *= 10;
		//最后赋值回原来数组
		values = values_sorted;
	}
}

void RadixSortDescending(vector<int>& values)
{
	if (values.empty())
		return;
	int n = values.size();
	vector<int>values_sorted(n, 0);
	vector<int>counts(10, 0);
	//得到位数
	int d = MaxBit(values);
	//位数控制
	int radix = 1;
	for (int i = 0; i < d; i++)
	{
		//分配前要清空计数器
		counts.clear();
		//还是统计每个桶的个数
		for (int j = 0; j < n; j++)
			counts[(values[j] / radix) % 10]++;
		//为了逆序，需要从最后开始累加
		for (int j = 8; j >= 0; j--)
			counts[j] += counts[j + 1];
		//还是只能从尾部开始遍历
		for (int j = n - 1; j >= 0; j--)
			values_sorted[--counts[(values[j] / radix) % 10]] = values[j];
		//改变位数
		radix *= 10;
		values = values_sorted;
	}
}


int main()
{
	cout << "input numbers:" << endl;
	int n;
	while (cin >> n)
	{
		if (n > 0)
			break;
		cout << "input again." << endl;
	}
	vector<int>values;
	for (int i = 0; i < n; i++)
	{
		cout << "input number:" << endl;
		int tmp;
		cin >> tmp;
		values.push_back(tmp);
	}
	//基数排序，升序
	//RadixSort(values);
	//降序
	RadixSortDescending(values);
	for (int i = 0; i < n; i++)
		cout << setw(5) << values[i];
	cout << endl;
}


