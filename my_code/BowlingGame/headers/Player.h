#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include<string>


class Player
{
public:
	Player(std::string Players);
	int getFrame();
	int getScore();
	std::string getName();
	std::string play();
	std::string swing();
private:
	std::string name;
	int score;
	int frame;
	
};