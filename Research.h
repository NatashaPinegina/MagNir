//
// Created by natasha on 04.03.23.
//

#ifndef MAGNIR_RESEARCH_H
#define MAGNIR_RESEARCH_H
#define c 299792.458 /**скорость света в км/с.*/
#include <iostream>
using namespace std;

struct Koord /**структура для координат источников и спутников*/
{
    double x;
    double y;
    double z;
};

class Research
{
public:
    /**Function*/
    double FindDistance(Koord koordSat, Koord koordSource);/**определение расстояния между источником и спутником.*/
    double FindDeltaTime(double Ram, double Rbm);/**определение временной задержки между парой спутников.*/
    void research(int kol);/**запуск исследования*/
    double DoubleRand(double _max, double _min);

    /**Variables*/
    int KolSour;/**Кол-во источников.*/
    int KolSat;/**Кол-во спутников.*/
};

#endif //MAGNIR_RESEARCH_H
