#include "CityNode.h"
#include "PathNode.h"
#include <iostream>

CityNode::CityNode(const std::string name)
{
	this->name = name;
	nextCity = nullptr;
	pathHead = nullptr;
}

CityNode::~CityNode()
{
	delete nextCity;
	delete pathHead;
}

void CityNode::AddChild(const std::string name)
{
	if (nextCity == nullptr) {
		nextCity = new CityNode(name);
		return;
	}
	
	nextCity->AddChild(name);
}

void CityNode::PrintAllPaths(const std::string destination) const
{
	std::cout << "print all paths not impleented" << std::endl;
}

void CityNode::AddPath(CityNode* destCity, int length)
{
	if (pathHead == nullptr) {
		pathHead = new PathNode(destCity, length);
		return;
	}

	pathHead->AddChild(destCity, length);
}
