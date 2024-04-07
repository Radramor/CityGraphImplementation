#pragma once
#include <string>
#include <vector>

class PathNode;

class CityNode
{
public:
	std::string name;
	CityNode* nextCity;
	PathNode* pathHead;

	CityNode(const std::string name);
	CityNode(const CityNode& CityNode) = delete;
	CityNode(CityNode&& CityNode) = delete;
	~CityNode();

	void AddChild(const std::string name);
	void PrintAllPaths(const std::string destination) const;
	void AddPath(CityNode* destCity, int length);
	void PrintPath(const std::string& destName, std::vector<std::string>& visited, int& totalLength) const;
	void RemovePath(const std::string& destName);
};