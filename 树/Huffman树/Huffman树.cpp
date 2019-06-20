// Huffman树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<typeinfo>
#include"huffman_tree.h"
using namespace std;

int main()
{
	vector<int>weights = { 27,8,15,15,30,5 };
	HuffmanTree<int>tree(weights);

	tree.ConstructTree();
	tree.Show();
	tree.HuffmanCode();
	tree.ShowCode();

	////测试vector中的字符数组解析后能否直接输出数组
	//vector<char*>names;
	//char name1[] = { '1','2','3','\0'};
	//char* name2 = new char[3];
	//name2[0] = 'a';
	//name2[1] = 'b';
	//name2[2] = '\0';
	////直接输出字符数组是完整内容，如果解析后输出是第一个元素
	//cout << "*name1: " << *name1 << endl;
	//cout << "name1:" << name1 << endl;
	//cout << "*name2: " << *name2 << endl;
	//cout << "name2:" << name2 << endl;
	//names.push_back(name1);
	//names.push_back(name2);
	//for (vector<char*>::const_iterator iter = names.begin(); iter != names.end(); iter++)
	//{
	//	//解析会输出所有元素
	//	*iter[0] = 's';
	//	cout << *iter << endl;
	//	//*iter是char*类型，可以修改内容
	//	cout << typeid(*iter).name() << endl;
	//}
}

