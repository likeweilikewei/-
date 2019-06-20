// 归并排序-稳定排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
归并排序
时间最好平均最差都是nlogn,空间n
时间复杂度分析：递归分解数据，需要递归logN次，每次都需要对n个数据扫描一次，最好最坏平均都一样，所以O(nlogn)
空间复杂度分析：归并排序需要一个临时temp[]来储存归并的结果，所以   O(n)

归并操作（merge），也叫归并算法，指的是将两个已经排序的序列合并成一个序列的操作。归并排序算法依赖归并操作。

递归法（Top-down）
申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
设定两个指针，最初位置分别为两个已经排序序列的起始位置
比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
重复步骤3直到某一指针到达序列尾
将另一序列剩下的所有元素直接复制到合并序列尾

迭代法（Bottom-up）
原理如下（假设序列共有 {\displaystyle n} n个元素）：

将序列每相邻两个数字进行归并操作，形成 {\displaystyle ceil(n/2)} {\displaystyle ceil(n/2)}个序列，排序后每个序列包含两/一个元素
若此时序列数不是1个则将上述序列再次归并，形成 {\displaystyle ceil(n/4)} {\displaystyle ceil(n/4)}个序列，每个序列包含四/三个元素
重复步骤2，直到所有元素排序完毕，即序列数为1
*/

#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

template <typename T>
void BottomUpMergeSort(vector<T>& values)
/*
自底向上迭代法归并排序
*/
{
	if (values.empty())
		return;
	int n = values.size();
	//保存待排序数组
	vector<T>second(n,0);
	//先从小组元素个数为1的小组开始合并，一直到小组个数为x,其中2^x<n的最大值，最后一次合并就完成了排序
	for (int seg = 1; seg < n; seg += seg)
	{
		//开始对小组个数为seg的小组两两合并,控制开始的下标
		for (int start = 0; start < n; start += seg * 2)
		{
			//得到这两个小组的开始和结束，方便一一比对两个小组的内容插入到新的排序数组中
			int low = start;
			//得到第一个小组的结束和第二个小组的开始位置，因为start可能已经到了末尾，因此要和n比较一下
			int middle = (start + seg) < n ? (start + seg) : n;
			//得到第二个小组的结束下标
			int high = (start + seg * 2) < n ? (start + seg * 2) : n;
			//开始填充辅助数组的下标
			int k = start;
			//第一个数组的开始下标和结束下标
			int start1 = low;
			int end1 = middle;
			//第二个小组的开始和结束下标
			int start2 = middle;
			int end2 = high;
			//如果两个小组都还有元素就将较小的插入到辅助数组中,这里的=保证了稳定性
			while (start1 < end1 && start2 < end2)
				second[k++] = values[start1] <= values[start2] ? values[start1++] : values[start2++];
			//如果第一个小组还有剩余则直接拷贝进辅助数组
			while (start1 < end1)
				second[k++] = values[start1++];
			//同样如果第二个小组还有剩余则直接拷贝进辅助数组
			while (start2 < end2)
				second[k++] = values[start2++];
		}
		//seg组长的小组合并完毕则用辅助数组覆盖源数组，接着上面的结果继续合并
		values = second;
	}
}

/*
归并排序递归版本
将划分子数组的动作交给了递归
* 基本实现：需要两个函数，一个用来递归划分数组，比较简单，依次二分即可
* 一个用来把划分好的数组递归排序并合并：两个数组从第一个元素开始比较，小的数据入，
直到一个数组中数据为空，
* 然后把另一个数组中的剩余数据写入
*/

template <typename T>
void Merge(vector<T>&values, int start, int middle, int end)
/*合并两个子数组，分别是start~middle,middle+1~end两个数组*/
{
	//申请数组保存这次合并后的数组,这样调整后就可以直接赋值给源数组
	vector<T>second(values);
	//第一个小组的开始和结束下标
	int start1 = start;
	int end1 = middle;
	//第二个小组的开始和结束
	int start2 = middle + 1;
	int end2 = end;
	//保存开始填充辅助数组的下标
	int k = start;
	//当两数组都还有元素时候将较小的放入辅助数组，=保证了稳定性
	while (start1 <= end1 && start2 <= end2)
		second[k++] = values[start1] <= values[start2] ? values[start1++] : values[start2++];
	//当第一个数组还有剩余时候直接放入辅助数组
	while (start1 <= end1)
		second[k++] = values[start1++];
	//当第二个数组还有剩余时候直接放入辅助数组
	while (start2 <= end2)
		second[k++] = values[start2++];
	//保存这次合并好的数组
	values = second;
}

template <typename T>
void RecursionMergeSort(vector<T>&values,int start,int end)
/*递归版本归并排序*/
{
	if (values.empty()||start<0||end>=values.size())
		return;
	//一直划分到子数组只有一个元素
	if (start < end)
	{
		//计算中间下标，划分数组
		int middle = (start + end) >> 1;
		RecursionMergeSort(values, start, middle);
		RecursionMergeSort(values, middle + 1, end);
		Merge(values, start, middle, end);
	}
}

int main()
{
	//vector<int>a(3, 1);
	//vector<int>b(5, 2);
	////赋值后覆盖了b原来的内容
	//b = a;
	//for (size_t i = 0; i < b.size(); i++)
	//{
	//	cout << b[i];
	//}
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
		cout << "input number:" << endl;
		int tmp;
		cin >> tmp;
		values.push_back(tmp);
	}

	//迭代版本的归并排序
	//BottomUpMergeSort(values);
	//迭代版本的归并排序
	RecursionMergeSort(values, 0, n - 1);
	for (int i = 0; i < values.size(); i++)
	{
		cout << setw(5) << values[i];
	}
	cout << endl;
}


