#pragma once
/*用单链表定义堆栈，链表头当做栈顶，单链表带头结点，头结点指向链表头，这样链表头不用因为出栈 进栈变换方向*/

//定义链表节点
template <typename T>
class StackNode
{
public:
	StackNode(StackNode<T>* next = nullptr) :next_(next) {}
	StackNode(const T& data, StackNode<T>* next = nullptr) :data_(data), next_(next) {}
	~StackNode() {}
	T data_;
	StackNode<T>* next_;
};

template <typename T>
class StackLink
{
public:
	StackLink();
	~StackLink();
	int size() const;
	bool empty() const;
	T top() const;
	void push(const T& data);
	void pop();

private:
	//下一个指向栈顶
	StackNode<T>* top_;
	void Clear();
};

template<typename T>
inline StackLink<T>::StackLink()
{
	//申请一个头结点
	top_ = new StackNode<T>;
}

template<typename T>
inline StackLink<T>::~StackLink()
{
	Clear();
}

template<typename T>
inline int StackLink<T>::size() const
{
	int count = 0;
	StackNode<T>* tmp_node = top_->next_;
	while (tmp_node)
	{
		count += 1;
		tmp_node = tmp_node->next_;
	}
	return count;
}

template<typename T>
inline bool StackLink<T>::empty() const
{
	return nullptr == top_->next_;
}

template<typename T>
inline T StackLink<T>::top() const
{
	if (empty())
		throw "ERROR:stack is empty.";
	return top_->next_->data_;
}

template<typename T>
inline void StackLink<T>::push(const T& data)
{
	StackNode<T>* new_node = new StackNode<T>(data);
	if (!new_node)
		throw "ERROR:new failed.";
	new_node->next_ = top_->next_;
	top_->next_ = new_node;
}

template<typename T>
inline void StackLink<T>::pop()
{
	if (empty())
		throw "ERROR:stack is empty,can not pop.";
	StackNode<T>* tmp_node = top_->next_;
	top_->next_ = top_->next_->next_;
	delete tmp_node;
	tmp_node = nullptr;
}

template<typename T>
inline void StackLink<T>::Clear()
{
	StackNode<T>* tmp_node;
	while (!top_->next_)
	{
		tmp_node = top_->next_;
		delete tmp_node;
		top_->next_ = top_->next_->next_;
		tmp_node = nullptr;
	}
	delete top_;
	top_ = nullptr;
}
