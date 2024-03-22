#include <iostream>
#include "CityNode.h"
#include "CityGraph.h"

int main()
{
	CityGraph* graph = new CityGraph();
	graph->AddCity("Novosibirsk");
	graph->AddCity("Amongus");
	graph->AddCity("SkibidiDopDop");
	graph->AddCity("YesYes");
	graph->AddCity("Ben");

	graph->AddPath("Novosibirsk", "SkibidiDopDop", 51);
	graph->AddPath("SkibidiDopDop", "Ben", 17);
	graph->AddPath("Ben", "Amongus", 17);
	graph->AddPath("Nobosibirsk", "Ben", 17);

	graph->PrintAllPaths("Novosibirsk", "Amongus");
}

