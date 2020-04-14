#include <iostream>
#include "Set.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "ReadT.h"

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
	int count = 0;
	while (count != setA.size())
	{
		count = 0;
		for (auto it = setA.begin(); it != setA.end(); ++it)
		{
			//we will find first name available from setA
			std::unordered_map<std::string, int>::iterator temp = it->second.firstNameAvailable();
			if (temp != it->second._end())
			{
				//we will verify if this hospital is available in setB
				if (setB[temp->first]._end() != setB[temp->first].isNameAvailable(it->first))
				{
					std::string str = setB[temp->first].updateSet();
					//update function will retun a string that represent resident that was rejected (from setB)
					if (str != " ")
					{
						//we need to note in first set(setA) that this resitent was rejected
						//change int value, from 1 to 2;
						setA[str].notTake(temp->first);
					}
				}
			}
		}
		//function (while) will end when all residents will be in a hospital
		for (auto it = setA.begin(); it != setA.end(); ++it)
		{
			if (it->second.isTakedAtLeastOne() == true)
				++count;
		}
	}
	//here we will store (in map resultPairs) all matched pairs
	for (auto it = setA.begin(); it != setA.end(); ++it)
	{
		resultPairs[it->first] = it->second._isTakedAtLeastOne();
	}
}

void main()
{
	//Gale–Shapley algorithm

	readSets();

	setB["H1"].capacity = 2;
	setB["H2"].capacity = 2;

	gale_shapley();

	printResultPairs();
}