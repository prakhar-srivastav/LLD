#pragma once
#include<utility>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include "Food.h"
using namespace std;

class Store
{
private:
	string name;
	map<pair<string,string>,Food> foods;
	map<pair<string,string>,int> priceList;
public:
	Store();
	Store(string storeName);
	vector<string> addFood(string foodType,string foodItem,int units,int price);
	vector<string> consumeFood(string foodType,string foodItem,int units);
	vector<string> soldStocks();
	vector<string> stockLeft();
	vector<string> getMenu();
};