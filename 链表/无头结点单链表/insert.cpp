#include"link.h"
#include"type.h"
#include<iostream>

using namespace std;

#ifndef NULL
#define NULL 0
#endif

int judge_sort(Node* link)
/*
判断单链表是否是排序好的,如果是升序则返回1，相等当为升序，降序返回-1，没有排序则返回0
*/
{
	Node* tmp_node = link;
	while (tmp_node->next != NULL)
	{
		tmp_node = tmp_node->next;
	}
	//当成升序的情况来判断
	if (tmp_node->value >= link->value)
	{
		while (link->next != NULL)
		{
			if (link->value > link->next->value)
				return 0;
			link = link->next;
		}
		return 1;
	}
	else
	{
		while (link->next != NULL)
		{
			if (link->value < link->next->value)
				return 0;
			link = link->next;
		}
		return -1;
	}
}

bool insert_append(Node** head, int value)
/*
单链表简单插入，直接追加在后面
*/
{
	Node* link = *head;
	*head = link;
	while (link&&link->next != NULL)
		link = link->next;
	Node* tmp = new Node;
	if (tmp == NULL)
		return false;
	tmp->next = NULL;
	tmp->value = value;
	if (link == NULL)
		*head = tmp;
	else
		link->next = tmp;
	return true; 
}

bool insert_sort(Node** head, int value)
/*
插入数据到排序好的链表中，保持链表的排序,如果没有排序则是普通的追加
*/
{
	cout << "insert before link:" << endl;
	show(*head);
	Node* link = *head;
	*head = link;
	Node* tmp_node = new Node;
	if (tmp_node == NULL)
		return false;
	tmp_node->next = NULL;
	tmp_node->value = value;

	//如果链表为空直接插入
	if (link == NULL)
	{
		*head = tmp_node;
		return true;
	}

	//只有一个元素的情况，默认是升序,无论是升序还是降序，相同的元素默认插入到第一个之前
	else if (link->next == NULL)
	{
		if (link->value >= value)
		{
			tmp_node->next = link;
			//改变link指向的地方也需要改变*head，以使得*head指向新的地址
			*head = tmp_node;
		}
		else
			link->next = tmp_node;
		return true;
	}

	//至少有两个元素的情况
	else
	{
		//判断是升序还是降序,头两个元素相等认为是升序的,当新值在头结点值之前则直接插入头结点
		Node* link_tmp = link;
		while (link_tmp->next != NULL)
		{
			link_tmp = link_tmp->next;
		}

		//判断是升序还是降序，如果不是排序程序，直接添加到后面
		if (!judge_sort(link))
		{
		return insert_append(head, value);
		}

		//升序新值大于等于头结点加插入到头结点之前，降序新值小于等于头结点也插入到头结点之前
		if (link->value <= link_tmp->value&&value<=link->value||link->value>link_tmp->value&&value>=link->value)
		{
				tmp_node->next = link;
				//这里也是一样，需要直接改变*head的指向
				*head = tmp_node;
				return true;
		}

		//当找到值在中间的情况，或者没找到到达最后一个节点都追加到最后一个节点上
		while (link->next != NULL)
		{
			int big_value = link->value > link->next->value ? link->value : link->next->value;
			int small_value = link->value < link->next->value ? link->value : link->next->value;
			if (big_value >= value && value >= small_value)
				break;
			//cout << "yes" << endl;
			//cout << big_value << value << small_value << endl;
			link = link->next;
		}
		//如果是最后一个直接追加上去,这种不改变link指向的插入不需要重新对*head进行改变，因为开头*head已经指向了新链表的头结点
		if (link->next == NULL)
			link->next = tmp_node;
		//否则插入到 中间
		else
		{
			//cout << "now" << endl;
			tmp_node->next = link->next;
			link->next = tmp_node;
			//show(link);
		}
		return true;
	}
}

bool insert(Node** head, int value)
/*
单链表插入
*/
{
	//bool flag = insert_append(head, value);
	bool flag=insert_sort(head,value);
	return flag;
}