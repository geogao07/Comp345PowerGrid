#pragma once
#include "City.h"
#include "Money.h"
#include <iostream>
#include <vector>
#include "Resources.h"

using namespace std;

class City;

class Player
{
public:
	Player();
	Player(int player_num, string player_name, Money* player_money, string player_colour);

	vector<string> cityOwned;//City cityOwned;
	vector<string> resourcesOwned;

	void setPlayer(string Pname)
	{
		name = Pname;
	}
	void setElektro(int Pmoney)
	{
		elektro->setMoney(Pmoney);
	}
	void setColour(string color)
	{
		colour = color;
	}
	string getColour()
	{
		return colour;
	}
	void setPlayerNum(int p_num) 
	{
		player_num = p_num;
	}
	string getPlayer()
	{
		return name;
	}

	int getPlayerNum() {
		return player_num; 
	};
	Money* getMoney()
	{
		return elektro;
	}

	void setResources(string resourceName) {
		resource.setResourceName(resourceName);
	}

	string getResources() {
		return resource.getResourceName();
	}

	string showCityOwned();
	string showInformation();

private:
	string name;
	Money* elektro;
	string colour;
	int player_num;
	Resources resource;
};
