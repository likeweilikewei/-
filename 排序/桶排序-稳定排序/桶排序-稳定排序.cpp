// 桶排序-稳定排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<iomanip>

using namespace std;

//桶的个数
const int kBucketNumber = 10;

//每个桶都是一个链表，所有桶组织在vector中
template <typename T>
struct ListNode
{
	explicit ListNode(T data) :data_(data),next_(nullptr) {};
	ListNode* next_;
	T data_;
};

template <typename T>
void Insert(ListNode<T>** head_pointer, T data)
/*在链表中按排序插入数据*/
{
	//原指针
	ListNode<T>* head = *head_pointer;
	//显示调用拷贝构造函数
	ListNode<T>* new_node = new(nothrow) ListNode<T>(data);
	//申请失败退出
	if (new_node == nullptr)
		throw "ERROR:new failed.";
	//当源指针为空直接对接
	if (head == nullptr)
	{
		*head_pointer = new_node;
		return;
	}
	else
	{
		//当元素小于头元素时候直接插入到头元素之前
		if (data < head->data_)
		{
			new_node->next_ = head;
			*head_pointer = new_node;
			return;
		}
		else
		{
			//查找升序的合适位置，为了保证稳定性，插在相同元素的后面
			while (head->next_ != nullptr && head->next_->data_ <= data)
				head = head->next_;
			//如果到了尾部直接加上去
			if (head->next_ == nullptr)
				head->next_ = new_node;
			//否则插入到中间
			else
			{
				new_node->next_ = head->next_;
				head->next_ = new_node;
			}
			return;
		}
	}
}

template<typename T>
void BucketSort(vector<T>& values)
{
	if (values.empty())
		return;
	int n = values.size();
	//申请桶
	vector<ListNode<int>*>buckets(kBucketNumber, (ListNode<int>*)0);
	//申明一个空指针
	//ListNode<int>* node = (ListNode<int>*) 0;
	//if (node == nullptr)
	//	cout << "yke" << endl;
	//得到最大和最小元素
	int max_value = INT_MIN;
	int min_value = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (values[i] < min_value)
			min_value = values[i];
		if (values[i] > max_value)
			max_value = values[i];
	}
	//计算每个桶需要装多少元素,每个桶的范围
	double numbers = (double)(max_value - min_value+1) / kBucketNumber;
	//元素分在floor((values[i]-min_value)/numbers)编号的桶里
	for (int i = 0; i < n; i++)
	{
		Insert(&buckets[floor((values[i] - min_value) / numbers)], values[i]);
	}
	//将桶合并起来就是排序好的数组
	//排序数组下标
	int j = 0;
	for (int i = 0; i < kBucketNumber; i++)
	{
		ListNode<int>* tmp = buckets[i];
		while (tmp != nullptr)
		{
			values[j++] = tmp->data_;
			tmp = tmp->next_;
		}
	}
}


int main()
{
	////可以将结果转化为double
	//auto b = 1.5 / 2;
	////都可以向下取整
	//b = int(b);
	//b = floor(b);
	//cout << "b" << b << endl;
	////这样是先取整了再转化的，损失了精度
	//auto a = (double)(2 / 3);
	////这样才不会损失
	//a = (double)2 / 3;
	//cout << a << endl;
	//abort();
	cout << "input numbers:" << endl;
	int n;
	while (cin >> n)
	{
		if (n > 0)
			break;
		cout << "input again." << endl;
	}
	vector<int>values;
	for (int i = 0; i < n; i++)
	{
		cout << "input number:" << endl;
		int tmp;
		cin >> tmp;
		values.push_back(tmp);
	}
	BucketSort(values);
	//输出排序数组
	for (int i = 0; i < n; i++)
		cout << setw(5) << values[i];
}

