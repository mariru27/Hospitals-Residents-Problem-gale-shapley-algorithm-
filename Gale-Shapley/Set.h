#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class Set
{
	std::string name;
	std::unordered_map<std::string, int> rank;
	//int from unordered_map represent 
	//1-taked,2-notTaked,3-free;
public:
	int capacity;
	void printBool()
	{
		for (auto it = rank.begin(); it != rank.end(); ++it)
		{
			std::cout << it->first << " "<<it->second << " ";
		}
		std::cout << std::endl;
	}
	Set(int capacity = 1) : capacity(capacity) { }
	void setName(std::string& str)
	{
		name = str;
	}
	void push_back(std::string name, int value = 3)
	{
		rank[name] = value;
	}
	std::unordered_map<std::string, int>::iterator isNameAvailable(const std::string value)
	{
		//if name is available we will return his position, if not we will return end
		for (auto it = rank.begin(); it != rank.end(); ++it)
		{
			if (value == it->first && it->second == 3)
			{
				it->second = 1;
				return it;
			}
		}
		//return a name that have value 3(have not been selected)
		return rank.end();
	}

	std::unordered_map<std::string, int>::iterator firstNameAvailable()
	{
		//if name is available we will return his position, if not we will return end()
		for (auto it = rank.begin(); it != rank.end(); ++it)
		{
			if (it->second == 3)
			{
				it->second = 1;
				return it;
			}
		}
		//return a name that have value 3(have not been selected)
		return rank.end();
	}
	std::unordered_map<std::string, int>::iterator end()
	{
		return rank.end();
	}
	
	void notTake(const std::string name)
	{
		//set position value to 2, because we notTake that
		rank[name] = 2;
	}
	bool check()
	{
		//check if all were chosen
		int number = 0;
		for (auto it = rank.begin(); it != rank.end(); ++it)
		{
			if (it->second == 1)
				++number;
		}

		if (number == rank.size() - 1)
			return true;
		return false;
	}
	void printSet()
	{
		std::cout << name << "->";
		for (auto it = rank.begin(); it != rank.end(); ++it)
		{
			std::cout << it->first << " ";
		}
		std::cout << std::endl;
	}
	std::string updateSet()
	{
		//accept only firsts that fit in capacity

		int count = 0;
		std::string str;
		for (auto it = rank.begin(); it != rank.end(); ++it)
		{
			if (it->second == 1)
			{
				++count;
				if (count == capacity)
				{
					it->second = 1;
					str = it->first;
				}

			}
			if (capacity + 1 == count)
			{
				it->second = 2;
				return str;
			}
			
		}
		return " ";

	}
	
	
};

