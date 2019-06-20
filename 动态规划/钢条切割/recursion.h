#pragma once
/*�ݹ�汾

��n���ȸ�����Ϊ1+n-1,2+n-2,3+n-3,...,n-1+1,n+0��n��������
ǰ���������֪���ͽ�����ת��Ϊ��С��ģ��������

�ݹ�汾�������������ظ�������
*/
#include<limits>
#include<algorithm>

using namespace std;

int cut(int p[],int len, int n)
/*��n���ȵ��и���������棬p�Ǽ۸��*/
{
	//��n����0������Ϊ0
	if (n <= 0)
		return 0;
	int max_value = INT_MIN;
	//��һ��������ȣ����ܳ���n,Ҳ���ܳ������鳤��
	int first = (n <= len) ? n : len;
	//������Ϊn������ֽ�Ϊn��������,��һ���ֵĳ���Ϊi
	for (int i = 1; i <= first; i++)
	{
		max_value = max(max_value, p[i] + cut(p, len, n - i));
	}
	return max_value;
}
