#pragma once
/*完全二叉树就节点类声明和定义*/
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

	//复制构造函数
	BinaryTreeNode(const BinaryTreeNode<T>&);
	//赋值运算符
	void operator=(const BinaryTreeNode<T>&);

	BinaryTreeNode(T const);
	BinaryTreeNode(const T kData, const BinaryTreeNode<T>* kLeftChild=NULL, const BinaryTreeNode<T>* kRightChild=NULL);

	//二元运算符、或者第一个参数不是该对象的运算符需要用友元函数
	friend ostream& operator<<(ostream&, const BinaryTreeNode<T>*);
};


template <typename T>
BinaryTreeNode<T>* copy(const BinaryTreeNode<T>* kOther)
/*
拷贝一个节点，并对子节点也进行拷贝
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

//复制构造函数
template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const BinaryTreeNode<T> & kOther)
{
	if (this == &kOther)
		return;

	data_ = kOther.data_;
	//对于指针数据需要深复制，不然释放一个对象后会造成另一个对象的指针悬浮
	//拷贝左孩子
	if (NULL == kOther.left_child_)
	{
		left_child_ = NULL;
	}
	else
	{
		left_child_ = copy(kOther.left_child_);
	}

	//拷贝右孩子
	if (NULL == kOther.right_child_)
	{
		right_child_ = NULL;
	}
	else
	{
		right_child_ = copy(kOther.right_child_);
	}
}

//赋值运算符
template <typename T>
void BinaryTreeNode<T>::operator=(const BinaryTreeNode<T> & kOther)
{
	if (this == &kOther)
		return *this;
	data_ = kOther.data_;
	//对于指针数据需要深复制，不然释放一个对象后会造成另一个对象的指针悬浮
	//拷贝左孩子
	if (NULL == kOther.left_child_)
	{
		left_child_ = NULL;
	}
	else
	{
		left_child_ = copy(kOther.left_child_);
	}

	//拷贝右孩子
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