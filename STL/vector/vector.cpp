// vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>

using namespace std;

template <typename T>
void show(T b[])
{
	int i = 0;
	while (b[i] != '\0')
		cout << b[i++] << " ";
	cout << endl;
}

template <typename T>
void shows(const vector<T>& values)
{
	//常量vector只能用常量迭代器接受
	for (typename vector<T>::const_iterator iter = values.begin(); iter != values.end(); iter++)
		cout << " " << *iter;
	cout << endl;
}

int main()
{
	vector<int>a = { 1,2,6,7 };
	//这种情况终止符有问题
	int b[] = { 1,34,5};
	//这种情况有终止符
	int b2[10] = { 1,34,5 };
	//列表初始化不会再后面加\n，直接字符串会加
	char c[10] = "2142t";
	show(b);

	vector<int>a1(10, 2);
	shows(a1);
	//重新赋值为111
	a1.assign(3, 1);
	shows(a1);
}

