#include "down_top_dynamic_programming.h"
/*
���ر�������

��Ŀ
��N����Ʒ��һ������ΪV�ı�������i����Ʒ�����n[i]����ÿ��������c[i]����ֵ��w[i]��
��⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�ķ����ܺͲ����������������Ҽ�ֵ�ܺ����

˼·
���ر��������˼·����ȫ������˼·�ǳ����ƣ�ֻ��k��ȡֵ�������Ƶģ���Ϊÿ����Ʒ�������������Ƶģ�
״̬ת�Ʒ���Ϊ��

dp[i][v] = max{dp[i - 1][v - k * c[i]] + w[i] | 0 <=k <= n[i],dp[i-1][v]}
*/

int bag(int n, int capacity, vector<int> values, vector<int> weights, vector<int> numbers)
{
	//ֱ�ӷ��ص����
	if (n <= 0 || capacity <= 0 || values.size() != weights.size() || values.size() != numbers.size() || values.size() == 0)
		return 0;

	//����һ����Ŷ�ά������м�����results[i][j]��ʾǰi����Ʒ���������Ϊj�µ�����ֵ
	vector<vector<int>>results(n+1, vector<int>(capacity+1, 0));

	//��ʼ����
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			//������k����Ʒ
			for (int k = 0; k <= numbers[i]; k++)
			{
				//����ռ�Ų�����Ʒi����ֱ������
				if (weights[i] * k > j)
					break;
				//��Ϊ�Ǽ���ǰk-1�����Թ��ˣ����ڳ��Էŵ�k��
				results[i][j] = max(results[i][j], results[i - 1][j - k * weights[i]] + k * values[i]);
			}
		}
	}
	return results[n][capacity];
}
