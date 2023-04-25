

#include "gra.h"




void gra::gra_init() {

    gracze[0].imie = "Bryanusz";
    gracze[1].imie = "Jessica  ";
    gracze[2].imie = "Nepomucen";

    do {

        haslo.print_maska();

        int sa_spolgloski = 0;
        int kwota = 0;

        for (int i = 0; i < haslo.n; i++)
            if ((!haslo.jestSamogloska(Haslo[i])) && (haslo.maska[i]))
            {
                sa_spolgloski = 1;
                break;
            }

        if (sa_spolgloski)
            cout << " -- Spolgloski sa --" << endl;

        //cout << gracze[kolejka].imie << " " << endl;
        print_board();

        cout << "1. zgaduj haslo" << endl;
        cout << "2. krecenie kolem" << endl;

        // TODO tylko 1 i 2, nie mozna wprowadzac liter

        char wybor = WczytajWybor();

        if (wybor == '1') {
            zgaduj_haslo();
        }

        int i = Kolo.krecenie();

        kwota = Kolo.kwota;

        // Strata kolejki i bankrut
        if ((Kolo.wartosci[i] == 0) || (Kolo.wartosci[i] == -1))
        {
            if (Kolo.wartosci[i] == -1) // bankrut
                gracze[Kolo.kolejka].kasa = 0;

            Kolo.kolejka = (Kolo.kolejka + 1) % 3;
            suma = 1;
            cout << endl << "=================================================" << endl;

            // TODO
            // sleep for
            // kupowanie samoglosek


        }

        cout << gracze[Kolo.kolejka].imie << ": Podaj litere" << endl;

        char literka = haslo.WczytajZnak();
        int zgadl = 0;

        if (haslo.jestSamogloska(literka))
            cout << "samogloska";
        else
            cout << "spolgloska";
        cout << endl;

        for (i = 0; i < haslo.n; i++)
        {
            if ((Haslo[i] == literka) && (haslo.maska[i] == 1)) {
                haslo.maska[i] = 0;
                zgadl++;
            }
        }

        if (zgadl)
        {
            cout << "OK";
            gracze[Kolo.kolejka].kasa += kwota * zgadl;

            cout << endl << gracze[Kolo.kolejka].imie << "\033[1;32m " << gracze[Kolo.kolejka].kasa << "\033[0m";


        }
        else {
            cout << "Zle!";
            // strata kolejki
            Kolo.kolejka = (Kolo.kolejka + 1) % 3;
            cout << endl << "=================================================" << endl;
            suma = 1;

        }

        cout << endl;

        suma = 0;

        for (i = 0; i < haslo.n; i++)
        {
            suma += haslo.maska[i];
        }

    } while (suma);

    cout << "BRAWO!";
    exit(0);

    print_board();
    Beep(523, 500);



}

void gra::print_board(){
    int i;
    std::cout << "\n";
    for (i = 0; i < 3; i++) {
        if (i == Kolo.kolejka) {
            cout << "\033[1;34m";
        }
        cout << gracze[i].imie << "\t" << gracze[i].kasa << "\n";
        cout << "\033[0m";

    }
    cout << "\n";
}

char gra::WczytajWybor()
{
    char wybor;
    wybor = haslo.WczytajZnak();

    while (wybor != '1' && wybor != '2')
    {
        cout << endl << "Wybierz [1-2]: ";
        cin >> wybor;
    }

    return wybor;

}

void gra::zgaduj_haslo() {

    cout << "Podaj haslo" << endl;
    getline(cin >> ws, proba);  // wczytanie z klawiatury string z uwzgl. whitespa
    for (auto& c : proba)  // & zapamietuje modyfikacje w petli & - referencja
        c = toupper(c);
    if (Haslo == proba) {
        cout << endl << " !!!!!!!!!! =======   WYGRANA ========== !!!!!!!!!!!!!" << endl;
        gracze[Kolo.kolejka].portfel += gracze[Kolo.kolejka].kasa;
        exit(0);

    }
    else
    {
        Kolo.kolejka = (Kolo.kolejka + 1) % 3;
        suma = 1;
        cout << endl << " !!!!!!!!!! =======   ZLE ========== !!!!!!!!!!!!!" << endl;
        cout << endl << "=================================================" << endl;
        

    }
}

