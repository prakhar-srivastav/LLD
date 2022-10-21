#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "Ride.h"
#include "Driver.h"
using namespace std;


class Rider
{
private:
	string name,id;
	int rideCount;
	Driver *currentDriver;
	Ride *currentRide;
public:
	Rider();
	Rider(string name0,string id0);
	vector<string> closeRide();
	vector<string> withdrawRide();
	bool haveRide();
	void markRide(Ride *ride);
	void markDriver(Driver *driver);
	void updateRide(int o,int d,int s);

};