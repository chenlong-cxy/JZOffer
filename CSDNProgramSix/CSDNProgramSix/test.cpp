////�ϲ�ǹ��
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	string s;
//	int count = 0;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s;
//		if (s == "ak" || s == "m4a1" || s == "skr")
//			count++;
//	}
//	cout << count << endl;
//	return 0;
//}


////������
//#include <iostream>
//#include <string>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int n = 0;
//	cin >> n;
//	//ͳ��ÿ���������ĵ�����
//	unordered_map<string, int> um;
//	string s;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s;
//		um[s]++;
//	}
//	//�ҳ������������Ĺ���
//	int mCount = 0;
//	string ret;
//	for (auto e : um)
//	{
//		if (e.second > mCount)
//		{
//			mCount = e.second;
//			ret = e.first;
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}


////���ʼ���
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	cin >> str;
//	string ret;
//	size_t pos = 0;
//	bool flag = false;
//	while (pos < str.size())
//	{
//		if ((pos != 0) && (pos + 2 != str.size() - 1) &&
//			(str[pos] == 'd') && (pos + 1 < str.size() && str[pos + 1] == 'o') && (pos + 2 < str.size() && str[pos + 2] == 't'))
//		{
//			ret += '.';
//			pos += 3;
//		}
//		else if ((flag == false) && (pos != 0) && (pos + 1 != str.size() - 1) &&
//			(str[pos] == 'a') &&(pos + 1 < str.size() && str[pos + 1] == 't'))
//		{
//			ret += '@';
//			pos += 2;
//			flag = true;
//		}
//		else
//		{
//			ret += str[pos];
//			pos++;
//		}
//	}
//	cout << ret << endl;
//	return 0;
//}


//����������䳤��
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	//��ȡ����
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	//�ҳ����������ĳ���
	int mCount = 0;
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i] - v[i - 1] > 0)
		{
			count++;
			if (count > mCount)
				mCount = count;
		}
		else
		{
			count = 0;
		}
	}
	cout << mCount + 1 << endl;
	return 0;
}