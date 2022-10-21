#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "../Header/Rider.h"

using namespace std;

Rider::Rider()
{
	name ="";
	id="";
	rideCount=0;
	currentRide = NULL;
	currentDriver =NULL;
}
Rider::Rider(string name0,string id0)
{
	name = name0;
	id = id0;
	rideCount=0;
	currentRide=NULL;
	currentDriver=NULL;
}
vector<string> Rider::closeRide()
{
	float amount = (*currentRide).getAmount(rideCount);
	
	rideCount++;
	(*currentDriver).freeCurrentRide();
	currentRide = NULL;	
	return vector<string>{"Amount = " + to_string(amount)};
}
vector<string> Rider::withdrawRide()
{
	(*currentRide).clearRide();
	(*currentDriver).freeCurrentRide();
	currentRide = NULL;
	return vector<string>{"Withdrawm"};
}
bool Rider::haveRide()
{
	return (currentRide!=NULL);
}
void Rider::markRide(Ride *ride)
{
	currentRide=ride;
}
void Rider::markDriver(Driver *driver)
{
	currentDriver=driver;
}
void Rider::updateRide(int o,int d,int s)
{
	(*currentRide).updateRide(o,d,s);
}