#pragma once
/*用两个堆栈构造一个队列,将栈顶当做队尾，方便入队，出队时将数据导入另一个堆栈，然后弹出栈顶，再倒回堆栈即可
为了方便取队首，将队首元素也存入另一个堆栈中*/

#include<stack>

template <typename T>
class QueueStack
{
public:
	QueueStack();
	~QueueStack();
public:
	int size() const;
	bool empty() const;
	T front() const;
	T back() const;
	void push(const T& data);
	void pop();
private:
	//主要存取数据的堆栈
	stack<T>primary_;
	//辅助堆栈
	stack<T>second_;
	//清空主要和次要的堆栈
	void Clear();
};

template<typename T>
inline QueueStack<T>::QueueStack()
{
}

template<typename T>
inline QueueStack<T>::~QueueStack()
{
}

template<typename T>
inline int QueueStack<T>::size() const
{
	return primary_.size();
}

template<typename T>
inline bool QueueStack<T>::empty() const
{
	return primary_.empty();
}

template<typename T>
inline T QueueStack<T>::front() const
{
	if (empty())
		throw "ERROR:queue is empty.";
	return second_.top();
}

template<typename T>
inline T QueueStack<T>::back() const
{
	if (empty())
		throw "ERROR:queue is empty.";
	return primary_.top();
}

template<typename T>
inline void QueueStack<T>::push(const T& data)
/*进栈，首元素在次要栈中叶放一个，将栈顶当做队尾*/
{
	if (empty())
	{
		primary_.push(data);
		while (!second_.empty())
			second_.pop();
		second_.push(data);
	}
	else
	{
		primary_.push(data);
	}
}

template<typename T>
inline void QueueStack<T>::pop()
/*出栈*/
{
	if (empty())
		throw "ERROR:queue is empty, can not pop.";
	T back_data;
	T tmp_data;

	while (!second_.empty())
	{
		second_.pop();
	}
	//将主要栈中数据导入次要栈中
	while (!primary_.empty())
	{
		tmp_data = primary_.top();
		primary_.pop();
		second_.push(tmp_data);
	}
	//弹出次要栈栈顶就是队列的队首出栈
	second_.pop();
	//如果只有一个元素并且弹出了结束
	if (second_.empty())
		return;

	//新队首元素
	back_data = second_.top();
	//倒回原来的栈
	while (!second_.empty())
	{
		tmp_data = second_.top();
		primary_.push(tmp_data);
		second_.pop();
	}
	//将新队首元素放入次要栈中
	second_.push(back_data);
}

template<typename T>
inline void QueueStack<T>::Clear()
{
	while (!primary_.empty())
		primary_.pop();
	while (!second_.empty())
		second_.pop();
}
