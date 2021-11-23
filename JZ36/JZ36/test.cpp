#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	void Inorder(TreeNode* cur, TreeNode*& prev)
	{
		if (cur == nullptr) //curΪ�ղ�������
			return;
		//cur��Ϊ�գ���������߼����д���
		Inorder(cur->left, prev); //�ȴ�����������
		//�ٴ���cur���
		cur->left = prev; //cur����ָ����ǰ��prev
		if (prev) //���ǰ��prev��Ϊ�գ�����ǰ��ָ��cur
			prev->right = cur;
		prev = cur; //����prev
		Inorder(cur->right, prev); //�������������
	}
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (pRootOfTree == nullptr) //������������
			return nullptr;
		TreeNode* prev = nullptr; //���ڱ��ǰ�����
		Inorder(pRootOfTree, prev); //������������ת���������˫������
		TreeNode* head = pRootOfTree;
		//TreeNode* tail = pRootOfTree;
		//�Ӹ����һֱ��ǰ�������ҵ������еĵ�һ�����
		while (head->left)
		{
			head = head->left;
		}
		//while (tail->right)
		//{
		//	tail = tail->right;
		//}
		//head->left = tail;
		//tail->right = head;
		return head; //���������еĵ�һ�����
	}
};
int main()
{
	TreeNode d10(10);
	TreeNode d6(6);
	TreeNode d14(14);
	TreeNode d4(4);
	TreeNode d8(8);
	TreeNode d12(12);
	TreeNode d16(16);

	d10.left = &d6;
	d10.right = &d14;
	d6.left = &d4;
	d6.right = &d8;
	d14.left = &d12;
	d14.right = &d16;

	TreeNode* ret = Solution().Convert(&d10);
	for (int i = 0; i < 7; i++)
	{
		cout << ret->val << " ";
		ret = ret->right;
	}
	cout << endl;
	return 0;
}