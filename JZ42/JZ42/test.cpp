#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> sum;
		sum.resize(nums.size()); //sum数组当中的元素个数与nums数组相同
		sum[0] = nums[0]; //以第0个元素为结束的最大子数组和就是其本身
		//依次计算sum数组当中的元素
		for (int i = 1; i < sum.size(); i++)
		{
			sum[i] = max(sum[i - 1] + nums[i], nums[i]);
		}
		//选出sum数组的最大元素，即数组nums的连续子数组最大和
		int max = sum[0];
		for (int i = 1; i < sum.size(); i++)
		{
			if (sum[i] > max)
				max = sum[i];
		}
		return max; //返回数组nums的连续子数组最大和
	}
};

int main()
{
	vector<int> v{ 1, -2, 3, 10, -4, 7, 2, -5 };
	cout << Solution().maxSubArray(v) << endl;
	return 0;
}