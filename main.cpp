#include <iostream>
#include "Calculator.hpp"
#include "Car.h"
#include <ctime>



int main() 
{
    srand(time(NULL));

    //Calculator
    std::cout << "Obiekt klasy Calculator\n\n";
    Calculator c0;
    double x1 = 0.0, x2 = 0.0;
    c0.square_function_roots(1.0, 5.0, 6.0, x1, x2);
    std::cout << "Miejsca zerowe:\t" << x1 << "\t"<<x2;

    //Car
    std::cout << "\n\n-----------------------------------------------------------------------------\n";
    std::cout << "\nObiekt klasy Car\n\n";
    Car flota[5];
    for (int i = 0; i < 5; i++)
    {
        flota[i].setNr_Start(i+1);
        flota[i].Tankowanie(flota[i].getPojemnosc_Baku() * 0.8);
    }

    int s = 5;
    int zwyciezca = 0;
    while (s > 0)
    {
        s = 0;
        for (int j = 0; j < 5; j++)
        {
            flota[j].Jazda(100);

            if (flota[j].getPaliwo() > 0.0)
            {
                zwyciezca=j;
                s++;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            std::cout << "Nr\tSpalanie\tPrzebieg\tPojemnosc\tPaliwo\n";
        }
        std::string stan;
        flota[i].getStan(stan);
        std::cout << stan << "\n";
    }

    std::string stan;
    flota[zwyciezca].getStan(stan);
    std::cout << "\nZwyciezca:\n";
    std::cout << "Nr\tSpalanie\tPrzebieg\tPojemnosc\tPaliwo\n";
    std::cout << stan << "\n\n";
}
