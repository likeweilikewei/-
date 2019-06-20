// 希尔排序-不稳定排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
希尔排序的时间复杂度与增量序列的选取有关，例如希尔增量（n/2^i）时间复杂度为O(n²)，
而Hibbard增量的希尔排序的时间复杂度为O(n3/2)，希尔排序时间复杂度的最好是n*log2n

最好是O(n),空间复杂度	O（1），不稳定排序

希尔排序算法是直接插入排序算法的一种改进，减少了其复制的次数，速度要快很多。 
原因是，当n值很大时数据项每一趟排序需要移动的个数很少，但数据项的距离很长。当n值减小时每一趟需要移动的数据增多，
此时已经接近于它们排序后的最终位置。 正是这两种情况的结合才使希尔排序效率比插入排序高很多。
*/

#include <iostream>
#include<iomanip>
#include<vector>

using namespace std;

void ShellSort(vector<int>& values)
/*希尔增量的希尔排序，每次步长减少为一半，最坏O（n^2），最好O（n）,平均O（n^2）,但是比直接插入排序快很多*/
{
	if (values.empty())
		return;
	int n = values.size();
	//从最大步长开始，逐渐减少为1，对每个步长都需要进行各组的排序，例如步长为3时候将数据分为3列，对每一列都进行插入排序
	for (int gap = n >> 1; gap >= 1; gap >>= 1)
	{
		//从第一列的第二个数据开始对每个数据直接插入排序
		for (int i = gap; i < n; i++)
		{
			//要插入的新值
			int key = values[i];
			//对当前所在列的数据进行直接插入排序
			int j = i - gap;
			//大数据向后移动一个gap
			while (j >= 0&&values[j]>key)
			{
				values[j + gap] = values[j];
				j -= gap;
			}
			//这时候的j有values[j]<=key,直接将数据插入到j的gap后面
			values[j + gap] = key;
		}
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

	ShellSort(values);
	for (int i = 0; i < values.size(); i++)
	{
		cout << setw(5) << values[i];
	}
	cout << endl;
}

