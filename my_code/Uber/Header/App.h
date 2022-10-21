#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "Rider.h"
#include "Driver.h"
#include "Ride.h"
using namespace std;


class App
{
private:
	vector<Ride> rides;
	map<string, Driver> drivers;
	map<string, Rider> riders;
public:
	App();
	vector<string> addRider();
	vector<string> addDriver();
	vector<string> createRide();
	vector<string> updateRide();
	vector<string> withdrawRide();
	vector<string> closeRide();
};