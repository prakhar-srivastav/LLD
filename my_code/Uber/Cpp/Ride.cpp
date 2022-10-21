#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "../Header/Ride.h"

using namespace std;

Ride::Ride()
{
	origin =0;
	destination =0 ;
	seats =0;
}
Ride::Ride(int origin0,int destination0,int seats0)
{
	origin = origin0;
	destination = destination0;
	seats = seats0;
}
void Ride::clearRide()
{
	origin = destination;
	return ;
}
float Ride::getAmount(int rideCount)
{
	float C;
	if(seats ==1)
		C = (rideCount>=10?0.75f:1.0f);
	else 
		C = (rideCount>=10?0.5f:0.75f);

	return C*seats*(destination-origin)*amountPerKM;
}
void Ride::updateRide(int o,int d,int s)
{
	origin = o ;
	destination = d;
	seats = s;
}