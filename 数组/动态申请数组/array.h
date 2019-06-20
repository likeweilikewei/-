#pragma once

/*
 C/C++�ж�̬����һά����ά�����Ƿǳ����õģ���ǰû��ס������ʱ��ôҲ�벻���������ںú�����һ�¡�

 C++�������ַ�������̬�����ά����

  (1)C�е�malloc/free

  (2)C++�е�new/delete

  (3)STL�����е�vector
*/

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

//��malloc����һά����
void malloc_one_dimension();

//��malloc�����ά����
void malloc_two_dimension();

//��new����һά����
void new_one_dimension();

//��new�����ά����
void new_two_dimension();

//��new�����ڴ�ı���
void new_two_dimension_2();

//�ö�̬����vector����һλ����
void vector_one_demension();

//�ö�̬����vector�����ά����
void vector_two_demensions();