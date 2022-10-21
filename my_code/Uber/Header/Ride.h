#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
static int amountPerKM = 20;

class Ride
{
private:
	int origin;
	int destination;
	int seats;

public:
	Ride();
	Ride(int origin0,int destination0,int seats0);
	void clearRide();
	float getAmount(int rideCount);
	void updateRide(int o,int d,int s);
};