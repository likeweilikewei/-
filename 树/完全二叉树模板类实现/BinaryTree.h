#pragma once
/*��ȫ��������������ʵ�֣�ģ�����������ʵ��Ӧ�÷���.h�ļ��������������Ϊģ����ֻ�����õ���ʱ��ʵ����*/

#include<iostream>
#include<queue>
#include<stack>
#include<iomanip>
#include<vector>
#include "BinaryTreeNode.h"

using namespace std;

template <typename T>
class BinaryTree
{
public:
	void show();
	BinaryTree();
	~BinaryTree();
	//������ȫ������
	void Destroy(BinaryTreeNode<T>*tree_node);
	//�õ����ڵ�,��ȡ�������С����������ʹ��Сд���»��ߣ�������ʱ������Ǻ�
	BinaryTreeNode<T>* get_root();
	//���ø��ڵ�
	void set_root(BinaryTreeNode<T>*root);

	//����������,Ĭ�ϵݹ��ǰ�����
	void Traversal(BinaryTreeNode<T>* tree_root,string order_type="preorder",int recursion_flag=1);

	//�ݹ�ǰ�����������
	void RecursionPreorderTraversal(BinaryTreeNode<T>* tree_root);
	//�ݹ��������������
	void RecursionInorderTraversal(BinaryTreeNode<T>* tree_root);
	//�ݹ�������������
	void RecursionPostorderTraversal(BinaryTreeNode<T>* tree_root);

	//�ǵݹ�ǰ�����������
	void NonRecursionPreorderTraversal(BinaryTreeNode<T>* tree_root);
	//�ǵݹ��������������
	void NonRecursionInorderTraversal(BinaryTreeNode<T>* tree_root);
	//�ǵݹ�������������
	void NonRecursionPostorderTraversal(BinaryTreeNode<T>* tree_root);

	//�������������
	void LevelorderTraversal(BinaryTreeNode<T>* tree_root);

	//�ֶ�ָ����������ǰ������ȫ������
	BinaryTreeNode<T>* ManualPreorderConstruct();
	//�ֶ�ָ������������������ȫ������
	BinaryTreeNode<T>* ManualInorderConstruct();
	//�ֶ�ָ������������������ȫ������
	BinaryTreeNode<T>* ManualPostorderConstruct();

	//�Զ��������ݽ�����ȫ������
	void LevelorderConstruct();
	//���ݲ���������ݽ���������
	template <typename I>
	static BinaryTreeNode<T>* LevelorderDatasConstruct(const I& datas);

	//����ǰ���������ݣ�Ȼ����ǰ����������ݽ�����ȫ������
	void PreorderInorderConstruct();
	//��ǰ����������ݽ�����ȫ������
	static BinaryTreeNode<T>* PreorderInorderDatasConstruct(T*pre,T*in,int n);

	//��������ͺ������ݣ����ó�����������
	void InorderPostorderConstruct();
	//������ͺ������ݽ���������
	static BinaryTreeNode<T>* InorderPostorderDatasConstruct(T* post, T* in, int n);

	//��ջ�����
	static void flush_buffer(istream&);

	//�ж����Ƿ�Ϊ��
	bool IsEmpty(BinaryTreeNode<T>* tree_root);
	//����ͷ�������
	void VistNode(BinaryTreeNode<T>* tree_root);
	//�õ����ڵ�
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* tree_root, BinaryTreeNode<T>* tree_node);
	//�õ�����
	BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T>* tree_node);
	//�õ��Һ���
	BinaryTreeNode<T>* RightChild(BinaryTreeNode<T>* tree_node);
	//�õ��ڵ���
	int Size(BinaryTreeNode<T>* tree_root);
	//�õ��ڵ�ĸ߶�
	int Height(BinaryTreeNode<T>* tree_node);
	//�õ����ĸ߶�
	int HeightTree();
	//�õ��ڵ�����
	int Depth(BinaryTreeNode<T>* tree_node);
	//�õ��������
	int DepthTree();

private:
	BinaryTreeNode<T>* root_;
};


template <typename T>
BinaryTree<T>::BinaryTree()
{
	root_ = NULL;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	Destroy(root_);
}

template <typename T>
void BinaryTree<T>::show()
{
	cout << "hello" << endl;
}

