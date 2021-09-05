#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		size_t i = 0, j = 0; //分别索引当前正在遍历的两个序列的元素位置
		stack<int> st; //辅助栈
		while (i < pushed.size()) //反复执行该操作，直到第一个序列被遍历完毕
		{
			st.push(pushed[i]); //将第一个序列当中i索引的元素压栈
			while (!st.empty() && st.top() == popped[j]) //判断栈顶元素与第二个序列当中j索引的元素是否相同，直到栈顶元素与j索引的元素不同或是栈已经为空为止
			{
				st.pop(); //若相同则将栈顶的元素弹出
				j++; //j转而索引第二个序列的后一个元素，并继续当前判断
			}
			i++; //索引pushed容器中的下一个元素
		}
		//return j == popped.size(); //判断第二个序列是否遍历完毕，若是，则匹配
		return st.empty(); //判断辅助栈是否为空，为空则匹配
	}
};

int main()
{
	vector<int> pushed{ 1, 2, 3, 4, 5 };
	vector<int> popped{ 4, 5, 3, 2, 1 };
	cout << Solution().validateStackSequences(pushed, popped) << endl;
	return 0;
}