/***********************************
 版本号升级
 
 给定两个版本号，只有版本号更高的时候，才可以升级
 例如：0.1 < 1.1可以升级返回true，否则返回false；
 一个版本号最多出现三个 . 版本号数字[1,100];
 
 ***********************************/
 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;



int main()
{
	int m;
	string str1, str2;
	while (cin >> m){
		vector<bool> ret;
		ret.reserve(m);

		for (int i = 0; i < m; ++i){

			cin >> str1 >> str2;
			for (int j = 0; j < str1.size(); ++j){
				if (str1[j] == '.')
					str1[j] = ' ';
			}

			for (int j = 0; j < str2.size(); ++j){
				if (str2[j] == '.')
					str2[j] = ' ';
			}

			stringstream s1(str1), s2(str2);
			int m1 = 0, m2 = 0, sum1 = 0, sum2 = 0, val = 1000000;

			while (s1 >> m1){
				sum1 += m1 * val;
				val /= 100;
			}

			val = 1000000;
			while (s2 >> m2){
				sum2 += m2 * val;
				val /= 100;
			}

			ret.push_back(sum1 < sum2);
		}

		for (int i = 0; i < ret.size(); ++i){
			if (ret[i])
				cout << "true" << endl;
			else
				cout << "false" << endl;
		}
	}
	return 0;
}