

#include <iostream>
#include <vector>
#include <utility>
#include<string>
#include <map>

#include "../headers/Game.h"
Game::Game(int Alley)
{
	alley = Alley;
	freeAlley = std::vector<bool>(Alley,true);
	sessions = std::vector<Session>(Alley,Session());
}


std::string Game::createSession(std::vector<std::string> playerName)
{
	std::string Output ;

	int curAlley = -1;
	for( curAlley =0 ; curAlley<alley; curAlley++)
	{
		if(freeAlley[curAlley])
			break;
	}

	
	if(curAlley == alley)
		{
			
			Output = "No free Alley available";
		}
	else 
	{
		Output = "Game session created with Alley ID" + std::to_string(curAlley);
		sessions[curAlley].startGame(curAlley,playerName);
		freeAlley[curAlley]=false;
	}
	return Output;
}

std::string Game::declareWinner(int alleyID)
{
	//

	std::string Output;
	if( alleyID <0 || alleyID>=alley || freeAlley[alleyID])
	{
		Output = "Either Wrong alleyID or alley is empty";
		return Output;
	}


	//
	
	auto WinnerInfo = sessions[alleyID].getWinner();
	auto Success = WinnerInfo.first;
	auto Winner = WinnerInfo.second;
	if(Success)
	{
		Output = "The winner is" + Winner;
		sessions[alleyID].clearGround();
		freeAlley[alley]=true;
	}	
	else 
	{
		Output ="The Game is not completed";
	}
	return Output;
}


std::string Game::play(std::string str,std::string Player)
{

    std::string Output;
	for(auto a:str)
		{
			if(a<'0' or a>'9')
			{
				return "alleyID incorret";
			}
		}
	int alleyID=0;
	for(auto x:str)
		alleyID = alleyID*10 + x - '0';

	if(alleyID<0 || alleyID>=alley || freeAlley[alleyID])
	{
		Output = "Either Wrong alleyID or alley is empty";
		return Output;
	}
	if(!sessions[alleyID].exists(Player))
	{
		Output ="No player named " + Player; 
		return Output; 
	}
	//
	if(sessions[alleyID].hasCompleted(Player))
	{
		Output ="All frames done for " + Player; 
		return Output; 
	}

	Output = sessions[alleyID].Play(Player);
	return Output;
}