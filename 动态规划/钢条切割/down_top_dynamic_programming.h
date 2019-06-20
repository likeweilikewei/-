#pragma once
/*
�Ե����ϵĶ�̬�滮
*/
#include<limits>
#include<algorithm>

using namespace std;

int cut_down_top_dp(int p[], int len, int n)
{
	if (n <= 0)
		return 0;

	//��̬�������м���������
	int* result = new int[n + 1];
	result[0] = 0;
	result[1] = p[1];
	for (int i = 2; i <= n; i++)
	{
		//������i��Ϊ������ʱ�򣬵�һ������󳤶�
		int first = (i <= len) ? i : len;
		//������
		int max_value = INT_MIN;
		//������i�ֽ�Ϊi��������
		for (int j = 1; j <= first; j++)
		{
			max_value = max(max_value, p[j] + result[i-j]);
		}
		result[i] = max_value;
	}
	return result[n];
}
