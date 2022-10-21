


#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include<string>

#include "../headers/Player.h"



Player::Player(std::string Players): name(Players)
{
 	score =0;
 	frame = 0;
}

int Player::getFrame()
{
	return frame;
}
int Player::getScore()
{
	return score;
}
std::string Player::getName()
{
	return name;
}

std::string Player::swing()
{
	frame++;
	int randomNumber = rand()%2 + 1;
	if(randomNumber<=2)
		{
			score+=10;
			return "Strike";
			
		}
	else if(randomNumber<=4)
		{
			score+=5;
			return "Spare";
			
		}
	return "Duck";



}


std::string Player::play()
{
	int oldScore = score;
	std::string result = swing();
	int newScore = score;

	std::string Output = name + " has got a " + result + " and gained " + std::to_string(newScore-oldScore) + " Points with a Final score: " + std::to_string(newScore);
	return Output; 
}