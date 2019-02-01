#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sentence
{
public:
	Sentence();	
	Sentence(const string& newSentence);	
	~Sentence();	
	void setSentence(const string& newSentence);	
	void showSentence();
	void replaceKey(const string& key, const string& dataKey);	
	string getStr();

private:
	vector<string> sentence;	
	void converting(const string& newSentence);	
};


class Generator
{
public:
	Generator();	
	~Generator();	
	string generate();

private:
	void loadData();	
	void setSurname(const string& surname);	
	void setName(const string& name);	

private:
	Sentence sentence;

	vector<string> congratulation;
	vector<string> surname;	
	vector<string> goods;	
	vector<string> holiday;	
};
