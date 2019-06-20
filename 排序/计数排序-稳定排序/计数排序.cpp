// 计数排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
计数排序

最坏时间复杂度	{\displaystyle O(n+k)} O(n+k)
最优时间复杂度	{\displaystyle O(n+k)} O(n+k)
平均时间复杂度	{\displaystyle O(n+k)} O(n+k)
最坏空间复杂度	{\displaystyle O(n+k)} O(n+k)
的核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。 
作为一种线性时间复杂度的排序，计数排序要求输入的数据必须数据集中，是有确定范围的整数。
这种情况下计数排序最快

算法简介
计数排序(Counting sort)是一种稳定的排序算法。计数排序使用一个额外的数组C，
其中第i个元素是待排序数组A中值等于i的元素的个数。然后根据数组C来将A中的元素排到正确的位置。它只能对整数进行排序。

算法描述和实现
具体算法描述如下：

找出待排序的数组中最大和最小的元素；
统计数组中每个值为i的元素出现的次数，存入数组C的第i项；
对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）；
反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1。
*/

#include <iostream>
#include<vector>
#include<iomanip>
#include<limits>

using namespace std;
//计数排序只能针对整数
void CountingSort(vector<int>& values)
{
	if (values.empty())
		return;
	int n = values.size();
	//得到最大数值max_value和最小数值min_value
	int max_value=INT_MIN, min_value=INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (values[i] > max_value)
			max_value = values[i];
		if (values[i] < min_value)
			min_value = values[i];
	}
	//得到统计数组的大小k=max-min+1,存放统计了数组时候将每个数减去最小的再存入统计数组
	int k = max_value - min_value + 1;
	vector<int>counts(k,0);
	//申请一个排序好的数组空间
	vector<int>values_sorted(n, 0);

	//对每个数据值进行计数
	for (int i = 0; i < n; i++)
		counts[values[i]-min_value]++;
	//累加计数，得到计数数组中下标值在源数组中的最大排名，排名从1开始，因此必须从尾部开始得到排序数组
	//为了保证稳定性
	for (int i = 1; i < k; i++)
		counts[i] += counts[i - 1];
	//从尾部开始排序，得到当前数据的排名就可以插入目标数中了
	for (int i = n - 1; i >= 0; i--)
		values_sorted[--counts[values[i] - min_value]] = values[i];
	//赋值回原来的数组
	values = values_sorted;
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
	//堆排序，升序
	CountingSort(values);
	for (int i = 0; i < n; i++)
		cout << setw(5) << values[i];
	cout << endl;
}
