#pragma once

#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<algorithm>
#include"avl_tree_node.h"
#include"stack_by_array.h"
#include"queue_by_array.h"

using namespace std;

template <typename T>
struct InputResult {
	//构建二叉树时用户输入
	T* datas_array_;
	int datas_len_;
};

template <typename T>
class AvlTree
{
public:
	AvlTree();
	~AvlTree();
	//删除树
	void DestroyTree();
	//删除节点
	void Destroy(AvlTreeNode<T>** tree_node_link);

	//得到根节点
	AvlTreeNode<T>* get_root();
	//得到根节点指针，从而可以改变根节点指向
	AvlTreeNode<T>* get_root_link();
	//设置根节点
	void set_root(AvlTreeNode<T>* root);

	//计算节点高度
	static int CalculateHeight(AvlTreeNode<T>* tree_node);
	//得到高度,默认得到数的高度
	static int GetHeight(AvlTreeNode<T>* tree_node = root_);
	//得到平衡因子，默认是左孩子高度-右孩子高度，只要高度相差不大于2，树就是平衡的，否则需要旋转
	static int GetFactor(AvlTreeNode<T>*tree_node);

	//LL情况，以是去平衡的根节点为中心，抓住左孩子右旋，使得左孩子为新根节点，原来的右孩子的柚子树给旧根的左孩子
	static AvlTreeNode<T>* LeftLeftRotation(AvlTreeNode<T>* tree_node);
	//RR情况，同上，只是抓住右孩子左旋，将右孩子作为新根节点
	static AvlTreeNode<T>* RightRightRotation(AvlTreeNode<T>* tree_node);
	//LR情况，先围绕根节点的左孩子RR旋转，再围绕是去平衡的根节点，LL旋转
	static AvlTreeNode<T>* LeftRightRotation(AvlTreeNode<T>* tree_node);
	//RL情况，先围绕失去平衡的右孩子进行LL旋转，即将根节点的左孩子的右孩子旋转到根节点的右孩子，在围绕根节点进行RR旋转，将根节点右孩子旋转为新根节点
	static AvlTreeNode<T>* RightLeftRotation(AvlTreeNode<T>* tree_node);

	//重新平衡插入了孩子的节点，插入从创建的新节点向上，沿着查找路径平衡
	static AvlTreeNode<T>* Reblanced(AvlTreeNode<T>* tree_node, T data);
	//重新平衡删除了节点的情况
	static AvlTreeNode<T>* ReblanceDelete(AvlTreeNode<T>* tree_node);
	//查找节点
	static bool Search(const AvlTreeNode<T>*const tree_root, const T& search_data, const AvlTreeNode<T>* &searched_node);
	//插入节点，并同时更新节点高度，并且重新平衡，因为需要改变节点指向，因此用引用
	static void Insert(AvlTreeNode<T>*& tree_root, T data);
	//构造节点
	void Construct();
	//删除节点
	void Delete(const T& data);
	//删除节点，改进版，让调整子节点和删除节点变成本质一样，用递归，因此代码可以简略很多
	void Remove(const T& data);

	//遍历二叉树,默认递归的前序访问
	void Traversal(AvlTreeNode<T>* tree_root, string order_type = "preorder", int recursion_flag = 1);
	//递归前序遍历二叉树
	void RecursionPreorderTraversal(AvlTreeNode<T>* tree_root);
	//非递归前序遍历二叉树
	void NonRecursionPreorderTraversal(AvlTreeNode<T>* tree_root);
	//递归中序遍历二叉树
	void RecursionInorderTraversal(AvlTreeNode<T>* tree_root);
	//非递归中序遍历二叉树
	void NonRecursionInorderTraversal(AvlTreeNode<T>* tree_root);
	//递归后序遍历二叉树
	void RecursionPostorderTraversal(AvlTreeNode<T>* tree_root);
	//非递归后序遍历二叉树
	void NonRecursionPostorderTraversal(AvlTreeNode<T>* tree_root);
	//层序遍历二叉树
	void LevelorderTraversal(AvlTreeNode<T>* tree_root);

