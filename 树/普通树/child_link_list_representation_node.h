#pragma once
/*孩子表示法中的孩子链表表示法

孩子链表法是将树按如图7.5 所示的形式存储。其主体是一个与结点个数一样大小的一维数组，
数组的每一个元素有两个域组成，一个域用来存放结点信息，另一个用来存放指针，
该指针指向由该结点孩子组成的单链表的首位置。单链表的结构也由两个域组成，
一个存放孩子结点在一维数组中的序号，另一个是指针域，指向下一个孩子。

在孩子表示法中查找双亲比较困难，查找孩子却十分方便，故适用于对孩子操作多的应用。
*/

template <typename T>
class ChildLinkRepresentationChild
/*孩子链表表示法孩子节点*/
{
public:
	ChildLinkRepresentationChild(int index=-1, ChildLinkRepresentationChild<T>* next=nullptr):index_(index),next_(next){}
	~ChildLinkRepresentationChild();
public:
	//树中该节点的下标索引
	int index_;
	//节点的兄弟
	ChildLinkRepresentationChild<T>* next_;
};

template <typename T>
class ChildLinkRepresentationNode
/*孩子链表表示法树节点*/
{
public:
	ChildLinkRepresentationNode();
	~ChildLinkRepresentationNode();
	ChildLinkRepresentationNode(T data,ChildLinkRepresentationChild<T>*first_child=nullptr):data_(data),first_child_(first_child){}
public:
	//节点值
	T data_;
	//节点第一个孩子
	ChildLinkRepresentationChild<T>* first_child_;
};

template<typename T>
inline ChildLinkRepresentationChild<T>::~ChildLinkRepresentationChild()
{
}

template<typename T>
inline ChildLinkRepresentationNode<T>::ChildLinkRepresentationNode()
{
	first_child_ = nullptr;
}

template<typename T>
inline ChildLinkRepresentationNode<T>::~ChildLinkRepresentationNode()
{
}
