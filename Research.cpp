//
// Created by natasha on 04.03.23.
//
#include "Research.h"
#include "math.h"

vector<string> str;

double Research::FindDistance(Koord koordSat, Koord koordSource)
{
    return sqrt((koordSat.x-koordSource.x)*(koordSat.x-koordSource.x)+
                        (koordSat.y-koordSource.y)*(koordSat.y-koordSource.y)+
                        (koordSat.z-koordSource.z)*(koordSat.z-koordSource.z));
}

double Research::FindDeltaTime(double Ram, double Rbm) {
    return (Ram-Rbm);
}

double Research::DoubleRand(double _max, double _min)
{
    return _min + double(rand()) / RAND_MAX * (_max - _min);
}

vector<double> Research::criteria(vector<vector<double>>& delays)
{
    double summ = 0;
    int s = 0;
    double buf = 0;
    vector<double> SummDelays;
    for (int i = 0; i < delays[0].size(); i++)// по элементам первой строке
    {
        summ = delays[0][i];
        s = 1;
        for (int k = 0; k < delays[0].size(); k++)//по строкам
        {
            summ += delays[s][k];
            int iter = 0;
            buf = summ;
            for (int m = 0; m < delays[0].size(); m++)// по столбцам
            {
                summ += delays[s + 1][m];
                if (abs(summ) < 1e-8)
                {
                    SummDelays.push_back(summ);
                    string stroka = to_string(i) + to_string(k) + to_string(m);
                    str.push_back(stroka);
                }
                summ = buf;
            }
            summ = delays[0][i];
        }

    }
    return SummDelays;
}


void Research::research(double kol){

    srand(time(0));
    int Popal=0;
    vector<vector<double>> Korr;
    for(int k = 0; k < kol;k++) {
        Korr.clear();
        //cout<<endl;
        //cout << k+1 << "-ая попытка" <<endl;
        vector<Koord> koordSat;
        koordSat.resize(KolSat);
        for (int i = 0; i < KolSat; i++) {
            koordSat[i].x = DoubleRand(36000, 25000);
            koordSat[i].y = DoubleRand(36000, 25000);
            koordSat[i].z = DoubleRand(36000, 25000);
        }

        vector<Koord> koordSource;
        koordSource.resize(KolSour);
        for (int i = 0; i < KolSour; i++) {
            koordSource[i].x = DoubleRand(7000, 0);
            koordSource[i].y = DoubleRand(7000, 0);
            koordSource[i].z = DoubleRand(7000, 0);
        }

        int kolPrav = 0;

        Korr.resize(KolSat);
        for(int i=0;i<KolSat;i++)
            Korr[i].resize(KolSour);

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

                Korr[j][i]=deltaT[j];
                //cout<< deltaT[j] <<"\t";
            }
            //cout<<endl;
        }
        /*for(int i=0;i<KolSat;i++) {
            for (int j = 0; j < KolSour; j++)
                cout << Korr[i][j] << "\t";
            cout<<endl;
        }*/

        str.clear();
        vector<double> Summ;
        Summ.clear();
        Summ = criteria(Korr);


        /*int iter=0;
        for(int i=0;i<str.size();i++) {
            for (int j = 0; j < str[i].size(); j++)
                cout << str[i][j] << "\t";
            cout<<Summ[iter]<<endl;
            iter++;
        }*/

        int ver=0;
        for(int i=0;i<KolSat;i++)
        {
            int PolKol=0;
            for(int j=0;j<KolSour;j++)
            {
                int kol=0;
                for(int k=j+1;k<KolSour;k++)
                {
                    if((str[j][i]-'0')!=(str[k][i])-'0') kol++;
                }
                if(kol == KolSour-1-j)
                    PolKol++;
            }
            if(PolKol == KolSour) ver++;
        }
        if(ver == KolSat) Popal++;
    }
    cout<<"Вероятность: "<< Popal/kol;
}
