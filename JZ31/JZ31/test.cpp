#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		size_t i = 0, j = 0; //�ֱ�������ǰ���ڱ������������е�Ԫ��λ��
		stack<int> st; //����ջ
		while (i < pushed.size()) //����ִ�иò�����ֱ����һ�����б��������
		{
			st.push(pushed[i]); //����һ�����е���i������Ԫ��ѹջ
			while (!st.empty() && st.top() == popped[j]) //�ж�ջ��Ԫ����ڶ������е���j������Ԫ���Ƿ���ͬ��ֱ��ջ��Ԫ����j������Ԫ�ز�ͬ����ջ�Ѿ�Ϊ��Ϊֹ
			{
				st.pop(); //����ͬ��ջ����Ԫ�ص���
				j++; //jת�������ڶ������еĺ�һ��Ԫ�أ���������ǰ�ж�
			}
			i++; //����pushed�����е���һ��Ԫ��
		}
		//return j == popped.size(); //�жϵڶ��������Ƿ������ϣ����ǣ���ƥ��
		return st.empty(); //�жϸ���ջ�Ƿ�Ϊ�գ�Ϊ����ƥ��
	}
};

int main()
{
	vector<int> pushed{ 1, 2, 3, 4, 5 };
	vector<int> popped{ 4, 5, 3, 2, 1 };
	cout << Solution().validateStackSequences(pushed, popped) << endl;
	return 0;
}