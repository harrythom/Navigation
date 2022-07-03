#ifndef NAVIGATION_NAVIGATION_H
#define NAVIGATION_NAVIGATION_H

#include <fstream>
#include <vector>
#include "NavigationInterface.h"

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

    virtual ~Navigation();


    virtual bool readNetwork(string _mapName);

    virtual queue<int> computeShortestPath(int _startInd, int _endInd);

    virtual void printPath(queue<int> _path);

private:

    vector <vector<int>> costMatrix;
    int numNodes;

};

#endif