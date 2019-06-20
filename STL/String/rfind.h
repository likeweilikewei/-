#pragma once
/*
rfind函数就是找最后一个出现的匹配字符串，返回的位置仍然是从前往后数的。
*/
#include<vector>
#include<iostream>
using namespace std;

void rfind()
{
	ios::sync_with_stdio(false);
	std::string str("The sixth sick sheik's sixth sheep's sick.");
	std::string key("sixth");//                    ^
	//rfind是找最后一个出现的匹配字符串
	std::size_t found = str.rfind(key);
	cout << "found: " << found << endl;
	if (found != std::string::npos)
	{
		cout << found << endl;//输出23
		str.replace(found, key.length(), "seventh");//找到的sixth替换成seventh
	}

	std::cout << str << '\n';
}