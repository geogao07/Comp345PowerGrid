#pragma once
#include<string>
#include "HouseColor.h"

using namespace std;



class Player;
class HouseColor;


class City {
public:
	static int cityCount; 	//The number of city objects that have been created

	int count; //Accessor for cityCount in constructor
	int cityId;

	City(string name, int Id);
	
	City(string name, int Id, int cost);

	
	void setId(int Id)
	{
		cityId = Id;
	}
	void setName(string cityName)
	{
		this->cityName = cityName;
	}
	void setFull(bool isFull)
	{
		isFull = true;
	}
	void setHouseColor(HouseColor* HouseColor);
	void setPlayer(Player* Owner);

	string getName()
	{
		return cityName;
	}
	int getId()
	{
		return cityId;
	}

	int getCost()
	{
		return cost;
	}

	bool getFull() {
		return isFull;
	}


private:
	static int nextId;
	string cityName;
	
	int cost;
	bool isFull;
	Player* player;
	HouseColor* house;

};