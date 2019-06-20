#pragma once

/*avl���Ľڵ�*/

template <typename T>
class AvlTreeNode
{
public:
	T data_;
	//�ڵ�߶�Ϊ���Һ������߶�+1��Ҷ�ӽڵ�߶ȶ�Ϊ1
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
