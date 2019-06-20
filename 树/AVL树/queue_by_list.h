#pragma once
/*用list定义队列*/
#include<list>

template <typename T>
class QueueList
{
public:
	QueueList();
	~QueueList();
	int size() const;
	bool empty() const;
	T& front();
	T& back();
	void push(const T& data);
	void pop();

private:
	list<T> queue_;
};

template<typename T>
inline QueueList<T>::QueueList()
{
}

template<typename T>
inline QueueList<T>::~QueueList()
{
}

template<typename T>
inline int QueueList<T>::size() const
{
	return queue_.size();
}

template<typename T>
inline bool QueueList<T>::empty() const
{
	return queue.empty();
}

template<typename T>
inline T& QueueList<T>::front()
{
	return queue_.front();
}

template<typename T>
inline T& QueueList<T>::back()
{
	return queue_.back();
}

template<typename T>
inline void QueueList<T>::push(const T& data)
{
	queue_.push_back(data);
}

template<typename T>
inline void QueueList<T>::pop()
{
	if (queue_.empty())
		throw "ERROR:queue is empty,can not pop.";
	queue_.pop_front();
}