	//得到树的最大元素，如果树空则False
	static AvlTreeNode<T>* MaxNode(AvlTreeNode<T>* tree_root);
	//是否有树的最小元素，如果树空则False
	static AvlTreeNode<T>* MinNode(AvlTreeNode<T>* tree_root);
	//得到某一个元素的在中序遍历的前一个节点
	static AvlTreeNode<T>* PreviousNode(AvlTreeNode<T>* tree_root, const T& data);
	//得到某一个元素的在中序遍历中的后一个元素
	static AvlTreeNode<T>* ForwardNode(AvlTreeNode<T>* tree_root, const T& data);

private:
	AvlTreeNode<T>* root_;

	//记录用户节点数据输入
	static InputResult<T> Input();
	//用数据和插入方法构造AVL树
	//根据数据和插入方法构造avl树
	static AvlTreeNode<T>* ConstructByDatas(void (*pfunc)(AvlTreeNode<T>*&, T), T* datas_array, T array_len);
	//删除给定树和给定节点，并且重新计算高度和平衡树
	static void Delete(AvlTreeNode<T>*& tree_root, const T& data);
	//根据BST删除节点，进行平衡动作，进行高度重新计算
	static void DeleteBST(AvlTreeNode<T>*& tree_root);
	//删除节点，改进版，具体针对一棵树进行删除，并调整高度和旋转平衡，并返回新树的指针，因为可能改变指针指向，因此传入指针引用，其实也可以不返回
	static AvlTreeNode<T>* Remove(AvlTreeNode<T>*& tree_root, const T& data);
};

template<typename T>
AvlTree<T>::AvlTree()
{
	root_ = nullptr;
}

template<typename T>
AvlTree<T>::~AvlTree()
{
	DestroyTree();
}

template<typename T>
void AvlTree<T>::DestroyTree()
{
	Destroy(&root_);
}

