#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> sum;
		sum.resize(nums.size()); //sum���鵱�е�Ԫ�ظ�����nums������ͬ
		sum[0] = nums[0]; //�Ե�0��Ԫ��Ϊ���������������;����䱾��
		//���μ���sum���鵱�е�Ԫ��
		for (int i = 1; i < sum.size(); i++)
		{
			sum[i] = max(sum[i - 1] + nums[i], nums[i]);
		}
		//ѡ��sum��������Ԫ�أ�������nums����������������
		int max = sum[0];
		for (int i = 1; i < sum.size(); i++)
		{
			if (sum[i] > max)
				max = sum[i];
		}
		return max; //��������nums����������������
	}
};

int main()
{
	vector<int> v{ 1, -2, 3, 10, -4, 7, 2, -5 };
	cout << Solution().maxSubArray(v) << endl;
	return 0;
}