// 堆排序-不稳定排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
堆排序
正序用大根堆，逆序用小根堆
时间复杂度最好平均最坏都是O（nlogn）
堆执行一次调整需要O(logn)的时间，在排序过程中需要遍历所有元素执行堆调整，
所以最终时间复杂度是O(nlogn)。空间复杂度是O(n)。
*/

#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

template <typename T>
void MaxHeapify(vector<T>& values, const int& start, const int& end)
/*调整start节点，这时候子节点都已经是大根堆*/
{
	//当前要调整的父节点
	int parent = start;
	//当前节点的左子节点
	int son = 2 * parent + 1;
	//递归判断和调整，直到没有孩子节点
	while (son <= end)
	{
		//比较左子节点和柚子节点的值，取到最大的那个来和父节点比较
		if (son + 1 <= end && values[son + 1] > values[son])
			son++;
		//比较最好孩子和父节点，如果孩子节点大于父节点，则交换两个节点，并将父节点指向新的孩子节点，调整可能影响的子树
		if (values[son] > values[parent])
		{
			swap(values[son], values[parent]);
			parent = son;
			son = 2 * parent + 1;
		}
		//如果是最大堆直接退出
		else
			return;
	}
}

template <typename T>
void MinHeapify(vector<T>& values, const int& start, const int& end)
/*
最小堆得到逆序数组
*/
{
	int parent = start;
	int son = 2 * parent + 1;
	while (son <= end)
	{
		if (son + 1 <= end && values[son] > values[son + 1])
			son++;
		if (values[son] < values[parent])
		{
			swap(values[son], values[parent]);
			parent = son;
			son = 2 * parent + 1;
		}
		else
			return;
	}
}

template <typename T>
void HeapSort(vector<T>& values)
{
	if (values.empty())
		return;
	int n = values.size();
	//先从最后一个父节点开始建立大根堆，依次按序号调整堆，这样在调整某个父节点时候其子节点都是
	//构造好的大根堆，在数组表示的完全二叉树，下标i的父节点是floor((i-1)/2),左孩子是2*i+1,右孩子使
	//2*i+2,因此从最后一个节点的父节点开始构建最大堆,一直调整到根节点
	for (int i = (n - 2) / 2; i >= 0; i--)
		MaxHeapify(values, i, n - 1);
	//MinHeapify(values, i, n - 1);
//最大堆构建完成后开始将根节点和最后一个节点交换，并所有最大堆的范围，调整n-1次就得到排序后的数组
//i表示要填充的下标
	for (int i = n - 1; i > 0; i--)
	{
		swap(values[i], values[0]);
		//永远都是从根节点开始调整，不错最大堆所有范围，i以及以后的下标已经是有序的
		MaxHeapify(values, 0, i - 1);
		//MinHeapify(values, 0, i - 1);
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
	//堆排序，升序
	HeapSort(values);
	for (int i = 0; i < n; i++)
		cout << setw(5) << values[i];
	cout << endl;
}

