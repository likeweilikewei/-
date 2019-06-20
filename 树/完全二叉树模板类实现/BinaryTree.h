#pragma once
/*完全二叉树的声明和实现，模板类的声明和实现应该放在.h文件里，否则编译出错，因为模板类只会在用到的时候实例化*/

#include<iostream>
#include<queue>
#include<stack>
#include<iomanip>
#include<vector>
#include "BinaryTreeNode.h"

using namespace std;

template <typename T>
class BinaryTree
{
public:
	void show();
	BinaryTree();
	~BinaryTree();
	//销毁完全二叉树
	void Destroy(BinaryTreeNode<T>*tree_node);
	//得到根节点,存取函数或短小的内联函数使用小写加下划线，且与访问变量相吻合
	BinaryTreeNode<T>* get_root();
	//设置根节点
	void set_root(BinaryTreeNode<T>*root);

	//遍历二叉树,默认递归的前序访问
	void Traversal(BinaryTreeNode<T>* tree_root,string order_type="preorder",int recursion_flag=1);

	//递归前序遍历二叉树
	void RecursionPreorderTraversal(BinaryTreeNode<T>* tree_root);
	//递归中序遍历二叉树
	void RecursionInorderTraversal(BinaryTreeNode<T>* tree_root);
	//递归后序遍历二叉树
	void RecursionPostorderTraversal(BinaryTreeNode<T>* tree_root);

	//非递归前序遍历二叉树
	void NonRecursionPreorderTraversal(BinaryTreeNode<T>* tree_root);
	//非递归中序遍历二叉树
	void NonRecursionInorderTraversal(BinaryTreeNode<T>* tree_root);
	//非递归后序遍历二叉树
	void NonRecursionPostorderTraversal(BinaryTreeNode<T>* tree_root);

	//层序遍历二叉树
	void LevelorderTraversal(BinaryTreeNode<T>* tree_root);

	//手动指定结束符，前序建立完全二叉树
	BinaryTreeNode<T>* ManualPreorderConstruct();
	//手动指定结束符，中序建立完全二叉树
	BinaryTreeNode<T>* ManualInorderConstruct();
	//手动指定结束符，后序建立完全二叉树
	BinaryTreeNode<T>* ManualPostorderConstruct();

	//自动层序数据建立完全二叉树
	void LevelorderConstruct();
	//根据层序遍历数据建立二叉树
	template <typename I>
	static BinaryTreeNode<T>* LevelorderDatasConstruct(const I& datas);

	//输入前序中序数据，然后由前序和中序数据建立完全二叉树
	void PreorderInorderConstruct();
	//由前序和中序数据建立完全二叉树
	static BinaryTreeNode<T>* PreorderInorderDatasConstruct(T*pre,T*in,int n);

	//输入中序和后序数据，调用程序建立二叉树
	void InorderPostorderConstruct();
	//由中序和后序数据建立二叉树
	static BinaryTreeNode<T>* InorderPostorderDatasConstruct(T* post, T* in, int n);

	//清空缓冲区
	static void flush_buffer(istream&);

	//判断树是否为空
	bool IsEmpty(BinaryTreeNode<T>* tree_root);
	//访问头结点数据
	void VistNode(BinaryTreeNode<T>* tree_root);
	//得到父节点
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* tree_root, BinaryTreeNode<T>* tree_node);
	//得到左孩子
	BinaryTreeNode<T>* LeftChild(BinaryTreeNode<T>* tree_node);
	//得到右孩子
	BinaryTreeNode<T>* RightChild(BinaryTreeNode<T>* tree_node);
	//得到节点数
	int Size(BinaryTreeNode<T>* tree_root);
	//得到节点的高度
	int Height(BinaryTreeNode<T>* tree_node);
	//得到树的高度
	int HeightTree();
	//得到节点的深度
	int Depth(BinaryTreeNode<T>* tree_node);
	//得到树的深度
	int DepthTree();

private:
	BinaryTreeNode<T>* root_;
};


template <typename T>
BinaryTree<T>::BinaryTree()
{
	root_ = NULL;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	Destroy(root_);
}

template <typename T>
void BinaryTree<T>::show()
{
	cout << "hello" << endl;
}

