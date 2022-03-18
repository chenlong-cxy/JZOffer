#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		size_t left = 0;
		size_t right = numbers.size() - 1;
		vector<int> ret;
		while (left < right)
		{
			//将left和right位置的数据相加
			int sum = numbers[left] + numbers[right];
			//1、如果sum小于target，则让left++，使得sum变大
			if (sum < target)
			{
				left++;
			}
			//2、如果sum大于target，则让right--，使得sum变小
			else if (sum > target)
			{
				right--;
			}
			//3、如果sum和target相等，则将其保持返回
			else
			{
				ret.push_back(left);
				ret.push_back(right);
				break;
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> v{ 1, 2, 4, 6, 10 };
	vector<int> ret = Solution().twoSum(v, 8);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}