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
			//��left��rightλ�õ��������
			int sum = numbers[left] + numbers[right];
			//1�����sumС��target������left++��ʹ��sum���
			if (sum < target)
			{
				left++;
			}
			//2�����sum����target������right--��ʹ��sum��С
			else if (sum > target)
			{
				right--;
			}
			//3�����sum��target��ȣ����䱣�ַ���
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