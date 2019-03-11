#include "City.h"
#include "Player.h"
#include<cstdlib>
#include<iostream>


int City::cityCount = 0; //Amount of cities created

City::City(string name, int Id, int costs)
{
	cityName = name;
	cityId = Id;
	cost = costs;
	isFull = false;
	player = new Player;
	house = new HouseColor; //sets house situated in a city

}
City::City(string names, int costs) {
	cityId = ++nextId; //increments ID
	cityName = names;
	cost = costs;
	isFull = false;
	player = new Player;//sets owner of a city
	house = new HouseColor; //sets house situated in a city
	++cityCount;
}

int City::nextId = -1; //The unique ID for each created City object


void City::setHouseColor(HouseColor* houses) {
	//if city isn't full, set the house
	if (getFull() == false) {
		house = houses;
		player = house->getOwner(); //sets city owner to owner of house
		player->cityOwned.push_back(getName()); //adds the city name to list of controlled cities for player
		cout << house->getOwner()->getPlayer() << " have set the house at " << getName() << endl; // output that player set a house
		setFull(true); //sets city to being occupied
	}
	else {
		cout << "City is Full!!!" << endl;
	}
}


//Set Player to a city
void City::setPlayer(Player* owner) {
	if (getFull() == false) {
		cout << owner->getPlayer() << " Is in " << getName() << endl;
	}
	else {
		cout << "City is Owned by someone else" << endl;
	}
}