template <typename T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T>* tree_node)
/*删除二叉树*/
{
	if (NULL == tree_node)
		return;
	//删除的时候必须用后序删除
	Destroy(tree_node->left_child_);
	Destroy(tree_node->right_child_);
	delete tree_node;
	tree_node = NULL;
}

template <typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::get_root()
/*取到根节点*/
{
	return root_;
}

template <typename T>
inline void BinaryTree<T>::set_root(BinaryTreeNode<T>* root)
/*设置根节点*/
{
	if (root_ == root)
		return;
	root_ = root;
}

template <typename T>
void BinaryTree<T>::Traversal(BinaryTreeNode<T> * tree_root, string order_type, int recursion_flag)
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

template <typename T>
void BinaryTree<T>::RecursionPreorderTraversal(BinaryTreeNode<T> * tree_root)
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

template <typename T>
void BinaryTree<T>::RecursionInorderTraversal(BinaryTreeNode<T> * tree_root)
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

template <typename T>
void BinaryTree<T>::RecursionPostorderTraversal(BinaryTreeNode<T> * tree_root)
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

template <typename T>
void BinaryTree<T>::NonRecursionPreorderTraversal(BinaryTreeNode<T> * tree_root)
/*非递归前序遍历完全二叉树*/
{
	if (tree_root == NULL)
	{
		return;
	}
	
	//暂存结点
	stack<BinaryTreeNode<T>*> nodes;
	//临时结点
	BinaryTreeNode<T>* tmp_node;

	tmp_node = tree_root;

	//当首节点不为空能进去
	while (tmp_node||!nodes.empty())
	{
		//先遍历该节点的左孩子
		while (NULL != tmp_node)
		{
			nodes.push(tmp_node);
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->left_child_;
		}

		//当节点左孩子为空时候考虑右孩子
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			tmp_node = tmp_node->right_child_;
			nodes.pop();
		}
	}
}

template <typename T>
void BinaryTree<T>::NonRecursionInorderTraversal(BinaryTreeNode<T> * tree_root)
/*非递归中序遍历二叉树*/
{
	if (tree_root == NULL)
	{
		return;
	}

	//暂存结点
	stack<BinaryTreeNode<T>*> nodes;
	//临时结点
	BinaryTreeNode<T>* tmp_node;

	tmp_node = tree_root;

	//当首节点不为空能进去
	while (tmp_node || !nodes.empty())
	{
		//先遍历该节点的左孩子
		while (NULL != tmp_node)
		{
			nodes.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//当节点左孩子为空时候考虑右孩子
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->right_child_;
			nodes.pop();
		}
	}
}

template <typename T>
void BinaryTree<T>::NonRecursionPostorderTraversal(BinaryTreeNode<T> * tree_root)
/*非递归后序遍历二叉树*/
{
	if (tree_root == NULL)
	{
		return;
	}

	//暂存结点
	stack<BinaryTreeNode<T>*> nodes;
	//临时结点
	BinaryTreeNode<T>* tmp_node;
	BinaryTreeNode<T>* last_visit_node;

	tmp_node = tree_root;
	last_visit_node = tree_root;

	//当首节点不为空能进去
	while (tmp_node || !nodes.empty())
	{
		//先遍历该节点的左孩子
		while (NULL != tmp_node)
		{
			nodes.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//当节点左孩子为空时候考虑右孩子
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
		}

		//当右孩子为空或者右孩子访问过，则输出当前节点
		if (tmp_node->right_child_ == NULL|| last_visit_node==tmp_node->right_child_)
		{
			cout << setw(5) << tmp_node->data_;
			nodes.pop();
			last_visit_node = tmp_node;
			tmp_node = NULL;
		}
		else 
		{
			tmp_node = tmp_node->right_child_;
		}
	}
}

template<typename T>
void BinaryTree<T>::LevelorderTraversal(BinaryTreeNode<T>* tree_root)
/*层序遍历二叉树*/
{
	if (tree_root == NULL)
	{
		return;
	}

	queue<BinaryTreeNode<T>*>nodes;
	BinaryTreeNode<T>* tmp_node;
	nodes.push(tree_root);

	//先进先出遍历各个节点
	while (!nodes.empty())
	{
		tmp_node = nodes.front();
		nodes.pop();
		cout << setw(5) << tmp_node->data_;
		if (NULL != tmp_node->left_child_)
			nodes.push(tmp_node->left_child_);
		if (NULL != tmp_node->right_child_)
			nodes.push(tmp_node->right_child_);
	}
}

