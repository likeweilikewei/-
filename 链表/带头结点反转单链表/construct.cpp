#include"head_link.h"

NODE construct()
{
	NODE head = new Node;
	//�����α�ʹ��
	NODE current = head;
	if (NULL == head)
	{
		cout << "new Node failed." << endl;
		exit(-1);
	}
	current->next = NULL;

	//��������
	cout << "please input list value.q to quit." << endl;
	int value;
	while (cin >> value)
	{
		NODE tmp_node = new Node;
		if (NULL == tmp_node)
		{
			cout << "new Node failed." << endl;
			exit(-1);
		}
		tmp_node->next = NULL;
		tmp_node->value = value;
		current->next = tmp_node;
		current = tmp_node;
	}
	return head;
}
