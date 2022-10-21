#pragma once
#include<utility>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include "City.h"
using namespace std;

class State
{
private:
	string name;
	map<string,City> cities;
public:
	State();
	State(string stateName);
	vector<string> createCity(string CityName);
	vector<string> createStore(string CityName,string storeName);
	vector<string> addFood(string CityName,string stateName,string storeName,string foodType,string foodItem,int price,int units);
	vector<string> consumeFood(string CityName,string stateName,string storeName,string foodType,string foodItem,int units);
	vector<string> getMenu(string CityName,string stateName,string storeName);
	vector<string> stockLeft(string CityName,string stateName,string storeName);
	vector<string> soldStocks(string CityName,string stateName,string storeName);
	
	
};