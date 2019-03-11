#include"HouseColor.h"


HouseColor::HouseColor() {
}

HouseColor::HouseColor(string name) : colorName{ name } {}



HouseColor::HouseColor(Player* newPlayer) {
	player = newPlayer;
}


HouseColor::~HouseColor() 
{
}


void HouseColor::setOwner(Player* newPlayer) {

	player = newPlayer;
}

Player* HouseColor::getOwner() {
	return player;
}
