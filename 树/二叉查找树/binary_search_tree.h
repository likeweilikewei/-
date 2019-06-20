#pragma once
#include<iostream>
#include<vector>
#include<stack>
#include<iomanip>
#include"binary_search_tree_node.h"

using namespace std;

template <typename T>
struct InputResult {
	//构建二叉树时用户输入
	T* datas_array_;
	int datas_len_;
};

template <typename T>
class BinarySearchTree
/*二叉查找树*/
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	//删除树
	void DestroyTree();
	//删除节点
	void Destroy(BinarySearchTreeNode<T>**tree_node_link);
	//查找节点
	static bool Search(BinarySearchTreeNode<T>* tree_root, T search_data, BinarySearchTreeNode<T>* &searched_node);
	//查找根节点
	BinarySearchTreeNode<T>* get_root();
	//查找根节点的指针，之所以取指针是为了得到原始的树节点，方便实时修改指针指向，
	//用上面的话返回的是一个右值，无法给非常量引用赋值,也就无法修改指针指向
	BinarySearchTreeNode<T>** get_root_link();
	//设置根节点
	void set_root(BinarySearchTreeNode<T>* root);
	//插入节点
	static bool Insert(BinarySearchTreeNode<T>* &tree_root, T insert_data);
	//插入节点，重复节点也进行插入，插入到右孩子上
	static bool InsertSort(BinarySearchTreeNode<T>*&tree_root, T insert_data);
	//构造二叉查找树
	void Construct();
	//构造有相同元素的二叉查找树，相同元素作为右孩子插入，可以用作二叉树排序，并且是稳定的排序，时间复杂度为nlogn
	void ConstructSortTree();
	//删除节点
	bool Delete(BinarySearchTreeNode<T>* &tree_root,int delete_data);

	//遍历二叉树,默认递归的前序访问
	void Traversal(BinarySearchTreeNode<T>* tree_root, string order_type = "preorder", int recursion_flag = 1);

	//递归前序遍历二叉树
	void RecursionPreorderTraversal(BinarySearchTreeNode<T>* tree_root);
	//递归中序遍历二叉树
	void RecursionInorderTraversal(BinarySearchTreeNode<T>* tree_root);
	//递归后序遍历二叉树
	void RecursionPostorderTraversal(BinarySearchTreeNode<T>* tree_root);

	//非递归前序遍历二叉树
	void NonRecursionPreorderTraversal(BinarySearchTreeNode<T>* tree_root);
	//非递归中序遍历二叉树
	void NonRecursionInorderTraversal(BinarySearchTreeNode<T>* tree_root);
	//非递归后序遍历二叉树
	void NonRecursionPostorderTraversal(BinarySearchTreeNode<T>* tree_root);

	//层序遍历二叉树
	void LevelorderTraversal(BinarySearchTreeNode<T>* tree_root);

private:
	BinarySearchTreeNode<T>* root_;
	//用具体数据构造二叉树
	BinarySearchTreeNode<T>* ConstructByDatas(bool (*pfunc)(BinarySearchTreeNode<T>*&, T),T* datas_array,int data_len);
	//清空缓冲区
	void FlushBuffer(istream& in);
	//具体删除节点
	void DeleteNode(BinarySearchTreeNode<T>* &tree_node);
	//构建二叉树时候用户的输入
	static InputResult<T> Input();
};

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	root_ = nullptr;
}

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	DestroyTree();
}

template<typename T>
void BinarySearchTree<T>::DestroyTree()
/*删除树*/
{
	Destroy(&root_);
}

template<typename T>
void BinarySearchTree<T>::Destroy(BinarySearchTreeNode<T>** tree_node_link)
/*删除节点及其子节点，因为需要改变节点的指向为nullptr因此需要传入指针的指针*/
{
	if (nullptr == *tree_node_link)
		return;
	Destroy(&((*tree_node_link)->left_child_));
	Destroy(&((*tree_node_link)->right_child_));
	delete *tree_node_link;
	*tree_node_link = nullptr;
}

