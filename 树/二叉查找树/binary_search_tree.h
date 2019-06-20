#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<iomanip>
#include"binary_search_tree_node.h"

using namespace std;

template <typename T>
struct InputResult {
	//����������ʱ�û�����
	T* datas_array_;
	int datas_len_;
};

template <typename T>
class BinarySearchTree
/*���������*/
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	//ɾ����
	void DestroyTree();
	//ɾ���ڵ�
	void Destroy(BinarySearchTreeNode<T>**tree_node_link);
	//���ҽڵ�
	static bool Search(BinarySearchTreeNode<T>* tree_root, T search_data, BinarySearchTreeNode<T>* &searched_node);
	//���Ҹ��ڵ�
	BinarySearchTreeNode<T>* get_root();
	//���Ҹ��ڵ��ָ�룬֮����ȡָ����Ϊ�˵õ�ԭʼ�����ڵ㣬����ʵʱ�޸�ָ��ָ��
	//������Ļ����ص���һ����ֵ���޷����ǳ������ø�ֵ,Ҳ���޷��޸�ָ��ָ��
	BinarySearchTreeNode<T>** get_root_link();
	//���ø��ڵ�
	void set_root(BinarySearchTreeNode<T>* root);
	//����ڵ�
	static bool Insert(BinarySearchTreeNode<T>* &tree_root, T insert_data);
	//����ڵ㣬�ظ��ڵ�Ҳ���в��룬���뵽�Һ�����
	static bool InsertSort(BinarySearchTreeNode<T>*&tree_root, T insert_data);
	//������������
	void Construct();
	//��������ͬԪ�صĶ������������ͬԪ����Ϊ�Һ��Ӳ��룬�����������������򣬲������ȶ�������ʱ�临�Ӷ�Ϊnlogn
	void ConstructSortTree();
	//ɾ���ڵ�
	bool Delete(BinarySearchTreeNode<T>* &tree_root,int delete_data);

	//����������,Ĭ�ϵݹ��ǰ�����
	void Traversal(BinarySearchTreeNode<T>* tree_root, string order_type = "preorder", int recursion_flag = 1);

	//�ݹ�ǰ�����������
	void RecursionPreorderTraversal(BinarySearchTreeNode<T>* tree_root);
	//�ݹ��������������
	void RecursionInorderTraversal(BinarySearchTreeNode<T>* tree_root);
	//�ݹ�������������
	void RecursionPostorderTraversal(BinarySearchTreeNode<T>* tree_root);

	//�ǵݹ�ǰ�����������
	void NonRecursionPreorderTraversal(BinarySearchTreeNode<T>* tree_root);
	//�ǵݹ��������������
	void NonRecursionInorderTraversal(BinarySearchTreeNode<T>* tree_root);
	//�ǵݹ�������������
	void NonRecursionPostorderTraversal(BinarySearchTreeNode<T>* tree_root);

	//�������������
	void LevelorderTraversal(BinarySearchTreeNode<T>* tree_root);

private:
	BinarySearchTreeNode<T>* root_;
	//�þ������ݹ��������
	BinarySearchTreeNode<T>* ConstructByDatas(bool (*pfunc)(BinarySearchTreeNode<T>*&, T),T* datas_array,int data_len);
	//��ջ�����
	void FlushBuffer(istream& in);
	//����ɾ���ڵ�
	void DeleteNode(BinarySearchTreeNode<T>* &tree_node);
	//����������ʱ���û�������
	static InputResult<T> Input();
};

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	root_ = nullptr;
}

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	DestroyTree();
}

template<typename T>
void BinarySearchTree<T>::DestroyTree()
/*ɾ����*/
{
	Destroy(&root_);
}

template<typename T>
void BinarySearchTree<T>::Destroy(BinarySearchTreeNode<T>** tree_node_link)
/*ɾ���ڵ㼰���ӽڵ㣬��Ϊ��Ҫ�ı�ڵ��ָ��Ϊnullptr�����Ҫ����ָ���ָ��*/
{
	if (nullptr == *tree_node_link)
		return;
	Destroy(&((*tree_node_link)->left_child_));
	Destroy(&((*tree_node_link)->right_child_));
	delete *tree_node_link;
	*tree_node_link = nullptr;
}

