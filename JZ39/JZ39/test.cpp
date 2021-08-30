#include <iostream>
#include <vector>
using namespace std;
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {
//		HeapSort(numbers);
//		return numbers[numbers.size() / 2];
//	}
//	void AdjustDown(vector<int>& n, int sz, int root)
//	{
//		int parent = root;
//		int child = 2 * parent + 1;
//		while (child < sz)
//		{
//			if (child + 1 < sz&&n[child + 1] > n[child])
//				child++;
//			if (n[child] > n[parent])
//			{
//				swap(n[child], n[parent]);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//				break;
//		}
//	}
//	void HeapSort(vector<int>& n)
//	{
//		for (int i = (n.size() - 1 - 1) / 2; i >= 0; i--)
//		{
//			AdjustDown(n, n.size(), i);
//		}
//		int end = n.size() - 1;
//		while (end > 0)
//		{
//			swap(n[0], n[end]);
//			AdjustDown(n, end, 0);
//			end--;
//		}
//	}
//};
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int val = 0; //记录当前未被抵消的元素
		int count = 0; //记录值为val的元素的出现次数
		//遍历数组进行抵消查找
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0) //遍历过的元素全部被抵消
			{
				val = nums[i]; //新加入的未被低效的元素
				count++; //当前出现次数为1
			}
			else //遍历过的元素有未被抵消的
			{
				if (nums[i] == val) //与这个未被抵消的元素相同
					count++; //出现次数增加
				else //与这个未被抵消的元素不同
					count--; //将其抵消一个
			}
		}
		//使用范围for遍历数组，统计值为val的元素总的出现次数
		count = 0;
		for (auto e : nums)
		{
			if (e == val)
				count++;
		}
		if (count > nums.size() / 2) //出现次数超过一半
			return val; //返回val
		else //出现次数未超过一半
			return 0; //不满足要求，返回0
	}
};
int main()
{
	vector<int> v{ 2, 2, 2, 2, 2, 1, 3, 4, 5 };
	cout << Solution().majorityElement(v) << endl;
	return 0;
}