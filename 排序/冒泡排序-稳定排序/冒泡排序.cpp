// 排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
冒泡排序,升序,稳定排序

（1）时间复杂度

在设置标志变量之后：

当原始序列“正序”排列时，冒泡排序总的比较次数为n-1，移动次数为0，也就是说冒泡排序在最好情况下的时间复杂度为O(n)；

当原始序列“逆序”排序时，冒泡排序总的比较次数为n(n-1)/2，移动次数为3n(n-1)/2次，所以冒泡排序在最坏情况下的时间复杂度为O(n^2)；

当原始序列杂乱无序时，冒泡排序的平均时间复杂度为O(n^2)。



（2）空间复杂度

冒泡排序排序过程中需要一个临时变量进行两两交换，所需要的额外空间为1，因此空间复杂度为O(1)。



（3）稳定性

冒泡排序在排序过程中，元素两两交换时，相同元素的前后顺序并没有改变，所以冒泡排序是一种稳定排序算法。


鸡尾酒排序
时间复杂度最坏、平均n^2，最好n，空间复杂度1

又叫定向冒泡排序，搅拌排序、来回排序等，是冒泡排序的一种变形。此算法与冒泡排序的不同处在于排序时是以双向在序列中进行排序。

鸡尾酒排序在于排序过程是先从低到高，然后从高到低；而冒泡排序则仅从低到高去比较序列里的每个元素。它可以得到比冒泡排序稍微好一点的效能，原因是冒泡排序只从一个方向进行比对（由低到高），每次循环只移动一个项目。

以序列(2,3,4,5,1)为例，鸡尾酒排序只需要从低到高，然后从高到低就可以完成排序，但如果使用冒泡排序则需要四次。

但是在乱数序列的状态下，鸡尾酒排序与冒泡排序的效率都很差劲。

*/

#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

void BubbleSort(vector<int>&values, const int& n)
{
	if (n <= 0 || values.size() == 0 || n != values.size())
		return;

	//n个元素有n-1对相邻元素，进行n-1次比较，每次内循环比较得到最大一个元素放在后面
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			//将大元素放在后面
			if (values[j] > values[j + 1])
			{
				int tmp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = tmp;
			}
		}
	}
}

void BubbleSortOptimize(vector<int>&values, const int& n)
/*冒泡排序的改进算法
如果已经排好序了就不需要进行下去
设置标志位，标识是否发生了交换，如果没有发生表示已经排序好了
*/
{
	if (n <= 0 || values.size() == 0 || n != values.size())
		return;
	//默认发生了交换，也就是没有排好序
	int change = 1;
	for (int i = 0; i < n - 1 && change != 0; i++)
	{
		//每次开始排序之前先将标志位标为没有发生交换
		int change = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (values[j] > values[j + 1])
			{
				change = 1;
				swap(values[j], values[j + 1]);
			}
		}
	}
}

void CocktailSort(vector<int>&values, const int& n)
/*和冒泡一样加上标志位change*/
{
	if (n <= 0 || values.size() == 0 || values.size() != n)
		return;

	int left=0, right=n-1;
	int i;
	int change = 1;
	while (left < right)
	{
		change = 0;
		//正向排序得到最大
		for (i = left; i < right; i++)
		{
 			if (values[i] > values[i + 1])
			{
				change = 1;
				swap(values[i], values[i + 1]);
			}
		}
		//缩小范围
		right--;
		//如果排好序了则返回
		if (change == 0)
			return;

		//重新置位
		change = 0;
		//反向排序得到最小
		for (i = right; i > left; i--)
		{
			if (values[i] < values[i - 1])
			{
				change = 1;
				swap(values[i], values[i - 1]);
			}
		}
		//缩小范围
		left++;
		//排序好了直接返回
		if (change == 0)
			return;
	}
}

int main()
{
	cout << "input numbers:" << endl;
	int numbers;
	while (cin >> numbers)
	{
		if (numbers > 0)
			break;
		cout << "input again." << endl;
	}
	//申请数组
	vector<int>values(numbers, 0);
	for (int i = 0; i < numbers; i++)
	{
		cout << "input value:" << endl;
		int tmp;
		cin >> tmp;
		values[i] = tmp;
	}
	////冒泡排序
	//BubbleSort(values, numbers);
	//for (int i = 0; i < values.size(); i++)
	//	cout <<setw(5)<< values[i];
	//cout << endl;

	////冒泡排序改进版
	//BubbleSortOptimize(values, numbers);
	//for (int i = 0; i < values.size(); i++)
	//	cout << setw(5) << values[i];
	//cout << endl;

	//；鸡尾酒排序
	CocktailSort(values, numbers);
	for (int i = 0; i < values.size(); i++)
		cout << setw(5) << values[i];
	cout << endl;
}

