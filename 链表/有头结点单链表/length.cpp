#include"head_link.h"

using namespace std;

#ifndef NULL
#define NULL 0
#endif

int length_list(Node* link)
/*
�������ȣ�ͷ��㲻��������
*/
{
	int len = 0;
	if (NULL == link)
	{
		return 0;
	}
	else
	{
		while (NULL != link->next)
		{
			len++;
			link = link->next;
		}
		return len;
	}
}
