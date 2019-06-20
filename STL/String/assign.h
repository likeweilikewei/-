#pragma once
/*
assign�����������Ϊ�Ƚ�ԭ�ַ�����գ�Ȼ�����µ�ֵ���滻
��������Ϊ string���͵����á��䳣�õ�����Ҳ�����м��֣�
*/

#include<vector>
#include<iostream>
using namespace std;

void assign()
{
	std::string str;
	std::string base = "The quick brown fox jumps over a lazy dog.";

	// used in the same order as described above:
	//ֱ�Ӱ�base��ֵ��str
	str.assign(base);
	std::cout << str << '\n';
	//��base��10���ַ��Լ������8���ַ�����str
	str.assign(base, 10, 9);
	std::cout << str << '\n';         // "brown fox"
	//�Ѳ����е�0��6���ַ�������str
	str.assign("pangrams are cool", 7);
	std::cout << str << '\n';         // "pangram"
	//ֱ��ʹ�ò�����ֵ
	str.assign("c-string");
	std::cout << str << '\n';         // "c-string"
	//��str��ֵ10��'*'�ַ�
	str.assign(10, '*');
	std::cout << str << '\n';         // "**********"
	//��ֵ��10��'-'
	//str.assign<int>(10, 0x2D);
	std::cout << str << '\n';         // "----------"
	//ָ��base��������Χ���ַ���
	str.assign(base.begin() + 16, base.end() - 12);
	std::cout << str << '\n';         // "fox jumps over"
}