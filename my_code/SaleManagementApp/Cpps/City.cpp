
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>
#include "../Header/City.h"
using namespace std;


City::City()
{
	stores=map<string,Store>{};
	cityName = "";
	priceList = map<pair<string,string>,int>{};
}
City::City(string name)
{
	stores=map<string,Store>{};
	cityName = name;
	priceList = map<pair<string,string>,int>{};
}
vector<string> City::createStore(string storeName)
{
	if(stores.find(storeName)!=stores.end())
	{
		return vector<string> {"Store already exists"};
	}
	
	Store c = Store(storeName);
	stores[storeName] =c ;
	return vector<string>{"Store added"};
}
vector<string> City::addFood(string storeName,string foodType,string foodItem,int units,int price)
{

	pair<string,string> p = make_pair(foodType,foodItem);
	if(stores.find(storeName)==stores.end())
		{
			return vector<string> {"Store does not exists"};
		}
	else if(!(foodType=="Food" || foodType=="Drinks"))
	{
		return vector<string>{"Wrong FoodType"};
	}


	if(priceList.find(p)==priceList.end())
	{
		priceList[p] = price;
	}
	
	if(priceList[p]!=price)
	{
		return vector<string>{"City have different Price"};
	}
	return stores[storeName].addFood(foodType,foodItem,units,price);

}
vector<string> City::consumeFood(string storeName,string foodType,string foodItem,int units)
{
	pair<string,string> p= make_pair(foodType,foodItem);
	if(stores.find(storeName)==stores.end())
		{
			return vector<string> {"Store doesnot exists"};
		}
	else if(!(foodType=="Food" || foodType=="Drinks"))
	{
		return vector<string>{"Wrong FoodType"};
	}
	return stores[storeName].consumeFood(foodType,foodItem,units);
}
vector<string> City::getMenu(string storeName)
{
	if(stores.find(storeName)==stores.end())
		{
			return vector<string> {"Store doesnt exists"};
		}

		return stores[storeName].getMenu();
}
vector<string> City::soldStocks(string storeName)
{
	if(stores.find(storeName)==stores.end())
			{
				return vector<string> {"Store doesnt exists"};
			}

		return stores[storeName].soldStocks();
}
vector<string> City::stockLeft(string storeName)
{
	if(stores.find(storeName)==stores.end())
			{
				return vector<string> {"Store doesnt exists"};
			}

		return stores[storeName].stockLeft();
}