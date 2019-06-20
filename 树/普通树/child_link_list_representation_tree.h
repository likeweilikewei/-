#pragma once

#include<vector>
#include<iomanip>
#include<iostream>
#include"child_link_list_representation_node.h"

using namespace std;

template <typename T>
class ChildLinkRepresentationTree
/*孩子链表表示法树*/
{
public:
	ChildLinkRepresentationTree();
	~ChildLinkRepresentationTree();
public:
	bool AppendNode(T data, int parent);
	//显示所有树节点信息
	void Show();
private:
	vector<ChildLinkRepresentationNode<T>>tree_;
};

template<typename T>
ChildLinkRepresentationTree<T>::ChildLinkRepresentationTree()
{
}

template<typename T>
ChildLinkRepresentationTree<T>::~ChildLinkRepresentationTree()
{
}

template<typename T>
inline bool ChildLinkRepresentationTree<T>::AppendNode(T data, int parent)
/*添加节点*/
{
	if(parent < -1 || parent >= (int)tree_.size())
		return false;
	ChildLinkRepresentationNode<T>new_node(data);
	tree_.push_back(new_node);
	cout << "parent:" << parent << endl;
	if (parent != -1)
	{
		ChildLinkRepresentationChild<T>* child = tree_[parent].first_child_;
		//新孩子
		ChildLinkRepresentationChild<T>* new_child = new ChildLinkRepresentationChild<T>(tree_.size()-1);
		if (child == nullptr)
			tree_[parent].first_child_ = new_child;
		else {
			while (child->next_ != nullptr)
				child = child->next_;
			//将新孩子对接在节点的孩子链表后面
			child->next_ = new_child;
		}
	}
	return true;
}

template<typename T>
inline void ChildLinkRepresentationTree<T>::Show()
/*显示孩子链表表示法的节点信息*/
{
	if (tree_.empty())
		return;
	int i = 0;
	for (i = 0; i < tree_.size(); i++)
	{
		cout << "tree index:" << setw(2) << i << setw(8) << "  data:" << setw(2) << tree_[i].data_;
		cout << setw(8) << "  child index:";
		ChildLinkRepresentationChild<T>* child = tree_[i].first_child_;
		if (child == nullptr)
			cout << "tree child is empty.";
		while (child != nullptr)
		{
			cout << setw(4) << child->index_;
			child = child->next_;
		}
		cout << endl;
	}
}
