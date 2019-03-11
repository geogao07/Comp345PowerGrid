#pragma once

#include <string>
#include"Player.h"

using std::string;



class Player;


class HouseColor 
{
private:
	string colorName;

public:
	Player * player;
	HouseColor() ;
	HouseColor(Player* player);
	HouseColor(string name);


	void setOwner(Player* newPlayer);
	Player* getOwner();


	void setName(string name)
	{
		colorName = name;
		
	}
	string getName()
	{
		return colorName;
	};

	~HouseColor();

};