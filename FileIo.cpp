#include <iostream>
#include <fstream>  
#include <map>
#include <algorithm>
#include <string>
#include "City.h"
#include "HouseColor.h"
#include <vector>
#include "Resources.h"
#include "Money.h"
#include "FileIO.h"
#include "Player.h"
#include"AdjList.h"
#include"City.h"
#include"AdjlistNode.h"
#include"Map.h"
#include"Player.h"
#include<cstdlib>
using namespace std;
	


FileIO::FileIO() {

}

	string fileName;
	//cout << "Please enter filename: " << endl;
	//cin >> filename;
	string firstWord;
	string line;
	typedef map<string, int> line_record;
	line_record lines;
	int line_number = 1;



	bool is_file_exist(const char *fileName)
	{
		std::ifstream infile(fileName);
		return infile.good();
	}

	void CreateFile(std::string Filename)
	{

		std::ofstream outfile(Filename);
		//outfile << "my text here!" << std::endl;
		outfile.close();
	}

	Map* FileIO::getMap() {

		return graph;

	}

	void checkCityDuplicate()
	{	
		ifstream inFile(fileName);
		int count = 0;
		if (inFile.is_open())
		{
			while (getline(inFile, line))
			{
				line_record::iterator existing = lines.find(line);

				if (existing != lines.end())
				{
					existing->second = (-1);
					cout << line << endl;
					cout << "Oops it seems we have the same city" << endl;
					cout << "File will be closed" << endl;
					inFile.close();

				}
				else
				{
					lines.insert(make_pair(line, line_number));
					++line_number;
					cout << line << endl;
					count++;

				}
			}
		}
		else
		{
			cout << "File open failed" << endl;
		}
		//cout << "its -- > " << count << " record" << endl;
		inFile.close();

	}


	Map* FileIO::loadMap()
	{
		vector<std::string> edges;
		vector<int> iter;
		iter.push_back(0);
		string cityName;
		int cost;

		ifstream inFile(fileName);
		if (inFile.is_open()) {
			if (inFile.peek() == EOF) { // check if file is empty.

				std::cout << "Invald. File is empty!" << endl;
				inFile.close();
				system("pause");
				exit(0);
			}

			while (inFile >> cityName >> cost) {
				city.push_back(City(cityName, cost));
				
				cout << cityName<<"->"<<cost<< endl;
				
			}
		}
		else cout << "File load failed, please check if the file exists" << endl;
		system("pause");
		inFile.close();
		Map* graph;
		graph = Map::createGraph(city.size());
		for (int i = 0; i < city.size()-2; i++) 
		{
			Map::addEdge(graph, city.at(i), city.at(i+2));
		}
		Map::printGraph(graph);
		return graph;
	}





	void CopyMap()
	{
		ifstream inFile(fileName);
		ofstream outfile("test1.txt");
		string content = "";
		int i;

		for (i = 0; inFile.eof() != true; i++) // get content of infile
			content += inFile.get();

		i--;
		content.erase(content.end() - 1);     // erase last character

		cout << i << " characters read...\n";
		inFile.close();

		outfile << content;                 // output
		outfile.close();
		
	}

	void createHouses()
	{

		std::ofstream outfile;
		outfile.open("test1.txt", std::ios_base::app);

		
		vector<HouseColor>	redHouse;
		vector<HouseColor>	blueHouse;
		vector<HouseColor>	blackHouse;
		vector<HouseColor>	whiteHouse;
		vector<HouseColor>	yellowHouse;
		vector<HouseColor>	greenHouse;

		for (int i = 0; i < 22; i++)
		{	
			redHouse.push_back(HouseColor("red"));
			outfile <<"\n" <<redHouse.at(i).getName();
		}
		for (int i = 0; i < 22; i++)
		{
			blueHouse.push_back(HouseColor("blue"));
			outfile << "\n" << blueHouse.at(i).getName();
		}
		for (int i = 0; i < 22; i++)
		{
			blackHouse.push_back(HouseColor("black"));
			outfile << "\n" << blackHouse.at(i).getName();
		}
		for (int i = 0; i < 22; i++)
		{
			whiteHouse.push_back(HouseColor("white"));
			outfile << "\n" << whiteHouse.at(i).getName();
		}
		for (int i = 0; i < 22; i++)
		{
			yellowHouse.push_back(HouseColor("yellow"));
			outfile << "\n" << yellowHouse.at(i).getName();
		}
		for (int i = 0; i < 22; i++)
		{
			greenHouse.push_back(HouseColor("green"));
			outfile << "\n" << greenHouse.at(i).getName();
		}
		cout << "Houses are created and placed on map" << endl;
		outfile.close();
		/*for (int i =0; i <redHouse.size(); i++)
		{
			std::cout <<redHouse.at(i).getName()<< std::endl;
		}
		for (int i = 0; i <blueHouse.size(); i++)
		{
			std::cout << blueHouse.at(i).getName() << std::endl;
		}
		for (int i = 0; i <blackHouse.size(); i++)
		{
			std::cout << blackHouse.at(i).getName() << std::endl;
		}
		for (int i = 0; i <whiteHouse.size(); i++)
		{
			std::cout << whiteHouse.at(i).getName() << std::endl;
		}
		for (int i = 0; i <yellowHouse.size(); i++)
		{
			std::cout << yellowHouse.at(i).getName() << std::endl;
		}
		for (int i = 0; i <greenHouse.size(); i++)
		{
			std::cout << greenHouse.at(i).getName() << std::endl;
		}*/
		

	}

	void createResoueces() {
		vector<Resources> Coal;
		vector<Resources> Oil;
		vector<Resources> Garbage;
		vector<Resources> Uranium;

		std::ofstream outfile;
		outfile.open("test1.txt", std::ios_base::app);

		for (int i = 0; i < 22; i++)
		{
			Coal.push_back(Resources("Coal"));
			outfile << "\n"<<Coal.at(i).getResourceName();
		}
		for (int i = 0; i < 22; i++)
		{
			Oil.push_back(Resources("Oil"));
			outfile << "\n" << Oil.at(i).getResourceName();
		}
		for (int i = 0; i < 22; i++)
		{
			Garbage.push_back(Resources("Garbage"));
			outfile << "\n" << Garbage.at(i).getResourceName();
		}
		for (int i = 0; i < 12; i++)
		{
			Uranium.push_back(Resources("Uranium"));
			outfile << "\n" << Uranium.at(i).getResourceName();
		}
		cout<<"Resources are created and placed on map"<<endl;
		outfile.close();
		/*for (int i = 0; i < 22; i++)
		{
			std::cout << Coal.at(i).getResourceName() << std::endl;
		}
		for (int i = 0; i < 22; i++)
		{
			std::cout << Oil.at(i).getResourceName() << std::endl;
		}
		for (int i = 0; i < 22; i++)
		{
			std::cout << Garbage.at(i).getResourceName() << std::endl;
		}
		for (int i = 0; i < 12; i++)
		{
			std::cout << Uranium.at(i).getResourceName() << std::endl;
		}*/


	}




	void createElektro()
	{	
		std::ofstream outfile;
		outfile.open("test1.txt", std::ios_base::app);
		Money TotalElektro(1000);

		outfile << "\n"<<TotalElektro.getMoney();
		cout<<"Elektro has been created and placed on map"<<endl;
		outfile.close();
	}

	void appendToFile() 
	{
		std::ofstream outfile;
		outfile.open("test.txt", std::ios_base::app);
		
		outfile <<"";
		
	}

	int main()
	{
		fileName = "test.txt";
		Map *map;
		FileIO newfile = FileIO();
		map = newfile.loadMap();
		
		checkCityDuplicate();
		
		CopyMap();
		createHouses();
		createResoueces();
		createElektro();





		//task 4
		City citya = City("cityA",1,10);
		City cityb = City("cityB",2,10);
		Money* money1 = new Money(50);
		Money* money2 = new Money(50);
		Player* player1 =new Player(1, "PlayerA", money1, "White");
		Player* player2 = new Player(2, "PlayerB", money2, "Black");
		map->setPlayer(citya, player1);
		map->setPlayer(cityb, player2);
		player1->setResources("coal");
		player2->setResources("garbage");
		cout << player1->showInformation() << endl;
		cout << player1->getResources() << endl;
		cout << player2->showInformation() << endl;
		cout << player2->getResources() << endl;
	

		system("pause");
		return 0;


	}
