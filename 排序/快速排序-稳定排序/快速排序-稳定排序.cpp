// 快速排序-稳定排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
快速排序
原地分割版本最好和平均时间复杂度O（nlogn），最差O（n^2）,空间复杂度平均O(logn)
使用原地（in-place）分割的快速排序版本，在任何递归调用前，仅会使用固定的額外空間。然而，
如果需要产生 {O(\log n)}嵌套递归调用，它需要在他们每一个存储一个固定数量的信息。
因为最好的情况最多需要  { O(\log n)}次的嵌套递归调用，
所以它需要  {O(\log n)}的空间。
最坏情况下需要 O(n)}次嵌套递归调用，因此需要 O(n)}的空间。
*/

#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

template <typename T>
void QuickSort(vector<T>&values, const int& start, const int& end)
/*原地快速排序递归版本*/
{
	if (values.empty() || start < 0 || end >= values.size())
		return;
	//正常递归退出条件是数组元素为0个或者1个
	if (start >= end)
		return;
	//选取首元素作为基准
	T key = values[start];
	//为了从左向右找到第一个大于基准的元素，需要下标前置递增，因此正好i取start,j取end+1
	//从左向右遍历的下标
	int i = start;
	//从右向左遍历的下标
	int j = end + 1;
	//开始讲所有元素分为两拨，前面部分小于等于基准，后面大于等于基准，直到i>=j结束
	while (true)
	{
		//从左到右找到第一个大于基准的元素
		while (values[++i] <= key)
		{
			if (i == end)
				break;
		}
		//从右到左找到第一个小于基准的元素，否则直接跳过
		while (values[--j] >= key)
		{
			//到了开始部分，表示遍历结束
			if (j == start)
				break;
		}
		//判断这次遍历是否结束
		if (i >= j)
			break;
		//如果没有结束则交换i和j对应元素，然后继续遍历和交换
		else
		{
			T tmp = values[i];
			values[i] = values[j];
			values[j] = tmp;
		}
	}
	//i和j交叉了，这时j的右边符合条件，i的左边符合条件，但是为了把基准插入到中间，需要将小元素和基准价交换，也就只能j和基准交换
	T tmp = values[j];
	values[j] = key;
	values[start] = tmp;
	//然后对基准左边部分和右边部分分别进行排序
	QuickSort(values, start, j - 1);
	QuickSort(values, j + 1, end);
}

int main()
{
	//int a = 13;
	////左移不会改变a
	//a >> 1;
	//cout << a << endl;
	//abort();
	cout << "input numbers：" << endl;
	int n;
	while (cin >> n)
	{
		if (n > 0)
			break;
		cout << "n<=0,input again:" << endl;
	}
	vector<int>values;
	for (int i = 0; i < n; i++)
	{
		cout << "input value:" << endl;
		int tmp;
		cin >> tmp;
		values.push_back(tmp);
	}
	QuickSort(values, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << setw(5) << values[i];
	}
}

