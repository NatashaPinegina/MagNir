#include "Research.h"

int main() {
    Research rc;

    rc.KolSat=3;
    for(int i=1;i<10;i++)
    {
        cout<<"Кол-во спутников: "<< i<< "\t";
        rc.KolSour=i;
        rc.research(100000);
        cout<<endl;
    }

    return 0;
}
