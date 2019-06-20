#pragma once
#pragma warning(disable : 4996)
#include<vector>
#include<iomanip>
#include<iostream>
#include<string>

using namespace std;
/*哈夫曼树节点和树操作

赫夫曼树的存储结构，它也是一种二叉树结构，
这种存储结构既适合表示树，也适合表示森林。
本质是双亲表示法*/

template <typename T>
class HuffmanTreeNode
{
public:
	HuffmanTreeNode();
	HuffmanTreeNode(T weight, int parent = -1, int left_child = -1,int right_child=-1):weight_(weight),parent_(parent),left_child_(left_child),right_child_(right_child){}
	~HuffmanTreeNode();
public:
	//双亲表示法中的父节点下标,-1表示根节点
	int parent_;
	//左孩子下标，左右孩子都为-1则表示叶结点
	int left_child_;
	//右孩子下标
	int right_child_;
	//权重
	T weight_;
};

template<typename T>
inline HuffmanTreeNode<T>::HuffmanTreeNode()
{
	parent_ = -1;
	left_child_ = -1;
	right_child_ = -1;
}

template<typename T>
inline HuffmanTreeNode<T>::~HuffmanTreeNode()
{
}


template <typename T>
class HuffmanTree
{
public:
	HuffmanTree(){}
	HuffmanTree(vector<T>weights):weights_(weights){}
	~HuffmanTree(){}
public:
	//得到权重数据
	vector<T>get_weights();
	//设置权重数据
	void set_weights(vector<T>weights);
	//构造哈夫曼树
	void ConstructTree();
	//得到前n个数中最小权重的根节点下标,返回-1表示不存在
	int GetMin(int n);
	//按树形状打印哈夫曼树
	void Show();
	//对每个权重叶子节点进行编码
	void HuffmanCode();
	//显示编码
	void ShowCode();
private:

	//对一课哈夫曼树进行编码，并返回相应编码
	vector<string> HuffmanCodeFromLeaf(vector<HuffmanTreeNode<T>>nodes);
	//哈夫曼编码，从根节点开始编码
	vector<string> HuffmanCodeFromRoot(vector<HuffmanTreeNode<T>>nodes);
	//在给定位置打印树,树节点在n个控制的地方打印
	//void ShowWithLocation(HuffmanTreeNode<T>node, int n, int to_be_printed);
private:
	//保存原来的权重数据
	vector<T>weights_;
	//保存节点，初始保存森林，最后保存哈夫曼树
	vector<HuffmanTreeNode<T>>nodes_;
	//保存哈夫曼编码
	vector<string>codes_;
};

template<typename T>
inline vector<T> HuffmanTree<T>::get_weights()
/*得到权重数据*/
{
	return weights_;
}

template<typename T>
inline void HuffmanTree<T>::set_weights(vector<T> weights)
/*设置权重数据*/
{
	weights_ = weights;
}

template<typename T>
void HuffmanTree<T>::ConstructTree()
/*建造二叉树*/
{
	if (weights_.empty())
		return;

	//先初始化所有哈夫曼树节点，叶子节点数n个，则总结点数为2n-1个
	//临时节点
	HuffmanTreeNode<T>node;
	node.parent_ = -1;
	node.left_child_ = -1;
	node.right_child_ = -1;

	//遍历权重向量先初始化所有节点为树
	typename vector<T>::const_iterator iter;
	for (iter = weights_.begin(); iter != weights_.end(); iter++)
	{
		node.weight_ = *iter;
		nodes_.push_back(node);
	}

	//将其他哈夫曼节点也生成
	for (int i = 0; i < (int)weights_.size() - 1; i++)
	{
		nodes_.push_back(node);
	}

	//生成非叶子节点，每次选取权重最小的根节点组合成一个新节点，权重小的作为左孩子
	//权重数
	int n = weights_.size();
	//哈夫曼节点数
	int total = 2 * n - 1;
	//保存最小权重根节点下标
	int min_index;
	//次小根节点下标
	int second_min_index;
	for (int i = n; i < total; i++)
	{
		//得到权重最小的两个节点
		min_index = GetMin(i);
		second_min_index = GetMin(i);
		//如果没有最小的两个节点则报错
		if (min_index == -2 || second_min_index == -2)
			throw "no two min weight";
		//得到新节点
		nodes_[i].left_child_ = min_index;
		nodes_[i].right_child_ = second_min_index;
		nodes_[i].weight_ = nodes_[min_index].weight_ + nodes_[second_min_index].weight_;
		nodes_[i].parent_ = -1;
		//更新孩子节点的父节点信息
		nodes_[min_index].parent_ = i;
		nodes_[second_min_index].parent_ = i;
	}
}

