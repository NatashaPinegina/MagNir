#include "Research.h"

int main() {
    Research rc;
    cout << "Введите максимальное кол-во спутников (>3)."<<endl;
    int maxSat;
    cin >> maxSat;
    if(maxSat < 3) {
        cout << "Неверное кол-во спутников!"<<endl;
        return -1;
    }

    cout << "Введите максимальное кол-во источников (>0)."<<endl;
    int maxSour;
    cin >> maxSour;
    if(maxSour < 0) {
        cout << "Неверное кол-во источников!"<<endl;
        return -1;
    }

    for (int sour = 1; sour <= maxSour; sour++)
    {
        rc.KolSour=sour;
        for(int sat = 3; sat <= maxSat; sat++) {
            rc.KolSat=sat;
            rc.research(10);
            cout<<endl;
        }
    }
    return 0;
}
