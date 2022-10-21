#pragma once
#include<utility>
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

class Food
{
private:
	string Type;
	string name;
	int sold;
	int price;
	int unit;
public:
	Food();
	Food(string foodType,string foodItem,int units,int price0);
	vector<string> stockLeft();
	vector<string> soldStocks();
	vector<string> consumeFood(int amount);
	void addFood(int amount);

	
};