template <typename T>
bool BinarySearchTree<T>::Search(BinarySearchTreeNode<T>* tree_root, T search_data, BinarySearchTreeNode<T>* &searched_node)
/*�ڶ���������в������ݽڵ㣬tree_root:���ڵ㣬search_data:���ҵ����ݣ�searched_node��������ҵ��Ľڵ㣬û�ҵ��������һ�����ҵĽڵ㣬�������*/
{
	if (tree_root == nullptr)
	{
		searched_node = nullptr;
		return false;
	}

	//���ҵ�ֱ�ӷ���
	if (search_data == tree_root->data_)
	{
		searched_node = tree_root;
		return true;
	}

	//�������ݱȽڵ�ֵС�������Ӳ���
	if (search_data < tree_root->data_)
	{
		//�������Ϊ��ֱ�ӷ���
		if (tree_root->left_child_ == nullptr)
		{
			searched_node = tree_root;
			return false;
		}
		else
			return Search(tree_root->left_child_, search_data, searched_node);
	}
	
	//�������ݱȽڵ�ֵ��������Һ���
	if (search_data > tree_root->data_)
	{
		if (tree_root->right_child_ == nullptr)
		{
			searched_node = tree_root;
			return false;
		}
		else
			return Search(tree_root->right_child_, search_data, searched_node);
	}
}

template <typename T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::get_root()
{
	return root_;
}

template<typename T>
inline BinarySearchTreeNode<T>** BinarySearchTree<T>::get_root_link()
{
	return &root_;
}

template <typename T>
inline void BinarySearchTree<T>::set_root(BinarySearchTreeNode<T>* root)
{
	if (root_ == root)
		return;
	root_ = root;
}

template<typename T>
inline bool BinarySearchTree<T>::Insert(BinarySearchTreeNode<T>* &tree_root, T insert_data)
/*����ڵ㣬����鵽��ֵ�򲻲��룬������뵽��Ӧλ�ã���Ϊ������Ҫ�ı���ڵ�ָ�򣬲���ָ������*/
{
	BinarySearchTreeNode<T>* searched_node=nullptr;
	if (!Search(tree_root, insert_data, searched_node))
	{
		//����û������ڵ���ʼ�������ڵ�
		BinarySearchTreeNode<T>* new_node = new BinarySearchTreeNode<T>;
		if (!new_node)
			throw "new binary node failed.";;
		new_node->data_ = insert_data;

		//��Ϊ��ֱ�Ӳ����½ڵ�
		if (searched_node == nullptr)
		{
			tree_root = new_node;
			return true;
		}

		//����Ϊ��
		else
		{
			//�����������С�������ҵĽڵ����ݣ����������
			if (insert_data < searched_node->data_)
			{
				searched_node->left_child_ = new_node;
				return true;
			}
			if (insert_data > searched_node->data_)
			{
				searched_node->right_child_ = new_node;
				return true;
			}
		}
	}
	return false;
}

template<typename T>
bool BinarySearchTree<T>::InsertSort(BinarySearchTreeNode<T>*&tree_root, T insert_data)
/*������������Ķ�����������Ӷ��ظ��ڵ���Ҫ���룬���Ҳ��뵽�Һ����ϣ��Ӷ����ֲ����㷨���ȶ���*/
{
	//�����½ڵ�
	BinarySearchTreeNode<T>* new_node = new BinarySearchTreeNode<T>;
	if (!new_node)
		throw "new node failed.";
	new_node->data_ = insert_data;

	BinarySearchTreeNode<T>* searched_node=nullptr;
	bool search_flag;

	//���ҵ�ǰֵ�Ƿ�������
	search_flag = Search(tree_root, insert_data, searched_node);
	//����ҵ��Ͳ��뵽�ýڵ���Һ�����
	if (search_flag &&searched_node)
	{
		new_node->right_child_ = searched_node->right_child_;
		searched_node->right_child_ = new_node;
	}

	//���û���ҵ������������뵽����
	else if (!search_flag)
	{
		//��Ϊ��ֱ�Ӳ���
		if (!tree_root)
		{
			tree_root = new_node;
			return true;
		}

		//����Ϊ�գ��������һ�����ҵĽڵ㲻Ϊ������뵽 ��Ӧλ����
		else if (searched_node)
		{
			//���С�����һ�����ҽڵ�Ͳ��뵽������
			if (insert_data < searched_node->data_&&searched_node->left_child_==nullptr)
			{
				searched_node->left_child_ = new_node;
				return true;
			}

			//����Һ���Ϊ�գ����Ҳ���ֵ�������һ���ڵ�ֵ������뵽�Һ�����
			if (insert_data > searched_node->data_ && searched_node->right_child_ == nullptr)
			{
				searched_node->right_child_ = new_node;
				return true;
			}
		}
	}
	return false;
}

