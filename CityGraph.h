#pragma once
#include <string>
#include <list>
#include "CityNode.h"

class CityGraph {
private:
	CityNode* head;
	CityNode* FindNode(CityNode* node, const std::string name) const;
	void CheckCity(CityNode* node, CityNode* destNode) const;
	void CheckPath(PathNode* path, CityNode* destNode) const;
public:
	CityGraph();
	~CityGraph();

	void AddCity(const std::string name);
	void AddPath(const std::string sourceName, const std::string destName, int length);
	
	CityNode* GetCity(const std::string name) const;
	void PrintCities() const;
	void PrintNode(const CityNode* cityNode) const;
	void PrintAllPaths(const std::string sourceName, const std::string destName) const;
};