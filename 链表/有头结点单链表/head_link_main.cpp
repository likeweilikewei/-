// 有头结点单链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

/*
以下为操作链表的算法，该链表为单链表。
链表以头指针为索引，头指针指向头节点，头节点指向首节点，以此类推，直到尾节点。
头节点中不存放数据，只存放指向首节点的指针，
设置头节点的目的是为了方便对链表的操作，如果不设置头节点，而是直接由头指针指向首节点，
这样在对头指针后的节点进行插入删除操作时就会与其他节点进行该操作时有所不同，便要作为一种特殊情况来分析
*/

#include <iostream>
#include"head_link.h"

using namespace std;

Node*root = NULL;

int main()
{
	root = construct();
	traverse_list(root);
	int len = length_list(root);
	cout << "len of the link:" << len << endl;
	bool s = is_emptys(root);
	
	cout << "link is " <<(is_emptys(root) ? " " : "not ")<< "empty." << endl;

	//升序排序
	sort_list(root);
	cout << "sorted link value is:" << endl;
	traverse_list(root);

	//在指定位置插入一个节点
	bool insert_flag = insert_list(root, 1, 10);
	if (insert_flag)
	{
		cout << "insert successed,new link is：" << endl;
		traverse_list(root);
	}
	else
	{
		cout << "insert failed." << endl;
	}

	//删除指定位置的节点
	int data_delete;
	bool delete_flag = delete_list(root, 2, &data_delete);
	if (data_delete)
	{
		cout << "delete successd,new link is:" << endl;
		traverse_list(root);
	}
	else
	{
		cout << "delete failed." << endl;
	}

	//清空链表
	clear_list(root);
	traverse_list(root);
}

