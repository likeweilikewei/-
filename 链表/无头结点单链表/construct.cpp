#include "link.h"
#include <iostream>

using namespace std;

void construct(Node** head)
/*
������ͷ���汾������
*/
{
	Node* current = *head;
	Node* tmp;
	int value;

	cout << "please input the first value(q to quit)" << endl;
	while (cin >> value)
	{
		tmp = new Node;
		tmp->value = value;
		tmp->next = NULL;
		//���ӵ����ϣ���ǰ�ڵ㲻�վ����ӵ���һ���ڵ���
		if (current != NULL)
			current->next = tmp;
		else
			//��ʵ��ָ������ָ������ĵ�һ���ڵ㣬����
			*head = tmp;
		//���Ϊ�վ�ֱ�Ӹ�ֵ�������Ϊ�յ����Ҳ��Ҫ�������½ڵ�
		current = tmp;
		cout << "please input the next value(q to quit)" << endl;
	}

	//������cin״̬λgood��Ȼ��������뻺����
	cin.clear();
	while (cin.get() != '\n')
		continue;
}
