#pragma once
/*
rfind�������������һ�����ֵ�ƥ���ַ��������ص�λ����Ȼ�Ǵ�ǰ�������ġ�
*/
#include<vector>
#include<iostream>
using namespace std;

void rfind()
{
	ios::sync_with_stdio(false);
	std::string str("The sixth sick sheik's sixth sheep's sick.");
	std::string key("sixth");//                    ^
	//rfind�������һ�����ֵ�ƥ���ַ���
	std::size_t found = str.rfind(key);
	cout << "found: " << found << endl;
	if (found != std::string::npos)
	{
		cout << found << endl;//���23
		str.replace(found, key.length(), "seventh");//�ҵ���sixth�滻��seventh
	}

	std::cout << str << '\n';
}