#include <iostream>
#include <string>

#define VOLTAGE 2.0
#define DISTANCE 5.0
#define WIDSTRIP1 1.95
#define WIDSTRIP2 1.8
#define LENSTRIP1 3.9
#define LENSTRIP2 3.8
/*
	How it's done:
	1. Find specific resistance from specific current (divide by voltage) giving ohms
	2. Take reciprocal of resistance (ohm^-1) finding the conductance in siemens (S) of the specific sample
	3. Divide the length between the electrodes (cm) by the average surface area of the electrodes exposed to the electrolyte (cm^2) to get cm^-1
	4. Divide the ratio of length to surface area (cm^-1) by the conductance to find the conductivity (Siemens / centimetre or S cm^-1)
	5. Return this value as well as conductance and resistance because they're useful to record too.

*/

using namespace std;                                                     

struct solution
{
	float current;
	float resistance;
	float conductance;
	float conductivity;
	string name;
};

void printSol(solution sol)
{
	cout << "--- " << sol.name << " ---" << endl;
	cout << "Current: " << sol.current << " A" << endl;
	cout << "Resistance: " << sol.resistance << " ohms" << endl;
	cout << "Conductance: " << sol.conductance << " S" << endl;
	cout << "Conuctivity: " << sol.conductivity << " S cm^-1" << endl;
	cout << "End" << endl;
	return;
}

int main()
{
	float surfaceArea1 = WIDSTRIP1 * LENSTRIP1;
	float surfaceArea2 = WIDSTRIP2 * LENSTRIP2;
	float averageSurfaceArea = (surfaceArea1 + surfaceArea2) / 2;
	
	solution solTested; 
	cout << "Specify solution name: ";
	cin >> solTested.name;
	cout << "Enter current : ";
	cin >> solTested.current;
	solTested.resistance = VOLTAGE / solTested.current;
	solTested.conductance = 1 / solTested.resistance;
	solTested.conductivity = solTested.conductance * (averageSurfaceArea / DISTANCE);
	printSol(solTested);
	string answer;
	while(1)
	{
	cout << "Continue? (y/n)";
	cin >> answer;
	if(answer == "y")
		main();
	else if(answer == "n")
		return 1 ;
	else
		cout << "Bad answer." << endl;
	}
}