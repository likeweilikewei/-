#pragma once

template <typename T>
class BinarySearchTreeNode
/*����������ڵ�*/
{
public:
	T data_;
	BinarySearchTreeNode<T>* left_child_, * right_child_;

	BinarySearchTreeNode();
	~BinarySearchTreeNode();
};


template <typename T>
BinarySearchTreeNode<T>::BinarySearchTreeNode():left_child_(NULL),right_child_(NULL)
{
}


template <typename T>
BinarySearchTreeNode<T>::~BinarySearchTreeNode()
{
}
