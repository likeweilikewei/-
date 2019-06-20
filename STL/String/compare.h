#pragma once
#include<vector>
#include<iostream>
using namespace std;
/*
和strcmp函数一样，如果两个字符串相等，那么返回0，调用对象大于参数返回1，小于返回-1。
在compare当中还支持部分比较，里面有6个参数可以设置。
由于string重载了运算符，可以直接用>,<，==来进行比较，也很方便。
*/

void compare()
{
	ios::sync_with_stdio(false);
	string s1 = "123", s2 = "123";
	cout << s1.compare(s2) << endl;//0
	if (s1 == s2)
		cout << "s1 equal to s2." << endl;

	s1 = "123", s2 = "1234";
	cout << s1.compare(s2) << endl;//-1

	s1 = "1234", s2 = "123";
	cout << s1.compare(s2) << endl;//1

	std::string str1("green apple");
	std::string str2("red apple");

	if (str1.compare(str2) != 0)
		std::cout << str1 << " is not " << str2 << '\n';
	//str1的第6个字符以及后面的4个字符和参数比较
	if (str1.compare(6, 5, "apple") == 0)
		std::cout << "still, " << str1 << " is an apple\n";

	//最后5个字符和后面比较
	if (str2.compare(str2.size() - 5, 5, "apple") == 0)
		std::cout << "and " << str2 << " is also an apple\n";
	//str1的第6个字符以及后面的4个字符和str2的第4个字符以及后面的4个字符比较
	if (str1.compare(6, 5, str2, 4, 5) == 0)
		std::cout << "therefore, both are apples\n";
}