#pragma once
/*�ݹ���쳲���������*/

int fib_recursion(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib_recursion(n - 1) + fib_recursion(n - 2);
}
