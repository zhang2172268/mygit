#include "TextSimilarity.h"
#include <iostream>

using namespace std;


void test()
{
	TextSimilarity ts("dict");
	TextSimilarity::wordFreq wf1 = ts.getWordFreq("text1.txt");
	TextSimilarity::wordFreq wf2 = ts.getWordFreq("text2.txt");
	vector<pair<string, int>> wfvec1 = ts.sortByValueReverse(wf1);
	vector<pair<string, int>> wfvec2 = ts.sortByValueReverse(wf2);
	cout << "wfvec1: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << ts.UTF8ToGBK(wfvec1[i].first) << ":" << wfvec1[i].second << '\t';
	}
	cout << endl;
	for (const auto& e : wfvec1)
	{
		cout << e.second << '\t';
	}
	cout << endl;
	cout << "wfvec2: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << ts.UTF8ToGBK(wfvec2[i].first) << ":" << wfvec2[i].second << '\t';
	}
	cout << endl;
	TextSimilarity::wordSet  wset;
	//用排好序的词频挑选前n个候选词
	ts.selectAimWords(wfvec1, wset);
	ts.selectAimWords(wfvec2, wset);
	cout << "wset: " << endl;
	for (const auto& e : wset)
	{
		cout << ts.UTF8ToGBK(e) << " " << endl;
	}
	cout << endl;
	//根据候选词构建词频向量
	vector<double> oneHot = ts.getOneHot(wset, wf1);
	vector<double> oneHot2 = ts.getOneHot(wset, wf2);
	cout << "oneHot: " << endl;
	for (const auto& v : oneHot)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "oneHot2: " << endl;
	for (const auto& v : oneHot2)
	{
		cout << v << " ";
	}
	cout << endl;

	cout << "cosin: " << ts.cosine(oneHot, oneHot2) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}