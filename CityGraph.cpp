#include "CityGraph.h"
#include "PathNode.h"
#include "CityNode.h"
#include <iostream>
#include <list>
#include <vector>

CityGraph::CityGraph()
{
	head = nullptr;
}

CityGraph::~CityGraph()
{
	delete head;
}

void CityGraph::AddCity(const std::string name)
{
	if (head == nullptr) {
		head = new CityNode(name);
		return;
	}
	
	head->AddChild(name);
}

void CityGraph::AddPath(const std::string sourceName, const std::string destName, int length)
{
	CityNode* source = GetCity(sourceName);
	if (source == nullptr) return;
	CityNode* destination = GetCity(destName);
	if (destination == nullptr) return;

	source->AddPath(destination, length);
	destination->AddPath(source, length);
}

CityNode* CityGraph::GetCity(const std::string name) const
{
	return FindNode(head, name);
}

CityNode* CityGraph::FindNode(CityNode* node, const std::string name) const 
{
	if (node == nullptr)
		return nullptr;

	if (node->name == name)
		return node;

	return FindNode(node->nextCity, name);
}

void CityGraph::PrintCities() const
{
	PrintNode(head);
}

void CityGraph::PrintNode(const CityNode * cityNode) const
{
	if (cityNode == nullptr)
		return;

	std::cout << cityNode->name << std::endl;

	PrintNode(cityNode->nextCity);
}

std::vector<CityNode*> vec;
int sum = 0;
void CityGraph::PrintAllPaths(const std::string sourceName, const std::string destName) const
{
	CityNode* source = GetCity(sourceName);
	if (source == nullptr) return;
	CityNode* destination = GetCity(destName);
	if (destination == nullptr) return;

	vec.clear();
	std::cout << "Все пути из " << sourceName << " в " << destName << ":" << std::endl;
	
	sum = 0;
	CheckCity(source, destination);
	// переставить
}

void CityGraph::CheckCity(CityNode* node, CityNode* destNode) const
{
	if (node == nullptr)
		return;

	if (node == destNode)
	{	
		std::cout << node->name << std::endl;
		std::cout << "Общая протяженность дороги: " << sum << std::endl << std::endl;
		return;
	}
	vec.push_back(node);
	std::cout << node->name << " -> ";
	CheckPath(node->pathHead, destNode);
	vec.pop_back();
}

void CityGraph::CheckPath(PathNode* path, CityNode* destNode) const
{

	if (path == nullptr) {
		return;
	}
	
	if (path->city == nullptr) {
		return;
	}

	auto passed{ std::find(vec.begin(), vec.end(), path->city) };
	if (passed != vec.end() && path->nextPath == nullptr) {
		return;
	}

	CheckPath(path->nextPath, destNode);
	sum += path->GetLength();
	CheckCity(path->city, destNode);
	sum -= path->GetLength();
	
}
