#include <iostream>
using namespace std;

typedef unsigned int uint32_t;
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0; //ͳ�ƶ�������1�ĸ���
		while (n) //��n������0ʱ��˵��������Ƶ��л���1����
		{
			n = n&(n - 1); //��ȥ�����������ұߵ�1
			count++; //����1�ĸ���
		}
		return count; //���ض�������1�ĸ���
	}
};

int main()
{
	cout << Solution().hammingWeight(11) << endl;
	return 0;
}