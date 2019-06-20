#pragma once
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int value(int n, int capacity, vector<int>values, vector<int>weights)
/*
�Ե�������01��������Ľ⣬n:��Ʒ������capacity:����������values:ÿ����Ʒ�ļ�ֵ��weights:ÿ����Ʒ������
ʱ��ռ临�Ӷȶ���O(n*capacity)
*/
{
	//ֱ�ӷ��ص����
	if (n <= 0 || capacity <= 0 || values.size() <= 0 || weights.size() == 0 || weights.size() != values.size())
		return 0;
	//����һ����ά���飬����Ϊn�����Ϊcapacity,i,j��ʾ��Ʒ����Ϊǰi��ʱ������Ϊjʱ������ֵ
	vector<vector<int>>results(n+1, vector<int>(capacity+1, 0));

	//�����������
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			//�����ǰ��Ʒ���ڵ�ǰ������������results[i][j]=result[i-1][j]
			if (weights[i] > j)
				results[i][j] = results[i - 1][j];
			else
				//��Ϊ��i����Ʒ�Ų���
				results[i][j] = max(results[i - 1][j], results[i - 1][j - weights[i]] + values[i]);
		}
	}
	cout << "values:" << endl;
	for (int i = 0; i <= n; i++)
		cout << setw(5) << values[i];
	cout << endl;
	cout << "weights:" << endl;
	for (int i = 0; i <= n; i++)
		cout << setw(5) << weights[i];
	cout << endl;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= capacity; j++)
		{
			cout <<setw(5)<< results[i][j];
		}
		cout << endl;
	}
	return results[n][capacity];
}

int value_optimize(int n, int capacity, vector<int>values, vector<int>weights)
/*
�Ե����϶�̬�滮�Ż��汾
ʱ�临�Ӷ�O(n*capacity),�ռ临�Ӷ�O(capacity)
����results[i][j]=max(results[i-1][j],results[i-1][j-weights[i]]+values[i])
��ʵֻ�洢��i-1���������Ϊj��j-weights[i]�������
�������Ʒ����1��ʼѭ���������Ϳ��Եõõ���һ����Ʒ�����������������
��������ֻ�ܴ�capacity��ʼѭ������Ϊ�����1��ʼѭ����������һ������ʱ��ǰһ�����������Ѿ�������results����Ϊresults��ȫ��i-1��Ʒ�����
*/
{
	//ֱ�ӷ��ص����
	if (n <= 0 || capacity <= 0 || values.size() == 0 || weights.size() == 0 || values.size() != weights.size())
		return 0;

	//����һ��һά���飬�����һ����Ʒʱ������������Ӧ������ֵ
	vector<int>results(capacity + 1,0);

	//��Ʒֻ�ܴ�С����ʼѭ��
	for (int i = 1; i <= n; i++)
	{
		//����ֻ�ܴӴ�ʼѭ����Ϊ�˲���Ⱦ��һ����Ʒ���������������
		for (int j = capacity; j >= 1; j--)
		{
			//�����ǰ��Ʒ����������������ֱ�ӷ�����ǰ��Ʒ,���ı�results
			//����ı�
			if (weights[i] <= j)
				results[j] = max(results[j], results[j - weights[i]] + values[i]);
		}
	}
	return results[capacity];
}
