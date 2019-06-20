#pragma once
#include<string>
#include<iostream>
using namespace std;

void show_replace()
{
	std::string base = "this is a test string.";
	std::string str2 = "n example";
	std::string str3 = "sample phrase";
	std::string str4 = "useful.";

	// replace signatures used in the same order as described above:

	// Using positions:                 0123456789*123456789*12345
	std::string str = base;           // "this is a test string."
	//第9个字符以及后面的4个字符被str2代替
	str.replace(9, 5, str2);          // "this is an example string." (1)
	//第19个字符串以及后面的5个字符用str的第7个字符以及后面的5个字符代替
	str.replace(19, 6, str3, 7, 6);     // "this is an example phrase." (2)
	//第8个字符以及后面的9个字符用字符串参数代替
	str.replace(8, 10, "just a");     // "this is just a phrase."     (3)
	//第8个字符以及后面的5个字符用字符串参数的前7个字符替换
	str.replace(8, 6, "a shorty", 7);  // "this is a short phrase."    (4)
	//第22以及后面的0个字符用3个叹号替换
	str.replace(22, 1, 3, '!');        // "this is a short phrase!!!"  (5)
	//迭代器的原理同上
	// Using iterators:                                               0123456789*123456789*
	//将开始字符和出最后三个之外用str3替换
	str.replace(str.begin(), str.end() - 3, str3);                    // "sample phrase!!!"      (1)
	std::cout << str << '\n';
	//迭代器都是左开右闭，将前6个字符替换
	str.replace(str.begin(), str.begin() + 6, "replace");             // "replace phrase!!!"     (3)
	std::cout << str << '\n';
	str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);    // "replace is cool!!!"    (4)
	std::cout << str << '\n';
	str.replace(str.begin() + 12, str.end() - 4, 4, 'o');                // "replace is cooool!!!"  (5)
	str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end());// "replace is useful."    (6)
	std::cout << str << '\n';
}
