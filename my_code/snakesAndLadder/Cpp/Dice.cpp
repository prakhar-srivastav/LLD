#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include "../Header/Dice.h"

using namespace std;


Dice::Dice()
{
	diceSeed=0;
}
Dice::Dice(int seed)
{
	diceSeed=seed;
}
int Dice::roll()
{
	return (diceSeed+(int(rand())))%6+1;
}