/*
Christopher Bishop
Assignment 7
Montero Quesada
*/

#include <iostream>
#include <string>
#include "ATW.hpp"
#include <chrono>
#include <thread>

using namespace std;

Graph g;

string mainMenu(string location){

	string user_input;

	cout<< " " << endl;
	//cout << location << endl;
	cout << "====== Day " << g.getDay() << " ======" << endl;
	if(g.getDay() != 0){
		cout << "You awake in " << location << " after a " << g.getTravelTime() << " day journey." << endl;
	}
	cout << "Passepartout: Good morning Monsieur! After reviewing our maps, we could travel to the following cities next." << endl;
		g.printNextCity(location);

		g.Dijkstra(location, "London");
	cout << "What is your decision sir? Type in the name of the city you would like to travel to." << endl;
	getline(cin, user_input);
	cout << "Wonderful! " << user_input << " it is. I will make the arrangements at once." << endl;

	return user_input;
}

int main(){


	g.buildGraph();
	//g.displayEdges();

	cout << "The year is 1872 and you, Phileas Fogg, have accepeted a wager of £20,000 \n"
		"to attempt to circumnavigate the globe within 80 days. Your trusty valet \n"
		"Passepartout will accompany you along your journey, and due to his extensive \n"
		"study of maps can provide you with the shortest path back home. However, the \n"
		"decision is up to you to select your route. Unexpected setbacks such as weather, \n"
		"changing travel conditions, and interactions with locals will influence your \n"
		"travel time. Due to the nature of the bet, you are only allowed to travel \n"
		"eastward, so once you have visited a city you cannot travel back. At each \n"
		"city you must send a message back home to inform them of your progress. This \n"
		"message will be send to each previous city for them to transmit again, as a \n"
		"telegram has only a limited range. It is up to you to select the fastest path \n"
		"around the world and win the wager!" <<endl;

		while(1){
			string location = g.getLocation();
			string user_input = mainMenu(location);
			g.travelCity(location, user_input);

			location = g.getLocation();
			if(location == "London"){
				cout << endl;
				cout << "===================" << endl;
				cout << "You made it around the world in "<< g.getDay() <<" days!" << endl;
				break;
			}
			//this_thread::sleep_for(chrono::milliseconds(2500));				//See references

		}

		

	return 0;
	
}


/* References

http://ports.com/sea-route/

https://www.google.com/maps

https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
*/