#pragma once
/*用两个队列构造堆栈,申明两个队列，一个主要队列，一个次要队列，主要队列队首作为栈顶，方便直接出栈
入栈需要导入到另个一队列*/

#include<queue>

template <typename T>
class StackQueue
{
public:
	StackQueue();
	~StackQueue();
public:
	bool empty() const;
	int size() const;
	T top() const;
	void push(const T& data);
	void pop();
private:
	//主要队列
	queue<T>primary_;
	//次要队列
	queue<T>second_;
};

template<typename T>
inline StackQueue<T>::StackQueue()
{
}

template<typename T>
inline StackQueue<T>::~StackQueue()
{
}

template<typename T>
inline bool StackQueue<T>::empty() const
{
	return primary_.empty();
}

template<typename T>
inline int StackQueue<T>::size() const
{
	return primary_.size();
}

template<typename T>
inline T StackQueue<T>::top() const
{
	return primary_.front();
}

template<typename T>
inline void StackQueue<T>::push(const T& data)
{
	while (!second_.empty())
		second_.pop();
	second_.push(data);
	T tmp_data;
	while (!primary_.empty())
	{
		tmp_data = primary_.front();
		second_.push(tmp_data);
		primary_.pop();
	}
	//重新导入主要队列中
	while (!second_.empty())
	{
		tmp_data = second_.front();
		second_.pop();
		primary_.push(tmp_data);
	}
}

template<typename T>
inline void StackQueue<T>::pop()
{
	primary_.pop();
}
