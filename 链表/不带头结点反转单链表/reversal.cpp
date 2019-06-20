#include"link.h"

bool reversal_judge(NODE link)
{
	if (NULL == link || NULL == link->next)
		return false;
	else
	{
		return true;
	}
}

void reversal_1(NODE_LINK link_link)
/*
反转单链表方法一，将节点存到一个数组中，然后逆序构建链表
*/
{
	NODE link = *link_link;
	if (!reversal_judge(link))
		return;

	//声明数组
	NODE current = link;
	vector<NODE> nodes;
	while (current != NULL)
	{
		nodes.push_back(current);
		current = current->next;
	}

	//重新构建链表
	current = nodes.back();
	*link_link = current;
	nodes.pop_back();
	while (!nodes.empty())
	{
		current->next = nodes.back();
		current = nodes.back();
		nodes.pop_back();
	}
	current->next = NULL;
}

void reversal_2(NODE_LINK link_link)
/*
方法二，用pq两个指针处理指向，r暂存剩余链表，最后处理头结点和第一个节点
*/
{
	NODE link = *link_link;
	if (!reversal_judge(link))
		return;
	NODE p, q, r;
	p = link;
	q = p->next;
	r = q->next;
	q->next = p;
	p->next = NULL;
	while (NULL != r)
	{
		p = q;
		q = r;
		//这里的顺序不能调换，否则会丢掉r后面的节点，进入死循环
		r = r->next;
		q->next = p;
	}
	*link_link = q;
}

void reversal_3(NODE_LINK link_link)
{
	NODE link = *link_link;
	if (!reversal_judge(link))
		return;

	//虚拟一个头结点方便插入
	NODE head_next;
	NODE head = new Node;
	if (NULL == head)
		throw "new node failed.";
	head->next = NULL;

	head_next = head->next;

	NODE tmp;
	while (link != NULL)
	{
		head->next = link;
		tmp = link->next;
		link->next = head_next;
		link = tmp;
		head_next = head->next;
	}
	*link_link = head->next;
}

//改变传入的指针办法三种：返回一个新指针、传入指针的指针、传入指针的引用（因为此时没有发生指针的拷贝）
NODE reverse(NODE link, NODE& head)
{

	if (NULL == link)
		return NULL;
	if (link->next == NULL)
	{
		head = link;
		return link;
	}
	NODE head_tmp = reverse(link->next, head);
	head_tmp->next = link;
	link->next = NULL;
	return link;
}

void reversal_4(NODE_LINK link_link)
{
	NODE link = *link_link;
	NODE new_head = NULL;
	//reverse返回最后一个节点，new_head存放新头结点
	reverse(link, new_head);
	*link_link = new_head;
}
