// 查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<iomanip>
#include<vector>
#include<algorithm>

using namespace std;

template <typename T>
int BinarySearch(const vector<T>& values, T value)
/*非递归二分查找*/
{
	if (values.empty())
		return -1;
	int n = values.size();
	int low = 0;
	int high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) >> 1;
		if (values[mid] == value)
			return mid;
		else if (values[mid] > value)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

template <typename T>
int BinarySearchRecursion(const vector<T>& values, int start, int end, T value)
/*在数组中查找数值下标，没有查找到将返回-1*/
{
	if (values.empty() || start<0 || end >= values.size() || start>end)
		return -1;
	//中间值
	int mid = (start + end) >> 1;
	if (values[mid] == value)
		return mid;
	else if (values[mid] > value)
		return BinarySearchRecursion(values, start, mid - 1,value);
	else
		return BinarySearchRecursion(values, mid + 1, end,value);
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
		cout << "input value:" << endl;
		int tmp;
		cin >> tmp;
		values.push_back(tmp);
	}
	sort(values.begin(), values.end());
	int result = BinarySearchRecursion(values, 0, n - 1,8);
	cout << result << endl;
	int result2 = BinarySearch(values, 8);
	cout << result2;
}

