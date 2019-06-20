#include"head_link.h"

bool reversal_judge(NODE link)
/*
判断是否需要进行反转
*/
{
	if (NULL == link)
	{
		cout << "link has no head node.can not reversal." << endl;
		return false;
	}
	if (link->next == NULL)
	{
		cout << "link is empty,no need to reversal." << endl;
		return false;
	}
	if (link->next->next == NULL)
	{
		cout << "link has one node,no need to reversal." << endl;
		return false;
	}
	return true;
}

void reversal_1(NODE link)
/*
方法一：将链表用数组或者堆栈存储起来，之后逆序重新构造带头结点单链表，有点简单，缺点是浪费空间
*/
{
	if (NULL == link)
	{
		cout << "link has no head." << endl;
		return;
	}
	NODE tmp = link->next;
	stack<NODE>nodes;
	while (tmp != NULL)
	{
		nodes.push(tmp);
		tmp = tmp->next;
	}

	//重新反向构建链表
	tmp = link;
	while (!nodes.empty())
	{
		tmp->next = nodes.top();
		tmp = nodes.top();
		nodes.pop();
	}
	tmp->next = NULL;
}

void reversal_2(NODE link)
/*
方法二，用pq两个指针处理指向，r暂存剩余链表，最后处理头结点和第一个节点
*/
{
	//如果没有头结点，或者没有一个节点，或者只有一个节点，没必要排序
	if (!reversal_judge(link))
		return;

	//需要反转的情况p先指向第一个节点，q指向后一个节点，r指向剩下的，令q的next为p
	NODE p, q, r;
	p = link->next;
	q = p->next;
	r = q->next;

	//第一次转换
	q->next = p;
	p->next = NULL;

	//直到剩余节点为空
	while (r != NULL)
	{
		p = q;
		q = r;
		r = r->next;
		q->next = p;
	}

	//此时q指向最后一个节点
	link->next = q;
}

void reversal_3(NODE link)
/*
反转单链表方法三，将第一个节点后面的节点不断插入到头结点后面，直到最后一个节点
*/
{
	NODE tmp;
	if (!reversal_judge(link))
		return;
	Node* first_node = link->next;
	while (first_node->next != NULL)
	{
		tmp = link->next;
		link->next = first_node->next;
		first_node->next = first_node->next->next;
		link->next->next = tmp;
	}
}

NODE reversal(NODE no_link, NODE& new_head)
/*
递归，这里的单链表是不带头结点的，new_head用来存放新链表的头结点
*/
{
	//终止条件
	if (NULL == no_link)
		return NULL;
	if (NULL == no_link->next)
	{
		new_head = no_link;
		return no_link;
	}

	NODE head=reversal(no_link->next,new_head);
	//将后一个几点的后继改为前一个节点
	head->next = no_link;
	no_link->next = NULL;
	return no_link;
}

void reversal_4(NODE link)
/*
反转单链表方法四，用递归的思想将单链表反转
*/
{
	if (!reversal_judge(link))
		return;
	NODE new_head;
	reversal(link->next, new_head);
	link->next = new_head;
}
