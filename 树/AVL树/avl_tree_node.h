#pragma once

/*avl树的节点*/

template <typename T>
class AvlTreeNode
{
public:
	T data_;
	//节点高度为左右孩子最大高度+1，叶子节点高度定为1
	int height_;
	AvlTreeNode<T>* left_child_, * right_child_;

	AvlTreeNode();
	AvlTreeNode(const T kData, const int kHeight = 1, AvlTreeNode<T>* kLeftChild = nullptr, AvlTreeNode<T>* kRightChild = nullptr);
	~AvlTreeNode();
};

template<typename T>
inline AvlTreeNode<T>::AvlTreeNode(const T kData, const int kHeight, AvlTreeNode<T>* kLeftChild, AvlTreeNode<T>* kRightChild):data_(kData),height_(kHeight),left_child_(kLeftChild),right_child_(kRightChild)
{
}

template<typename T>
inline AvlTreeNode<T>::~AvlTreeNode()
{
}

template<typename T>
inline AvlTreeNode<T>::AvlTreeNode() :left_child_(nullptr), right_child_(nullptr), height_(1)
{
}
