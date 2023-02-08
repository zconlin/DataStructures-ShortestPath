#include "Navigation.h"
#include <queue>
#include <sstream>
#include <fstream>

using namespace std;

Navigation::Navigation() {
	// cout << "This is the Navigation constructor." << endl;
	numNodes = 0;
}

Navigation::~Navigation() {
	// cout << "This is the Navigation destructor." << endl;
	}

bool Navigation::readNetwork(string _mapName) {
	// cout << "Reading the map file..." << endl;

	ifstream myMap;
	myMap.open(_mapName);
	myMap >> numNodes;
	
	for (int i = 0; i < numNodes; i++) {
		vector <int>rowStorage;
		
		for (int j = 0; j < numNodes; j++) {
			int num;
			myMap >> num;
			rowStorage.push_back(num);
			
		}
		theCosts.push_back(rowStorage);
	}

	// cout << "Network has been read." << endl;

	return true;
}

queue<int> Navigation::computeShortestPath(int _startInd, int _endInd) {
	queue<int> thePath;
	
		cout << "Computing shortest path..." << endl << endl;

	// (1) Create the priority queue
	priority_queue<Node, vector<Node>, Node> myPriorityQueue;

	// (2) Create Node n, with n.cost = 0 and n.path = <A>
	Node n;
	n.cost = 0;
	n.path.push(_startInd);

	// (3) Insert Node n into PQ
	myPriorityQueue.push(n);
	
	// (4)   Loop while the top Node in PQ does not contain a 
	// path that ends in the destination
	//cout << "Entering the while loop..." << endl;

		while (myPriorityQueue.top().path.back() != _endInd) {
		// (5)      Pop the top item off the priority queue and 
		// store it in current (see programming hint 3)
			Node current = myPriorityQueue.top();
			myPriorityQueue.pop();
				//cout << "While loop 5" << endl;

				
		// (6)      Set last to be the last destination in current.path (see programming hint 4)
			int last = current.path.back();
			//cout << "While loop 6" << endl;

				
		// (7)      For each neighbor j of last (i.e., Cost(last,j) > 0), insert a new Node (denoted nn) into PQ in which nn.cost = current.cost+Cost(last,j) and nn.path = concat(current.path, j)
			//try debugger, trace numnodes and inside readnetwork print the matrix, print out info about top of PQ
			//cout << "While loop 7.1" << endl;
			for (int j = 0; j < numNodes; j++) {
					//cout << "While For loop" << endl;
				if (theCosts[last][j] > 0) {
					Node nn;
					nn.cost = theCosts[last][j] + current.cost;
					nn.path = current.path;
					nn.path.push(j);
					myPriorityQueue.push(nn);
					}
				}
			}
			//cout << "While loop 7.2" << endl;
	// (8)   Return the path (which is a queue of integers) of 
	// the top Node in PQ
	thePath = myPriorityQueue.top().path;
		
	//cout << "You broke out of the while loop!" << endl;
	
	return thePath;
}

void Navigation::printPath(queue<int> _path) {
	cout << "Printing the path: " << endl;
	// print the queue
			int size = _path.size();
				
		for (int i = 0; i < size; i++) {
			_path.front();
			cout << _path.front() << " ";
			_path.pop();
		}	
	cout << endl;
}