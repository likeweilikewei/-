#pragma once
/*
find函数主要是查找一个字符串是否在调用的字符串中出现过，大小写敏感。
*/
#include<iostream>
#include<vector>
using namespace std;

void find()
{
	ios::sync_with_stdio(false);
	std::string str("There are two needles in this haystack with needles.");
	std::string str2("needle");

	// different member versions of find in the same order as above:
	//在str当中查找第一个出现的needle，找到则返回出现的位置，否则返回结尾
	std::size_t found = str.find(str2);
	cout << "found: " << found << endl;
	if (found != std::string::npos)
		std::cout << "first 'needle' found at: " << found << '\n';
	//在str当中，从第found+1的位置开始查找参数字符串的前6个字符
	//如果还是从found位置查找，和前一个查找结果一致
	found = str.find("needles are small", found + 1, 6);
	if (found != std::string::npos)
		std::cout << "second 'needle' found at: " << found << '\n';
	//在str当中查找参数中的字符串
	found = str.find("haystack");
	if (found != std::string::npos)
		std::cout << "'haystack' also found at: " << found << '\n';
	//查找一个字符
	found = str.find('.');
	if (found != std::string::npos)
		std::cout << "Period found at: " << found << '\n';
	//组合使用，把str2用参数表中的字符串代替
	// let's replace the first needle:
	str.replace(str.find(str2), str2.length(), "preposition");
	std::cout << str << '\n';
}