template <typename T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T>* tree_node)
/*ɾ��������*/
{
	if (NULL == tree_node)
		return;
	//ɾ����ʱ������ú���ɾ��
	Destroy(tree_node->left_child_);
	Destroy(tree_node->right_child_);
	delete tree_node;
	tree_node = NULL;
}

template <typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::get_root()
/*ȡ�����ڵ�*/
{
	return root_;
}

template <typename T>
inline void BinaryTree<T>::set_root(BinaryTreeNode<T>* root)
/*���ø��ڵ�*/
{
	if (root_ == root)
		return;
	root_ = root;
}

template <typename T>
void BinaryTree<T>::Traversal(BinaryTreeNode<T> * tree_root, string order_type, int recursion_flag)
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

template <typename T>
void BinaryTree<T>::RecursionPreorderTraversal(BinaryTreeNode<T> * tree_root)
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

template <typename T>
void BinaryTree<T>::RecursionInorderTraversal(BinaryTreeNode<T> * tree_root)
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

template <typename T>
void BinaryTree<T>::RecursionPostorderTraversal(BinaryTreeNode<T> * tree_root)
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

template <typename T>
void BinaryTree<T>::NonRecursionPreorderTraversal(BinaryTreeNode<T> * tree_root)
/*�ǵݹ�ǰ�������ȫ������*/
{
	if (tree_root == NULL)
	{
		return;
	}
	
	//�ݴ���
	stack<BinaryTreeNode<T>*> nodes;
	//��ʱ���
	BinaryTreeNode<T>* tmp_node;

	tmp_node = tree_root;

	//���׽ڵ㲻Ϊ���ܽ�ȥ
	while (tmp_node||!nodes.empty())
	{
		//�ȱ����ýڵ������
		while (NULL != tmp_node)
		{
			nodes.push(tmp_node);
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->left_child_;
		}

		//���ڵ�����Ϊ��ʱ�����Һ���
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			tmp_node = tmp_node->right_child_;
			nodes.pop();
		}
	}
}

template <typename T>
void BinaryTree<T>::NonRecursionInorderTraversal(BinaryTreeNode<T> * tree_root)
/*�ǵݹ��������������*/
{
	if (tree_root == NULL)
	{
		return;
	}

	//�ݴ���
	stack<BinaryTreeNode<T>*> nodes;
	//��ʱ���
	BinaryTreeNode<T>* tmp_node;

	tmp_node = tree_root;

	//���׽ڵ㲻Ϊ���ܽ�ȥ
	while (tmp_node || !nodes.empty())
	{
		//�ȱ����ýڵ������
		while (NULL != tmp_node)
		{
			nodes.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//���ڵ�����Ϊ��ʱ�����Һ���
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->right_child_;
			nodes.pop();
		}
	}
}

template <typename T>
void BinaryTree<T>::NonRecursionPostorderTraversal(BinaryTreeNode<T> * tree_root)
/*�ǵݹ�������������*/
{
	if (tree_root == NULL)
	{
		return;
	}

	//�ݴ���
	stack<BinaryTreeNode<T>*> nodes;
	//��ʱ���
	BinaryTreeNode<T>* tmp_node;
	BinaryTreeNode<T>* last_visit_node;

	tmp_node = tree_root;
	last_visit_node = tree_root;

	//���׽ڵ㲻Ϊ���ܽ�ȥ
	while (tmp_node || !nodes.empty())
	{
		//�ȱ����ýڵ������
		while (NULL != tmp_node)
		{
			nodes.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//���ڵ�����Ϊ��ʱ�����Һ���
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
		}

		//���Һ���Ϊ�ջ����Һ��ӷ��ʹ����������ǰ�ڵ�
		if (tmp_node->right_child_ == NULL|| last_visit_node==tmp_node->right_child_)
		{
			cout << setw(5) << tmp_node->data_;
			nodes.pop();
			last_visit_node = tmp_node;
			tmp_node = NULL;
		}
		else 
		{
			tmp_node = tmp_node->right_child_;
		}
	}
}

