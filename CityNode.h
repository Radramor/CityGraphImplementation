#pragma once
#include <string>

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
};