template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::ManualPreorderConstruct()
/*手动指定结束符，输入0结尾，前序建立完全二叉树*/
{
	cout << "start preorder construct binary tree,input 0 to end." << endl;
	T data;
	cin >> data;
	if (0 == data || '0' == data)
		return NULL;
	BinaryTreeNode<T>* new_root = new BinaryTreeNode<T>;
	if (NULL == new_root)
		throw "new node failed";
	new_root->data_ = data;
	cout << "请输入" << data << "的左孩子：" << endl;
	new_root->left_child_ = ManualPreorderConstruct();
	cout << "请输入" << data << "的右孩子：" << endl;
	new_root->right_child_ = ManualPreorderConstruct();

	//清除缓冲区
	flush_buffer(cin);

	return new_root;
}

template <typename T>
BinaryTreeNode<T> * BinaryTree<T>::ManualInorderConstruct()
/*手动指定结束符，输入0结尾，中序建立完全二叉树,其中输入是前序，但是建立是中序*/
{
	cout << "start inorder construct binary tree,input 0 to end." << endl;
	T data;
	cin >> data;
	if (0 == data || '0' == data)
		return NULL;
	BinaryTreeNode<T>* new_root = new BinaryTreeNode<T>;
	if (NULL == new_root)
		throw "new node failed";
	cout << "请输入" << data << "的左孩子：" << endl;
	new_root->left_child_ = ManualInorderConstruct();
	new_root->data_ = data;
	cout << "请输入" << data << "的右孩子：" << endl;
	new_root->right_child_ = ManualInorderConstruct();

	//清除缓冲区
	flush_buffer(cin);

	return new_root;
}

template <typename T>
BinaryTreeNode<T> * BinaryTree<T>::ManualPostorderConstruct()
/*手动指定结束符，输入0结尾，后序建立完全二叉树，输入是前序，赋值建立是后序*/
{
	cout << "start postorder construct binary tree,input 0 to end." << endl;
	T data;
	cin >> data;
	if (0 == data || '0' == data)
		return NULL;
	BinaryTreeNode<T>* new_root = new BinaryTreeNode<T>;
	if (NULL == new_root)
		throw "new node failed";
	cout << "请输入" << data << "的左孩子：" << endl;
	new_root->left_child_ = ManualPostorderConstruct();
	cout << "请输入" << data << "的右孩子：" << endl;
	new_root->right_child_ = ManualPostorderConstruct();
	new_root->data_ = data;

	//清除缓冲区
	flush_buffer(cin);

	return new_root;
}

template<typename T>
void BinaryTree<T>::LevelorderConstruct()
/*层序输入建立完全二叉树*/
{
	T data;
	vector<T> datas;

	cout << "start levelorder construct binary tree." << endl;
	cout << "please input datas,0 to quit." << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		datas.push_back(data);
	}

	//清除缓冲区
	flush_buffer(cin);

	root_ = LevelorderDatasConstruct(datas);
	//cout << "root:" << root_->data_ << endl;
}

template<typename T>
inline void BinaryTree<T>::PreorderInorderConstruct()
/*输入前序和中序数据，建立完全二叉树*/
{
	T data;
	vector<T>preorder_datas;

	cout << "start preorder and inorderd datas to construct tree." << endl;
	cout << "please input preorder datas,0 to quit." << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		preorder_datas.push_back(data);
	}
	if (preorder_datas.empty())
	{
		cout << "no input data,exit." << endl;
		return;
	}

	//清除缓冲区
	flush_buffer(cin);
	
	//如果有数据，则将向量的数据导入数组，为了之后数组索引计算方便
	int n = preorder_datas.size();
	T* preorder_datas_array = new T[n];
	T* inorder_datas_array = new T[n];

	int i;
	cout << "please input inorder datas.numbers:" << n << endl;
	for (i = 0; i < n; ++i)
	{
		preorder_datas_array[i] = preorder_datas[i];
		cin >> data;
		inorder_datas_array[i] = data;
	}

	//调用前序和中序建立二叉树的程序
	//for (i = 0; i < n; i++)
	//{
	//	cout << preorder_datas_array[i] << " " << inorder_datas_array[i] << endl;
	//}
	root_ = PreorderInorderDatasConstruct(preorder_datas_array, inorder_datas_array, n);
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::PreorderInorderDatasConstruct(T* pre, T* in, int n)
/*由前序和中序数据建立完全二叉树*/
{
	if (n == 0)
		return NULL;
	
	//得到这n个数据部分的根，k代表左边部分有k个数据
	int k=0;
	while (pre[0] != in[k])
		k++;

	BinaryTreeNode<T>* node = new BinaryTreeNode<T>;
	node->data_ = pre[0];
	node->left_child_ = PreorderInorderDatasConstruct(pre + 1, in, k);
	node->right_child_ = PreorderInorderDatasConstruct(pre + k + 1, in + k + 1, n - k - 1);
	return node;
}