template<typename T>
int HuffmanTree<T>::GetMin(int n)
/*得到前n个数汇总权重最小的根节点下标*/
{
	T min_weight;
	int index=-1;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (nodes_[i].parent_ == -1)
		{
			if (flag)
			{
				if (min_weight > nodes_[i].weight_)
				{
					min_weight = nodes_[i].weight_;
					index = i;
				}
			}
			//第一次直接初始化
			else
			{
				min_weight = nodes_[i].weight_;
				flag = true;
				index = i;
			}
		}
	}
	//将查找到的节点父节点置为-2，以免下次筛选看最小节点筛选到
	if (index >= 0 && index < n)
		nodes_[index].parent_ = -2;
	return index;
}

template<typename T>
inline void HuffmanTree<T>::Show()
/*打印树*/
{
	cout << "start show tree:" << endl;
	if (nodes_.empty())
	{
		cout << "tree is empty." << endl;
		return;
	}
	//得到根节点
	for (int i=0;i<(int)nodes_.size();i++)
	{
		cout << setw(6) << "index: " << setw(6) << i << "  weight: " << nodes_[i].weight_ << "  parent: " << nodes_[i].parent_;
		cout << "  left child:  " << nodes_[i].left_child_ << "  right child:  " << nodes_[i].right_child_ << endl;
	}
}

template<typename T>
inline void HuffmanTree<T>::HuffmanCode()
/*哈夫曼编码控制函数*/
{
	//从节点到根节点编码
	//codes_ = HuffmanCodeFromLeaf(nodes_);
	//从根节点到叶子节点遍历
	codes_ = HuffmanCodeFromRoot(nodes_);
}

template<typename T>
inline void HuffmanTree<T>::ShowCode()
/*显示编码*/
{
	cout << "start show huffman codes." << endl;
	//for (vector<string>::const_iterator iter = codes_.begin(); iter != codes_.end(); iter++)
	for(int i=0;i<codes_.size();i++)
	{
		cout << "weight: " << setw(10) << weights_[i] <<"  code: "<< setw(10) << codes_[i] << endl;
	}
	cout << endl;
}

