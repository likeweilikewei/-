#pragma once
/*
内联函数只能用于简单的函数，不能有循环递归等，它会节约函数调用的开销，但是会赋值代码，增加了相应内存
inline最好放在定义的地方，内联函数定义最好放在头文件中
用模板匹配的机制，得到了类型比较函数，作用相当于typeinfo中的typeid的用法
*/

template<typename T> bool isSameType(const T&, const T&);
template<typename T1, typename T2> bool isSameType(const T1&, const T2&);

template<typename T>
inline bool isSameType(const T& t1, const T& t2)
{
	return true;
}

template<typename T1, typename T2>
inline bool isSameType(const T1& t1, const T2& t2)
{
	return false;
}
