/*
Christopher Bishop
Assignment 7
Montero Quesada
*/

#include <iostream>
#include <string>
#include <climits> //Dijkstra INT_MAX
#include "ATW.hpp"

using namespace std;

Graph::Graph(){
	string currCity;
	head = new cityVisited("London ");
	tail = new cityVisited("London ");
	lastCityTrav = head;
	travelLog =  new city_message[10];
};

Graph::~Graph(){
}

void Graph::buildGraph(){
	addVertex("London ");		//This includes the space to differentiate it from the endpoint
	addVertex("London");		//Ending point
	addVertex("Istanbul");
	addVertex("Suez");
	addVertex("Delhi");
	addVertex("Bombay");
	addVertex("Hong Kong");
	addVertex("Singapore");
	addVertex("Yokohama");
	addVertex("San Francisco");
	addVertex("Chicago");
	addVertex("New Orleans");
	addVertex("Panama City");
	addVertex("New York");
	addEdge("London ", "Istanbul", 1900, 6, "via horsedrawn buggy. A bumpy but quick ride.");	//Land
	addEdge("London ", "Suez", 2500, 7, "via railcar to Rome, then across the Mediterranean by cargo ship.");	//Land to Rome then boat 7 days
	addEdge("Istanbul", "Suez", 1550, 2, "on a private sailboat. Favorable winds make for rapid journey.");  //Land
	addEdge("Istanbul", "Delhi", 3500, 9, "as a member of a camel caravan.");
	addEdge("Suez", "Delhi", 3400, 9, "by what a mysterious man called a flying machine, some sort of new technology.");
	addEdge("Suez", "Bombay", 3700, 13, "via the Red Sea."); //13 days by boat
	addEdge("Delhi","Yokohama", 3900, 19, "along the Silk Road to Beijing then a ship to Japan. ");  //Stop in Beijing(2300 miles) and 1600 miles to yokohama by boat
	addEdge("Delhi", "Hong Kong", 2300, 10, "along dangerous roads, although this is the most direct route."); 
	addEdge("Bombay", "Hong Kong", 2700, 10, "through coastal villages of India and then through China");
	addEdge("Bombay", "Singapore", 3000, 5, "by a friendly fisherman who agreed to take us aboard his vessel.");
	addEdge("Hong Kong", "Yokohama", 2300, 6, "via a six day long boatride."); //6 days boat ride
	addEdge("Singapore", "Panama City", 11700, 31, "by a long boatride, could be anywhere from 25 to 35 days depending on trade winds.");  //Stop in Hawaii (6700 miles) then 5000 more to Panama City
	addEdge("Singapore", "Hong Kong", 1600, 7, "as a stowaway on a cargo ship.");  //7 days by boat
	addEdge("Yokohama", "San Francisco", 5200, 20, "via a steamship. A long journey, but follows strong ocean currents for rapid passage."); //20 days
	addEdge("San Francisco", "Chicago", 2100, 5, "on a new cross country rail system."); //rail
	addEdge("San Francisco", "New Orleans", 2275, 4,"by crossing a long and dry part of the United States."); //rail
	addEdge("Chicago", "New York", 800, 2, "on a scenic route through the northeast by coal train."); //rail
	addEdge("New Orleans", "New York", 1300, 4, "by riding along the eastern coast of the US by railway."); //rail
	addEdge("Panama City", "New York", 2600, 9, "through the Caribbean and along the eastern seaboard."); //9 day boat ride
	addEdge("Panama City", "London", 4500, 20, "On a long and arduous journey, however it is faster than other options."); //20 day boat ride
	addEdge("New York", "London", 3600, 13, "on a massive passenger liner. Some of the most modern comforts of travel."); //9 days boat ride
	currCity = vertices[0].cityName;
	
}

void Graph::addVertex(string cityName){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].cityName == cityName){
            found = true;
            cout<<vertices[i].cityName<<" found."<<endl;
        }
    }
    if(found == false){
        vertex v;
        v.cityName = cityName;
        vertices.push_back(v);

    }
}

void Graph::addEdge(string c1, string c2, int miles, int travelTime, string travelType){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].cityName == c1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].cityName == c2 && i != j){
                    adjVertex av;
                    av.v = &vertices[j];
                    av.miles = miles;
                    av.travelTime = travelTime;
                    av.travelType = travelType;
;                   vertices[i].adj.push_back(av);
                }
            }
        }
    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i].cityName<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->cityName<<"***";
        }
        cout<<endl;
    }
}

string Graph::getLocation(){
	return currCity;
}

int Graph::getDay(){
	return day;
}

int Graph::getTravelTime(){
	return prevTravel;
}

string Graph::readMessage(){			//Reads the message to be sent back to London
	string message = tail->message;
	return message;
}

