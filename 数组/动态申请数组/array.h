#pragma once

/*
 C/C++中动态开辟一维、二维数组是非常常用的，以前没记住，做题时怎么也想不起来，现在好好整理一下。

 C++中有三种方法来动态申请多维数组

  (1)C中的malloc/free

  (2)C++中的new/delete

  (3)STL容器中的vector
*/

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

//用malloc申请一维数组
void malloc_one_dimension();

//用malloc申请二维数组
void malloc_two_dimension();

//用new申请一维数组
void new_one_dimension();

//用new申请二维数组
void new_two_dimension();

//用new申请内存的变种
void new_two_dimension_2();

//用动态数组vector申请一位数组
void vector_one_demension();

//用动态数组vector申请二维数组
void vector_two_demensions();