template<typename T>
void BinaryTree<T>::InorderPostorderConstruct()
/*输入中序和后序数据建立二叉树*/
{
	T data;
	vector<T>postorder_datas;

	cout << "start postorder and inorderd datas to construct tree." << endl;
	cout << "please input postorder datas,0 to quit." << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		postorder_datas.push_back(data);
	}
	if (postorder_datas.empty())
	{
		cout << "no input data,exit." << endl;
		return;
	}

	//清除缓冲区
	flush_buffer(cin);

	//如果有数据，则将向量的数据导入数组，为了之后数组索引计算方便
	int n = postorder_datas.size();
	T* postorder_datas_array = new T[n];
	T* inorder_datas_array = new T[n];

	int i,j,tmp_data;
	cout << "please input inorder datas.numbers:" << n << endl;
	for (i = 0; i < n; ++i)
	{
		postorder_datas_array[i] = postorder_datas[i];
		cin >> data;
		inorder_datas_array[i] = data;
	}

	//先将后序数据反转方便计算
	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		tmp_data = postorder_datas_array[i];
		postorder_datas_array[i] = postorder_datas_array[j];
		postorder_datas_array[j] = tmp_data;
	}
	//调用前序和中序建立二叉树的程序
	//for (i = 0; i < n; i++)
	//{
	//	cout << postorder_datas_array[i] << " " << inorder_datas_array[i] << endl;
	//}

	root_ = InorderPostorderDatasConstruct(postorder_datas_array,inorder_datas_array,n);
}

template<typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::InorderPostorderDatasConstruct(T* post, T* in, int n)
/*由中序和后序数据建立二叉树*/
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (post[0] != in[k])
		k++;

	//建立当前部分的根节点
	BinaryTreeNode<T>* node = new BinaryTreeNode<T>;
	node->data_ = post[0];
	//左孩子从相应部分开始
	node->left_child_ = InorderPostorderDatasConstruct(post+n-k, in, k);
	node->right_child_ = InorderPostorderDatasConstruct(post+1,in+k+1,n-k-1);
	return node;
}

template<typename T>
inline void BinaryTree<T>::flush_buffer(istream&in)
/*清空缓冲区*/
{
	in.clear();
	while (in.get() != '\n')
		continue;
}

template<typename T>
inline bool BinaryTree<T>::IsEmpty(BinaryTreeNode<T>* tree_root)
/*判断树是否为空*/
{
	return NULL==tree_root;
}

template<typename T>
inline void BinaryTree<T>::VistNode(BinaryTreeNode<T>* tree_root)
/*访问节点数据*/
{
	if (NULL == tree_root)
	{
		cout << "the node is empty." << endl;
		return;
	}
	cout << setw(5) << tree_root->data_ << endl;
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* tree_root, BinaryTreeNode<T>* tree_node)
/*得到父节点*/
{
	if (tree_root == NULL || tree_node == NULL || tree_root == tree_node)
		return NULL;

	queue<BinaryTreeNode<T>*>nodes;
	BinaryTreeNode<T>* node;
	nodes.push(tree_root);
	while (!nodes.empty())
	{
		node = nodes.front();
		nodes.pop();
		if (node->left_child_ == tree_node || node->right_child_ == tree_node)
			return node;
		if (node->left_child_ != NULL)
			nodes.push(node->left_child_);
		if (node->right_child_ != NULL)
			nodes.push(node->right_child_);
	}
	return NULL;
}

