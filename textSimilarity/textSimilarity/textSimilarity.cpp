#include "TextSimilarity.h"
#include <windows.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <assert.h>

using namespace std;


TextSimilarity::TextSimilarity(string dict)
	:DICT(dict)
	, DICT_PATH(dict + "/jieba.dict.utf8")
	, HMM_PATH(dict + "/hmm_model.utf8")
	, USER_DICT_PATH(dict + "/user.dict.utf8")
	, IDF_PATH(dict + "/idf.utf8")
	, STOP_WORD_PATH(dict + "/stop_words.utf8")
	, _jieba(DICT_PATH,
		HMM_PATH,
		USER_DICT_PATH,
		IDF_PATH,
		STOP_WORD_PATH)
	, _maxWordNumber(10)
{
	getStopWordTable(STOP_WORD_PATH.c_str());
}

void TextSimilarity::getStopWordTable(const char* stopWordFile)
{
	ifstream fin(stopWordFile);
	if (!fin.is_open())
	{
		cout << "open file" << stopWordFile << "failed" << endl;
		return;
	}
	string line;
	while (!fin.eof())
	{
		getline(fin, line);
		//UTF8
		_stopWordSet.insert(line);
	}
	fin.close();

}

TextSimilarity::wordFreq TextSimilarity::getWordFreq(const char* filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "open file:" << filename << "failed" << endl;
		return wordFreq();
	}
	string line;
	wordFreq wf;
	while (!fin.eof())
	{
		getline(fin, line);
		//GBK--UTF8
		cout << line << endl;
		line = GBKToUTF8(line);
		//cout << "UTF8:" << endl;
		//cout << line << endl;
		vector<string>words;
		//对文本当前行分词
		cout << "before cut :" << endl;
		_jieba.Cut(line, words, true);
		cout << "end cut" << endl;
		//统计词频
		for (const auto& e : words)
		{
			//去掉停用词
			if (_stopWordSet.count(e) > 0)
				continue;
			else
			{
				//统计词频
				if (wf.count(e) > 0)
					wf[e]++;
				else
					wf[e] = 1;
			}
		}
	}
	return wf;
}

bool cmpReverse(pair<string, int> lp, pair<string, int>rp)
{
	return lp.second > rp.second;
}

vector<pair<string, int>> TextSimilarity::sortByValueReverse(TextSimilarity::wordFreq& wf)
{
	//unordered_map
	vector<pair<string, int>> wfvector(wf.begin(), wf.end());
	sort(wfvector.begin(), wfvector.end(), cmpReverse);
	return wfvector;
}

string TextSimilarity::GBKToUTF8(string str)
{
	int len;
	//GKBToUTF16
	len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
	//UTF16ToUTF8
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* utf8char = new char[len];
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8char, len, NULL, NULL);
	string out(utf8char);
	if (wstr)
	{
		delete[]wstr;
		wstr = NULL;
	}
	if (utf8char)
	{
		delete[]utf8char;
		utf8char = NULL;
	}
	return out;
}

string TextSimilarity::UTF8ToGBK(string str)
{
	int len;
	//UTF8ToUTF16
	len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len];
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr, len);
	//UTF16ToGBK
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* gbkchar = new char[len];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, gbkchar, len, NULL, NULL);
	string out(gbkchar);
	if (wstr)
	{
		delete[]wstr;
		wstr = NULL;
	}
	if (gbkchar)
	{
		delete[]gbkchar;
		gbkchar = NULL;
	}
	return out;
}

void TextSimilarity::selectAimWords(std::vector<std::pair<std::string, int>>& wfvec, wordSet& wset)
{
	int len = wfvec.size();
	int sz = len > _maxWordNumber ? _maxWordNumber : len;
	for (int i = 0; i < sz; i++)
	{
		//pair<string, int>
		wset.insert(wfvec[i].first);
	}
}

//构建词频向量
vector<double> TextSimilarity::getOneHot(TextSimilarity::wordSet& wset, TextSimilarity::wordFreq& wf)
{
	//遍历wordSet中的每一个词
	vector<double> oneHot;
	for (const auto& e : wset)
	{
		if (wf.count(e))
			//存放value(单词词频）
			oneHot.push_back(wf[e]);
		else
			oneHot.push_back(0);
	}
	return oneHot;
}

double TextSimilarity::cosine(std::vector<double>& oneHot1, std::vector<double>& oneHot2)
{
	double modular1 = 0, modular2 = 0;
	double products = 0;
	assert(oneHot1.size() == oneHot2.size());
	for (int i = 0; i < oneHot1.size(); i++)
	{
		//sum(ai*bi)
		products += oneHot1[i] * oneHot2[i];
	}

	for (int i = 0; i < oneHot1.size(); i++)
	{
		modular1 += pow(oneHot1[i], 2);
	}
	modular1 = pow(modular1, 0.5);

	for (int i = 0; i < oneHot2.size(); i++)
	{
		modular2 += pow(oneHot1[i], 2);
	}
	modular2 = pow(modular2, 0.5);

	return products / (modular1 * modular2);
}
