#pragma once
#include <vector>
using namespace std;

struct RangeBlock
{
	int sum;
	int start;
	int end;
};

RangeBlock MaxSubArray(vector<int > arry);