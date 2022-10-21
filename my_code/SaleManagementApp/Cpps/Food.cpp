#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>
#include "../Header/Food.h"
using namespace std;



Food::Food()
{
	Type = "";
	name = "";
	sold =0;
	price =0 ;
	unit =0 ; 
}
Food::Food(string foodType,string foodItem,int units0,int price0)
{
	Type = foodType;
	name = foodItem;
	sold =0 ;
	price= price0;
	unit =units0;
}
vector<string> Food::stockLeft()
{
	return vector<string>{Type+"-"+name+" "+to_string(unit)};
}
vector<string> Food::soldStocks()
{
	return vector<string>{to_string(sold)};
}
vector<string> Food::consumeFood(int amount)
{
	if(amount<0) amount =0 ;
	if(amount>unit) amount = unit;
	unit-=amount;
	sold+=amount;
	return vector<string>{"Food consumed"};
}
void Food::addFood(int amount)
{
	unit+=amount;
}