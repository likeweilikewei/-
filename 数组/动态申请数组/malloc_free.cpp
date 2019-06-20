
#include"array.h"


void malloc_one_dimension()
/*
��malloc��̬����һλ����
*/
{
	int i, m;

	cout << "please input len of array:" << endl;
	cin >> m;
	int* array = (int*)malloc(m * sizeof(int));

	//�������ʧ�����˳�
	if (NULL == array)
	{
		cout << "malloc failed." << endl;
		exit(-1);
	}

	//��ʼ�������
	for (i = 0; i < m; i++)
	{
		//���ֵȼ۵ı��
		array[i] = i;
		//*(array + i) = i;
	}

	//��ӡ����
	for (i = 0; i < m; i++)
	{
		cout << array[i] << " ";
		//cout << *(array + i) << " ";
	}
	cout << endl;

	//�ͷ��ڴ�ռ�
	free(array);
	//����ָ����Ϊ��ָ��
	array = NULL;
}

void malloc_two_dimension()
/*
��malloc�����ά����
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
		//�����������쳣�Ļ�ֱ���˳��������޷���׽
		cout << "input again." << endl;
		//�������
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
	//�������
	cin.clear();
	while (cin.get() != '\n')
		continue;

	//����ռ�
	int** array = (int**)malloc(m * sizeof(int*));//�������У���ΪarrayԪ����int*,�����ôд��������sizeof(int)
	if (NULL == array)
	{
		cout << "malloc array row failed." << endl;
		exit(-1);
	}

	//�����ֵ
	for (i = 0; i < m; i++)
	{
		array[i] = (int*)malloc(n * sizeof(int));//������
		//�������ʧ����Ҫ���֮ǰ������ڴ�
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

		//��ȷ�������ֵ
		for (j = 0; j < n; j++)
		{
			array[i][j] = i * n + j;
		}
	}

	//��ӡ����
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << setw(5) << array[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//�ͷ��ڴ�
	for (i = 0; i < m; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
