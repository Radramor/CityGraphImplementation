#pragma once

class CityNode;

class PathNode
{
public:
	int length;
	CityNode* city;
	PathNode* nextPath;

	PathNode(CityNode* city, int length);
	~PathNode();

	int GetLength();
	void AddChild(CityNode* city, int length);
};