void Graph::showTelegrams(){				//Called once return to London. Lists messages in order sent
	for(int k = 0; k < 10; k++){
		if(travelLog[k].cityName != ""){
			cout << travelLog[k].message << endl;
		}
	}
	return;
}

void Graph::printNextCity(string currCity){		//Prints possible paths onward
	for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].cityName == currCity){
        	for(int j = 0; j < vertices[i].adj.size(); j++){
        		cout << " --" << vertices[i].adj[j].v->cityName <<" "<< vertices[i].adj[j].travelType << " (" << vertices[i].adj[j].miles << " miles)"<<endl;
        	}
        }
    }
}

void Graph::travelCity(string prevCity, string nextCity){			//Travels from one city to the next
	for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].cityName == prevCity){						//Goes to currCity vertex
        	for(int j = 0; j < vertices[i].adj.size(); j++){
        		if(vertices[i].adj[j].v->cityName == nextCity){
        			currCity = vertices[i].adj[j].v->cityName;		//Updates current city
        			day = day + vertices[i].adj[j].travelTime;		//Increments day count
        			prevTravel = vertices[i].adj[j].travelTime;		//Keeps track of travel time to display in next menu
        			
        			cityVisited * added = new cityVisited(vertices[i].adj[j].v->cityName);
        			added->prevCity = lastCityTrav;
        			added->prevCity->nextCity = added;
        			lastCityTrav = added;
        			string dispDay = to_string(day);
        			added->message = "Friends, it is now day " + dispDay + " and we have made it to " + nextCity + ". More updates soon to follow.";
        			tail = lastCityTrav;							//Updates tail of list

        			if(nextCity != "London"){
        				for(int k = 0; k < 10; k++){
        					if(travelLog[k].cityName == ""){
        						travelLog[k].cityName = nextCity;
        						travelLog[k].message = added->message;
        						break;
        					}
        				}
        			}
        		}
        	}
        }
    }
}

void Graph::printTraveled(){			//Callled once return to London to show path taken.
	cityVisited * current = head;

	if(head->nextCity == nullptr){
		cout<< "You haven't traveled anywhere yet!" <<endl;
		return;
	}else{
		cout<<"===Your Journey===" <<endl;
		while(1){
			cout<< current -> cityName;
			if( (current->nextCity != nullptr) ){
				cout << " -> ";
			}else{
				cout<< endl;
				cout<< "==================" << endl;
				break;
			}
			current = current->nextCity;
		}
	}
	return;
}

void Graph::sendMessage(){			//Send the message back to London
	cityVisited * current = tail->prevCity;
	while(1){
		cout << "**Telegraph recieved in " << current->cityName << "**" <<endl;
		if(current->prevCity == nullptr){
			current->message = "";
			break;
		}
		current->prevCity->message = current->message;
		current->message = "";
		current= current->prevCity;
	}
	return;
}

void Graph::Dijkstra(string starting, string destination){

    vertex * start = nullptr;
    vertex * ending = nullptr;
    //search routine to find starting and destination
    for (int i = 0; i < vertices.size(); i++) {
        vertices[i].visited = false;
        vertices[i].distance = INT_MAX;
        vertices[i].previous = nullptr;
        if (vertices[i].cityName == starting) {
            start = &vertices[i];
        }
        if (vertices[i].cityName == destination) {
            ending = &vertices[i];
        }
    }
    if (start != nullptr && ending != nullptr)
    {
      start->visited = true;
      start->distance = 0;
      vector<vertex *> solved;
      vector<vertex *> path;
      solved.push_back(start);	//adds new element to end of vector
      adjVertex * v;
      vertex * u;
      vertex * minVertex;
      vertex * prev;
      while (ending->visited == false) {
        int minDistance = INT_MAX;
        for (int i = 0; i < solved.size(); i++) {
            u = solved[i];
            for (int j = 0; j < u->adj.size(); j++) {
                v = &solved[i]->adj[j];
                if (v->v->visited == false) {
                    int dist = u->distance + v->miles;
                    if (dist < minDistance) {
                        minDistance = dist;
                        minVertex = v->v;
                        prev = u;
                    }
                }
            }
        }

        solved.push_back(minVertex);
        minVertex->distance = minDistance;
        minVertex->previous = prev;
        minVertex->visited = true;
      }
      cout<<"The shortest path from here is ";
      vertex * vert = ending;
      while (vert != nullptr) {
          path.push_back(vert);
          vert = vert->previous;
      }
          for (int i = 0; i < path.size(); i++) {
            if (i == path.size()-1)
              cout<<path[path.size()-1-i]->cityName;
            else
              cout<<path[path.size()-1-i]->cityName<<" -> ";

          }
      cout<<" with a distance of "<<solved[solved.size()-1]->distance <<" miles."	<< endl;
  }else if (ending!=nullptr){
    cout<<"Starting city not found."<<endl;
    exit(1);
  }else{
    cout<<"Ending city not found."<<endl;
    exit(1);
  }
}