#pragma once
/*����¼��Ҳ�ǱȽϺ����ģ�������һ��n+1��С�����������������쳲����������е�ÿһ��ֵ��
�ڵݹ��ʱ���������ǰ��fib��n����ֵ��������˾Ͳ��ټ��㣬���δ���������
���������󱣴���Memo�����У��´��ڵ���fib��n����ʱ��Ͳ������µݹ��ˡ�
��������ĵݹ������ڼ���fib��6����ʱ���ȼ���fib��5��������fib��5�������fib��4����
fib��6���ٵ���fib��4���Ͳ����ڵݹ�fib��4���������ˣ���Ϊfib��4����ֵ�Ѿ�������Memo[4]�С�
*/

int fib(int n, int result[]);
int fib_top_down_dp(int n);

int fib(int n, int results[])
{
	if (results[n] != -1)
		return results[n];
	//�ݹ��˳�����
	if (n <= 2)
		results[n] = 1;
	else
		results[n] = fib(n - 1, results) + fib(n - 2, results);
	return results[n];
}

int fib_top_down_dp(int n)
{
	//�������鱣���м������±�Ϊ1����f(1),�±�Ϊ0����
	int* results = new int[n + 1];
	//��Ϊ-1����ʾû�м��㣬��ʱ��Ҫ�����������飬����ֱ��ȡ��
	for (int i = 0; i <= n; i++)
		results[i] = -1;
	return fib(n, results);
}

