#pragma once
/*
��io�Ĳ����й���ֵ���ַ����໥ת�������ӣ�ʹ�õ���stringstream��������c++11�����ж���õ��ֳɵĺ���ȡ���ã��ǳ����㡣

string����ֵת��
to_string(val)	��valת����string
stoi(s,p,b)	���ַ���s��p��ʼת����b���Ƶ�int
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