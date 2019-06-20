#include "link.h"

#ifndef NULL
#define NULL 0
#endif


void bubble_sort(Node* link, bool ascending = true)
/*
ð������
*/
{
	if (link == NULL)
		return;
	for (Node * current = link; current->next != NULL; current = current->next)
	{
		for (Node* tmp = link; tmp->next != NULL; tmp = tmp->next)
		{
			if ((ascending&& tmp->value > tmp->next->value)||(!ascending&& tmp->value < tmp->next->value))
			{
					int tmp_value = tmp->value;
					tmp->value = tmp->next->value;
					tmp->next->value = tmp_value;
			}
		}
	}
}


void sort(Node* link, bool ascending)
/*
�Ե������������Ĭ������,���øı�ָ����ָ����ֻ�ı�ָ����ָ�����ֵ��ֻ��Ҫ��ָ��Ϳ�����
*/
{
	bubble_sort(link, ascending);
}
