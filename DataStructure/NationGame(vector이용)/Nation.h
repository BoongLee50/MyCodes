#ifndef NATION_H
#define NATION_H
#include <iostream> 
#include <string> 
#include <vector> 
using namespace std;
#include <ctime> 
#include <cstdlib> 

class Nation
{
	string nation, capital;
public:
	Nation() {}
	Nation(string n, string c) { nation = n; capital = c; }
	void setCapital(string c) { capital = c; }
	void setNation(string n) { nation = n; }
	string getCapital() { return capital; }
	string getNation() { return nation; }
};

#endif // !NATION_H