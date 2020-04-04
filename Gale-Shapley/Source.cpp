#include <iostream>
#include "Set.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "ReadT.h"

//std::vector<Set> setA, setB;
std::unordered_map<std::string, Set> setA, setB;
std::unordered_map<std::string, std::string> resultPairs;

std::ifstream in("data.in");


void readSets()
{
	std::string line;
	std::string temp;
	std::string temp1;
	int i = 0;
	int j = 0;
	while (std::getline(in, line))
	{
		replace(line, ':', ' ');
		replace(line, ',', ' ');
		replace(line, '(', ' ');
		replace(line, ')', ' ');
		temp = getstring(line);
		if (temp[0] == 'R')
		{
			while (line.size() != 1)
			{
				temp1.erase();
				temp1 = getstring(line);
				setA[temp].push_back(temp1);
			}
			++i;
		}
		else
		{
			while (line.size() != 1)
			{
				temp1.erase();
				temp1 = getstring(line);
				setB[temp].push_back(temp1);
			}
			++j;
		}
	}
}

void printResultPairs()
{
	for (auto it = resultPairs.begin(); it != resultPairs.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}

void gale_shapley()
{
	int a = 0;
	while (a != 3)
	{
		for (auto it = setA.begin(); it != setA.end(); ++it)
		{
			//am gasit primul nume liber din setA 
			std::unordered_map<std::string, int>::iterator temp = it->second.firstNameAvailable();
			//am verificat daca nu este luat acel nume, este liber in setulB
			if (setB[temp->first].isNameAvailable(it->first) != setB[temp->first].end())
			{

				//am executat functia update in setulB, in cazul in care au fost alese mai multe spitaluri
				//acestea vor fi sterse din setulB, adica ultimele, care nu se incadreaza in capacitatea noastra
				//setB[temp->first].take(it->first);
				//while (setB[temp->first].updateSet() == " ") {}
				std::string str = setB[temp->first].updateSet();
				if (str != " ")
				{
					resultPairs[temp->first] = str;
				}
				//setB[temp->first].printBool();
			}
		}
		++a;
		printResultPairs();
	}
}

void main()
{
	//Gale–Shapley algorithm
	readSets();
	setB["H1"].capacity = 2;
	setB["H2"].capacity = 2;

	gale_shapley();
	for (auto it = setA.begin(); it != setA.end(); ++it)
	{
		it->second.printSet();
	}
}