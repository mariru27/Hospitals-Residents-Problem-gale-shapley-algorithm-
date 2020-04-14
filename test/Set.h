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
	Set(int capacity = 1) : capacity(capacity) { }
	bool isTakedAtLeastOne()
	{
		for (auto it = rank.begin(); it != rank.end(); ++it)
			if (it->second == 1)
				return true;
		return false;
	}
	std::string _isTakedAtLeastOne()
	{
		for (auto it = rank.begin(); it != rank.end(); ++it)
			if (it->second == 1)
				return it->first;
		return " ";
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
		std::unordered_map<std::string, int>::iterator a = rank.end();

		return a;
	}

	std::unordered_map<std::string, int>::iterator firstNameAvailable()
	{
		//if name is available we will return his position, if not we will return end()
		bool count = 0;
		for (auto it = rank.begin(); it != rank.end(); ++it)
		{
			if (it->second == 1)
				count = 1;
			if (it->second == 3 && count == 0)
			{
				it->second = 1;
				return it;
			}
		}
		//return a name that have value 3(have not been selected)
		return rank.end();
	}
	std::unordered_map<std::string, int>::const_iterator _end()
	{
		std::unordered_map<std::string, int>::const_iterator a = rank.end();
		return a;
	}
	
	void notTake(const std::string name)
	{
		//set position value to 2, because we notTake that
		rank[name] = 2;
	}
	bool wasTaked(std::string str)
	{

		if (rank[str] == 2)
			return true;
		
		return false;
	}
	std::string updateSet()
	{
		//accept only firsts that fit in capacity
		int count = 0;
		std::string str = " ";
		for (auto it = rank.begin(); it != rank.end(); ++it)
		{
			if (it->second == 1)
			{
				++count;
			}
			if (capacity + 1 == count)
			{
				it->second = 2;
				str = it->first;
				return str;
			}
			
		}
		return str;
	}
	
	
};

