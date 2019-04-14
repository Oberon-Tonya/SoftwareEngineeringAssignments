#include "MaxSubarray.h"
//#include <vector>
#define POSCLIP(X) (X>0)?X:0
#define MAX(X,Y) (X>Y)?X:Y

using namespace std;

RangeBlock MaxSubArray(vector<int> arry)
{
	RangeBlock rb = { 0,-1,-1 };
	if (arry.size() == 0)
	{
		return rb;
	}
	int maxsum = 0;
	int sum = 0;
	int kickoff = 0;
	for (int i = 0; i < arry.size(); i++)
	{
		sum = POSCLIP(sum + arry[i]);
		maxsum = MAX(sum, maxsum);
		if (sum == 0 && arry[i] < 0)
		{
			kickoff = i + 1;
			//rb.end = rb.start;
		}
		else if(sum == maxsum)
		{
			rb.start = kickoff;
			rb.end = i;
		}
	}
	rb.sum = maxsum;
	if (rb.start >= arry.size())
	{
		rb.start = rb.end = -1;
	}
	return rb;
}
