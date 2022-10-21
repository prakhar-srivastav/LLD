#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "../Header/Driver.h"
using namespace std;

Driver::Driver()
{
	name ="";
	id ="";
	currentRide = NULL;
}
void Driver::freeCurrentRide()
{
	currentRide = NULL;
}
Driver::Driver(string name0,string id0)
{
	name =name0;
	id =id0;
	currentRide = NULL;
}
bool Driver::isFree()
{
	return (currentRide==NULL);
}
void Driver::markRide(Ride *ride)
{
	currentRide = ride;
}