template<typename T>
void BinarySearchTree<T>::Construct()
/*������������*/
{
	InputResult<T> input_result = Input();
	//��ʼ�������������
	root_ = ConstructByDatas(Insert,input_result.datas_array_,input_result.datas_len_);
}

template<typename T>
inline void BinarySearchTree<T>::ConstructSortTree()
/*��������Ķ����������������ǿ��Կ��Բ����ظ�Ԫ��*/
{
	InputResult<T> input_result;
	input_result = Input();
	root_=ConstructByDatas(InsertSort, input_result.datas_array_, input_result.datas_len_);
}

template<typename T>
bool BinarySearchTree<T>::Delete(BinarySearchTreeNode<T>*&tree_root, int delete_data)
/*������ɾ���ڵ㣬���ﲻ���ò��ҽڵ�ķ�ʽ����Ϊ�����ɾ�ڵ���û�к��ӵĻ�����Ҫ�ı�ڵ�ָ��ָ��
���������ʱ�ڵ��޷�����,ͬʱ��Ϊ��Ҫ�ݹ�ɾ��������޷��ں��������ʼ��root,��Ҫ����*/
{
	//�����������ʾ��
	//BinarySearchTreeNode<T>*tree_node;
	//if (Search(root_, delete_data, tree_node))
	//{
	//	DeleteNode(tree_node);
	//	return true;
	//}
	//else
	//	return false;

	//�ݹ���ֹ����
	if (nullptr == tree_root)
		return false;

	//����ҵ���ɾ�ڵ���ɾ��
	if (delete_data == tree_root->data_)
	{
		DeleteNode(tree_root);
		return true;
	}

	//���ֵС�ڽڵ�ֵ�����������в���
	if (delete_data < tree_root->data_)
		Delete(tree_root->left_child_,delete_data);
	else
	{
		Delete(tree_root->right_child_, delete_data);
	}
}

