//���������ַ���a,b�е�������Ӵ�

//��Ŀ���������������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ�

/*
����:abcdefghijklmnop
	 abcsafjklmnopqrstuvw
���:jklmnop
*/


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b;
	while (cin >> a >> b){
		if (a.size() > b.size())
			swap(a, b);
		string str_max;
		for (int i = 0; i < a.size(); ++i){
			for (int j = i; j < a.size(); ++j){
				string temp = a.substr(i, j - i + 1);
				if (int(b.find(temp))<0)
					break;
				if (str_max.size() < temp.size())
					str_max = temp;
			}
		}
		cout << str_max << endl;
	}
}