template<typename T>
void BinaryTree<T>::LevelorderTraversal(BinaryTreeNode<T>* tree_root)
/*�������������*/
{
	if (tree_root == NULL)
	{
		return;
	}

	queue<BinaryTreeNode<T>*>nodes;
	BinaryTreeNode<T>* tmp_node;
	nodes.push(tree_root);

	//�Ƚ��ȳ����������ڵ�
	while (!nodes.empty())
	{
		tmp_node = nodes.front();
		nodes.pop();
		cout << setw(5) << tmp_node->data_;
		if (NULL != tmp_node->left_child_)
			nodes.push(tmp_node->left_child_);
		if (NULL != tmp_node->right_child_)
			nodes.push(tmp_node->right_child_);
	}
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::ManualPreorderConstruct()
/*�ֶ�ָ��������������0��β��ǰ������ȫ������*/
{
	cout << "start preorder construct binary tree,input 0 to end." << endl;
	T data;
	cin >> data;
	if (0 == data || '0' == data)
		return NULL;
	BinaryTreeNode<T>* new_root = new BinaryTreeNode<T>;
	if (NULL == new_root)
		throw "new node failed";
	new_root->data_ = data;
	cout << "������" << data << "�����ӣ�" << endl;
	new_root->left_child_ = ManualPreorderConstruct();
	cout << "������" << data << "���Һ��ӣ�" << endl;
	new_root->right_child_ = ManualPreorderConstruct();

	//���������
	flush_buffer(cin);

	return new_root;
}

template <typename T>
BinaryTreeNode<T> * BinaryTree<T>::ManualInorderConstruct()
/*�ֶ�ָ��������������0��β����������ȫ������,����������ǰ�򣬵��ǽ���������*/
{
	cout << "start inorder construct binary tree,input 0 to end." << endl;
	T data;
	cin >> data;
	if (0 == data || '0' == data)
		return NULL;
	BinaryTreeNode<T>* new_root = new BinaryTreeNode<T>;
	if (NULL == new_root)
		throw "new node failed";
	cout << "������" << data << "�����ӣ�" << endl;
	new_root->left_child_ = ManualInorderConstruct();
	new_root->data_ = data;
	cout << "������" << data << "���Һ��ӣ�" << endl;
	new_root->right_child_ = ManualInorderConstruct();

	//���������
	flush_buffer(cin);

	return new_root;
}

template <typename T>
BinaryTreeNode<T> * BinaryTree<T>::ManualPostorderConstruct()
/*�ֶ�ָ��������������0��β����������ȫ��������������ǰ�򣬸�ֵ�����Ǻ���*/
{
	cout << "start postorder construct binary tree,input 0 to end." << endl;
	T data;
	cin >> data;
	if (0 == data || '0' == data)
		return NULL;
	BinaryTreeNode<T>* new_root = new BinaryTreeNode<T>;
	if (NULL == new_root)
		throw "new node failed";
	cout << "������" << data << "�����ӣ�" << endl;
	new_root->left_child_ = ManualPostorderConstruct();
	cout << "������" << data << "���Һ��ӣ�" << endl;
	new_root->right_child_ = ManualPostorderConstruct();
	new_root->data_ = data;

	//���������
	flush_buffer(cin);

	return new_root;
}

template<typename T>
void BinaryTree<T>::LevelorderConstruct()
/*�������뽨����ȫ������*/
{
	T data;
	vector<T> datas;

	cout << "start levelorder construct binary tree." << endl;
	cout << "please input datas,0 to quit." << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		datas.push_back(data);
	}

	//���������
	flush_buffer(cin);

	root_ = LevelorderDatasConstruct(datas);
	//cout << "root:" << root_->data_ << endl;
}

template<typename T>
inline void BinaryTree<T>::PreorderInorderConstruct()
/*����ǰ����������ݣ�������ȫ������*/
{
	T data;
	vector<T>preorder_datas;

	cout << "start preorder and inorderd datas to construct tree." << endl;
	cout << "please input preorder datas,0 to quit." << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		preorder_datas.push_back(data);
	}
	if (preorder_datas.empty())
	{
		cout << "no input data,exit." << endl;
		return;
	}

	//���������
	flush_buffer(cin);
	
	//��������ݣ������������ݵ������飬Ϊ��֮�������������㷽��
	int n = preorder_datas.size();
	T* preorder_datas_array = new T[n];
	T* inorder_datas_array = new T[n];

	int i;
	cout << "please input inorder datas.numbers:" << n << endl;
	for (i = 0; i < n; ++i)
	{
		preorder_datas_array[i] = preorder_datas[i];
		cin >> data;
		inorder_datas_array[i] = data;
	}

	//����ǰ����������������ĳ���
	//for (i = 0; i < n; i++)
	//{
	//	cout << preorder_datas_array[i] << " " << inorder_datas_array[i] << endl;
	//}
	root_ = PreorderInorderDatasConstruct(preorder_datas_array, inorder_datas_array, n);
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::PreorderInorderDatasConstruct(T* pre, T* in, int n)
/*��ǰ����������ݽ�����ȫ������*/
{
	if (n == 0)
		return NULL;
	
	//�õ���n�����ݲ��ֵĸ���k������߲�����k������
	int k=0;
	while (pre[0] != in[k])
		k++;

	BinaryTreeNode<T>* node = new BinaryTreeNode<T>;
	node->data_ = pre[0];
	node->left_child_ = PreorderInorderDatasConstruct(pre + 1, in, k);
	node->right_child_ = PreorderInorderDatasConstruct(pre + k + 1, in + k + 1, n - k - 1);
	return node;
}

