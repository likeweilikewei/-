#pragma once
/*
find������Ҫ�ǲ���һ���ַ����Ƿ��ڵ��õ��ַ����г��ֹ�����Сд���С�
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
	//��str���в��ҵ�һ�����ֵ�needle���ҵ��򷵻س��ֵ�λ�ã����򷵻ؽ�β
	std::size_t found = str.find(str2);
	cout << "found: " << found << endl;
	if (found != std::string::npos)
		std::cout << "first 'needle' found at: " << found << '\n';
	//��str���У��ӵ�found+1��λ�ÿ�ʼ���Ҳ����ַ�����ǰ6���ַ�
	//������Ǵ�foundλ�ò��ң���ǰһ�����ҽ��һ��
	found = str.find("needles are small", found + 1, 6);
	if (found != std::string::npos)
		std::cout << "second 'needle' found at: " << found << '\n';
	//��str���в��Ҳ����е��ַ���
	found = str.find("haystack");
	if (found != std::string::npos)
		std::cout << "'haystack' also found at: " << found << '\n';
	//����һ���ַ�
	found = str.find('.');
	if (found != std::string::npos)
		std::cout << "Period found at: " << found << '\n';
	//���ʹ�ã���str2�ò������е��ַ�������
	// let's replace the first needle:
	str.replace(str.find(str2), str2.length(), "preposition");
	std::cout << str << '\n';
}