template <typename T>
bool BinarySearchTree<T>::Search(BinarySearchTreeNode<T>* tree_root, T search_data, BinarySearchTreeNode<T>* &searched_node)
/*在二叉查找树中查找数据节点，tree_root:根节点，search_data:查找的数据，searched_node：保存查找到的节点，没找到则是最后一个查找的节点，方便插入*/
{
	if (tree_root == nullptr)
	{
		searched_node = nullptr;
		return false;
	}

	//查找到直接返回
	if (search_data == tree_root->data_)
	{
		searched_node = tree_root;
		return true;
	}

	//查找数据比节点值小则在左孩子查找
	if (search_data < tree_root->data_)
	{
		//如果左孩子为空直接返回
		if (tree_root->left_child_ == nullptr)
		{
			searched_node = tree_root;
			return false;
		}
		else
			return Search(tree_root->left_child_, search_data, searched_node);
	}
	
	//查找数据比节点值到则查找右孩子
	if (search_data > tree_root->data_)
	{
		if (tree_root->right_child_ == nullptr)
		{
			searched_node = tree_root;
			return false;
		}
		else
			return Search(tree_root->right_child_, search_data, searched_node);
	}
}

template <typename T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::get_root()
{
	return root_;
}

template<typename T>
inline BinarySearchTreeNode<T>** BinarySearchTree<T>::get_root_link()
{
	return &root_;
}

template <typename T>
inline void BinarySearchTree<T>::set_root(BinarySearchTreeNode<T>* root)
{
	if (root_ == root)
		return;
	root_ = root;
}

template<typename T>
inline bool BinarySearchTree<T>::Insert(BinarySearchTreeNode<T>* &tree_root, T insert_data)
/*插入节点，如果查到了值则不插入，否则插入到相应位置，因为可能需要改变根节点指向，采用指针引用*/
{
	BinarySearchTreeNode<T>* searched_node=nullptr;
	if (!Search(tree_root, insert_data, searched_node))
	{
		//树中没有这个节点则开始构造树节点
		BinarySearchTreeNode<T>* new_node = new BinarySearchTreeNode<T>;
		if (!new_node)
			throw "new binary node failed.";;
		new_node->data_ = insert_data;

		//树为空直接插入新节点
		if (searched_node == nullptr)
		{
			tree_root = new_node;
			return true;
		}

		//树不为空
		else
		{
			//如果插入数据小于最后查找的节点数据，则插入左孩子
			if (insert_data < searched_node->data_)
			{
				searched_node->left_child_ = new_node;
				return true;
			}
			if (insert_data > searched_node->data_)
			{
				searched_node->right_child_ = new_node;
				return true;
			}
		}
	}
	return false;
}

template<typename T>
bool BinarySearchTree<T>::InsertSort(BinarySearchTreeNode<T>*&tree_root, T insert_data)
/*构建用来排序的二叉查找树，从而重复节点需要插入，并且插入到右孩子上，从而保持插入算法的稳定性*/
{
	//申请新节点
	BinarySearchTreeNode<T>* new_node = new BinarySearchTreeNode<T>;
	if (!new_node)
		throw "new node failed.";
	new_node->data_ = insert_data;

	BinarySearchTreeNode<T>* searched_node=nullptr;
	bool search_flag;

	//查找当前值是否在树中
	search_flag = Search(tree_root, insert_data, searched_node);
	//如果找到就插入到该节点的右孩子上
	if (search_flag &&searched_node)
	{
		new_node->right_child_ = searched_node->right_child_;
		searched_node->right_child_ = new_node;
	}

	//如果没有找到，则正常插入到树中
	else if (!search_flag)
	{
		//树为空直接插入
		if (!tree_root)
		{
			tree_root = new_node;
			return true;
		}

		//树不为空，并且最后一个查找的节点不为空则插入到 相应位置上
		else if (searched_node)
		{
			//如果小于最后一个查找节点就插入到左孩子上
			if (insert_data < searched_node->data_&&searched_node->left_child_==nullptr)
			{
				searched_node->left_child_ = new_node;
				return true;
			}

			//如果右孩子为空，并且插入值大于最后一个节点值，则插入到右孩子上
			if (insert_data > searched_node->data_ && searched_node->right_child_ == nullptr)
			{
				searched_node->right_child_ = new_node;
				return true;
			}
		}
	}
	return false;
}

template<typename T>
void BinarySearchTree<T>::Construct()
/*构造二叉查找树*/
{
	InputResult<T> input_result = Input();
	//开始构建二叉查找树
	root_ = ConstructByDatas(Insert,input_result.datas_array_,input_result.datas_len_);
}

template<typename T>
inline void BinarySearchTree<T>::ConstructSortTree()
/*构建排序的二叉查找树，区别就是可以可以插入重复元素*/
{
	InputResult<T> input_result;
	input_result = Input();
	root_=ConstructByDatas(InsertSort, input_result.datas_array_, input_result.datas_len_);
}

