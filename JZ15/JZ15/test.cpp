#include <iostream>
using namespace std;

typedef unsigned int uint32_t;
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0; //统计二进制中1的个数
		while (n) //当n不等于0时，说明其二进制当中还有1存在
		{
			n = n&(n - 1); //消去二进制中最右边的1
			count++; //更新1的个数
		}
		return count; //返回二进制中1的个数
	}
};

int main()
{
	cout << Solution().hammingWeight(11) << endl;
	return 0;
}