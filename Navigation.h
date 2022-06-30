#ifndef NAVIGATION_NAVIGATION_H
#define NAVIGATION_NAVIGATION_H

#include <iostream>
#include <string>
#include <queue>
#include "NavigationInterface.h"


class Navigation : public NavigationInterface {

public:

    Navigation() {}

    virtual ~Navigation() {}


    virtual bool readNetwork(string _mapName);

    virtual queue<int> computeShortestPath(int _startInd, int _endInd);

    virtual void printPath(queue<int> _path);

};


#endif
