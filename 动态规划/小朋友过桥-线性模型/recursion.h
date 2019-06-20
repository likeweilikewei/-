#pragma once
/*�ݹ���С���ѹ���
������������߶��ͣ�
������ϸ��Ϊ��һ�������߶��ͣ�����2�������߶���
����Сʱ����˹�Сʱ����Ҫ2��һ�𣬵���СҲ�Ƚϴ�ʱ���1���˾Ϳ�����

��������
T[i]��ʾi���˹�����Сʱ��
T[1]=t[0]
T[2]=t[1]
i>=3ʱ���������Ĺ�ʽ
T[3]=t[1]+t[2]+t[0]
Ȼ��T[i]=min(T[i-1]+t[0]+t[i-1], T[i-2]+t[0]+t[i-1]+2t[1])
*/
#include<algorithm>
using namespace std;

int bridge_recursion(int* t, int n)
/*n���˹�������Сʱ��*/
{
	if (n <= 0||t==nullptr)
		return 0;
	if (n == 1)
		return t[0];
	if (n == 2)
		return t[1];
	return min(bridge_recursion(t, n - 1) + t[0] + t[n - 1], bridge_recursion(t, n - 2) + t[0] + t[n - 1] + 2 * t[1]);
}
