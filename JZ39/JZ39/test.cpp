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
		int val = 0; //��¼��ǰδ��������Ԫ��
		int count = 0; //��¼ֵΪval��Ԫ�صĳ��ִ���
		//����������е�������
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0) //��������Ԫ��ȫ��������
			{
				val = nums[i]; //�¼����δ����Ч��Ԫ��
				count++; //��ǰ���ִ���Ϊ1
			}
			else //��������Ԫ����δ��������
			{
				if (nums[i] == val) //�����δ��������Ԫ����ͬ
					count++; //���ִ�������
				else //�����δ��������Ԫ�ز�ͬ
					count--; //�������һ��
			}
		}
		//ʹ�÷�Χfor�������飬ͳ��ֵΪval��Ԫ���ܵĳ��ִ���
		count = 0;
		for (auto e : nums)
		{
			if (e == val)
				count++;
		}
		if (count > nums.size() / 2) //���ִ�������һ��
			return val; //����val
		else //���ִ���δ����һ��
			return 0; //������Ҫ�󣬷���0
	}
};
int main()
{
	vector<int> v{ 2, 2, 2, 2, 2, 1, 3, 4, 5 };
	cout << Solution().majorityElement(v) << endl;
	return 0;
}