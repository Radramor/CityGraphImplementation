#include <iostream>
#include "CityNode.h"
#include "CityGraph.h"

#include <iostream>
#include "CityNode.h"
#include "CityGraph.h"

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
    graph->AddPath("A", "D", 36);
    graph->AddPath("D", "E", 100);

    graph->PrintAllPathsBetweenCities("A", "E");

    // Удаление города
    std::cout << "Удаление города C" << std::endl;
    graph->RemoveCity("C", graph);
    graph->PrintCities();

    // Удаление пути
    std::cout << "Удаление пути между A и E" << std::endl;
    CityNode* cityA = graph->GetCity("A");
    if (cityA != nullptr) {
        cityA->RemovePath("E");
    }
    graph->PrintAllPathsBetweenCities("A", "E");

    delete graph;
    return 0;
}

