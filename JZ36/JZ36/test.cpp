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
		if (cur == nullptr) //cur为空不做处理
			return;
		//cur不为空，按中序的逻辑进行处理
		Inorder(cur->left, prev); //先处理其左子树
		//再处理cur结点
		cur->left = prev; //cur的左指向其前驱prev
		if (prev) //如果前驱prev不为空，则让前驱指向cur
			prev->right = cur;
		prev = cur; //更新prev
		Inorder(cur->right, prev); //最后处理其右子树
	}
	TreeNode* Convert(TreeNode* pRootOfTree) {
		if (pRootOfTree == nullptr) //空树不做处理
			return nullptr;
		TreeNode* prev = nullptr; //用于标记前驱结点
		Inorder(pRootOfTree, prev); //将搜索二叉树转换成排序的双向链表
		TreeNode* head = pRootOfTree;
		//TreeNode* tail = pRootOfTree;
		//从根结点一直找前驱即可找到链表中的第一个结点
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
		return head; //返回链表中的第一个结点
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