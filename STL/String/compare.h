#pragma once
#include<vector>
#include<iostream>
using namespace std;
/*
��strcmp����һ������������ַ�����ȣ���ô����0�����ö�����ڲ�������1��С�ڷ���-1��
��compare���л�֧�ֲ��ֱȽϣ�������6�������������á�
����string�����������������ֱ����>,<��==�����бȽϣ�Ҳ�ܷ��㡣
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
	//str1�ĵ�6���ַ��Լ������4���ַ��Ͳ����Ƚ�
	if (str1.compare(6, 5, "apple") == 0)
		std::cout << "still, " << str1 << " is an apple\n";

	//���5���ַ��ͺ���Ƚ�
	if (str2.compare(str2.size() - 5, 5, "apple") == 0)
		std::cout << "and " << str2 << " is also an apple\n";
	//str1�ĵ�6���ַ��Լ������4���ַ���str2�ĵ�4���ַ��Լ������4���ַ��Ƚ�
	if (str1.compare(6, 5, str2, 4, 5) == 0)
		std::cout << "therefore, both are apples\n";
}