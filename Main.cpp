#include <iostream>
#include <cstdlib>
#include <locale>
#include <ctime>
#include <conio.h>
#include "Sentence.hpp"

int main()
{
	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(NULL));

	Generator gen;
	string str;

	while ((str = gen.generate()) != "None")
		cout << str << endl;

	system("pause");
	return 0;
}
