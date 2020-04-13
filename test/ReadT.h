#pragma once
#include <iostream>
#include "Set.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

void replace(std::string& str, char a, char b)
{
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if (*it == a)
			*it = b;
	}
}

std::string getstring(std::string& str)
{
	std::string resultString;
	int index = 0;
	while (str.size() != index)
	{
		if (str[index] != ' ')
		{
			resultString.push_back(str[index]);
		}
		if (str[index] == ' ' && resultString.size() != 0)
			break;
		++index;
	}
	str.erase(0, index);
	return resultString;
}
