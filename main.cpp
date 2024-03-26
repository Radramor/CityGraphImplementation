#include <iostream>
#include "CityNode.h"
#include "CityGraph.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	CityGraph* graph = new CityGraph();
	graph->AddCity("A");
	graph->AddCity("B");
	graph->AddCity("C");
	graph->AddCity("D");
	graph->AddCity("E");

	graph->AddPath("A", "C", 51);
	graph->AddPath("C", "E", 20);
	graph->AddPath("E", "B", 5);
	graph->AddPath("A", "E", 1);

	graph->PrintAllPaths("A", "E");
}

