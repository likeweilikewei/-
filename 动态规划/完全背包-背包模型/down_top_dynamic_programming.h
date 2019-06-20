#pragma once
#include<vector>
#include<algorithm>

using namespace std;

//自底向上动态规划求解完全背包问题
int bag(int n, int capacity, vector<int>values, vector<int>weights);
