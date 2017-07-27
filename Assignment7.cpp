/*
Christopher Bishop
Assignment 7
Montero Quesada
*/

#include <iostream>
#include <string>
#include "ATW.hpp"

using namespace std;

Graph g;

string mainMenu(string location){

	string user_input;

	cout<< " " << endl;
	//cout << location << endl;
	cout << "====== Day " << g.getDay() << " ======" << endl;
	if(g.getDay() != 0){
		cout << "You awake in " << location << " after a " << g.getTravelTime() << " day journey." << endl;
		cout << "Passepartout: Good morning Monsieur! I have prepared a telegram to notify our friends at home of our progress. " << endl;
		cout << "It reads '" << g.readMessage() << "' I shall send it now. " << endl;
		g.sendMessage();
	}else{
		cout << "Passepartout: With haste! We must hurry in order succeed in our journey!" << endl;
	}

	cout << "Passepartout: After reviewing our maps, we could travel to the following cities next." << endl;
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
		"decision is up to you to select your route. At each city you must send a telegram \n"
		"back home to inform them of your progress. This message will be sent to each \n"
		"previous city for them to transmit again, as a telegram has only a limited range. \n"
		"It is up to you to select the fastest path around the world and win the wager!" <<endl;

		while(1){
			string location = g.getLocation();
			string user_input = mainMenu(location);
			g.travelCity(location, user_input);

			location = g.getLocation();
			//g.printTraveled();
			
			if(location == "London"){
				cout << endl;
				cout << "====== Day " << g.getDay() << " ======" << endl;
				cout << "Upon returning to London, you collect your £20,000 much to the dismay of \n"
						"those who believed such a journey was impossible. As a memento to your trip, \n"
						"all of your telegrams you send home were saved and given back to you. These \n"
						"are shown below." << endl;
				g.showTelegrams();
				g.printTraveled();
				break;
			}
		}

	return 0;
	
}


/* References

http://ports.com/sea-route/

https://www.google.com/maps

Assignment 3

*/