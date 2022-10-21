
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include<string>
#include "../headers/Session.h"



Session::Session()
{
	alleyID = -1;
	players =std::vector<Player>{};
	dict = std::map<std::string, int>{};
}

std::string Session::Play(std::string Player)
{
	auto &playerObject = players[dict[Player]];
	std::string Output = playerObject.play();
	return Output;
}


bool Session::hasCompleted(std::string Player)
{
	auto &playerObject = players[dict[Player]];
	int frame = playerObject.getFrame();

	return (frame==10);
}

bool Session::exists(std::string Player)
{
	return (dict.find(Player)!=dict.end());
}

void Session::clearGround()
{
	alleyID = -1;
	dict.clear();
	players.clear();
}

std::pair<bool,std::string> Session::getWinner()
{
	std::string playerName ="";
	int maxScore = 0 ;

	bool anyRemaingPlayer = false;

	for(auto &player : players)
	{
		if(player.getFrame()<10)
			anyRemaingPlayer=true;
		else
		{
			if(maxScore<player.getScore())
			{
				maxScore = player.getScore();
				playerName = player.getName();
			}
		}
	}
	return {!anyRemaingPlayer,playerName};

}


void Session::startGame(int curAlley,std::vector<std::string> playerName)
{
	alleyID = curAlley;
	for(auto player:playerName)
	{
		Player playerObject(player);
		players.push_back(playerObject);
		dict[player] = (int)(players.size()) - 1;
	}
	return ;
}