#pragma once
/*�Զ����±���¼��
���õݹ飬���ǲ���ÿ�ζ����㣬�жϵ�������û�д洢���ʱ��
���㲢���������У�����ֱ�ӷ���
���ǵݹ�Ҳ�ж��⿪��
*/
#include<algorithm>
#include<limits>

using namespace std;

int cut(int p[], int len, int n, int result[]);
int cut_top_down_dp(int p[], int len, int n);

int cut_top_down_dp(int p[], int len, int n)
{
	//�������鱣��������������ΪҪ����n�����������������Ҫn+1��С������
	int* results = new int[n + 1];
	//��ʼ������Ϊ��С��������ʾδ���ʣ����ﲻ��-1����Ϊ������Ҳ����Ϊ��
	for (int i = 0; i < n + 1; i++)
		results[i] = INT_MIN;
	return cut(p, len, n, results);
}

int cut(int p[], int len, int n, int result[])
{
	if (n <= 0)
		return 0;
	//�������ֱ�ӷ���
	if (result[n] != INT_MIN)
		return result[n];
	
	int max_value = INT_MIN;
	//��һ���ֵĳ��Ȳ��ܳ���n��Ҳ���ܳ���len
	int first = (n <= len) ? n : len;
	//������ֽ�ΪС����
	for (int i = 1; i <= first; i++)
	{
		max_value = max(max_value, p[i] + cut(p, len, n - i, result));
	}
	result[n] = max_value;
	return max_value;
}
