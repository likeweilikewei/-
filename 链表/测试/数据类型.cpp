#include<typeinfo>
#include<iostream>
#include"type.h"

using namespace std;

//自己用模板函数实现类型比较


int main()
{
	cout << typeid(int).name() << endl;
	cout << typeid(typeid(int).name()).name() << endl;
	char const* a = "int";
	if (a == typeid(int).name())
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	if (typeid(int) == typeid(1))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	auto result = isSameType(1, 1.0);
	cout << "result:" << result << endl;
}
