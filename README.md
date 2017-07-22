# Bishop_CSCI2270_FinalProject
Assignment 7 for CSCI2270

Around the World in 80 Days

The year is 1872 and you, Phileas Fogg, have accepeted a wager of £20,000 to attemp to circumnavigate the globe within 80 days.
 Your trusty valet Passepartout will accompany you along your journey, and due to his extensive study of maps can provide you with 
the shortest path back home. However, the decision is up to you to select your route. Unexpected setbacks such as weather, changing
 travel conditions, and interactions with locals will influence your travel time. Due to the nature of the bet, you are only allowed
 to travel eastward, so once you have visited a city you cannot travel back. At each city you must send a message back home to inform
 them of your progress. This message will be send to each previous city for them to transmit again, as a telegram has only a limited
 range. It is up to you to select the fastest path around the world and win the wager!



Implementation

-At each city, allocate a node to a linked list with each city you have visited. When transmitting a message back home, this list is 
traversed from tail to head, where each city must receive your message and forward it to the previously linked city. This functionality
 is similar to Assignment 3.

-To determine the shortest distance in miles around the globe, Dijkstras algoritm is used. The graph with all the cities gets smaller
 with each new stop, as backtravel to previous cities is not allowed. Deletes nodes and updates graph. Another possibility is to compare
 this result against another shortest path algorithm.
