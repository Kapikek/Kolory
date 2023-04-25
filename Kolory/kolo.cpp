

#include "kolo.h"


int kolo::krecenie() {

    string rezultat = "";
    int i = rand() % 15;
    if (wartosci[i] == 0)
        rezultat = "Strata kolejki";
    if (wartosci[i] == -1)
        rezultat = "Bankrut";
    if (rezultat != "")
        cout << "\033[1;31m" << rezultat << "\033[0m" << endl;
    else
    {
        cout << "\033[1;34m" << wartosci[i] << "\033[0m" << endl;
        kwota = wartosci[i];
    }

    return i;



}


