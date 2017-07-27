#ifndef ATW_HPP
#define ATW_HPP

#include <vector>
#include <string>

struct vertex;

struct adjVertex{
    vertex *v;
    int miles;
    std::string travelType;
    int travelTime;
};

struct vertex{
    std::string cityName;
    std::vector<adjVertex> adj;
    bool visited;
    int distance;
    vertex * previous;
};

class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(std::string c1, std::string c2, int miles, int travelTime, std::string travelType);
        void addVertex(std::string cityName);
        void displayEdges();
        void buildGraph();
        std::string getLocation();
        int getDay();
        int getTravelTime();
        void printNextCity(std::string currCity);
        void travelCity(std::string currCity, std::string nextCity);
        void Dijkstra(std::string starting, std::string destination);
    private:
    	std::string currCity;
        std::vector<vertex> vertices;
        int day;
        int prevTravel;

};

#endif