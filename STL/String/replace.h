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
	//��9���ַ��Լ������4���ַ���str2����
	str.replace(9, 5, str2);          // "this is an example string." (1)
	//��19���ַ����Լ������5���ַ���str�ĵ�7���ַ��Լ������5���ַ�����
	str.replace(19, 6, str3, 7, 6);     // "this is an example phrase." (2)
	//��8���ַ��Լ������9���ַ����ַ�����������
	str.replace(8, 10, "just a");     // "this is just a phrase."     (3)
	//��8���ַ��Լ������5���ַ����ַ���������ǰ7���ַ��滻
	str.replace(8, 6, "a shorty", 7);  // "this is a short phrase."    (4)
	//��22�Լ������0���ַ���3��̾���滻
	str.replace(22, 1, 3, '!');        // "this is a short phrase!!!"  (5)
	//��������ԭ��ͬ��
	// Using iterators:                                               0123456789*123456789*
	//����ʼ�ַ��ͳ��������֮����str3�滻
	str.replace(str.begin(), str.end() - 3, str3);                    // "sample phrase!!!"      (1)
	std::cout << str << '\n';
	//�������������ұգ���ǰ6���ַ��滻
	str.replace(str.begin(), str.begin() + 6, "replace");             // "replace phrase!!!"     (3)
	std::cout << str << '\n';
	str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);    // "replace is cool!!!"    (4)
	std::cout << str << '\n';
	str.replace(str.begin() + 12, str.end() - 4, 4, 'o');                // "replace is cooool!!!"  (5)
	str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end());// "replace is useful."    (6)
	std::cout << str << '\n';
}
