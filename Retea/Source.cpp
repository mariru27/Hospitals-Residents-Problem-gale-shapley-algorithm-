#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>

std::ifstream in("retea.in");
std::ofstream out("retea.out");
//adiacent list
std::unordered_map<int, std::vector<int>> server;
std::vector<int> network;
int n, m;

void read()
{
	in >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int node1, node2;
		in >> node1 >> node2;
		server[node1].push_back(node2);
		server[node2].push_back(node1);
	}
}

int numberConnectedComponents()
{
	std::vector<int> visited;
	int number = 0;
	for (auto it = server.begin(); it != server.end(); ++it)
	{
		auto i = std::find(visited.begin(), visited.end(), it->first);
		if (i == visited.end())
		{
			std::queue<int> queue;
			queue.push(it->first);
			while (!queue.empty())
			{
				int currentNode = queue.front();
				queue.pop();
				visited.push_back(currentNode);
				for (auto j = server[currentNode].begin(); j != server[currentNode].end(); ++j)
				{
					auto i = std::find(visited.begin(), visited.end(), *j);
					if (i == visited.end())
					{
						queue.push(*j);
					}
				}

			}
			++number;
		}
	}
	return number;
}

void print()
{
	for (auto i = network.begin(); i < network.end(); ++i)
	{
		out << *i;
		if (i < network.end() - 1)
			out << " ";
	}
}

int main()
{
	read();
	int nrConnectedComp = numberConnectedComponents();
	
	for (int it = 1; it <= n; ++it)
	{
		std::vector<int> temp = server[it];
		server.erase(it);
		if (nrConnectedComp == numberConnectedComponents())
			network.push_back(0);
		else
			network.push_back(1);
		server[it] = temp;
	}

	print();

	return 0;
}