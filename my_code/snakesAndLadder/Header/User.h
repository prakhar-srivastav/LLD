#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "Dice.h"

using namespace std;
class User
{
private:
	string name;
	int pos;
	Dice dice;
public:
	User();
	User(string userName);
	string getName();
	int getPos();
	void setPos(int newPosition);
	int roll();
};