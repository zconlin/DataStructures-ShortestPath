#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include "NavigationInterface.h"

using namespace std;

struct Node {
    int cost;
    queue<int> path;

    bool operator() (Node const& n1, Node const& n2) {
        return n1.cost > n2.cost;
    }
};

class Navigation : public NavigationInterface {
public:
  	Navigation();
 	 ~Navigation();
		virtual bool readNetwork(string _mapName);
    queue<int> computeShortestPath(int _startInd, int _endInd);
    void printPath(queue<int> _path);

private:
int numNodes;
	vector < vector<int> > theCosts;
};

#endif