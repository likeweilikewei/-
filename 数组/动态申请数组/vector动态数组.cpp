#include"array.h"

void vector_one_demension()
{
	cout << "please input len of arr:" << endl;
	int m,i;

	cin >> m;
	if (m <= 0)
	{
		return;
	}

	vector<int> array(m);
	for (i = 0; i < m; i++)
	{
		array[i] = i;
	}

	//输出
	for (i = 0; i < m; i++)
	{
		cout << setw(4) << array[i];
	}
	cout << endl;
}

void vector_two_demensions()
/*
用vector申请二维数组
*/
{
	int i, j, m, n;

	cout << "please input array len of row and column:" << endl;
	while (cin >> m >> n)
	{
		if (m <= 0 || n <= 0)
		{
			cout << "value not profit." << endl;
			continue;
		}
		break;
	}

	//construct
	vector<vector<int>> array(m, vector<int>(n));
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			array[i][j] = j + i * n;
		}
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout<<setw(4) << array[i][j];
		}
		cout << endl;
	}
}


