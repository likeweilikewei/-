#include"array.h"

void new_one_dimension()
{
	int i, m;
	cout << "please input len of array:" << endl;
	while (cin >> m)
	{
		if (m <= 0)
		{
			cout << "m<=0,please input again." << endl;
			continue;
		}
		break;
	}
	
	//开始申请内存
	int* array = new int[m];
	if (NULL == array)
	{
		cout << "new array failed." << endl;
		throw "new array failed.";
	}

	//开始填充数值
	for (i = 0; i < m; i++)
	{
		array[i] = i;
	}

	//开始输出数值
	for (i = 0; i < m; i++)
	{
		cout << setw(5) << array[i];
	}
	cout << endl;

	//清除内存
	delete[] array;
	array = NULL;
}

void new_two_dimension()
{
	int i, j, m, n;
	cout << "please input len of row and column:" << endl;
	while (cin >> m >> n)
	{
		if (m <= 0 || n <= 0)
		{
			cout << "m or n <=0,please input again." << endl;
			continue;
		}
		break;
	}

	//c++中new失败返回bad_alloc异常，需要不抛出异常才会返回空指针
	//开始申请内存
	int** array = new(nothrow) int* [m];//开辟行空间
	if (NULL == array)
	{
		throw "new array failed.";
	}
	for (i = 0; i < m; i++)
	{
		array[i] = new int[n];//开辟列空间
		//如果申请失败则还要释放之前申请的内存
		if (NULL == array[i])
		{
			while (--i >= 0)
			{
				delete[]array[i];
				array[i] = NULL;
			}
			delete[]array;
			array = NULL;
			throw "new array failed.";
		}

		//如果申请成功继续赋值
		for (j = 0; j < n; j++)
		{
			array[i][j] = i * n + j;
		}
	}

	//输出数组
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << setw(5) << array[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//释放内存空间
	for (i = 0; i < m; i++)
	{
		delete[]array[i];
		array[i] = NULL;
	}
	delete[]array;
	array = NULL;
}

void new_two_dimension_2()
/*
用new申请二维数组的变种，这里不行和列分开申请，而是一起申请
*/
{
	int i, j, m, n1;
	cout << "please input len of row and column:" << endl;
	while (cin >> m >> n1)
	{
		if (m <= 0 || n1 <= 0)
		{
			cout << "m or n <=0,please input again." << endl;
			continue;
		}
		break;
	}
	const int n=n1;

	//开始申请内存
	int(* array)[10] = new int[m][10];//申请连续空间时候n必须是常量
	if (NULL == array)
	{
		throw "new array failed.";
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 10; j++)
		{
			array[i][j] = i * 10 + j;
		}
	}

	//输出数组
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cout << setw(5) << array[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//释放内存空间
	delete[]array;
	array = NULL;
}

