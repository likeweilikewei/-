#pragma once
/*递归解决小朋友过河
解决方法是能者多劳，
还可以细分为是一个人能者多劳，还是2个人能者多劳
当次小时间的人够小时候需要2人一起，当次小也比较大时候就1个人就可以了

首先排序
T[i]表示i个人过河最小时间
T[1]=t[0]
T[2]=t[1]
i>=3时候符合下面的公式
T[3]=t[1]+t[2]+t[0]
然后T[i]=min(T[i-1]+t[0]+t[i-1], T[i-2]+t[0]+t[i-1]+2t[1])
*/
#include<algorithm>
using namespace std;

int bridge_recursion(int* t, int n)
/*n个人过桥求最小时间*/
{
	if (n <= 0||t==nullptr)
		return 0;
	if (n == 1)
		return t[0];
	if (n == 2)
		return t[1];
	return min(bridge_recursion(t, n - 1) + t[0] + t[n - 1], bridge_recursion(t, n - 2) + t[0] + t[n - 1] + 2 * t[1]);
}
