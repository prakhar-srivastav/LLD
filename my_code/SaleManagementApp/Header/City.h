#pragma once
#include<utility>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include "Store.h"
using namespace std;

class City
{
private:
	map<string,Store> stores;
	string cityName;
	map<pair<string,string>,int> priceList;

public:
	City();
	City(string name);
	vector<string> createStore(string storeName);
	vector<string> addFood(string storeName,string foodType,string foodItem,int units,int price);
	vector<string> consumeFood(string storeName,string foodType,string foodItem,int units);
	vector<string> getMenu(string storeName);
	vector<string> soldStocks(string storeName);
	vector<string> stockLeft(string storeName);
};