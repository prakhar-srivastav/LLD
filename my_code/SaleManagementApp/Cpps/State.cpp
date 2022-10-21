
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include "../Header/State.h"
#include<utility>
using namespace std;








	State::State()
	{
		name = "";
		cities = map<string,City>{};
	}
	State::State(string stateName)
	{
		name = stateName;
		cities = map<string,City>{};
	}
	vector<string> State::createCity(string CityName)
	{
		if(cities.find(CityName)!=cities.end())
		{
			return vector<string> {"City already exists"};
		}
		
		City c = City(CityName);
		cities[CityName] =c ;
		return vector<string>{CityName+" City added"};
	}
	vector<string> State::createStore(string CityName,string storeName)
	{
		if(cities.find(CityName)==cities.end())
		{
			return vector<string> {"City does not exists"};
		}

		return cities[CityName].createStore(storeName);
		
	}
	vector<string> State::addFood(string CityName,string stateName,string storeName,string foodType,string foodItem,int price,int units)
	{
		if(cities.find(CityName)==cities.end())
		{
			return vector<string> {"City does not exists"};
		}

		return cities[CityName].addFood(storeName,foodType,foodItem,units,price);
	}

	vector<string> State::consumeFood(string CityName,string stateName,string storeName,string foodType,string foodItem,int units)
	{
		if(cities.find(CityName)==cities.end())
		{
			return vector<string> {"City does not exists"};
		}

		return cities[CityName].consumeFood(storeName,foodType,foodItem,units);
	}
	vector<string> State::getMenu(string CityName,string stateName,string storeName)
	{
		if(cities.find(CityName)==cities.end())
		{
			return vector<string> {"City does not exists"};
		}

		return cities[CityName].getMenu(storeName);
	}
	vector<string> State::stockLeft(string CityName,string stateName,string storeName)
	{
			if(cities.find(CityName)==cities.end())
		{
			return vector<string> {"City does not exists"};
		}

		return cities[CityName].stockLeft(storeName);
	}
	vector<string> State::soldStocks(string CityName,string stateName,string storeName)
	{
			if(cities.find(CityName)==cities.end())
		{
			return vector<string> {"City does not exists"};
		}

		return cities[CityName].soldStocks(storeName);
	}