#pragma once
/*备忘录法也是比较好理解的，创建了一个n+1大小的数组来保存求出的斐波拉契数列中的每一个值，
在递归的时候如果发现前面fib（n）的值计算出来了就不再计算，如果未计算出来，
则计算出来后保存在Memo数组中，下次在调用fib（n）的时候就不会重新递归了。
比如上面的递归树中在计算fib（6）的时候先计算fib（5），调用fib（5）算出了fib（4）后，
fib（6）再调用fib（4）就不会在递归fib（4）的子树了，因为fib（4）的值已经保存在Memo[4]中。
*/

int fib(int n, int result[]);
int fib_top_down_dp(int n);

int fib(int n, int results[])
{
	if (results[n] != -1)
		return results[n];
	//递归退出条件
	if (n <= 2)
		results[n] = 1;
	else
		results[n] = fib(n - 1, results) + fib(n - 2, results);
	return results[n];
}

int fib_top_down_dp(int n)
{
	//申请数组保存中间结果，下标为1保存f(1),下标为0不用
	int* results = new int[n + 1];
	//置为-1，表示没有计算，这时需要计算后放入数组，否则直接取出
	for (int i = 0; i <= n; i++)
		results[i] = -1;
	return fib(n, results);
}

