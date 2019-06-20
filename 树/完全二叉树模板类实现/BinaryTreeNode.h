#pragma once
/*��ȫ�������ͽڵ��������Ͷ���*/
#include<iostream>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
	T data_;
	BinaryTreeNode<T>* left_child_, * right_child_;
	
	BinaryTreeNode();
	~BinaryTreeNode();

	//���ƹ��캯��
	BinaryTreeNode(const BinaryTreeNode<T>&);
	//��ֵ�����
	void operator=(const BinaryTreeNode<T>&);

	BinaryTreeNode(T const);
	BinaryTreeNode(const T kData, const BinaryTreeNode<T>* kLeftChild=NULL, const BinaryTreeNode<T>* kRightChild=NULL);

	//��Ԫ����������ߵ�һ���������Ǹö�����������Ҫ����Ԫ����
	friend ostream& operator<<(ostream&, const BinaryTreeNode<T>*);
};


template <typename T>
BinaryTreeNode<T>* copy(const BinaryTreeNode<T>* kOther)
/*
����һ���ڵ㣬�����ӽڵ�Ҳ���п���
*/
{
	if (NULL == kOther)
		return NULL;
	BinaryTreeNode<T> * new_onde = new BinaryTreeNode<T>;
	new_onde->data_ = kOther->data_;
	new_onde->left_child_ = copy(kOther->left_child_);
	new_onde->right_child_ = copy(kOther->right_child_);
	return new_onde;
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode():left_child_(NULL),right_child_(NULL)
{
}

template<typename T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T kData) :data_(kData), left_child_(NULL), right_child_(NULL)
{
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T kData, const BinaryTreeNode<T> * kLeftChild, const BinaryTreeNode<T> * kRightChild) : data_(kData), left_child_(kLeftChild), right_child_(kRightChild)
{
}

//���ƹ��캯��
template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T> & kOther)
{
	if (this == &kOther)
		return;

	data_ = kOther.data_;
	//����ָ��������Ҫ��ƣ���Ȼ�ͷ�һ�������������һ�������ָ������
	//��������
	if (NULL == kOther.left_child_)
	{
		left_child_ = NULL;
	}
	else
	{
		left_child_ = copy(kOther.left_child_);
	}

	//�����Һ���
	if (NULL == kOther.right_child_)
	{
		right_child_ = NULL;
	}
	else
	{
		right_child_ = copy(kOther.right_child_);
	}
}

//��ֵ�����
template <typename T>
void BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> & kOther)
{
	if (this == &kOther)
		return *this;
	data_ = kOther.data_;
	//����ָ��������Ҫ��ƣ���Ȼ�ͷ�һ�������������һ�������ָ������
	//��������
	if (NULL == kOther.left_child_)
	{
		left_child_ = NULL;
	}
	else
	{
		left_child_ = copy(kOther.left_child_);
	}

	//�����Һ���
	if (NULL == kOther.right_child_)
	{
		right_child_ = NULL;
	}
	else
	{
		right_child_ = copy(kOther.right_child_);
	}
}

template <typename T>
ostream& operator<<(ostream & out, const BinaryTreeNode<T> * binary_node)
{
	out << "the node data is:" << binary_node->data_ << endl;
	return out;
}