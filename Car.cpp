// Adam Geppert, Piotr Bodnar Grupa 7

#include "Car.h"
#include <string.h>
#include <cstdlib>


Car::Car() : Nr_Start(0), Paliwo(0.0), Przebieg(0.0) {
	Spalanie = (double)rand() / RAND_MAX * (0.10 - 0.04) + 0.04;
	Pojemnosc_Baku = (double)rand() / RAND_MAX * (100 - 40) + 40;
}

bool Car::Jazda(double dystans)
{
	double zasoby = Paliwo / Spalanie; 
	if (dystans <= zasoby)
	{
		Przebieg += dystans;
		Paliwo -= dystans * Spalanie;
		return true;
	}
	else
	{
		Paliwo = 0;
		Przebieg += zasoby;
		return false;
	}
}

void Car::Tankowanie(double litry)
{
	double wolne_miejsce = Pojemnosc_Baku - Paliwo;
	if (litry >= 0)
	{
		if (wolne_miejsce >= litry)
		{
			Paliwo += litry;
		}
		else
		{
			Paliwo = Pojemnosc_Baku;
		}
	}
	else
	{
		if (Paliwo >= fabs(litry))
		{
			Paliwo += litry;
		}
		else
		{
			Paliwo = 0;
		}
	}
}

void Car::setNr_Start(unsigned int numer)
{
	Nr_Start = numer;
}

double Car::getPrzebieg()
{ 
	return Przebieg;
}

double Car::getPaliwo()
{
	return Paliwo;
}

double Car::getPojemnosc_Baku()
{
	return Pojemnosc_Baku;
}

void Car::getStan(std::string &stan)
{
	stan = std::to_string(Nr_Start)+ "\t" + std::to_string(Spalanie) + "\t" + std::to_string(Przebieg) + "\t" + std::to_string(Pojemnosc_Baku) + "\t" + std::to_string(Paliwo);
}

