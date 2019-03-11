#include "Player.h"
#include "City.h"


using namespace std;

Player::Player() {
	name = "";
	player_num = 0;
	elektro = 0;
	colour = "";
}
Player::Player(int p_num, string player_name, Money* player_money, string player_colour) {
	player_num = p_num;
	name = player_name;
	elektro = player_money;
	colour = player_colour;
}

string Player::showCityOwned() {
	cout << "Controlled Cities: ";
	for (int i = 0; i < (int)cityOwned.size(); i++) {
		cout << cityOwned.at(i) << ", ";
	}
	return "\n";
}
string Player::showInformation() {

	cout << "\n************************\n" << getPlayer() << "\n************************\n" << endl;

	//Output for cities owned
	//showCityOwned();

	cout << "Money has: " << getMoney()->getMoney() << endl;
	return "";
}