template<typename T>
bool BinarySearchTree<T>::Delete(BinarySearchTreeNode<T>*&tree_root, int delete_data)
/*从树中删除节点，这里不能用查找节点的方式，因为如果被删节点是没有孩子的话就需要改变节点指针指向，
而这里的临时节点无法做到,同时因为需要递归删除，因此无法在函数里面初始化root,需要传入*/
{
	//反面错误做法示例
	//BinarySearchTreeNode<T>*tree_node;
	//if (Search(root_, delete_data, tree_node))
	//{
	//	DeleteNode(tree_node);
	//	return true;
	//}
	//else
	//	return false;

	//递归终止条件
	if (nullptr == tree_root)
		return false;

	//如果找到被删节点则删除
	if (delete_data == tree_root->data_)
	{
		DeleteNode(tree_root);
		return true;
	}

	//如果值小于节点值则在左子树中查找
	if (delete_data < tree_root->data_)
		Delete(tree_root->left_child_,delete_data);
	else
	{
		Delete(tree_root->right_child_, delete_data);
	}
}

template<typename T>
inline void BinarySearchTree<T>::Traversal(BinarySearchTreeNode<T>* tree_root, string order_type, int recursion_flag)
/*遍历二叉树*/
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

template<typename T>
inline void BinarySearchTree<T>::RecursionPreorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*递归前序遍历二叉树*/
{
	if (tree_root == NULL)
	{
		return;
	}
	cout << setw(5) << tree_root->data_;
	RecursionPreorderTraversal(tree_root->left_child_);
	RecursionPreorderTraversal(tree_root->right_child_);
}

template<typename T>
inline void BinarySearchTree<T>::RecursionInorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*递归中序遍历二叉树*/
{
	if (tree_root == NULL)
	{
		return;
	}
	RecursionInorderTraversal(tree_root->left_child_);
	cout << setw(5) << tree_root->data_;
	RecursionInorderTraversal(tree_root->right_child_);
}

template<typename T>
inline void BinarySearchTree<T>::RecursionPostorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*递归后序遍历二叉树*/
{
	if (tree_root == NULL)
	{
		return;
	}
	RecursionPostorderTraversal(tree_root->left_child_);
	RecursionPostorderTraversal(tree_root->right_child_);
	cout << setw(5) << tree_root->data_;
}

template<typename T>
void BinarySearchTree<T>::NonRecursionPreorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*非递归前序遍历二叉查找树*/
{
	if (tree_root == nullptr)
		return;

	//当左孩子遍历完后，需要输出右孩子，用堆栈保存父节点信息
	stack<BinarySearchTreeNode<T>*>nodes_stack;
	BinarySearchTreeNode<T>* tmp_node=tree_root;

	//为了头结点能进去，仅此而已
	while (!nodes_stack.empty()||tmp_node)
	{
		//先遍历根和其左孩子
		while (tmp_node != nullptr)
		{
			nodes_stack.push(tmp_node);
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->left_child_;
		}

		//当处理完当前左孩子后，处理当前节点的右孩子
		if (!nodes_stack.empty())
		{
			tmp_node = nodes_stack.top();
			tmp_node = tmp_node->right_child_;
			nodes_stack.pop();
		}
	}
}

