// 数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma warning(disable : 4996)
#include <iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

//#define _CRT_SECURE_NO_WARNINGS  0
//#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
template <typename T>
void show(T array[])
{
	cout << "start show array." << endl;
	int i = 0;
	while(array[i]!='\0')
	{
		cout << setw(5)<< array[i++];
	}
	cout << endl;
	//cout << "str len:" << strlen(array) << endl;
	//数组传入函数退化为数组指针，因子sizeof返回4，strlen还可以继续使用
	//cout << "str size:" << sizeof(array) << endl;
	cout << endl<<endl;
}

int main()
{
	//当定义一个字符数组时，可以采用逐个字符初始化的方式：
	//当显示指定的字符不足字符数组的长度时，编译器将剩余字符置为空字符’\0’,申请10个最多填9个，填10会没有终止符，但是不会报错
	//如果超过十个则会报错，最好用这种方是时，加上终止符,strlen是实际字符数组长度，不算终止符
	char str[10] = { 'h','e','l','l','o' ,'\0'};
	//cout <<"str len:"<< strlen(str)<<endl;
	//实际使用了6个字节，strlen返回5，指的是5个元素，sizeof返回10,是分配的字节数
	cout << "str size:" << sizeof(str) << endl;
	if (str[9] == '\0')
		cout << "yes"<<endl;
	show(str);
	int a = 1;
	//求变量大小，字符数组正好一个char占一个字节，因子正好是分配的长度
	cout << sizeof(a) << endl;

	//在C语言中，将字符串作为字符数组来处理，因此可以使用字符串来初始化字符数组。
	char str2[] = { "hello" };
	//cout << "str2 len:" << strlen(str2) << endl;
	cout << "str2 size:" << sizeof(str2) << endl;
	show(str2);

	//也可以省略花括号。
	char str3[10] = "hello";
	//cout << "str3 len:" << strlen(str3) << endl;
	cout << "str3 size:" << sizeof(str3) << endl;
	show(str3);

	//不及字符数组长度时，剩余字符置为空字符’\0’。
	//因此，我们不难得出，当为一个字符数组初始化为空字符数组的做法有如下几种：
	//这种定义字符串都填充了\0
	char str4[10] = "";
	cout << "str4 size:" << sizeof(str4) << endl;
	if (str4[2] == '\0')
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	show(str4);

	//同理空字符串也可以这样申明
	char str5[10] = { "" };
	cout << "str5 size:" << sizeof(str5) << endl;
	if (str5[2] == '\0')
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	show(str5);

	//也可以用0来初始化
	char str6[10] = { 0 };
	cout << "str6 size:" << sizeof(str6) << endl;
	if (str6[2] == '\0')
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	show(str6);

	//也可以用\0来初始化
	char str7[10] = { '\0' };
	cout << "str7 size:" << sizeof(str7) << endl;
	if (str7[2] == '\0')
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	show(str7);

	char str8[10]="123456";
	char str9[] = "abc";
	show(str8);
	show(str9);
	//利用已有的字符串，通过memcpy,strcpy或者strncpy等函数实现拷贝赋值，参考代码如下：
	//这三个函数效果一样,与strcpy相比，memcpy并不是遇到'\0'就结束，而是一定会拷贝完n个字节。
	//memcpy用来做内存拷贝，你可以拿它拷贝任何数据类型的对象，可以指定拷贝的数据长度；
	/*
	例：

　　char a[100], b[50];

　　memcpy(b, a,sizeof(b)); //注意如用sizeof(a)，会造成b的内存地址溢出。
  这里也有问题，应该是拷贝较小的字节数进目标地址

　　strcpy就只能拷贝字符串了，它遇到'\0'就结束拷贝；例：
	*/
	cout << "mencpy str8 str9:" << endl;
	memcpy(str8, str9, min(sizeof(str8),sizeof(str9)));
	show(str8);
	show(str9);

	//cout << "strcpy str8 str9:" << endl;
	////目标数组大小不够会报错
	//strcpy(str9, str8);
	////会覆盖目标数组所有内容
	//strcpy(str8, str9);
	//show(str8);
	//show(str9);

	////效果和strcpy一样
	//strncpy(str8, str9, strlen(str9) + 1);
	//show(str8);
	//show(str9);

	char str10[10] = "";
	str10[9] = '\n';
	str10[8] = 'a';
	cout << str10[8] << endl;
	if (str10[1] == '\0')
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	//从后向前添加数据时候，前面还是终止符，strlen识别不了，返回0
	cout << "str 10 len:" << strlen(str10);

	int m = 1;
	//如果有表达式不是常量，也会出错
	//const int n = 10+m;
	//常量表达式可以
	const int n = 1 + 9;
	//非常量无法创建字符数组
	char str11[n] = "aaa";
	show(str11);

	cout << "ssssssssssssssssssssssssss" << endl;
	//申明数组并没有初始化
	int aa[10];
	aa[0] = 0;

	int nn[10]; // n 是一个包含 10 个整数的数组

    // 初始化数组元素          
	for (int i = 0; i < 10; i++)
	{
		nn[i] = i + 100; // 设置元素 i 为 i + 100
	}
	cout << "Element" << setw(13) << "Value" << endl;

	// 输出数组中每个元素的值                     
	for (int j = 0; j < 10; j++)
	{
		cout << setw(7) << j << setw(13) << nn[j] << endl;
	}

	const int n2 = 10;
	int n1[n2];
}

