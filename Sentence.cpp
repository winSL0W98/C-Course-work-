#include "Sentence.hpp"
#include <cstdlib>
#include <fstream>


Sentence::Sentence()
{
}

Sentence::Sentence(const string & newSentence)
{
	converting(newSentence);
}

Sentence::~Sentence()
{
}

void Sentence::setSentence(const string& newSentence)
{
	sentence.clear();
	converting(newSentence);
}

void Sentence::converting(const string & newSentence)
{
	string temp;	

	for (unsigned int i = 0; i < newSentence.size(); i++)
	{
		if (newSentence[i] == ' ')
		{
			sentence.push_back(temp);
			temp.clear();	
		}
		else
			temp.push_back(newSentence[i]);	
	}

	
	sentence.push_back(temp);
}

void Sentence::showSentence()
{
	for (unsigned int i = 0; i < sentence.size(); i++)
		cout << sentence[i] << ' ';

	cout << '\b';
}

void Sentence::replaceKey(const string & key, const string & dataKey)
{
	for (unsigned int i = 0; i < sentence.size(); i++)
	{
		if (sentence[i] == key)
			sentence[i] = dataKey;
	}
}

string Sentence::getStr()
{
	string str;

	for (unsigned int i = 0; i < sentence.size(); i++)
	{
		str += sentence[i] + ' ';
	}

	str.pop_back();
	str.push_back('.');

	return str;
}

Generator::Generator()
{
	loadData();	

	congratulation.push_back("Дорогой $surname$ поздравляю вас с $holiday$ и желаю вам $goods$");
	congratulation.push_back("Желаю $goods$ в этот прекрасный $holiday$ самому лучшему $surname$");
}

Generator::~Generator()
{
}


string Generator::generate()
{
	int index = rand() % congratulation.size();
	static int i = 0;

	string str = congratulation[index];
	sentence.setSentence(str);


	index = rand() % holiday.size();
	sentence.replaceKey("$holiday$", holiday[index]);

	index = rand() % goods.size();
	sentence.replaceKey("$goods$", goods[index]);

	if (i < surname.size())
	{
		sentence.replaceKey("$surname$", surname[i++]);
		str = sentence.getStr();
	}
	else
	{
		str = "None";	
	}

	return str;
}

void Generator::loadData()
{
	ifstream file("holiday.txt");
	string str;
	char* letter = new char[255];

	if (file.is_open())
	{
		while (true)
		{
			file.getline(letter, 254, '\n');
			if (file.eof())
				break;
			str = letter;
			holiday.push_back(str);
		}
	}

	file.close();
	file.open("goods.txt");

	if (file.is_open())
	{
		while (true)
		{
			file.getline(letter, 254, '\n');
			if (file.eof())
				break;
			str = letter;
			goods.push_back(str);
		}
	}

	file.close();
	file.open("surname.txt");

	if (file.is_open())
	{
		while (true)
		{
			file.getline(letter, 254, '\n');
			if (file.eof())
				break;
			str = letter;
			surname.push_back(str);
		}
	}
	file.close();
	delete[] letter;
}
