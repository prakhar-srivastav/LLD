#pragma once
#include<utility>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include "State.h"
using namespace std;




class App
{
private:
	map<string,State> states;
public:
	App();
	vector<string> createState();
	vector<string> createCity();
	vector<string> createStore();
	vector<string> addFood();
	vector<string> consumeFood();
	vector<string> getMenu();
	vector<string> stockLeft();
	vector<string> soldStocks();
	vector<string> close();
};