template<typename T>
void BinarySearchTree<T>::NonRecursionInorderTraversal(BinarySearchTreeNode<T>* tree_root)
/*非递归中序遍历二叉查找树*/
{
	if (tree_root == nullptr)
		return;

	//当左孩子遍历完后，需要输出右孩子，用堆栈保存父节点信息
	stack<BinarySearchTreeNode<T>*>nodes_stack;
	BinarySearchTreeNode<T> * tmp_node = tree_root;

	//为了头结点能进去，仅此而已
	while (!nodes_stack.empty() || tmp_node)
	{
		//先遍历根和其左孩子，使得tmp_node指向最左边的nullptr指针
		while (tmp_node != nullptr)
		{
			nodes_stack.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//当处理完当前左孩子后，处理当前节点的右孩子
		if (!nodes_stack.empty())
		{
			//首先弹出的是最左边的孩子，因为其左孩子指针为null，因此直接处理本节点
			tmp_node = nodes_stack.top();
			cout << setw(5) << tmp_node->data_;
			//处理完后，处理右孩子
			tmp_node = tmp_node->right_child_;
			nodes_stack.pop();
		}
	}
}

template<typename T>
inline void BinarySearchTree<T>::NonRecursionPostorderTraversal(BinarySearchTreeNode<T>* tree_root)
{
	if (nullptr == tree_root)
		return;

	stack<BinarySearchTreeNode<T>*>nodes_stack;
	BinarySearchTreeNode<T> * tmp_node = tree_root;
	BinarySearchTreeNode<T> * last_visit_node = tree_root;

	while (tmp_node || !nodes_stack.empty())
	{
		while (tmp_node)
		{
			nodes_stack.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		if (!nodes_stack.empty())
			tmp_node = nodes_stack.top();

		if (tmp_node->right_child_ == nullptr || tmp_node->right_child_ == last_visit_node)
		{
			cout << setw(5) << tmp_node->data_;
			last_visit_node = tmp_node;
			nodes_stack.pop();
			tmp_node = nullptr;
		}
		else
		{
			tmp_node=tmp_node->right_child_;
		}
	}
}


template<typename T>
inline void BinarySearchTree<T>::LevelorderTraversal(BinarySearchTreeNode<T>* tree_root)
{

}

template<typename T>
inline BinarySearchTreeNode<T>* BinarySearchTree<T>::ConstructByDatas(bool (*pfunc)(BinarySearchTreeNode<T>*&, T),T* datas_array, int data_len)
/*用数据构造二叉查找树*/
{
	if (data_len <= 0)
		return nullptr;

	int i = 0;
	BinarySearchTreeNode<T>* root=nullptr;

	//插入数据构造二叉查找树，用相应的插入方法进行插入
	for (i = 0; i < data_len; ++i)
	{
		pfunc(root, datas_array[i]);
	}
	return root;
}

template<typename T>
inline void BinarySearchTree<T>::FlushBuffer(istream& in)
/*清空缓冲区*/
{
	in.clear();
	while (in.get() != '\n')
		continue;
}

template<typename T>
inline void BinarySearchTree<T>::DeleteNode(BinarySearchTreeNode<T>*& tree_node)
/*从树中删除节点，这里选择将删除节点的左子树中最大的节点作为新的局部根，因为可能需要改变节点指针指向，因此用引用*/
{
	BinarySearchTreeNode<T>* tmp_node=nullptr;
	BinarySearchTreeNode<T>* tmp_parent = nullptr;

	if (tree_node == nullptr)
		return;

	//如果左孩子为空则改变节点指针指向，为该节点右孩子,包含了左右孩子为空的情况,
	//这是需要改变指针的指向，因此这时必须传入原本的树指针
	if (nullptr == tree_node->left_child_)
	{
		//cout << "yes" << endl;
		//cout << tree_node->data_ << endl;
		tmp_node = tree_node;
		tree_node = tree_node->right_child_;
		//cout << tree_node->data_ << endl;
		delete tmp_node;
		tmp_node = nullptr;
	}

	//如果右孩子为空则重新对接被删节点的左孩子
	else if (!tree_node->right_child_)
	{
		tmp_node = tree_node;
		tree_node = tree_node->left_child_;
		delete tmp_node;
		tmp_node = nullptr;
	}

	//如果左右孩子都不为空则取左子树中最大的节点作为局部根
	else
	{
		//找到左子树中最大的节点和其父节点，方便拼接左子树
		tmp_parent = tree_node;
		tmp_node = tree_node->left_child_;
		while (tmp_node->right_child_)
		{
			tmp_parent = tmp_node;
			tmp_node = tmp_node->right_child_;
		}

		//之后将找到的节点值替换被删节点，实现替换节点
		tree_node->data_ = tmp_node->data_;

		//如果父节点是被删节点则需要重新对接左子树
		if (tmp_parent == tree_node)
			tmp_parent->left_child_ = tmp_node->left_child_;
		else
			tmp_parent->right_child_ = tmp_node->left_child_;

		//删除节点
		delete tmp_node;
		tmp_node = nullptr;
	}
}

template<typename T>
inline InputResult<T> BinarySearchTree<T>::Input()
{
	InputResult<T> input_result;
	T data;
	vector<T>datas_vector;

	cout << "start input binary search tree datas,0 to quit." << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		datas_vector.push_back(data);
	}

	//将向量中的数据转化为数组
	int datas_len = datas_vector.size();
	int i = 0;
	T* datas_array = new T[datas_len];

	for (i = 0; i < datas_len; ++i)
	{
		datas_array[i] = datas_vector[i];
	}

	//将数据放入结构体中一起返回
	input_result.datas_array_ = datas_array;
	input_result.datas_len_ = datas_len;
	return input_result;
}