template<typename T>
void BinaryTree<T>::InorderPostorderConstruct()
/*��������ͺ������ݽ���������*/
{
	T data;
	vector<T>postorder_datas;

	cout << "start postorder and inorderd datas to construct tree." << endl;
	cout << "please input postorder datas,0 to quit." << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		postorder_datas.push_back(data);
	}
	if (postorder_datas.empty())
	{
		cout << "no input data,exit." << endl;
		return;
	}

	//���������
	flush_buffer(cin);

	//��������ݣ������������ݵ������飬Ϊ��֮�������������㷽��
	int n = postorder_datas.size();
	T* postorder_datas_array = new T[n];
	T* inorder_datas_array = new T[n];

	int i,j,tmp_data;
	cout << "please input inorder datas.numbers:" << n << endl;
	for (i = 0; i < n; ++i)
	{
		postorder_datas_array[i] = postorder_datas[i];
		cin >> data;
		inorder_datas_array[i] = data;
	}

	//�Ƚ��������ݷ�ת�������
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp_data = postorder_datas_array[i];
		postorder_datas_array[i] = postorder_datas_array[j];
		postorder_datas_array[j] = tmp_data;
	}
	//����ǰ����������������ĳ���
	//for (i = 0; i < n; i++)
	//{
	//	cout << postorder_datas_array[i] << " " << inorder_datas_array[i] << endl;
	//}

	root_ = InorderPostorderDatasConstruct(postorder_datas_array,inorder_datas_array,n);
}

template<typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::InorderPostorderDatasConstruct(T* post, T* in, int n)
/*������ͺ������ݽ���������*/
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (post[0] != in[k])
		k++;

	//������ǰ���ֵĸ��ڵ�
	BinaryTreeNode<T>* node = new BinaryTreeNode<T>;
	node->data_ = post[0];
	//���Ӵ���Ӧ���ֿ�ʼ
	node->left_child_ = InorderPostorderDatasConstruct(post+n-k, in, k);
	node->right_child_ = InorderPostorderDatasConstruct(post+1,in+k+1,n-k-1);
	return node;
}

template<typename T>
inline void BinaryTree<T>::flush_buffer(istream&in)
/*��ջ�����*/
{
	in.clear();
	while (in.get() != '\n')
		continue;
}

template<typename T>
inline bool BinaryTree<T>::IsEmpty(BinaryTreeNode<T>* tree_root)
/*�ж����Ƿ�Ϊ��*/
{
	return NULL==tree_root;
}

template<typename T>
inline void BinaryTree<T>::VistNode(BinaryTreeNode<T>* tree_root)
/*���ʽڵ�����*/
{
	if (NULL == tree_root)
	{
		cout << "the node is empty." << endl;
		return;
	}
	cout << setw(5) << tree_root->data_ << endl;
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* tree_root, BinaryTreeNode<T>* tree_node)
/*�õ����ڵ�*/
{
	if (tree_root == NULL || tree_node == NULL || tree_root == tree_node)
		return NULL;

	queue<BinaryTreeNode<T>*>nodes;
	BinaryTreeNode<T>* node;
	nodes.push(tree_root);
	while (!nodes.empty())
	{
		node = nodes.front();
		nodes.pop();
		if (node->left_child_ == tree_node || node->right_child_ == tree_node)
			return node;
		if (node->left_child_ != NULL)
			nodes.push(node->left_child_);
		if (node->right_child_ != NULL)
			nodes.push(node->right_child_);
	}
	return NULL;
}