template<typename T>
vector<string> HuffmanTree<T>::HuffmanCodeFromLeaf(vector<HuffmanTreeNode<T>> nodes)
/*从叶子节点开始编码*/
{
	if (nodes.empty())
		return vector<string>();

	//保存当前节点
	HuffmanTreeNode<T>node;
	//保存编码结果
	vector<string>codes;
	//保存一个编码,编码最多只有叶子节点个数,加一个是为了能处理只有一个字符需要编码
	int n = (nodes.size() + 1) / 2+1;
	//char* code = new char[n];

	//code[n - 1] = '\0';
	//叶子节点计数
	int j = 0;

	//从叶子节点开始编码
	for (int i = 0; i < (int)nodes.size(); i++)
	{
		//不是叶子节点跳过
		if (nodes[i].left_child_ != -1 || nodes[i].right_child_ != -1)
			continue;
		//指向当前编码值,最后指向code中编码的开头，方便拷贝出来
		//放在循环内部才可以每次都复制相应的新编码
		int start = n - 1;
		//查看父节点，如果节点是父节点的左孩子则编码加入0，否则加入1，因为是从叶子节点开始编码，因此code从最后一个向前添加编码
		node = nodes[i];
		//当前的访问节点下标
		int current = i;
		//保存编码
		string code;
		while (node.parent_ != -1)
		{
			//左子节点则添加0到code末尾
			if (nodes[node.parent_].left_child_ == current)
				code.insert(code.begin(), '0');
			else if (nodes[node.parent_].right_child_ == current)
				code.insert(code.begin(), '1');
			else
			{
				Show();
				throw "wrong huffman nodes.";
			}
			//更新当前处理的节点下标
			current = node.parent_;
			//将当前节点指向父节点
			node = nodes[node.parent_];
		}
		//将编码拷贝进编码数组中，如果为一个字符不需要编码，会返回空codes
		//windows下会出错
		//strcpy(codes[j++], code + start);
		//也不能是仅仅对指针复制，每次都会改写上一次的编码，所以必须用复制
		//而配合指针的复制必须是指针数组，不能用vector，用vector就需要用string作为元素方便
		codes.push_back(code);
		//用memcpy也不好求源数组大小，用strncpy也不好确定数组大小（包括终止符）
		//strncpy(codes[j++],code+start,)
	}

	//删除code
	//delete code;
	//code = nullptr;
	//返回编码
	return codes;
}

template<typename T>
inline vector<string> HuffmanTree<T>::HuffmanCodeFromRoot(vector<HuffmanTreeNode<T>> nodes)
/*哈夫曼编码，从根节点开始编码,对数进行复制传参，这样可以对weight做修改而不会影响到原来的树*/
{
	if (nodes.empty())
		return vector<string>();

	//先将所有weight改为0，当weight=0时，左右孩子都没访问，weight=1时，左孩子被访问了，weight=2
	//标明左右孩子都被访问了，这时需要将下标指向父亲节点，并将编码回退一个
	for (typename vector<HuffmanTreeNode<T>>::iterator iter = nodes.begin(); iter != nodes.end(); iter++)
		(* iter).weight_ = 0;

	//叶子节点个数
	int n = (nodes.size() + 1) >> 1;
	//保存编码下标和树叶子节点下标一一对应，为了方便直接插入非第一个节点，因此在这里将节点都申请空间
	vector<string>codes(n);
	//保存单个编码
	string code;
	//从根节点开始编码,为-1时结束
	int current = nodes.size()-1;

	//循环遍历树，本质是前序遍历
	//从根节点开始前序遍历，最后回到根节点，知道根节点父节点，编码结束
	while (current != -1)
	{
		//左右子树都没访问，则先访问左子树
		if (nodes[current].weight_ == 0)
		{
			//先设置标志表示左子树被访问过
			nodes[current].weight_ = 1;
			//如果左子树不为空则继续遍历左子树并添加编码
			if (nodes[current].left_child_ != -1)
			{
				//添加编码
				code.append("0");
				//将当前下标设置为左孩子
				current = nodes[current].left_child_;
			}
		}
		//如果左子树被访问了
		else if (nodes[current].weight_ == 1)
		{
			//设置标志表示左右子树都被访问了
			nodes[current].weight_ = 2;
			//如果柚子树不为空则遍历柚子树
			if (nodes[current].right_child_ != -1)
			{
				//添加编码
				code.append("1");
				//将下标设置为右孩子
				current = nodes[current].right_child_;
			}
			//右孩子为空
			else
			{
				//如果左孩子也为空则是叶子节点，添加编码
				if (nodes[current].left_child_ == -1)
				{
					codes[current] = code;
				}
			}
		}
		//如果左右子树都访问了则回退
		else
		{
			//将当前下标设为父节点下标
			current = nodes[current].parent_;
			//删除一个编码
			//如果回到根节点，这时候字符串为空，不能删除
			if (current != -1)
				code.erase(code.end() - 1);
		}
	}
	return codes;
}

