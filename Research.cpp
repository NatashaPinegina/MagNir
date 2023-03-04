//
// Created by natasha on 04.03.23.
//
#include "Research.h"
#include "math.h"
#include <vector>

double Research::FindDistance(Koord koordSat, Koord koordSource)
{
    return sqrt((koordSat.x-koordSource.x)*(koordSat.x-koordSource.x)+
                        (koordSat.y-koordSource.y)*(koordSat.y-koordSource.y)+
                        (koordSat.z-koordSource.z)*(koordSat.z-koordSource.z));
}

double Research::FindDeltaTime(double Ram, double Rbm) {
    return (Ram-Rbm)/c;
}

double Research::DoubleRand(double _max, double _min)
{
    return _min + double(rand()) / RAND_MAX * (_max - _min);
}


void Research::research(int kol){

    srand(time(0));
    int Popal=0;
    for(int k = 0; k < kol;k++) {
        cout<<endl;
        cout << k+1 << "-ая попытка" <<endl;
        vector<Koord> koordSat;
        koordSat.resize(KolSat);
        for (int i = 0; i < KolSat; i++) {
            koordSat[i].x = DoubleRand(0, 36000);
            koordSat[i].y = DoubleRand(0, 36000);
            koordSat[i].z = DoubleRand(0, 36000);
        }

        vector<Koord> koordSource;
        koordSource.resize(KolSour);
        for (int i = 0; i < KolSour; i++) {
            koordSource[i].x = DoubleRand(0, 36000);
            koordSource[i].y = DoubleRand(0, 36000);
            koordSource[i].z = DoubleRand(0, 36000);
        }

        int kolPrav = 0;
        for (int i = 0; i < KolSour; i++)
        {
            vector<double> Distance(KolSat, 0);

            for (int j = 0; j < KolSat; j++)
                Distance[j] = FindDistance(koordSat[j], koordSource[i]);

            vector<double> deltaT(KolSat, 0);
            for (int j = 0; j < KolSat; j++) {
                if (j == KolSat-1)
                    deltaT[j] = FindDeltaTime(Distance[0], Distance[j]);
                else
                    deltaT[j] = FindDeltaTime(Distance[j+1], Distance[j]);
            }
            double t = 0;
            for (int j = 0; j < KolSat; j++)
                t += deltaT[j];

            cout << "\t" << i+1 << "-ый источник\t Результат: " << t << endl;

            if ((int)t == 0) kolPrav++;
        }
        if(kolPrav == KolSour) Popal++;
    }
    cout << "Вероятность данной группировки (кол-во спутников = " << KolSat << "; кол-во источников = "<< KolSour <<"): "<< Popal/kol << endl;
}
