#include"Money.h"

Money::Money() {
	Elektro = 50; //default player money to 50
}

Money::Money(int newMoney) {
	Elektro = newMoney;
}

Money::~Money() {}