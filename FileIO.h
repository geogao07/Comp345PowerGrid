#pragma once
#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include"Map.h"
#include"City.h"

class FileIO {
private:
	Map * graph;
	std::vector<City> city;

public:
	FileIO();
	Map* loadMap();
	Map* getMap();

};