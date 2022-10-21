#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>
#include "Header/App.h"
using namespace std;


signed main()
{
	freopen("input.txt", "r", stdin);
  App app;
  vector<string> mes; 
  while(true)
  {
  	
	cout << "0 createState()" << endl;
	cout << "1 createCity()" << endl;
	cout << "2 createStore()" << endl;
	cout << "3 addFood()" << endl;
	cout << "4 consumeFood()" << endl;
	cout << "5 getMenu()" << endl;
	cout << "6 stockLeft()" << endl;
	cout << "7 soldStocks()" << endl;
	cout << "8 close()" << endl;
	int c;
  	cin >> c ;
  	cout << c << endl;
	switch(c)
	{

		case 0:
		{
			mes =app.createState();
			break;
		}
		case 1:
		{
			mes =app.createCity();
			break;
		}
		case 2:
		{
			mes =app.createStore();
			break;
		}
		case 3:
		{
			mes =app.addFood();
			break;
		}
		case 4:
		{

			mes =app.consumeFood();
			break;
		}
		case 5:
		{
			mes =app.getMenu();
			break;
		}
		case 6:
		{

			mes =app.stockLeft();
			break;
		}
		case 7:
		{
			mes =app.soldStocks();
			break;

		}
		case 8:
		{
			mes =app.close();
			return 0;
		}
		default:
		{
			cout << "Bad Choice" << endl;
			break;
		}


  }
  for(auto line : mes) cout << line << endl;
  	mes.clear();
}


	
  return 0;
}
