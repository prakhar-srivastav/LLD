		
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include "../Header/App.h"
using namespace std;





App::App()
{
	rides = vector<Ride>{};
	drivers= map<string,Driver>{};
	riders =map<string,Rider>{};
}
vector<string> App::addRider()
{
	string name,id;
	cin >> name >> id;
	if(riders.find(id)!=riders.end())
		return vector<string>{"rider already exists"};

	riders[name] = Rider(name,id);
	return vector<string>{"Successful"};
}
vector<string> App::addDriver()
{
	string name,id;
	cin >> name >> id;
	if(drivers.find(id)!=drivers.end())
		return vector<string>{"rider already exists"};

	drivers[name] = Driver(name,id);
	return vector<string>{"Successful"};
}

vector<string> App::updateRide()
{
	string riderID;
	int origin,destination,seats;
	cin >> riderID >> origin >> destination >> seats;

	if(riders.find(riderID)==riders.end())
		return vector<string> {"No such rider exists"};

	if(origin<0 || destination<0 || destination<origin || seats<0)
		return vector<string>{"Error in figures given"};

	auto &rider = riders[riderID];

	if(rider.haveRide())
		{
			rider.updateRide(origin,destination,seats);
			return vector<string>{"Ride updated"};
		}

	for(auto &driverPair : drivers)
	{
		auto &driver = driverPair.second;
		if(driver.isFree())
		{
			rides.push_back(Ride(origin,destination,seats));
			rider.markRide(&rides.back());
			driver.markRide(&rides.back());
			rider.markDriver(&driver);
			return vector<string>{"Ride created"};

		}
	}
	return vector<string>{"No free Drivers at a moment"};
}

vector<string> App::createRide()
{
	string riderID;
	int origin,destination,seats;
	cin >> riderID >> origin >> destination >> seats;

	if(riders.find(riderID)==riders.end())
		return vector<string> {"No such rider exists"};

	if(origin<0 || destination<0 || destination<origin || seats<0)
		return vector<string>{"Error in figures given"};

	auto &rider = riders[riderID];

	if(rider.haveRide())
		return vector<string>{"Rider is already in a ride"};

	for(auto &driverPair : drivers)
	{
		auto &driver = driverPair.second;
		if(driver.isFree())
		{
			Ride ride = Ride(origin,destination,seats);
			rides.push_back(ride);
			rider.markRide(&rides.back());
			driver.markRide(&rides.back());
			rider.markDriver(&driver);
			return vector<string>{"Ride created"};

		}
	}
	return vector<string>{"No free Drivers at a moment"};
}

vector<string> App::withdrawRide()
{
	string riderID;
	cin >> riderID;
	if(riders.find(riderID)==riders.end())
		return vector<string> {"No such rider exists"};
	if(!riders[riderID].haveRide())
		return vector<string>{"No rides to withdraw"};
	return riders[riderID].withdrawRide();

}
vector<string> App::closeRide()
{
	string riderID;
	cin >> riderID;
	if(riders.find(riderID)==riders.end())
		return vector<string> {"No such rider exists"};
	if(!riders[riderID].haveRide())
		return vector<string>{"No rides to close"};
	return riders[riderID].closeRide();
}