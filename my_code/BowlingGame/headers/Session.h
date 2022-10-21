#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include "Player.h"



class Session
{
public:
	Session();
	std::string Play(std::string Player);
	bool hasCompleted(std::string Player);
	bool exists(std::string Player);
	void clearGround();
	std::pair<bool, std::string> getWinner();
	void startGame(int curAlley, std::vector<std::string> playerName);
private:
	int alleyID;
	std::vector<Player> players;
	std::map<std::string, int> dict;
};