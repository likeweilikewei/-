#include"head_link.h"

bool reversal_judge(NODE link)
/*
�ж��Ƿ���Ҫ���з�ת
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
����һ����������������߶�ջ�洢������֮���������¹����ͷ��㵥�����е�򵥣�ȱ�����˷ѿռ�
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

	//���·��򹹽�����
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
����������pq����ָ�봦��ָ��r�ݴ�ʣ�����������ͷ���͵�һ���ڵ�
*/
{
	//���û��ͷ��㣬����û��һ���ڵ㣬����ֻ��һ���ڵ㣬û��Ҫ����
	if (!reversal_judge(link))
		return;

	//��Ҫ��ת�����p��ָ���һ���ڵ㣬qָ���һ���ڵ㣬rָ��ʣ�µģ���q��nextΪp
	NODE p, q, r;
	p = link->next;
	q = p->next;
	r = q->next;

	//��һ��ת��
	q->next = p;
	p->next = NULL;

	//ֱ��ʣ��ڵ�Ϊ��
	while (r != NULL)
	{
		p = q;
		q = r;
		r = r->next;
		q->next = p;
	}

	//��ʱqָ�����һ���ڵ�
	link->next = q;
}

void reversal_3(NODE link)
/*
��ת����������������һ���ڵ����Ľڵ㲻�ϲ��뵽ͷ�����棬ֱ�����һ���ڵ�
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
�ݹ飬����ĵ������ǲ���ͷ���ģ�new_head��������������ͷ���
*/
{
	//��ֹ����
	if (NULL == no_link)
		return NULL;
	if (NULL == no_link->next)
	{
		new_head = no_link;
		return no_link;
	}

	NODE head=reversal(no_link->next,new_head);
	//����һ������ĺ�̸�Ϊǰһ���ڵ�
	head->next = no_link;
	no_link->next = NULL;
	return no_link;
}

void reversal_4(NODE link)
/*
��ת���������ģ��õݹ��˼�뽫������ת
*/
{
	if (!reversal_judge(link))
		return;
	NODE new_head;
	reversal(link->next, new_head);
	link->next = new_head;
}
