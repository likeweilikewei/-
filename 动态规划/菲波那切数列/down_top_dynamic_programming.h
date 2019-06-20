#pragma once
/*
����¼�����������˵ݹ飬�����㷨��������������fib��6����ʱ�������Ҫ�����
fib��1����fib��2����fib��3������,��ô�β��ȼ����fib��1����fib��2����fib��3������,�أ�
��Ҳ���Ƕ�̬�滮�ĺ��ģ��ȼ��������⣬������������㸸���⡣
�ݹ��к����Ŀ�������˻������Ż�
ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
*/

int fib_down_top_dp(int n)
{
	int* results = new int[n + 1];
	results[0] = 0;
	results[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		results[i] = results[i - 1] + results[i - 2];
	}
	return results[n];
}

/*�Կռ临�ӶȽ�һ��ѹ����û�б�Ҫ�������е��ӽ����ֻ��Ҫ��������������Ϳ�����
*/

int fib_down_to_top_dp_optimize(int n)
/*�Ե����϶�̬�滮���ռ临�Ӷ��Ż�*/
{
	int result_i_2 = 0;
	int result_i_1 = 1;
	int result_i;
	for (int i = 2; i <= n; i++)
	{
		result_i = result_i_1 + result_i_2;
		result_i_2 = result_i_1;
		result_i_1 = result_i;
	}
	return result_i;
}