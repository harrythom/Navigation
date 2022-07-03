#include "Navigation.h"

Navigation::Navigation() {

    cout << "In constructor..." << endl;

}

Navigation::~Navigation() {

    cout << "In destructor..." << endl;

}

bool Navigation::readNetwork(string _mapName) {

    cout << "In read network..." << endl;

    ifstream input;
    input.open(_mapName);

}

queue<int> Navigation::computeShortestPath(int _startInd, int _endInd) {

    cout << "In compute shortest path..." << endl;

    queue<int> path;

    //Step 1
    priority_queue <Node, vector<Node>, Node> myPriorityQueue;

    //Step 2
    Node n;
    n.cost = 0;
    n.path.push(_startInd);

    //Step 3
    myPriorityQueue.push(n);

    //Step 4

    while (myPriorityQueue.top() != ) {

    }

    //Step 5


    return path;
}

void Navigation::printPath(queue<int> _path) {

    cout << "In print path..." << endl;

}



