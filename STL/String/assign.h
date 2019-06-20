#pragma once
/*
assign方法可以理解为先将原字符串清空，然后赋予新的值作替换
返回类型为 string类型的引用。其常用的重载也有下列几种：
*/

#include<vector>
#include<iostream>
using namespace std;

void assign()
{
	std::string str;
	std::string base = "The quick brown fox jumps over a lazy dog.";

	// used in the same order as described above:
	//直接把base赋值给str
	str.assign(base);
	std::cout << str << '\n';
	//把base第10个字符以及后面的8个字符赋给str
	str.assign(base, 10, 9);
	std::cout << str << '\n';         // "brown fox"
	//把参数中的0到6个字符串赋给str
	str.assign("pangrams are cool", 7);
	std::cout << str << '\n';         // "pangram"
	//直接使用参数赋值
	str.assign("c-string");
	std::cout << str << '\n';         // "c-string"
	//给str赋值10个'*'字符
	str.assign(10, '*');
	std::cout << str << '\n';         // "**********"
	//赋值是10个'-'
	//str.assign<int>(10, 0x2D);
	std::cout << str << '\n';         // "----------"
	//指定base迭代器范围的字符串
	str.assign(base.begin() + 16, base.end() - 12);
	std::cout << str << '\n';         // "fox jumps over"
}