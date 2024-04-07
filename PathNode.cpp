#include "PathNode.h"

PathNode::PathNode(CityNode* city, int length)
{
	this->city = city;
	this->length = length;
	nextPath = nullptr;
}

PathNode::~PathNode()
{
}

int PathNode::GetLength()
{
	return length;
}

void PathNode::AddChild(CityNode* city, int length)
{
	if (nextPath == nullptr) {
		nextPath = new PathNode(city, length);
		return;
	}

	nextPath->AddChild(city, length);
}
