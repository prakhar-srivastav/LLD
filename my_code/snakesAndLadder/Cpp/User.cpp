#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include "../Header/User.h"

using namespace std;

User::User()
{
	name = "";
	pos = 0;
}
User::User(string userName)
{
	name = userName;
	pos =0 ;
	dice = Dice(((int(rand()))%10)); 
}
string User::getName()
{
	return name;
}
int User::getPos()
{
	return pos;
}
void User::setPos(int newPosition)
{
	pos = newPosition;
}
int User::roll()
{
	return dice.roll();
}