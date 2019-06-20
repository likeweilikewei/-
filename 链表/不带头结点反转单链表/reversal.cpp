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
��ת��������һ�����ڵ�浽һ�������У�Ȼ�����򹹽�����
*/
{
	NODE link = *link_link;
	if (!reversal_judge(link))
		return;

	//��������
	NODE current = link;
	vector<NODE> nodes;
	while (current != NULL)
	{
		nodes.push_back(current);
		current = current->next;
	}

	//���¹�������
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
����������pq����ָ�봦��ָ��r�ݴ�ʣ�����������ͷ���͵�һ���ڵ�
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
		//�����˳���ܵ���������ᶪ��r����Ľڵ㣬������ѭ��
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

	//����һ��ͷ��㷽�����
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

//�ı䴫���ָ��취���֣�����һ����ָ�롢����ָ���ָ�롢����ָ������ã���Ϊ��ʱû�з���ָ��Ŀ�����
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
	//reverse�������һ���ڵ㣬new_head�����ͷ���
	reverse(link, new_head);
	*link_link = new_head;
}