template<typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::LeftChild(BinaryTreeNode<T>* tree_node)
/*�õ��ڵ������*/
{
	if (NULL == tree_node || tree_node->left_child_ == NULL)
		return NULL;
	return tree_node->left_child_;
}

template<typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::RightChild(BinaryTreeNode<T>* tree_node)
/*�õ��ڵ���Һ���*/
{
	if (NULL == tree_node || tree_node->right_child_ == NULL)
		return NULL;
	return tree_node->right_child_;
}

template<typename T>
int BinaryTree<T>::Size(BinaryTreeNode<T>* tree_root)
/*�õ��ڵ���*/
{
	int count = 0;
	if (tree_root != NULL)
	{
		count++;
		count += Size(tree_root->left_child_);
		count += Size(tree_root->right_child_);
	}
	return count;
}

template<typename T>
int BinaryTree<T>::Height(BinaryTreeNode<T>* tree_node)
/*�õ��ڵ�ĸ߶ȣ�Ҷ�ӵ�߶�Ϊ0���������ε���*/
{
	if (tree_node == NULL||tree_node->left_child_==NULL)
		return 0;
	return 1 + max(Height(tree_node->left_child_), Height(tree_node->right_child_));
}

template<typename T>
int BinaryTree<T>::HeightTree()
/*�õ����ĸ߶�*/
{
	return Height(root_);
}

template<typename T>
int BinaryTree<T>::Depth(BinaryTreeNode<T>* tree_node)
/*�õ��ڵ����ȣ����ڵ����Ϊ0*/
{
	if(tree_node==NULL||tree_node==root_)
		return 0;
	return 1 + Depth(Parent(root_,tree_node));
}

template<typename T>
int BinaryTree<T>::DepthTree()
/*�õ��������*/
{
	if (NULL == root_)
		return 0;
	BinaryTreeNode<T>* node = root_;
	queue<BinaryTreeNode<T>*>nodes;
	int count = 0;
	int tmp_count = 0;

	nodes.push(node);
	while (!nodes.empty())
	{
		node = nodes.front();
		nodes.pop();
		if (node->left_child_ == NULL && node->right_child_ == NULL)
		{
			tmp_count = Depth(node);
			if (count < tmp_count)
				count = tmp_count;
		}

		//�������ҽڵ������
		if (NULL != node->left_child_)
			nodes.push(node->left_child_);
		if (NULL != node->right_child_)
			nodes.push(node->right_child_);
	}
	return count;
}

template<typename T>
template<typename I>
inline BinaryTreeNode<T>* BinaryTree<T>::LevelorderDatasConstruct(const I& datas)
/*�������ݽ�����ȫ������*/
{
	if (datas.begin() == datas.end())
		return NULL;

	//�����Žڵ����ݵ�����
	typename I::const_iterator iter = datas.begin();
	//�������Žڵ�Ķ���
	queue<BinaryTreeNode<T>*>nodes;
	//���ڵ�
	BinaryTreeNode<T>* root;
	//��ʱ�ڵ�
	BinaryTreeNode<T>* tmp_node;

	//ȡ����ֵ
	T data_tmp;
	try
	{
		data_tmp = *iter++;
	}
	catch (...)
	{
		throw "data in datas is not type of T.";
	}

	//��ʼ����������
	//cout << "data tmp" << data_tmp << endl;
	root = new BinaryTreeNode<T>;
	root->data_ = data_tmp;
	nodes.push(root);

	while (!nodes.empty())
	{
		tmp_node = nodes.front();
		nodes.pop();
		//��������
		if (NULL==tmp_node->left_child_&&iter!=datas.end())
		{
			tmp_node->left_child_ = new BinaryTreeNode<T>;
			tmp_node->left_child_->data_ = *iter++;
			nodes.push(tmp_node->left_child_);
		}
		//�����Һ���
		if (NULL==tmp_node->right_child_ && iter != datas.end())
		{
			tmp_node->right_child_ = new BinaryTreeNode<T>;
			tmp_node->right_child_->data_ = *iter++;
			nodes.push(tmp_node->right_child_);
		}
	}
	
	//cout << "root.data:" << root->data_ << endl;
	return root;
}
