// String.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

//

/*string是C++标准库的一个重要的部分，主要用于字符串处理。可以使用输入输出流方式直接进行操作，也可以通过文件等手段进行操作。
同时C++的算法库对string也有着很好的支持，而且string还和c语言的字符串之间有着良好的接口。虽然也有一些弊端，但是瑕不掩瑜。 */

#include <iostream>
#include<string>
#include"replace.h"
#include"assign.h"
#include"find.h"
#include"rfind.h"
#include"find_of.h"
#include"compare.h"
#include"数值转换.h"

using namespace std;

int main()
{
	/*
	vcin慢是有原因的，其实默认的时候，cin与stdin总是保持同步的，也就是说这两种方法可以混用，
	而不必担心文件指针混乱，同时cout和stdout也一样，两者混用不会输出顺序错乱。正因为这个兼容性的特性，
	导致cin有许多额外的开销，如何禁用这个特性呢？只需一个语句std::ios::sync_with_stdio(false);这样就可以取消cin于stdin的同步了。
	*/
	ios::sync_with_stdio(false);
	//声明
	string s;//声明一个string 对象
	cout << s.size() << endl;
	string ss[10];//声明一个string对象的数组

    //初始化：使用等号的初始化叫做拷贝初始化，不使用等号的初始化叫做直接初始化。
	string s0;//默认初始化，一个空字符串
	string s1("ssss");//s1是字面值“ssss”的副本
	string s2(s1);//s2是s1的副本
	string s3 = s2;//s3是s2的副本
	string s4(10, 'c');//把s4初始化,生成10个c
	cout << "s4:" << s4 << endl;
	string s5 = "hiya";//拷贝初始化
	string s6 = string(10, 'c');//拷贝初始化，生成一个初始化好的对象，拷贝给s6

	//char*和string复制上的区别
	char cs[] = "12345";
	//string s(cp,n)
	//复制字符串cs的前三个到s7中
	string s7(cs, 3);
	cout << "s7:" << s7 << endl;

	//string是从下标为3的字符开始拷贝,从0开始计数
	//string s(s2,pos2)
	string s8 = "123456";
	string s9(s8, 3);
	cout << "s9: " << s9 << endl;

	//三个参数则可以指定开始下标和长度
	//string s(s2,pos2,len2)
	//从下标3开始4个字符的拷贝，超过s3.size出现未定义
	string s10(s8, 3, 3);
	cout << "s10: " << s10 << endl;

	//得到子串
	string s11 = "abcdefg";

	//s.substr(pos1,n)返回字符串位置为pos1后面的n个字符组成的串，下标为1开始的50个串
	//第二个参数超过了字符串时候返回结尾所有字符串，不会报错
	string s12 = s11.substr(1, 50);//bcdef
	cout << "s12: " << s12 << endl;

	//s.substr(pos)//得到一个pos到结尾的串
	//得到从下标4开始到结尾的串
	//第一个参数查出字符的长度就会抛出一个out_of_range异常
	string s13 = s11.substr(4);//efg
	cout << "s13: " << s13 << endl;



	//插入字符串
	string str = "to be question";
	string str2 = "the ";
	string str3 = "or not to be";
	string::iterator it;

	//s.insert(pos,str)//在s的pos位置前插入str
	str.insert(6, str2);                 // to be the question
	cout << "str: " << str << endl;

	//s.insert(pos,str,a,n)在s的pos位置插入str中插入位置a到后面的n个字符
	str.insert(6, str3, 3, 4);             // to be not the question
	cout << "str: " << str << endl;

	//s.insert(pos,cstr,n)//在pos位置插入cstr字符串从开始到后面的n个字符
	//这里8代表长度是因为这里将字符串当做了字符数组
	str.insert(10, "that is cool", 8);    // to be not that is the question
	cout << "str: " << str << endl;

	//s.insert(pos,cstr)在s的pos位置插入cstr
	str.insert(10, "to be ");            // to be not to be that is the question
	cout << "str: " << str << endl;

	//s.insert(pos,n,ch)在s.pos位置上面插入n个ch
	str.insert(15, 1, ':');               // to be not to be: that is the question
	cout << "str: " << str << endl;

	//s.insert(s.it,ch)在s的it指向位置前面插入一个字符ch，返回新插入的位置的迭代器
	it = str.insert(str.begin() + 5, ','); // to be, not to be: that is the question
	//这里it指向了,
	cout << "it:" << *it << endl;
	cout << "str: " << str << endl;

	//s.insert(s.it,n,ch)//在s的it所指向位置的前面插入n个ch
	str.insert(str.end(), 3, '.');       // to be, not to be: that is the question...
	cout << "str: " << str << endl;

	//s.insert(it,str.ita,str.itb)在it所指向的位置的前面插入[ita,itb)的字符串
	//在n的前面插入后面表示的字符串
	str.insert(it + 2, str3.begin(), str3.begin() + 3); // to be, or not to be: that is the question...
	cout << "str: " << str << endl;



	//删除字符
	cout << endl;
	std::string str4("This is an example sentence.");

	//str4的begin和end的指向
	cout << "str4 begin: " << *str4.begin() << endl;
	//end指向最后一个字符后面的位置
	cout << "str4 end: " << *(str4.end()-1) << endl;

	cout << "str4: " << str4 << endl;
	// "This is an example sentence."
	//删除下标10开始的8个字符
	str4.erase(10, 8);       //            ^^^^^^^^
	cout << "str4: " << str4 << endl;
	//直接指定删除的字符串位置第十个后面的8个字符
	std::cout << str4 << '\n';
	// "This is an sentence."
	//删除下标9的字符
	str4.erase(str4.begin() + 9);//
	//删除迭代器指向的字符
	std::cout << str4 << '\n';
	// "This is a sentence."
	//删除下标5开始，倒数第8个（不包括倒数第8个，从0开始）之间的元素，不包括后面迭代器指向的字符
	str4.erase(str4.begin() + 5, str4.end() - 9);
	//删除迭代器范围的字符
	std::cout << str4 << '\n';
	// "This sentence."

	std::string str5;
	std::string str12 = "Writing ";
	std::string str13 = "print 10 and then 5 more";

	//直接追加一个str12的字符串
	str5.append(str12);                       // "Writing "
	cout << "str 5: " << str5 << endl;
	//后面追加str13第6个字符开始的3个字符串
	str5.append(str13, 6, 3);                   // "10 "
	cout << "str 5: " << str5 << endl;

	//追加字符串形参的前5个字符,常量字符串当做字符数组，5当做前5个字符
	str5.append("dots are cool", 5);          // "dots "
	cout << "str 5: " << str5 << endl;

	//直接添加
	str5.append("here: ");                   // "here: "
	cout << "str 5: " << str5 << endl;

	//添加10个'.'
	str5.append(10u, '.');                    // ".........."
	cout << "str 5: " << str5 << endl;

	//添加str13迭代器范围的字符串，左闭右开
	str5.append(str13.begin() + 8, str13.end());  // " and then 5 more"
	cout << "str 5: " << str5 << endl;

	//最后这个比较特殊，意思是添加5个'A'，实际上参数里面的65对应的asc码就是65
	//str.append<int>(5, 65);                // "....."
	//字符串追加也可以用重载运算符实现
	//也可以加字符
	str5 += "lalala";
	cout << "str 5: " << str5 << endl;

	//直接加上
	str5 = str5 + "like  ";
	cout << "str 5: " << str5 << endl;

	//添加下标第二个字符开始到最后一个字符
	string str20 = "xiamei";
	str5.append(str20, 2);
	cout << "str 5: " << str5 << endl;

	//append没有办法直接加一个字符，需要这种方式，但是+可以
	str5.append(1,'a');
	cout << "test str 5 : " << str5 << endl;

	//show_replace();
	//assign();
	//find();
	//rfind();
	//find_of();
	//compare();
	convert();
}
