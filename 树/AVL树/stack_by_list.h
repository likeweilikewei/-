#pragma once
/*用链表定义堆栈,将链表的头当做堆栈的栈顶*/

template <typename T>
class StackList
{
public:
	StackList();
	~StackList();
	int size() const;
	bool empty() const;
	T& top();
	void push(const T& data);
	void pop();

private:
	list<T> stack_;
};

template<typename T>
inline StackList<T>::StackList()
{
}

template<typename T>
inline StackList<T>::~StackList()
{
}

template<typename T>
inline int StackList<T>::size() const
{
	return stack_.size();
}

template<typename T>
inline bool StackList<T>::empty() const
{
	return Stack.empty();
}

template<typename T>
inline T& StackList<T>::top()
{
	return stack_.front();
}

template<typename T>
inline void StackList<T>::push(const T& data)
{
	stack_.push_front(data);
}

template<typename T>
inline void StackList<T>::pop()
{
	if (stack_.empty())
		throw "ERROR:Stack is empty,can not pop.";
	stack_.pop_front();
}
