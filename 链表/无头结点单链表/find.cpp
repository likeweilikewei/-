#include"link.h"

//using namespace std;

find_result find(Node* link, int value)
/*
����Ԫ�أ�����pair,first:�Ƿ��ҵ���second:pair,first:ǰһ���ڵ㣬second:��ǰ�ڵ�
*/
{
	find_result result(false, pair<Node*, Node*>(NULL, NULL));
	if (link == NULL)
		return result;

	//��ʱ��һ���ڵ�ʱ��
	if (link->value == value)
	{
		result.first = true;
		result.second.second = link;
		return result;
	}

	while (link->next!=NULL)
	{
		if (link->next->value == value)
		{
			break;
		}
		link = link->next;
	}
	//��û���ҵ���ʱ��
	if (link->next == NULL)
	{
		return result;
	}
	//�ҵ����Ҳ��ǵ�һ���ڵ��ʱ��
	else
	{
			result.first = true;
			result.second.first = link;
			result.second.second = link->next;
			return result;
	}
}