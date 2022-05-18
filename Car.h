#pragma once
#include <string>

class Car
{
private:
	unsigned int Nr_Start; 
	double Paliwo;
	double Pojemnosc_Baku;
	double Spalanie;
	double Przebieg;

public:
	Car();
	bool Jazda(double);
	void Tankowanie(double);
	void setNr_Start(unsigned int);
	double getPrzebieg();
	double getPaliwo();
	double getPojemnosc_Baku();
	void getStan(std::string&);
};

