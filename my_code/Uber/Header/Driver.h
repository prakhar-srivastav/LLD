#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "Ride.h"
using namespace std;


class Driver
{
private:
	string name,id;
	Ride *currentRide;
public:
	Driver();
	Driver(string name0,string id0);
	bool isFree();
	void markRide(Ride *ride);
	void freeCurrentRide();
};