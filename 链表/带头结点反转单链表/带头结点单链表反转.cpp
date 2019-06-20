// 题目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
#include"head_link.h"

using namespace std;

#ifndef NULL
#define NULL 0
#endif

Node* root=NULL;

int main()
{
	root = construct();
	traverse(root);
	reversal_1(root);
	traverse(root);
	reversal_2(root);
	traverse(root);
	reversal_3(root);
	traverse(root);
	reversal_4(root);
	traverse(root);
}
