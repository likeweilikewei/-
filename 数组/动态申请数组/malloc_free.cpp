
#include"array.h"


void malloc_one_dimension()
/*
用malloc动态开辟一位数组
*/
{
	int i, m;

	cout << "please input len of array:" << endl;
	cin >> m;
	int* array = (int*)malloc(m * sizeof(int));

	//如果申请失败则退出
	if (NULL == array)
	{
		cout << "malloc failed." << endl;
		exit(-1);
	}

	//开始填充数组
	for (i = 0; i < m; i++)
	{
		//两种等价的表达
		array[i] = i;
		//*(array + i) = i;
	}

	//打印数组
	for (i = 0; i < m; i++)
	{
		cout << array[i] << " ";
		//cout << *(array + i) << " ";
	}
	cout << endl;

	//释放内存空间
	free(array);
	//并将指针置为空指针
	array = NULL;
}

void malloc_two_dimension()
/*
用malloc申请二维数组
*/
{
	int i, j, m, n;

	cout << "please imput array m,n" << endl;
	try
	{
		while (cin >> m >> n)
		{
			if (m <= 0 || n <= 0)
			{
				cout << "m or n <=0,please input right number:" << endl;
				continue;
			}
			break;
		}
	}
	catch (...)
	{
		//上述的输入异常的话直接退出，这里无法捕捉
		cout << "input again." << endl;
		//清除缓存
		cin.clear();
		while (cin.get() != '\n')
			continue;

		cout << "input failed,please two number again." << endl;
		while (cin >> m >> n)
		{
			if (m <= 0 || n <= 0)
			{
				cout << "m or n <=0,please input right number:" << endl;
				continue;
			}
			break;
		}
	}
	//清除缓存
	cin.clear();
	while (cin.get() != '\n')
		continue;

	//申请空间
	int** array = (int**)malloc(m * sizeof(int*));//先申请行，因为array元素是int*,因此这么写，而不是sizeof(int)
	if (NULL == array)
	{
		cout << "malloc array row failed." << endl;
		exit(-1);
	}

	//填充数值
	for (i = 0; i < m; i++)
	{
		array[i] = (int*)malloc(n * sizeof(int));//申请列
		//如果申请失败需要清空之前申请的内存
		if (NULL == array[i])
		{
			while (--i >= 0)
			{
				free(array[i]);
				array[i] = NULL;
			}
			free(array);
			array = NULL;
			cout << "malloc array column failed." << endl;
			exit(-1);
		}

		//正确就填充数值
		for (j = 0; j < n; j++)
		{
			array[i][j] = i * n + j;
		}
	}

	//打印数组
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << setw(5) << array[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//释放内存
	for (i = 0; i < m; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