template<typename T>
inline void BinarySearchTree<T>::Traversal(BinarySearchTreeNode<T>* tree_root, string order_type, int recursion_flag)
/*����������*/
{
	if (order_type == "preorder" && recursion_flag == 1)
	{
		cout << "start recursion preorder traversal the tree." << endl;
		RecursionPreorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "inorder" && recursion_flag == 1)
	{
		cout << "start recursion inporder traversal the tree." << endl;
		RecursionInorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "postorder" && recursion_flag == 1)
	{
		cout << "start recursion postorder traversal the tree." << endl;
		RecursionPostorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "preorder" && recursion_flag == 0)
	{
		cout << "start non recursion preorder traversal the tree." << endl;
		NonRecursionPreorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "inorder" && recursion_flag == 0)
	{
		cout << "start non recursion inorder traversal the tree." << endl;
		NonRecursionInorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "postorder" && recursion_flag == 0)
	{
		cout << "start non recursion postorder traversal the tree." << endl;
		NonRecursionPostorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "levelorder")
	{
		cout << "start levelorder traversal the tree." << endl;
		LevelorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else {
		cout << "parameter is error,chose default traversal." << endl;
		RecursionPreorderTraversal(tree_root);
		cout << endl;
		return;
	}
}

template<typename T>
inline void BinarySearchTree<T>::RecursionPreorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*�ݹ�ǰ�����������*/
{
	if (tree_root == NULL)
	{
		return;
	}
	cout << setw(5) << tree_root->data_;
	RecursionPreorderTraversal(tree_root->left_child_);
	RecursionPreorderTraversal(tree_root->right_child_);
}

template<typename T>
inline void BinarySearchTree<T>::RecursionInorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*�ݹ��������������*/
{
	if (tree_root == NULL)
	{
		return;
	}
	RecursionInorderTraversal(tree_root->left_child_);
	cout << setw(5) << tree_root->data_;
	RecursionInorderTraversal(tree_root->right_child_);
}

template<typename T>
inline void BinarySearchTree<T>::RecursionPostorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*�ݹ�������������*/
{
	if (tree_root == NULL)
	{
		return;
	}
	RecursionPostorderTraversal(tree_root->left_child_);
	RecursionPostorderTraversal(tree_root->right_child_);
	cout << setw(5) << tree_root->data_;
}

template<typename T>
void BinarySearchTree<T>::NonRecursionPreorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*�ǵݹ�ǰ��������������*/
{
	if (tree_root == nullptr)
		return;

	//�����ӱ��������Ҫ����Һ��ӣ��ö�ջ���游�ڵ���Ϣ
	stack<BinarySearchTreeNode<T>*>nodes_stack;
	BinarySearchTreeNode<T>* tmp_node=tree_root;

	//Ϊ��ͷ����ܽ�ȥ�����˶���
	while (!nodes_stack.empty()||tmp_node)
	{
		//�ȱ�������������
		while (tmp_node != nullptr)
		{
			nodes_stack.push(tmp_node);
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->left_child_;
		}

		//�������굱ǰ���Ӻ󣬴���ǰ�ڵ���Һ���
		if (!nodes_stack.empty())
		{
			tmp_node = nodes_stack.top();
			tmp_node = tmp_node->right_child_;
			nodes_stack.pop();
		}
	}
}

template<typename T>
void BinarySearchTree<T>::NonRecursionInorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*�ǵݹ�����������������*/
{
	if (tree_root == nullptr)
		return;

	//�����ӱ��������Ҫ����Һ��ӣ��ö�ջ���游�ڵ���Ϣ
	stack<BinarySearchTreeNode<T>*>nodes_stack;
	BinarySearchTreeNode<T> * tmp_node = tree_root;

	//Ϊ��ͷ����ܽ�ȥ�����˶���
	while (!nodes_stack.empty() || tmp_node)
	{
		//�ȱ������������ӣ�ʹ��tmp_nodeָ������ߵ�nullptrָ��
		while (tmp_node != nullptr)
		{
			nodes_stack.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//�������굱ǰ���Ӻ󣬴���ǰ�ڵ���Һ���
		if (!nodes_stack.empty())
		{
			//���ȵ�����������ߵĺ��ӣ���Ϊ������ָ��Ϊnull�����ֱ�Ӵ����ڵ�
			tmp_node = nodes_stack.top();
			cout << setw(5) << tmp_node->data_;
			//������󣬴����Һ���
			tmp_node = tmp_node->right_child_;
			nodes_stack.pop();
		}
	}
}

template<typename T>
inline void BinarySearchTree<T>::NonRecursionPostorderTraversal(BinarySearchTreeNode<T>* tree_root)
{
	if (nullptr == tree_root)
		return;

	stack<BinarySearchTreeNode<T>*>nodes_stack;
	BinarySearchTreeNode<T> * tmp_node = tree_root;
	BinarySearchTreeNode<T> * last_visit_node = tree_root;

	while (tmp_node || !nodes_stack.empty())
	{
		while (tmp_node)
		{
			nodes_stack.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		if (!nodes_stack.empty())
			tmp_node = nodes_stack.top();

		if (tmp_node->right_child_ == nullptr || tmp_node->right_child_ == last_visit_node)
		{
			cout << setw(5) << tmp_node->data_;
			last_visit_node = tmp_node;
			nodes_stack.pop();
			tmp_node = nullptr;
		}
		else
		{
			tmp_node=tmp_node->right_child_;
		}
	}
}


template<typename T>
inline void BinarySearchTree<T>::LevelorderTraversal(BinarySearchTreeNode<T>* tree_root)
{

}

template<typename T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::ConstructByDatas(bool (*pfunc)(BinarySearchTreeNode<T>*&, T),T* datas_array, int data_len)
/*�����ݹ�����������*/
{
	if (data_len <= 0)
		return nullptr;

	int i = 0;
	BinarySearchTreeNode<T>* root=nullptr;

	//�������ݹ�����������������Ӧ�Ĳ��뷽�����в���
	for (i = 0; i < data_len; ++i)
	{
		pfunc(root, datas_array[i]);
	}
	return root;
}

template<typename T>
inline void BinarySearchTree<T>::FlushBuffer(istream& in)
/*��ջ�����*/
{
	in.clear();
	while (in.get() != '\n')
		continue;
}

template<typename T>
inline void BinarySearchTree<T>::DeleteNode(BinarySearchTreeNode<T>*& tree_node)
/*������ɾ���ڵ㣬����ѡ��ɾ���ڵ�������������Ľڵ���Ϊ�µľֲ�������Ϊ������Ҫ�ı�ڵ�ָ��ָ�����������*/
{
	BinarySearchTreeNode<T>* tmp_node=nullptr;
	BinarySearchTreeNode<T>* tmp_parent = nullptr;

	if (tree_node == nullptr)
		return;

	//�������Ϊ����ı�ڵ�ָ��ָ��Ϊ�ýڵ��Һ���,���������Һ���Ϊ�յ����,
	//������Ҫ�ı�ָ���ָ�������ʱ���봫��ԭ������ָ��
	if (nullptr == tree_node->left_child_)
	{
		//cout << "yes" << endl;
		//cout << tree_node->data_ << endl;
		tmp_node = tree_node;
		tree_node = tree_node->right_child_;
		//cout << tree_node->data_ << endl;
		delete tmp_node;
		tmp_node = nullptr;
	}

	//����Һ���Ϊ�������¶Խӱ�ɾ�ڵ������
	else if (!tree_node->right_child_)
	{
		tmp_node = tree_node;
		tree_node = tree_node->left_child_;
		delete tmp_node;
		tmp_node = nullptr;
	}

	//������Һ��Ӷ���Ϊ����ȡ�����������Ľڵ���Ϊ�ֲ���
	else
	{
		//�ҵ������������Ľڵ���丸�ڵ㣬����ƴ��������
		tmp_parent = tree_node;
		tmp_node = tree_node->left_child_;
		while (tmp_node->right_child_)
		{
			tmp_parent = tmp_node;
			tmp_node = tmp_node->right_child_;
		}

		//֮���ҵ��Ľڵ�ֵ�滻��ɾ�ڵ㣬ʵ���滻�ڵ�
		tree_node->data_ = tmp_node->data_;

		//������ڵ��Ǳ�ɾ�ڵ�����Ҫ���¶Խ�������
		if (tmp_parent == tree_node)
			tmp_parent->left_child_ = tmp_node->left_child_;
		else
			tmp_parent->right_child_ = tmp_node->left_child_;

		//ɾ���ڵ�
		delete tmp_node;
		tmp_node = nullptr;
	}
}

template<typename T>
inline InputResult<T> BinarySearchTree<T>::Input()
{
	InputResult<T> input_result;
	T data;
	vector<T>datas_vector;

	cout << "start input binary search tree datas,0 to quit." << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		datas_vector.push_back(data);
	}

	//�������е�����ת��Ϊ����
	int datas_len = datas_vector.size();
	int i = 0;
	T* datas_array = new T[datas_len];

	for (i = 0; i < datas_len; ++i)
	{
		datas_array[i] = datas_vector[i];
	}

	//�����ݷ���ṹ����һ�𷵻�
	input_result.datas_array_ = datas_array;
	input_result.datas_len_ = datas_len;
	return input_result;
}
