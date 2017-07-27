# Bishop_CSCI2270_FinalProject
Assignment 7 for CSCI2270

___________________________________________________________________________

Around the World in 80 Days

The year is 1872 and you, Phileas Fogg, have accepeted a wager of £20,000 to attemp to circumnavigate the globe within 80 days. Your trusty valet Passepartout will accompany you along your journey, and due to his extensive study of maps can provide you with the shortest path back home. However, the decision is up to you to select your route. At each city you must send a telegram back home to inform them of your progress. This message will be sent to each previous city for them to transmit again, as a telegram has only a limited range. It is up to you to select the fastest path around the world and win the wager!

___________________________________________________________________________

Summary:
When the program is initialized, it builds a weighted directed graph with 13 major cities across the globe. Each edge between nodes contains three important pieces of information: the distance in miles between cities, the travel time in days between cities, and a brief message describing the method of travel. When calculating the shortest path, only the distance (miles) between cities is taken into account. Since the point is to make it around the world as fast as possible, the time it will take to travel to another city is unknown to the user until they arrive there. Thus, there is a certain amount of guesswork as to what the fastest route will be, but the travel times are related to the actual distances. These distances were all found using Google Maps, and are to be considered accurate to +/- 100 miles. As one travels to each new city, the location is added to a linked list with previous cities traveled to. Then a message can be send through this linked list, until it reaches the starting point London. At the end of the game, these messages are all retrieved to show the user their chosen path.

How to Run:
The compiled program has already been compiled and posted. This can be run in a Linux operating system from terminal using the command "./AroundtheWorld". If there is an error message about permissions, enter this command "chmod +x AroundtheWorld". After this the program should be able to run. While not tested under Windows/ Mac, the program should run as long as it is recompiled using the operating system specific command. In linux, this is done using the command "g++ -std=c++11 Assignment7.cpp ATW.cpp -o AroundtheWorld". It is required to use a c++11 compiler since the program frequently uses the nullptr keyword, and this was not available in previous versions.

Dependencies:
The only libraries used for this program were iostream, vector, string, and climits, there are no third party libraries required to by the program.

System Requirements:
Tested under Linux (Ubuntu 16.04), but should be working on Windows/Mac as well.

Author:
Christopher Bishop

Open Issues/Bugs:
No known bugs at this time. The next step would be to implement a check for the cityname the user enters. As the program stands right now, the city to travel next to must be entered exactly, or else the menu will repeat itself and ask the user again for a city. A better option would be to implement a check if the city entered is one of the cities to travel to, and inform the user if they entered it incorrectly.

