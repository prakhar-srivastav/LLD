#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include "Header/App.h"


signed main()
{

	App app = App();
	app.createBoard();
	app.createUser();
	app.play();
	return 0;
}