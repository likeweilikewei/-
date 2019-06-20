#pragma once
#include<vector>
#include"parents_child_link_tree_node.h"

using namespace std;

template <typename T>
class ParentsChildLinkTree
{
public:
	ParentsChildLinkTree();
	~ParentsChildLinkTree();
public:
	//添加节点
	void AppendNode(T data,int parent);
	//显示节点信息
	void Show();
private:
	//保存树
	vector<ParentsChildLinkNode<T>>tree_;
};

template<typename T>
inline ParentsChildLinkTree<T>::ParentsChildLinkTree()
{
}

template<typename T>
inline ParentsChildLinkTree<T>::~ParentsChildLinkTree()
{
	for (int i = 0; i < tree_.size(); i++)
	{
		ParentsChildLinkChild* child = tree_[i].first_child_;
		ParentsChildLinkChild* delete_child = child;
		while (child)
		{
			delete_child = child;
			child = child->next_;
			delete delete_child;
			delete_child = nullptr;
		}
	}
}

template<typename T>
inline void ParentsChildLinkTree<T>::AppendNode(T data, int parent)
{
	//如果树为空，parent只能是-1
	if (tree_.empty())
	{
		if (parent != -1)
		{
			cout << "empty tree parent is not -1." << endl;
			return;
		}
	}
	else if (parent < 0 || parent >= tree_.size())
	{
		cout << "parent is not right." << endl;
		return;
	}

	//添加本节点
	ParentsChildLinkNode<T>new_node(data,parent);
	tree_.push_back(new_node);
	//如果是第一个节点则不需要添加父节点孩子信息
	if (parent == -1)
		return;

	//生成孩子节点
	ParentsChildLinkChild* new_child = new ParentsChildLinkChild(tree_.size() - 1);
	//往父节点后添加本节点为孩子节点
	ParentsChildLinkChild* child = tree_[parent].first_child_;

	//如果孩子链表为空则直接添加新节点指针即可
	if (child == nullptr)
		tree_[parent].first_child_ = new_child;
	else
	{
		while (child->next_!=nullptr)
		{
			child = child->next_;
		}
		//添加节点
		child->next_ = new_child;
	}

}

template<typename T>
inline void ParentsChildLinkTree<T>::Show()
/*显示节点信息*/
{
	if (tree_.empty())
	{
		cout << "tree is empty." << endl;
		return;
	}

	int i = 0;
	for (; i < tree_.size(); i++)
	{
		cout << "index: " << setw(5) << i << " data: " << setw(5) << tree_[i].data_ << " parent: " << tree_[i].parent_ << " child: ";
		ParentsChildLinkChild* child = tree_[i].first_child_;
		while (child != nullptr)
		{
			cout << setw(5) << child->index_;
			child = child->next_;
		}
		cout << endl;
	}
}
