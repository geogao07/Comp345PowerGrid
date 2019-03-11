#pragma once
#include <iostream>
#include <string>

class Money 
{
public:
	Money();

	Money(int money);



	int getMoney()
	{
		return Elektro;
	}


	void setMoney(int money)
	{
		Elektro = money;
	}


	void addMoney(int money)
	{
		Elektro += money;
	}

	void subtractMoney(int money)
	{
		Elektro -= money;
	}
	void show()
	{
		std::cout << "Total Amout:"<<Elektro << std::endl;
	}
	void buy(int price, int player)
	{
	
	}
	~Money();
	private:
		int Elektro;
};