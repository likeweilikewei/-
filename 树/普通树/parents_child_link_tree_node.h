#pragma once
/*双亲孩子表示法
双亲表示法是将双亲表示法和孩子表示法相结合的结果。其仍将各结点的孩子结点分别组成单链表，
同时用一维数组顺序存储树中的各结点，
数组元素除了包括结点本身的信息和该结点的孩子结点链表的头指针之外，
还增设一个域，存储该结点双亲结点在数组中的序号。

还有一种孩子兄弟表示法

这是一种常用的存储结构。其方法是这样的：在树中，每个结点除其信息域外，
再增加两个分别指向该结点的第一个孩子结点和下一个兄弟结点的指针。
在这种存储结构下，树中结点的存储表示可描述为：
typedef struct TreeNode {
elemtype data;
struct TreeNode *son;
struct TreeNode *next;
}NodeType;
*/

class ParentsChildLinkChild
	/*双亲孩子表示法中的孩子节点*/
{
public:
	ParentsChildLinkChild(int index=-1,ParentsChildLinkChild*next=nullptr):index_(index),next_(next){}
	~ParentsChildLinkChild();
public:
	//保存孩子在树数组中的节点下标
	int index_;
	//保存下一个孩子
	ParentsChildLinkChild* next_;
};

inline ParentsChildLinkChild::~ParentsChildLinkChild()
{
}

template <typename T>
class ParentsChildLinkNode
/*双亲孩子表示法中的节点*/
{
public:
	ParentsChildLinkNode();
	ParentsChildLinkNode(T data,int parent=-1, ParentsChildLinkChild* first_child = nullptr):data_(data),first_child_(first_child),parent_(parent){}
	~ParentsChildLinkNode();
public:
	//节点值
	T data_;
	//第一个孩子指针
	ParentsChildLinkChild* first_child_;
	//父亲节点的下标
	int parent_;
};

template<typename T>
inline ParentsChildLinkNode<T>::ParentsChildLinkNode()
{
}

template<typename T>
inline ParentsChildLinkNode<T>::~ParentsChildLinkNode()
{
}
