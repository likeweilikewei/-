#pragma once
/*
��������ֻ�����ڼ򵥵ĺ�����������ѭ���ݹ�ȣ������Լ�������õĿ��������ǻḳֵ���룬��������Ӧ�ڴ�
inline��÷��ڶ���ĵط�����������������÷���ͷ�ļ���
��ģ��ƥ��Ļ��ƣ��õ������ͱȽϺ����������൱��typeinfo�е�typeid���÷�
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
