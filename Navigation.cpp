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

    if (input.is_open()) {
        int tempInt;
        input >> numNodes;

        cout << "numNodes = " << numNodes << endl;

        for (int i = 0; i < numNodes; ++i) {
            vector<int> tempVector;

            for (int j = 0; j < numNodes; ++j) {
                input >> tempInt;
                tempVector.push_back(tempInt);
            }
            costMatrix.push_back(tempVector);
        }

        input.close();
        return true;
    }
    else {

        return false;
    }
}

queue<int> Navigation::computeShortestPath(int _startInd, int _endInd) {

    cout << "Computing the shortest path..." << endl;

    queue<int> bestPath;

    //Step 1
    priority_queue <Node, vector<Node>, Node> myPriorityQueue;

    //Step 2
    Node n;
    n.cost = 0;
    n.path.push(_startInd);

    //Step 3
    myPriorityQueue.push(n);

    //Step 4
    while (myPriorityQueue.top().path.back() != _endInd) {
        //Step 5
        Node current = myPriorityQueue.top();
        myPriorityQueue.pop();

        //Step 6
        int last = current.path.back();

        //Step 7
        for (int i = 0; i < numNodes; ++i) {
            if (costMatrix.at(last).at(i) > 0) {
                Node nn;
                nn.cost = current.cost + costMatrix.at(last).at(i);
                nn.path = current.path;
                nn.path.push(i);

                //Step 8
                myPriorityQueue.push(nn);
            }
        }
    }

    bestPath = myPriorityQueue.top().path;

    return bestPath;
}

void Navigation::printPath(queue<int> _path) {

    cout << "Printing the shortest path..." << endl;

    while (!_path.empty()) {
        if (_path.size() > 1) {
            cout << _path.front() << ", ";
            _path.pop();
        }
        else {
            cout << _path.front() << endl;
            _path.pop();
        }
    }
}