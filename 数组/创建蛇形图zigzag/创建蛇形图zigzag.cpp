// 创建蛇形图zigzag.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#define TYPE 1


int** construct(int n)
/*
zigzag数组是一个“之”字形排列的数组。也被称为蛇形数组。
*/
{
	int s, i, j;
	int squa;
	int** a = (int**)malloc(n * sizeof(int));
	if (NULL == a)
	{
		return NULL;
	}

	//开始构造zigzag数组
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
		//如果第i个数组申请失败，则需要将前i-1个数组释放，并将二维数组释放
		if (NULL == a[i])
		{
			while (--i >= 0)
			{
				free(a[i]);
			}
			free(a);
			return NULL;
		}
	}

	//开始对数组赋值
	squa = n * n;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			s = i + j;
			if (s < n)
			{
				a[i][j] = s * (s + 1) / 2 + ((s % 2) == 0 ? i : j);
			}
			else
			{
				s = (n - 1 - i) + (n - 1 - j);
				a[i][j] = squa - s * (s + 1) / 2 - (n - ((s % 2) == 0 ? i : j));
			}
		}
	}

	//输出打印
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return a;

	////释放内存
	//for (i = 0; i < n; i++)
	//{
	//	free(a[i]);
	//	a[i] = NULL;
	//}
	//free(a);
	//a = NULL;
}

//int** construct_2(int n)
///*
//用new的方法动态申请内存
//*/
//{
//
//}


int main()
{
	int N;
	cout << "please input N:" << endl;
	cin >> N;
	construct(N);
}
