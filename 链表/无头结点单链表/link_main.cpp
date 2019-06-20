#include <iostream>
#include"link.h"
#include <stdio.h>

using namespace std;

/*
测试单链表的各种操作
*/

Node* root = NULL;

int main()
{
	cout << "start construct link" << endl;
	construct(&root);

	//cout << root->value;
	show(root);
	cout << "start sort the link." << endl;
	sort(root, true);
	show(root);
	cout << "the link items number is:" << endl;
	cout << count(root) << endl;

	/*开始检测元素是否在链表中，如果不在则插入
	先清空之前的输入缓冲
	c做法
	while (getchar() != '\n')
		continue;	

	cin.clear()是用来更改cin的状态标示符的，cin在接收到错误的输入的时候，会设置状态位good。
	如果good位不为1，则cin不接受输入，直接跳过。
	如果下次输入前状态位没有改变那么即使清除了缓冲区数据流也无法输入。所以清除缓冲区之前必须要cin.clear()。
	
	置输入状态为good为1
	清除缓冲区，sync()的作用就是清除输入缓冲区。成功时返回0，失败时badbit会置位，函数返回-1. 
	另外，对于绑定了输出的输入流，调用sync()，还会刷新输出缓冲区。

	cin.get()从流中读入一个字符，到达末尾则返回EOF，也就是-1,重新读入，不带参数的返回值是int型，流的ascii码
	cin.get(a)返回一个流对象
	当cin状态为不为1的时候cin.get()返回-1，cin.get(a),int(a)得到-52
	因此在cin读入失败后应该使用cin.clear()恢复状态位才可以读入流中的数据

	int('2')==50
	字符转换为int时是用ascii码转换的
	*/
	/*auto a = cin.get()*/;
	//cin.clear();
	//char a;
	//cin.get(a);
	//cout <<"a:"<< int(a) << endl;
	//
	//while (a != '\n')
	//{
	//	cout <<"new a:"<< a << endl;

	//	auto b = cin.get();
	//	cout << "b:" << b << endl;

	//	cin.get(a);
	//	cout << "new a:" << a << endl;
	//	cout << "news a:" << int(a) << endl;
	//}
	//exit(99);

	//auto b = getchar();
	//while (b != '\n')
	//{
	//	cout <<"b:"<< b << endl;
	//	b = getchar();
	//	cout << "b:" << b << endl;
	//}
	//if (10 == '\n')
	//	cout << "yes";
	//cin.clear();

	int insert_value;
	cout << "please input a value to insert:" << endl;
	while (cin >> insert_value)
	{
		if (!contain(root, insert_value))
		{
			cout << "link not contain this value,can insert." << endl;
			break;
		}
		else
		{
			cout << "link hased this value,please input again:" << endl;
		}
	}

	//首先置cin状态位good，然后清空输入缓冲区
	cin.clear();
	while (cin.get() != '\n')
		continue;
	/*
	root输出是所指对象的地址值，&root是这个指针的地址值
	因此后两个不相同，前两个相同
	*/
	//Node* root_tmp = root;
	//cout << root << endl;
	//cout << root_tmp << endl;
	//cout << &root << endl;
	//cout << &root_tmp << endl;

	if (insert(&root, insert_value))
	{
		cout << "insert to link successd.new link:" << endl;
		show(root);
		cout << "the link items number is:" << endl;
		cout << count(root) << endl;
	}
	else
	{
		cout << "insert to link failed." << endl;
	}
	cout << endl;

	//开始删除一个元素
	int delete_value;
	cout << "please input a value to delete:" << endl;
	while (cin>>delete_value)
	{
		if (!contain(root, delete_value))
		{
			cout << "link do not has the value,please input again:" << endl;
		}
		else
		{
			cout << "link has the value,can delete." << endl;
			break;
		}
	}
	//清除缓冲区
	cin.clear();
	while (cin.get() != '\n')
		continue;
	//删除这个元素
	deletes(&root, delete_value);
	cout << "delete after link is:" << endl;
	show(root);

	//删除整个链表
	free_link(&root);
	cout << "delete all value:" << endl;
	show(root);
}

