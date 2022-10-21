
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>
#include "../Header/Store.h"
using namespace std;




Store::Store()
{
	name ="";
	foods = map<pair<string,string>,Food>{};
	priceList = map<pair<string,string>,int>{};
}
Store::Store(string storeName)
{
	name =storeName;
	foods = map<pair<string,string>,Food>{};
	priceList = map<pair<string,string>,int>{};
}
vector<string> Store::addFood(string foodType,string foodItem,int units,int price)
{
	pair<string,string> p = make_pair(foodType,foodItem);

	if(foods.find(p)==foods.end())
	{
		Food f = Food(foodType,foodItem,0,price);
		foods[p] = f;
		priceList[p]=price;
	}
	if(units<0)
		units = 0 ;
	foods[p].addFood(units);

	return vector<string>{"Added food to the store"};
}
vector<string> Store::consumeFood(string foodType,string foodItem,int units)
{
	pair<string,string> p = make_pair(foodType,foodItem);

	if(foods.find(p)==foods.end())
	{
		return vector<string>{"No such food in the store"};
	}
	return foods[p].consumeFood(units);
}
vector<string> Store::soldStocks()
{
	vector<string> message;
	for(auto food : foods)
	{
		message.push_back(food.second.soldStocks()[0]);
	}
	return message;
}
vector<string> Store::stockLeft()
{
	vector<string> message;
	for(auto food : foods)
	{
		message.push_back(food.second.stockLeft()[0]);
	}
	return message;
}
vector<string> Store::getMenu()
{
	vector<string> message;
	for(auto food : priceList)
	{
		string res = food.first.first + "=>" + food.first.second + ": "  + to_string(food.second);
		message.push_back(res);
	}
	return message;
}

