// 插入排序-稳定排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
直接插入排序
最坏时间复杂度	 O(n^{2})
最优时间复杂度	 O(n)
平均时间复杂度	 O(n^{2})
最坏空间复杂度	总共  O(n) ，需要辅助空间  O(1)

一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：

从第一个元素开始，该元素可以认为已经被排序
取出下一个元素，在已经排序的元素序列中从后向前扫描
如果该元素（已排序）大于新元素，将该元素移到下一位置
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
将新元素插入到该位置后
重复步骤2~5
如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的数目。该算法可以认为是插入排序的一个变种，称为二分查找插入排序。

二分查找插入排序
二分查找插入排序比直接插入排序快,也是稳定排序
最坏时间复杂度	 O(n^{2})
这时候已经排好序了，不需要移动元素，但是每次插入平均需要log2n次查找
最优时间复杂度	 O(nlog2n)
平均时间复杂度	 O(n^{2})
空间复杂度	需要辅助空间  O(1)

希尔排序也是直接插入排序的改进版
*/

#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

void InsertionSort(vector<int>&values)
/*直接插入排序*/
{
	if (values.empty())
		return;
	int n = values.size();
	//认为0下标元素已经排序好了，从1开始向前插入
	for (int i = 1; i < n; i++)
	{
		//先得到要插入的元素值
		int key = values[i];
		//然后再0~i-1的元素从后向前中找到第一个大于等于新值的数，然后插入到后面，之前需要不断将大于新值的数向后移动
		int j = i - 1;
		//只有元素值大于新值才需要向后移动，相等不需要移动，这点导致算法具有稳定性
		while (j >= 0 && values[j] > key)
		{
			//移动到后面一个位置，初始时候移动到i的位置上
			values[j + 1] = values[j];
			//将下标向前移动，判断下一个值
			j--;
		}
		//找到了这个位置，这时候j指向了大于等于新值的位置，因此新值需要插入到j后面,还有注意是否发生过移动，如果没有不需要插入
		//这条保证最优情况下只需要n-1次比较，不需要一次插入
		if (j + 1 != i)
			values[j + 1] = key;
	}
}

void BinarySearchInsertionSort(vector<int>& values)
/*二分查找插入排序，如果查找*/
{
	if (values.empty())
		return;
	int n = values.size();
	for (int i = 1; i < n; i++)
	{
		//得到要插入的元素
		int key = values[i];
		//得到二分查找的上限和下限
		int low = 0;
		int high = i - 1;
		int middle;
		//对i个数据进行logi次查找，最后high指向第一个<=新值的数,可能不存在，例如只有一个6，插入5时候，low指向6，high=-1，low指向第一个>新值的数，low可能不存在
		while (low <= high)
		{
			//得到中间下标
			middle = (low + high) >> 1;
			//如果中间对应值大于新值，则查找结果在左边
			if (values[middle] > key)
				//将下标对应左边部分
				high = middle - 1;
			else
				//如果中间数值小于等于low，则认为可能的结果在右边
				low = middle + 1;
		}
		//最后找到了适当位置，这时应该将high后面的元素全部向后移动一个，并将新值插入到high后面的一个位置,如果已经排好序，high=i-1,不会移动元素
		for (int j = i - 1; j > high; j--)
		{
			values[j + 1] = values[j];
		}
		//当需要插入时候才插入
		if (high + 1 != i)
			values[high + 1] = key;
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
		cout << "n<=0,input again:" << endl;
	}
	vector<int>values;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cout << "input values" << endl;
		cin >> tmp;
		values.push_back(tmp);
	}

	//InsertionSort(values);
	BinarySearchInsertionSort(values);
	for (int i = 0; i < values.size(); i++)
	{
		cout << setw(5) << values[i];
	}
	cout << endl;
}