template<typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::LeftChild(BinaryTreeNode<T>* tree_node)
/*得到节点的左孩子*/
{
	if (NULL == tree_node || tree_node->left_child_ == NULL)
		return NULL;
	return tree_node->left_child_;
}

template<typename T>
inline BinaryTreeNode<T>* BinaryTree<T>::RightChild(BinaryTreeNode<T>* tree_node)
/*得到节点的右孩子*/
{
	if (NULL == tree_node || tree_node->right_child_ == NULL)
		return NULL;
	return tree_node->right_child_;
}

template<typename T>
int BinaryTree<T>::Size(BinaryTreeNode<T>* tree_root)
/*得到节点数*/
{
	int count = 0;
	if (tree_root != NULL)
	{
		count++;
		count += Size(tree_root->left_child_);
		count += Size(tree_root->right_child_);
	}
	return count;
}

template<typename T>
int BinaryTree<T>::Height(BinaryTreeNode<T>* tree_node)
/*得到节点的高度，叶子点高度为0，往上依次递增*/
{
	if (tree_node == NULL||tree_node->left_child_==NULL)
		return 0;
	return 1 + max(Height(tree_node->left_child_), Height(tree_node->right_child_));
}

template<typename T>
int BinaryTree<T>::HeightTree()
/*得到树的高度*/
{
	return Height(root_);
}

template<typename T>
int BinaryTree<T>::Depth(BinaryTreeNode<T>* tree_node)
/*得到节点的深度，根节点深度为0*/
{
	if(tree_node==NULL||tree_node==root_)
		return 0;
	return 1 + Depth(Parent(root_,tree_node));
}

template<typename T>
int BinaryTree<T>::DepthTree()
/*得到树的深度*/
{
	if (NULL == root_)
		return 0;
	BinaryTreeNode<T>* node = root_;
	queue<BinaryTreeNode<T>*>nodes;
	int count = 0;
	int tmp_count = 0;

	nodes.push(node);
	while (!nodes.empty())
	{
		node = nodes.front();
		nodes.pop();
		if (node->left_child_ == NULL && node->right_child_ == NULL)
		{
			tmp_count = Depth(node);
			if (count < tmp_count)
				count = tmp_count;
		}

		//将其左右节点进队列
		if (NULL != node->left_child_)
			nodes.push(node->left_child_);
		if (NULL != node->right_child_)
			nodes.push(node->right_child_);
	}
	return count;
}

template<typename T>
template<typename I>
inline BinaryTreeNode<T>* BinaryTree<T>::LevelorderDatasConstruct(const I& datas)
/*层序数据建立完全二叉树*/
{
	if (datas.begin() == datas.end())
		return NULL;

	//层序存放节点数据的容器
	typename I::const_iterator iter = datas.begin();
	//按层序存放节点的队列
	queue<BinaryTreeNode<T>*>nodes;
	//根节点
	BinaryTreeNode<T>* root;
	//临时节点
	BinaryTreeNode<T>* tmp_node;

	//取出数值
	T data_tmp;
	try
	{
		data_tmp = *iter++;
	}
	catch (...)
	{
		throw "data in datas is not type of T.";
	}

	//开始构建二叉树
	//cout << "data tmp" << data_tmp << endl;
	root = new BinaryTreeNode<T>;
	root->data_ = data_tmp;
	nodes.push(root);

	while (!nodes.empty())
	{
		tmp_node = nodes.front();
		nodes.pop();
		//构建左孩子
		if (NULL==tmp_node->left_child_&&iter!=datas.end())
		{
			tmp_node->left_child_ = new BinaryTreeNode<T>;
			tmp_node->left_child_->data_ = *iter++;
			nodes.push(tmp_node->left_child_);
		}
		//构建右孩子
		if (NULL==tmp_node->right_child_ && iter != datas.end())
		{
			tmp_node->right_child_ = new BinaryTreeNode<T>;
			tmp_node->right_child_->data_ = *iter++;
			nodes.push(tmp_node->right_child_);
		}
	}
	
	//cout << "root.data:" << root->data_ << endl;
	return root;
}
