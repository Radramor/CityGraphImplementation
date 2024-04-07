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

void CityGraph::PrintAllPathsBetweenCities(const std::string& sourceName, const std::string& destName) const
{
	CityNode* source = GetCity(sourceName);
	if (source == nullptr) {
		std::cout << "√ород-источник не найден" << std::endl;
		return;
	}

	CityNode* dest = GetCity(destName);
	if (dest == nullptr) {
		std::cout << "√ород назначени€ не найден" << std::endl;
		return;
	}

	std::vector<std::string> visited;
	int totalLength = 0;
	std::cout << "¬се пути из " << sourceName << " в " << destName << ":" << std::endl;
	source->PrintPath(destName, visited, totalLength);
}
void CityGraph::RemoveCity(const std::string& name, CityGraph *graph)
{
	if (head == nullptr) return; // граф пуст

	// если нужно удалить головной узел
	if (head->name == name) {
		CityNode* temp = head;
		head = head->nextCity;
		delete temp;
		return;
	}

	// найти узел, предшествующий удал€емому
	CityNode* prev = nullptr;
	CityNode* current = head;
	while (current != nullptr && current->name != name) {
		prev = current;
		current = current->nextCity;
	}

	// если город не найден
	if (current == nullptr) return;

	// удалить узел
	prev->nextCity = current->nextCity;

	// удаление всех дорог к этому городу из остальных городов
	CityNode* everyCity = graph->head;
	for (everyCity; everyCity->nextCity != nullptr; everyCity = everyCity->nextCity)
		everyCity->RemovePath(current->name);

	delete current;
}
