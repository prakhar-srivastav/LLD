#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include<string>
#include "Session.h"






class Game
{

public:
	Game(int alley);
	std::string createSession(std::vector<std::string> playerName);
	std::string declareWinner(int alleyID);
	std::string play(std::string alleyID, std::string Player);

private:
	int alley;
	std::vector<bool> freeAlley;
	std::vector<Session> sessions;


};