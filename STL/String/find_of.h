#pragma once
#include<vector>
#include<iostream>
using namespace std;

void find_of()
{
	ios::sync_with_stdio(false);
	std::string str1("Please, replace the vowels in this sentence by asterisks.");
	std::size_t found1 = str1.find_first_of("aeiou");
	cout << "found: " << found1 << endl;
	//把所有元音找出来用*代替
	while (found1 != std::string::npos)
	{
		str1[found1] = '*';
		found1 = str1.find_first_of("aeiou", found1 + 1);
	}
	std::cout << str1 << '\n';

	//在str2中找到第一个不是消协英文字母和空格的字符
	std::string str2("look for non-alphabetic characters...");
	std::size_t found2 = str2.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
	if (found2 != std::string::npos)
	{
		std::cout << "The first non-alphabetic character is " << str2[found2];
		std::cout << " at position " << found2 << '\n';
	}
}