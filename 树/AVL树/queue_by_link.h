#pragma once
/*用单链表定义队列*/

//定义链表节点
template <typename T>
class QueueNode
{
public:
	QueueNode(QueueNode<T>*next=nullptr):next_(next){}
	QueueNode(const T& data,QueueNode<T>*next=nullptr):data_(data),next_(next){}
	~QueueNode(){}
	T data_;
	QueueNode<T>* next_;
};

template <typename T>
class QueueLink
{
public:
	QueueLink();
	~QueueLink();
	int size() const;
	bool empty() const;
	T front() const;
	T back() const;
	void push(const T& data);
	void pop();

private:
	//指向队列头
	QueueNode<T>* front_;
	//指向队列尾
	QueueNode<T>* back_;
	//清空队列
	void Clear();
};

template<typename T>
inline QueueLink<T>::QueueLink():front_(nullptr),back_(nullptr)
{
}

template<typename T>
inline QueueLink<T>::~QueueLink()
{
	Clear();
}

template<typename T>
inline int QueueLink<T>::size() const
{
	int count = 0;
	QueueNode<T>* tmp_node = front_;
	while (tmp_node)
	{
		count += 1;
		tmp_node = tmp_node->next_;
	}
	return count;
}

template<typename T>
inline bool QueueLink<T>::empty() const
{
	return nullptr==front_;
}

template<typename T>
inline T QueueLink<T>::front() const
{
	if (empty())
		throw "ERROR:queue is empty.";
	return front_->data_;
}

template<typename T>
inline T QueueLink<T>::back() const
{
	if (empty())
		throw "ERROR:queue is empty.";
	return back_->data_;
}

template<typename T>
inline void QueueLink<T>::push(const T& data)
{
	QueueNode<T>* new_node = new QueueNode<T>(data);
	if (!new_node)
		throw "ERROR:new failed.";
	if (empty())
	{
		front_ = new_node;
		back_ = new_node;
	}
	else
	{
		back_->next_ = new_node;
		back_ = back_->next_;
	}
}

template<typename T>
inline void QueueLink<T>::pop()
{
	if (empty())
		throw "ERROR:queue is empty,can not pop.";
	QueueNode<T>* tmp_node = front_;
	if (!front_->next_)
	{
		front_ = nullptr;
		back_ = nullptr;
	}
	else
	{
		front_ = front_->next_;
	}
	delete tmp_node;
	tmp_node = nullptr;
}

template<typename T>
inline void QueueLink<T>::Clear()
{
	QueueNode<T>* node;
	while (!front_)
	{
		node = front_;
		front_ = front_->next_;
		delete node;
		node = nullptr;
	}
	back_ = nullptr;
}
