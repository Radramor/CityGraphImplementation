#include "CityNode.h"
#include "PathNode.h"
#include <iostream>
#include <vector>

CityNode::CityNode(const std::string name)
{
	this->name = name;
	nextCity = nullptr;
	pathHead = nullptr;
}

CityNode::~CityNode()
{
	nextCity == nullptr; // удалить следующий CityNode в цепочке

	// удалить все PathNode, связанные с этим CityNode
	PathNode* current = pathHead;
	while (current != nullptr) {
		PathNode* next = current->nextPath;
		delete current;
		current = next;
	}
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

void CityNode::PrintPath(const std::string& destName, std::vector<std::string>& visited, int& totalLength) const
{
	visited.push_back(name);

	if (name == destName) {
		std::cout << "Путь: ";
		for (const auto& city : visited)
			std::cout << city << " ";
		std::cout << "Общая протяженность: " << totalLength << std::endl;
	}
	else {
		for (PathNode* path = pathHead; path != nullptr; path = path->nextPath) {
			if (std::find(visited.begin(), visited.end(), path->city->name) == visited.end()) {
				totalLength += path->length;
				path->city->PrintPath(destName, visited, totalLength);
				totalLength -= path->length;
			}
		}
	}

	visited.pop_back();
}
void CityNode::RemovePath(const std::string& destName)
{
	if (pathHead == nullptr) return; // нет путей

	// если нужно удалить первый путь
	if (pathHead->city->name == destName) {
		PathNode* temp = pathHead;
		pathHead = pathHead->nextPath;
		delete temp;
		return;
	}

	// найти путь, предшествующий удаляемому
	PathNode* prev = nullptr;
	PathNode* current = pathHead;
	while (current != nullptr && current->city->name != destName) {
		prev = current;
		current = current->nextPath;
	}

	// если путь не найден
	if (current == nullptr) return;

	// удалить путь
	prev->nextPath = current->nextPath;
	delete current;
}