template<typename T>
void AvlTree<T>::Destroy(AvlTreeNode<T>** tree_node_link)
{
	if (!*tree_node_link)
		return;
	Destroy(&((*tree_node_link)->left_child_));
	Destroy(&((*tree_node_link)->right_child_));
	delete tree_node_link;
	tree_node_link = nullptr;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::get_root()
{
	return root_;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::get_root_link()
{
	return &root_;
}

template<typename T>
inline void AvlTree<T>::set_root(AvlTreeNode<T>* root)
{
	root_ = root;
}

template<typename T>
int AvlTree<T>::CalculateHeight(AvlTreeNode<T>* tree_node)
/*计算树的高度，叶子节点从1开始*/
{
	if (!tree_node)
		return 0;
	return max(GetHeight(tree_node->left_child_), GetHeight(tree_node->right_child_)) + 1;
}

template<typename T>
inline int AvlTree<T>::GetHeight(AvlTreeNode<T>* tree_node)
/*得到树的高度*/
{
	if (!tree_node)
		return 0;
	return tree_node->height_;
}

template<typename T>
int AvlTree<T>::GetFactor(AvlTreeNode<T>* tree_node)
/*得到平衡因子，如果绝对值大于1，就是不平衡*/
{
	if (!tree_node)
		return 0;
	return GetHeight(tree_node->left_child_) - GetHeight(tree_node->right_child_);
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::LeftLeftRotation(AvlTreeNode<T>* tree_node)
/*左左旋转,围绕根节点进行右旋，是的左孩子为新的根节点，原来的右孩子的右孩子变为旧根的左孩子*/
{
	if (!tree_node || !tree_node->left_child_)
		return tree_node;
	
	//保存根节点的左孩子，也就是新根节点
	AvlTreeNode<T>* new_root = tree_node->left_child_;

	tree_node->left_child_ = new_root->right_child_;
	new_root->right_child_ = tree_node;

	//因为发生旋转，导致旧根和新根高度可能发生变化，先更新旧根的高度，才能更新新根的高度
	tree_node->height_ = max(GetHeight(tree_node->left_child_), GetHeight(tree_node->right_child_)) + 1;
	new_root->height_ = max(GetHeight(new_root->left_child_), tree_node->height_)+1;

	return new_root;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::RightRightRotation(AvlTreeNode<T>* tree_node)
/*右右旋转*/
{
	if (!tree_node || !tree_node->right_child_)
		return tree_node;
	
	//保存新根节点
	AvlTreeNode<T>* new_root = tree_node->right_child_;

	//交换和旋转，将新根节点的左孩子给旧根节点的右孩子
	tree_node->right_child_ = new_root->left_child_;
	new_root->left_child_ = tree_node;

	//更新节点的高度，先更新旧根节点的高度，然后更新新根节点的高度
	tree_node->height_ = max(GetHeight(tree_node->left_child_), GetHeight(tree_node->right_child_)) + 1;
	new_root->height_ = max(GetHeight(new_root->right_child_), tree_node->height_) + 1;

	return new_root;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::LeftRightRotation(AvlTreeNode<T>* tree_node)
/*LR情况，先以根节点左孩子为中心进行RR旋转，然后以根节点为中心进行LL旋转*/
{
	if (!tree_node || !tree_node->left_child_ || !tree_node->left_child_->right_child_)
		return tree_node;

	//先保存新根节点
	AvlTreeNode<T>* new_root;

	//先以根节点左孩子为中心进行RR旋转,直接复用上面的代码
	//tree_node->left_child_->right_child_ = new_root->left_child_;
	//new_root->left_child_ = tree_node->left_child_;
	tree_node->left_child_ = RightRightRotation(tree_node->left_child_);

	//以根节点为中心进行LL旋转
	//tree_node->left_child_ = new_root->right_child_;
	//new_root->right_child_ = tree_node;
	new_root = LeftLeftRotation(tree_node);
	return new_root;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::RightLeftRotation(AvlTreeNode<T>* tree_node)
/*右左情况，先对根节点的右孩子为中心做LL旋转，是的右孩子的左孩子为根的右孩子，然后对根节点做RR旋转，使的右孩子为新根*/
{
	if (!tree_node || !tree_node->right_child_ || !tree_node->right_child_->left_child_)
		return tree_node;

	//先对右孩子进行LL旋转
	tree_node->right_child_ = LeftLeftRotation(tree_node->right_child_);
	//再对根节点进行RR旋转
	return  RightRightRotation(tree_node);
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::Reblanced(AvlTreeNode<T>* tree_node, T data)
/*重新平衡*/
{
	if (!tree_node)
		return NULL;

	int factor = GetFactor(tree_node);
	//如果没有不平衡则跳过
	if (abs(factor) < 2)
		return tree_node;

	//如果值小于左孩子，则是LL
	else if (factor > 1 && data < tree_node->left_child_->data_)
		return LeftLeftRotation(tree_node);

	//如果大于左孩子，则是LR
	else if (factor > 1 && data >= tree_node->left_child_->data_)
		return LeftRightRotation(tree_node);

	//如果右边因子大，并且插入值大于右孩子则是RR
	else if (factor<-1 && data>=tree_node->right_child_->data_)
		return RightRightRotation(tree_node);

	//如果右边因子大，并且插入值小于右孩子则是RL
	else if (factor < -1 && data < tree_node->right_child_->data_)
		return RightLeftRotation(tree_node);

	//对于其他情况返回
	else
		return tree_node;
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::ReblanceDelete(AvlTreeNode<T>* tree_node)
/*删除节点后的重新平衡，需要检测识别四种反转的哪一种情况,并返回指向可能的新的节点*/
{
	//为空直接返回
	if (!tree_node)
		return nullptr;

	//取平衡因子
	int factor = GetFactor(tree_node);

	//没有破坏平衡则返回
	if (abs(factor) < 2)
		return tree_node;

	//如果失衡且左孩子高于右孩子，左孩子中左孩子高于右孩子则是LL,注意删除的情况可能是高的子树那边左右子树一样长，这时候用LL只需要旋转一次，LR需要旋转两次
	else if (factor > 1 && GetHeight(tree_node->left_child_->left_child_) >= GetHeight(tree_node->left_child_->right_child_))
	{
		return LeftLeftRotation(tree_node);
	}

	//如果失衡且左孩子高于右孩子，左孩子中的左孩子低于右孩子则是LR
	else if (factor > 1 && GetHeight(tree_node->left_child_->left_child_) < GetHeight(tree_node->left_child_->right_child_))
	{
		return LeftRightRotation(tree_node);
	}

	//如果失衡且左孩子低于右孩子，右孩子中的左孩子高于右孩子，则是RL
	else if (factor < -1 && GetHeight(tree_node->right_child_->left_child_) < GetHeight(tree_node->right_child_->right_child_))
	{
		return RightLeftRotation(tree_node);
	}

	//如果失衡且左孩子低于右孩子，右孩子中的左孩子低于右孩子，则是RR,注意删除的情况可能是高的子树那边左右子树一样长，这时候用RR只需要旋转一次，RL需要旋转两次
	else if (factor < -1 && GetHeight(tree_node->right_child_->left_child_) <= GetHeight(tree_node->right_child_->right_child_))
	{
		return RightRightRotation(tree_node);
	}

	//其他情况失衡不能通过消除单个点平衡，是错误状态，报错
	else
	{
		//cout << "the avl tree is wrong.";
		//return nullptr;
		throw "the avl tree is wrong.";
	}
}

template<typename T>
bool AvlTree<T>::Search(const AvlTreeNode<T>*const tree_root, const T& search_data, const AvlTreeNode<T>*& searched_node)
/*查找节点，如果查找到则返回true，searched_node指向查找到的节点，否则返回false,searched_node指向最后查找到的节点*/
{
	//如果节点为空直接返回
	if (!tree_root)
	{
		searched_node = nullptr;
		return false;
	}

	//如果查找到直接返回
	else if (tree_root->data_ == search_data)
	{
		searched_node = tree_root;
		return true;
	}

	//如果查找值小于根节点值，则在左子树中查找
	else if (tree_root->data_ > search_data)
	{
		//如果没有左孩子，则直接返回
		if (!tree_root->left_child_)
		{
			searched_node = tree_root;
			return false;
		}
		//有的话继续查找
		else
		{
			Search(tree_root->left_child_, search_data, searched_node);
		}
	}

	//如果查找值大于节点值，在柚子树中查找
	else
	{
		if (!tree_root->right_child_)
		{
			searched_node = tree_root;
			return false;
		}
		else
		{
			Search(tree_root->right_child_, search_data, searched_node);
		}
	}
}

template<typename T>
void AvlTree<T>::Insert(AvlTreeNode<T>*& tree_root, T data)
/*插入节点，更新高度，重新平衡，为了平衡路径上的节点，需要用递归*/
{
	//如果为空直接插入并更新高度就可以了
	if (!tree_root)
	{
		//构造新节点
		AvlTreeNode<T>* new_node = new AvlTreeNode<T>(data);
		if (!new_node)
			throw "ERROR:new node failed.";
		tree_root = new_node;
	}

	//如果插入值小于当前值
	else if (data < tree_root->data_)
		Insert(tree_root->left_child_, data);

	//如果插入值大于当前值
	else if (data > tree_root->data_)
		Insert(tree_root->right_child_, data);

	//相等则跳过
	else
		cout << "can not insert same data." << endl;

	//更新高度，从新添加的节点开始，这样就算申请的时候没有初始化高度，在这里也会进行初始化
	tree_root->height_ = max(GetHeight(tree_root->left_child_), GetHeight(tree_root->right_child_)) + 1;

	//重新平衡，从新添加的这个节点开始
	tree_root = Reblanced(tree_root, data);
}

template<typename T>
InputResult<T> AvlTree<T>::Input()
/*记录用户输入*/
{
	InputResult<T> input_result;
	vector<T>datas_vector;
	T data;

	cout << "please inputs avl tree datas,0 to quit:" << endl;
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

template<typename T>
void AvlTree<T>::Construct()
/*构造avl树*/
{
	InputResult<T> input_result = Input();
	root_ = ConstructByDatas(Insert, input_result.datas_array_, input_result.datas_len_);
}

template<typename T>
void AvlTree<T>::Delete(const T& data)
/*删除节点并重新平衡，可能改变根节点指向*/
{
	//根节点
	AvlTreeNode<T>* tree_root = root_;
	//保存查找到的节点，这里没有用
	const AvlTreeNode<T>* searched_node = nullptr;
	//先查找，如果存在则删除，否则不作动作
	if (Search(tree_root, data, searched_node))
	{
		Delete(tree_root, data);
	}

	//重新更新新根
	root_ = tree_root;
}

template<typename T>
inline void AvlTree<T>::Remove(const T& data)
/*改进版删除节点*/
{
	const AvlTreeNode<T>* node = nullptr;
	if (Search(root_, data, node))
		root_ = Remove(root_, data);
}

template<typename T>
void AvlTree<T>::Delete(AvlTreeNode<T>*&tree_root,const T& data)
/*删除节点，如果节点存在，按照二叉查找树规则删除节点，选取被删节点左子树最大节点作为新根，然后调整从原来的左子树的最大节点的父节点开始向上调整*/
{
	//为空直接返回
	if (!tree_root)
		return;

	//查找节点
	if (data == tree_root->data_)
	{
		//删除节点
		DeleteBST(tree_root);
	}
	else if (data < tree_root->data_)
	{
		Delete(tree_root->left_child_,data);
	}
	else
	{
		Delete(tree_root->right_child_,data);
	}

	if (tree_root != NULL)
	{
		//计算进入这里的根的高度
		tree_root->height_ = max(GetHeight(tree_root->left_child_), GetHeight(tree_root->right_child_)) + 1;

		//对失去平衡的节点重新平衡
		tree_root = ReblanceDelete(tree_root);
	}
}

template<typename T>
void AvlTree<T>::DeleteBST(AvlTreeNode<T>*& tree_root)
/*删除节点，更新高度，并重新平衡这部分*/
{
	//如果为空略过
	if (!tree_root)
		return;

	//待删除节点
	AvlTreeNode<T>* delete_node = nullptr;
	//新根
	AvlTreeNode<T>* new_root;
	//新根父节点，方便拼接新根的左孩子
	AvlTreeNode<T>* new_root_parent;
	//保存路径节点，从底向上更新高度和重平衡
	Stack<AvlTreeNode<T>*>nodes;

	//如果左右孩子都为空则置为空就可以了
	if (!tree_root->left_child_ && !tree_root->right_child_)
		tree_root = nullptr;

	//如果左孩子为空则重新对接右孩子
	else if (!tree_root->left_child_)
	{
		delete_node = tree_root;
		tree_root = tree_root->right_child_;
		delete delete_node;
		delete_node = nullptr;
	}

	//如果右孩子为空则重新对接左孩子
	else if (!tree_root->right_child_)
	{
		delete_node = tree_root;
		tree_root = tree_root->left_child_;
		delete delete_node;
		delete_node = nullptr;
	}

	//如果都不为空，则选取左子树最大节点作为新根，更新高度和重新平衡，调整都是从新根的父节点向上知道删除节点为止
	else
	{
		new_root = tree_root->left_child_;
		new_root_parent = tree_root;
		nodes.push(new_root_parent);
		//找到新根
		while (new_root->right_child_)
		{
			new_root_parent = new_root;
			new_root = new_root->right_child_;
			nodes.push(new_root_parent);
		}

		//将新根值赋给旧根，就是移动新根
		tree_root->data_ = new_root->data_;

		//如果新根就是旧根的左孩子,直接删除重复的新根
		if (new_root_parent == tree_root)
		{
			tree_root->left_child_ = new_root->left_child_;
		}
		//否则还要对接新根的左孩子（新根没有右孩子）
		else
		{
			new_root_parent->right_child_ = new_root->left_child_;
		}

		//删除新根节点
		delete new_root;
		new_root = nullptr;

		//重新从新根父节点开始更新节点高度
		AvlTreeNode<T>* tmp_node = nullptr;
		AvlTreeNode<T>* tmp_node_parent = nullptr;
		while (!nodes.empty())
		{
			tmp_node = nodes.top();
			nodes.pop();
			//更新高度
			tmp_node->height_= max(GetHeight(tmp_node->left_child_), GetHeight(tmp_node->right_child_)) + 1;

			if (!nodes.empty())
			{
				//得到父节点
				tmp_node_parent = nodes.top();
				//如果是右孩子，则返回的新指针指向右孩子，之所以这么做是因为nodes存储的都是拷贝节点指针，无法改变原来的节点指向
				if (tmp_node_parent->right_child_ == tmp_node)
				{
					tmp_node_parent->right_child_ = ReblanceDelete(tmp_node);
				}
				else if (tmp_node_parent->left_child_ == tmp_node)
				{
					tmp_node_parent->left_child_ = ReblanceDelete(tmp_node);                                    
				}
			}
			//如果nodes为空说明只放入一个元素
			else
			{
				tree_root = ReblanceDelete(tmp_node);
			}
		}
	}
	//计算进入这里的根的高度
	if (tree_root != nullptr)
		tree_root->height_ = max(GetHeight(tree_root->left_child_), GetHeight(tree_root->right_child_)) + 1;
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::Remove(AvlTreeNode<T>*& tree_root, const T& data)
/*删除树中的节点，重算高度，重新平衡*/
{
	if (tree_root == nullptr)
		return NULL;

	//递归判断，如果值小于根值，则进入左子树,删除节点并重新平衡
	if (data < tree_root->data_)
	{
		//在左子树中删除节点
		tree_root->left_child_ = Remove(tree_root->left_child_, data);

		//判断是否不平衡，因为是删除左子树，因此只可能是左子树高度小于柚子树2
		if (GetHeight(tree_root->right_child_) - GetHeight(tree_root->left_child_) > 1)
		{
			//RL情况
			if (GetHeight(tree_root->right_child_->right_child_) < GetHeight(tree_root->right_child_->left_child_))
				tree_root = RightLeftRotation(tree_root);
			//RR情况，删除节点会出现柚子树的左右子树一样高，这样RR和RL都可以，但是RR更简单，只需要旋转一次，RL需要旋转两次
			else
				tree_root = RightRightRotation(tree_root);
		}
	}
	//删除节点在柚子树中
	else if (data > tree_root->data_)
	{
		//在柚子树中删除节点
		tree_root->right_child_ = Remove(tree_root->right_child_, data);

		//判断是否发生不平衡，因为删除的是柚子树的节点，因此不平衡只可能是左子树高度比柚子树大1
		if (GetHeight(tree_root->left_child_) - GetHeight(tree_root->right_child_) > 1)
		{
			//LL的情况，当左子树中左右孩子一样高的时候用LL，LR需要两次旋转
			if (GetHeight(tree_root->left_child_->left_child_) >= GetHeight(tree_root->left_child_->right_child_))
				tree_root = LeftLeftRotation(tree_root);
			//LR的情况
			else
				tree_root = LeftRightRotation(tree_root);
		}
	}
	//找到删除节点
	else
	{
		//如果左右子树都不为空，则删除节点的同时，子树也需要平衡，用递归
		//左右子树不为空，且左子树高则取左子树最大节点作为新根，同时删除左子树中的最大节点，因为左子树最多降低高度，
		//但是原来根的平衡不会打破，因此操作更简单，否则需要对原来的根重平衡
		if (tree_root->left_child_ != nullptr && tree_root->right_child_ != nullptr)
		{
			//存放新根
			AvlTreeNode<T>* new_root;

			//如果左子树高则新根为左子树最大节点,则新根为左子树最大节点
			if (GetHeight(tree_root->left_child_) >= GetHeight(tree_root->right_child_))
			{
				new_root = MaxNode(tree_root->left_child_);
				//将新根值赋给旧根实现根的替换
				tree_root->data_ = new_root->data_;
				//在左子树中删除新根节点，并且不会导致原根失去平衡
				tree_root->left_child_ = Remove(tree_root->left_child_, new_root->data_);
			}

			//当柚子树高，选取柚子树最小节点为新根，并在柚子树中删除新根，并且原根不会不平衡
			else
			{
				new_root = MinNode(tree_root->right_child_);
				//将新根赋给旧根，实现根的替换
				tree_root->data_ = new_root->data_;
				//在柚子树中删除旧根
				tree_root->right_child_ = Remove(tree_root->right_child_, new_root->data_);
			}
		}

		//当左右子树不全，包括两边都为空时候，直接返回相应节点并且删除节点，也是递归终止条件
		else
		{
			AvlTreeNode<T>* tmp = tree_root;
			//重新对接节点
			tree_root = (tree_root->left_child_ != nullptr) ? tree_root->left_child_ : tree_root->right_child_;
			//删除节点
			delete tmp;
			tmp = nullptr;
		}
	}

	//重新计算高度，最后一个节点可能为空
	if (tree_root != nullptr)
		tree_root->height_ = CalculateHeight(tree_root);

	//返回新根节点指针
	return tree_root;
}

template<typename T>
inline void AvlTree<T>::Traversal(AvlTreeNode<T>* tree_root, string order_type, int recursion_flag)
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
inline void AvlTree<T>::RecursionPreorderTraversal(AvlTreeNode<T>* tree_root)
/*递归前序遍历二叉树*/
{
	if (!tree_root)
		return;
	cout << setw(5) << tree_root->data_;
	RecursionPreorderTraversal(tree_root->left_child_);
	RecursionPreorderTraversal(tree_root->right_child_);
}

template<typename T>
inline void AvlTree<T>::NonRecursionPreorderTraversal(AvlTreeNode<T>* tree_root)
/*非递归前序遍历二叉树，采用库函数堆栈*/
{
	if (!tree_root)
		return;

	//保留当前节点
	AvlTreeNode<T>* tmp_node = tree_root;
	//保存路径的堆栈，出栈的条件是左孩子和根已经输出，则指针指向右孩子，出栈当前节点
	stack<AvlTreeNode<T>*>nodes;

	//用tmp_node判断仅仅是为了第一次能进去，之所以不在外面放入堆栈，是为了下面第一次进栈不需要判断特殊情况
	while (tmp_node || !nodes.empty())
	{
		//用里面的while来保存从当前节点到最左孩子的路径
		while (tmp_node)
		{
			nodes.push(tmp_node);
			//前序遍历先输出根节点
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->left_child_;
		}

		//从堆栈中取出栈顶元素，并将指针指向右孩子，继续上面的过程，右孩子当成根的情况处理了
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			tmp_node = tmp_node->right_child_;
			//处理完了左孩子和根，弹出元素
			nodes.pop();
		}
	}
}

template<typename T>
inline void AvlTree<T>::RecursionInorderTraversal(AvlTreeNode<T>* tree_root)
/*递归中序遍历二叉树*/
{
	if (!tree_root)
		return;
	RecursionInorderTraversal(tree_root->left_child_);
	cout << setw(5) << tree_root->data_;
	RecursionInorderTraversal(tree_root->right_child_);
}

template<typename T>
inline void AvlTree<T>::NonRecursionInorderTraversal(AvlTreeNode<T>* tree_root)
/*非递归中序遍历二叉树*/
{
	if (!tree_root)
		return;

	//临时节点
	AvlTreeNode<T>* tmp_node=tree_root;
	//保存路径节点的堆栈
	Stack<AvlTreeNode<T>*>nodes;

	//开始遍历节点,不能单独将tmp_node作为条件，因为最后一个节点右孩子可能为空，这时就需要其他判断
	while (tmp_node||!nodes.empty())
	{
		//将当前节点循环到最左孩子
		while (tmp_node)
		{
			nodes.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//调转方向，当最左孩子存储完了，处理左孩子和根节点，然后出栈，然后从右孩子开始上述过程
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->right_child_;
			nodes.pop();
		}
	}
}

template<typename T>
inline void AvlTree<T>::RecursionPostorderTraversal(AvlTreeNode<T>* tree_root)
/*递归后序遍历二叉树*/
{
	if (!tree_root)
		return;
	RecursionPostorderTraversal(tree_root->left_child_);
	RecursionPostorderTraversal(tree_root->right_child_);
	cout << setw(5) << tree_root->data_; 
}

template<typename T>
inline void AvlTree<T>::NonRecursionPostorderTraversal(AvlTreeNode<T>* tree_root)
/*非递归后序遍历二叉树*/
{
	if (!tree_root)
		return;

	//临时节点
	AvlTreeNode<T>* tmp_node=tree_root;
	//最后访问的节点，用来标记右孩子是否已经被访问，才能处理根节点，然后弹出
	AvlTreeNode<T>* lase_visit_node=nullptr;
	//存放路径，右孩子处理后弹出
	Stack<AvlTreeNode<T>*>nodes;
	
	while (tmp_node || !nodes.empty())
	{
		//保存到最左的孩子
		while (tmp_node)
		{
			nodes.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//开始处理节点
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			//如果右孩子处理过或者为空就处理根节点，并出栈
			if (tmp_node->right_child_ == nullptr || tmp_node->right_child_ == lase_visit_node)
			{
				cout << setw(5) << tmp_node->data_;
				nodes.pop();
				//标记当前节点已经处理过了
				lase_visit_node = tmp_node;
				//下一个循环会自动处理下一个节点
				tmp_node = nullptr;
			}
			//如果右孩子不为空且没有处理过则转到右孩子
			else
			{
				tmp_node = tmp_node->right_child_;
			}
		}
	}
}

template<typename T>
inline void AvlTree<T>::LevelorderTraversal(AvlTreeNode<T>* tree_root)
/*层序遍历*/
{
	if (!tree_root)
		return;
	//保存节点，由于是先处理先进去的，因此用队列
	Queue<AvlTreeNode<T>*>nodes;
	AvlTreeNode<T>* tmp_node = tree_root;
	nodes.push(tmp_node);
	while (!nodes.empty())
	{
		tmp_node = nodes.front();
		nodes.pop();
		cout << setw(5) << tmp_node->data_;
		//如果有左孩子先将左孩子入队
		if (tmp_node->left_child_)
			nodes.push(tmp_node->left_child_);
		if (tmp_node->right_child_)
			nodes.push(tmp_node->right_child_);
	}
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::MaxNode(AvlTreeNode<T>* tree_root)
/*得到最大节点*/
{
	AvlTreeNode<T>* node = tree_root;
	if (!tree_root)
		return nullptr;

	while (node->right_child_)
		node = node->right_child_;
	return node;
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::MinNode(AvlTreeNode<T>* tree_root)
/*得到树的最小节点*/
{
	AvlTreeNode<T>* node = tree_root;
	if (!tree_root)
		return NULL;

	while (node->left_child_)
		node = node->left_child_;
	return node;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::PreviousNode(AvlTreeNode<T>* tree_root, const T& data)
/*得到元素在中序遍历中的前一个元素，找左子树中的最大元素，如果没有则查找值小于当前节点的父节点，如果找到根节点还不是则是*/
{
	AvlTreeNode<T>* node = tree_root;
	//查找到的前一个节点
	AvlTreeNode<T>* previous_node = nullptr;

	if (!node)
		return NULL;

	//不为空则先查找到当前节点
	Stack<AvlTreeNode<T>*>nodes;
	while (node)
	{
		if (node->data_ == data)
			break;
		nodes.push(node);
		if (node->data_ > data)
			node = node->left_child_;
		else if (node->data_ < data)
			node = node->right_child_;
	}

	//如果没找到则返回空
	if (!node)
		return nullptr;

	//如果找到则先查找左子树最大节点
	if (node->left_child_)
		previous_node = MaxNode(node->left_child_);

	//如果没有左子树则查找第一个小于节点值的父节点
	else if (!nodes.empty())
	{
		while (!nodes.empty())
		{
			node = nodes.top();
			if (data > node->data_)
			{
				previous_node = node;
				break;
			}
			else
				nodes.pop();
		}
	}
	else
		previous_node = nullptr;

	return previous_node;
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::ForwardNode(AvlTreeNode<T>* tree_root, const T& data)
/*查找节点在中序遍历中的后一个元素，先在柚子树中查找最小节点，如果没有则查找第一个大于节点值的父节点*/
{
	if (!tree_root)
		return NULL;

	AvlTreeNode<T>* node = tree_root;
	//查找的后一个节点
	AvlTreeNode<T>* forward_node = nullptr;
	//存放父节点路径
	Stack<AvlTreeNode<T>*>nodes;

	//先查找这个节点
	while (node)
	{
		if (node->data_ == data)
			break;
		nodes.push(node);
		if (node->data_ < data)
		{
			node = node->right_child_;
		}
		else
			node = node->left_child_;
	}

	//如果没有查找到则返回空指针
	if (!node)
		return nullptr;

	//查找到了节点就先查看柚子树中的最小节点
	//如果有柚子树则查找柚子树
	if (node->right_child_)
		forward_node = MinNode(node->right_child_);
	//有父节点就查找父节点
	else if (!nodes.empty())
	{
		//查到根节点还没有符合要求的，这里默认返回的是NULL
		while (!nodes.empty())
		{
			node = nodes.top();
			if (node->data_ > data)
			{
				forward_node = node;
				break;
			}
			else
				nodes.pop();
		}

		//如果找到根节点还是没有，则返回NULL
		if (nodes.empty())
			forward_node = nullptr;
	}
	else
		forward_node = nullptr;
	return forward_node;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::ConstructByDatas(void(*pfunc)(AvlTreeNode<T>*&, T), T* datas_array, T array_len)
/*根据数据构建AVL树*/
{
	if (array_len <= 0)
		return nullptr;

	int i;
	AvlTreeNode<T>* root=nullptr;
	
	//遍历每个数据构造
	for (i = 0; i < array_len; ++i)
	{
		pfunc(root, datas_array[i]);
	}
	return root;
}

