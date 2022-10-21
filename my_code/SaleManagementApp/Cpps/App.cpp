#include<iostream>
#include<map>
#include<vector>
#include<string>
#include "../Header/App.h"
#include<utility>
using namespace std;



App::App()
{
	states = map<string,State>{};
}
vector<string> App::createState()
{
	string stateName;
	cin >> stateName;
	if(states.find(stateName)!=states.end())
		return vector<string>{"State already Exists"};
	
		State s = State(stateName);
		states[stateName] = s;
		return vector<string>{"State added"};

}
vector<string> App::createCity()
{
	string stateName, CityName;
	cin >> stateName >> CityName;
	if(states.find(stateName)==states.end())
		return vector<string>{"State does not Exists"};
	
		return states[stateName].createCity(CityName);
	
}
vector<string> App::createStore()
{
	string stateName, CityName,storeName;
	cin >> stateName >> CityName >> storeName;
	if(states.find(stateName)==states.end())
		return vector<string>{"State does not Exists"};
	
		
		return states[stateName].createStore(CityName,storeName);
	
}
vector<string> App::addFood()
{
	string stateName, CityName,storeName,foodItem,foodType;
	int price,units;

	cin >> stateName >> CityName >> storeName >> foodType >> foodItem;
	cin >> price >> units;
	if(states.find(stateName)==states.end())
		return vector<string>{"State does not Exists"};
	
		
		return states[stateName].addFood(CityName,stateName,storeName,foodType,foodItem,price,units);
	
}
vector<string> App::consumeFood()
{
	string stateName, CityName,storeName,foodItem,foodType;
	int units;

	cin >> stateName >> CityName >> storeName >> foodType >> foodItem;
	cin >> units;
	if(states.find(stateName)==states.end())
		return vector<string>{"State does not Exists"};
	
		
		return states[stateName].consumeFood(CityName,stateName,storeName,foodType,foodItem,units);

}
vector<string> App::getMenu()
{
	string stateName, CityName,storeName;
	cin >> stateName >> CityName >> storeName;
	if(states.find(stateName)==states.end())
		return vector<string>{"State does not Exists"};

		return states[stateName].getMenu(CityName,stateName,storeName);
	
}
vector<string> App::stockLeft()
{
	string stateName, CityName,storeName;
	cin >> stateName >> CityName >> storeName;
	if(states.find(stateName)==states.end())
		return vector<string>{"State does not Exists"};
	
		
		return states[stateName].stockLeft(CityName,stateName,storeName);
	

}
vector<string> App::soldStocks()
{
	string stateName, CityName,storeName;
	cin >> stateName >> CityName >> storeName;
	if(states.find(stateName)==states.end())
		return vector<string>{"State does not Exists"};
	
		return states[stateName].soldStocks(CityName,stateName,storeName);
	
}
vector<string> App::close()
{
	return vector<string>{"System closing"};

}


