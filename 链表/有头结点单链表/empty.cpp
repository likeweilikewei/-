#include"head_link.h"

using namespace std;

#ifndef NULL
#define NULL 0
#endif

bool is_emptys(Node* link)
/*
�ж��Ƿ�Ϊ��
*/
{
	if (NULL == link || link->next == NULL)
		return true;
	else
		return false;
}
