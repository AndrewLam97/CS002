	/* 
		CS002_Assignment1.cpp 
		Andrew Lam
		9-17-19
	
		NAME: Bus Stops
		PURPOSE: Tracks the amount of passengers that enter and exit a bus, as well as the amount of stops the bus makes.
		INPUTS: Amount of passengers that enter and exit the bus, continue y/n
		RETURNS: Number of stops and passengers on the bus
	*/

	#include <iostream>
	using namespace std;

	int passengerOn = 0, passengerOff = 0, passengerTotal = 0, stopCounter = 0;
	char continueVar;

	int getOn()
	{
		cin >> passengerOn;
		return passengerOn;
	}

	int getOff()
	{
		cin >> passengerOff;
		return passengerOff;
	}

	int main()
	{
		while(continueVar != 'n')
		{
			cout << "How many passengers are getting on the bus? \n";
			getOn();
			cout << "How many passengers are getting off the bus? \n";
			passengerTotal += passengerOn - getOff();
			stopCounter ++;
			cout << "Continue? Enter 'y' for yes and 'n' for no \n";
			cin >> continueVar;	
		}
		cout << "After " << stopCounter << " stops, there are " << passengerTotal << " people remaining on the bus.";
	}
