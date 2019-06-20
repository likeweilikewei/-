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
	
	//��ʼ�����ڴ�
	int* array = new int[m];
	if (NULL == array)
	{
		cout << "new array failed." << endl;
		throw "new array failed.";
	}

	//��ʼ�����ֵ
	for (i = 0; i < m; i++)
	{
		array[i] = i;
	}

	//��ʼ�����ֵ
	for (i = 0; i < m; i++)
	{
		cout << setw(5) << array[i];
	}
	cout << endl;

	//����ڴ�
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

	//c++��newʧ�ܷ���bad_alloc�쳣����Ҫ���׳��쳣�Ż᷵�ؿ�ָ��
	//��ʼ�����ڴ�
	int** array = new(nothrow) int* [m];//�����пռ�
	if (NULL == array)
	{
		throw "new array failed.";
	}
	for (i = 0; i < m; i++)
	{
		array[i] = new int[n];//�����пռ�
		//�������ʧ����Ҫ�ͷ�֮ǰ������ڴ�
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

		//�������ɹ�������ֵ
		for (j = 0; j < n; j++)
		{
			array[i][j] = i * n + j;
		}
	}

	//�������
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << setw(5) << array[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//�ͷ��ڴ�ռ�
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
��new�����ά����ı��֣����ﲻ�к��зֿ����룬����һ������
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

	//��ʼ�����ڴ�
	int(* array)[10] = new int[m][10];//���������ռ�ʱ��n�����ǳ���
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

	//�������
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cout << setw(5) << array[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//�ͷ��ڴ�ռ�
	delete[]array;
	array = NULL;
}

