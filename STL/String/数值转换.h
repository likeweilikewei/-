#pragma once
/*
在io的部分有过数值和字符串相互转换的例子，使用的是stringstream函数，在c++11当中有定义好的现成的函数取调用，非常方便。

string和数值转换
to_string(val)	把val转换成string
stoi(s,p,b)	把字符串s从p开始转换成b进制的int
stol(s,p,b)	long
stoul(s,p,b)	unsigned long
stoll(s,p,b)	long long
stoull(s,p,b)	unsigned long long
stof(s,p)	float
stod(s,p)	double
stold(s,p)	long double
*/
#include<string>
#include<iostream>
using namespace std;

void convert()
{
	ios::sync_with_stdio(false);
	string s1;
	s1 = to_string(100);
	cout << s1 << endl;
	int a = stoi(s1, 0, 10) + 1;
	cout << a << endl;
}