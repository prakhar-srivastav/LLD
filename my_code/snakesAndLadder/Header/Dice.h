#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>


using namespace std;
class Dice
{
private:
	int diceSeed =0 ; 
public:
	Dice();
	Dice(int seed);
	int roll();
};