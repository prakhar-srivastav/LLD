#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include<string>
#include "headers/Session.h"
#include "headers/Player.h"
#include "headers/Game.h"





const int Alley = 10; 
signed main()
{

	Game game(Alley);
	
	while(true)
	{

		std::cout <<"Enter your choice" << std::endl; 
		std::cout <<"1.Create Session" << std::endl; 
		std::cout <<"2.Declere Winner" << std::endl; 
		std::cout <<"3.Play" << std::endl; 
		std::cout <<"4.Exit" << std::endl; 
		int Choice ;
		// return ;
		std::cin >> Choice;

		switch(Choice)
		{
			case 1:
			{
				int Player;
				std::cout <<"Enter number of players" << std::endl; 
				std::cin >> Player;
				std::cout <<"Enter all the players name" << std::endl; 
				std::vector<std::string> playerName(Player);
				for(auto &name: playerName) std::cin >> name;
				std::cout <<"Enter all the players name" << std::endl; 	
				std::string Output = game.createSession(playerName);
				std::cout << Output << std::endl;
				break;
			}
			case 2:
			{
				int alleyID;
				std::cout <<"Enter Alley ID" << std::endl; 
				std::cin >> alleyID;
				std::string Output = game.declareWinner(alleyID);
				std::cout << Output << std::endl;
				break;
			}
			case 3:
			{
				std::string alleyID;
				std::string Player;
				std::cout <<"Enter Alley ID" << std::endl; 
				std::cin >> alleyID;
				std::cout <<"Enter Player name" << std::endl; 
				std::cin >> Player;
				std::string Output = game.play(alleyID,Player);
				std::cout << Output << std::endl;
				break;
			}
			case 4:
			{
				std::cout << "Ending the Game" << std::endl;
				return 0;
			}
			default:
			{
				std::cout << "Wrong Choice" <<std::endl;
				break;
			}
		}

	} 
	return 0; 
}