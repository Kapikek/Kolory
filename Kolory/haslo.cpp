
#include "haslo.h"


int haslo::jestSamogloska(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return 1;
    else
        return 0;

}

char haslo::WczytajZnak()
{
    string letter;
    cin >> letter;

    while (letter.length() != 1)
    {
        cout << endl << "Type a single letter and press <enter>: ";
        cin >> letter;
    }

    for (auto& c : letter)  // & zapamietuje modyfikacje w petli & - referencja
        c = toupper(c);

    return letter[0];

}

haslo::haslo() {
    
    
    vector<string> hasla;
    int j = 0;

    ifstream strum;
    strum.open("dane.txt");

    setlocale(LC_CTYPE, "Polish");

    while (!strum.eof())
    {
        string s;
        //strum >> s;
        getline(strum, s);
        //cout << s << endl;
        hasla.push_back(s);

    }

    strum.close();
    
    assert(hasla.size() > 0);
    j = rand() % hasla.size(); // losujemy j-te haslo z przedzialu 0 ... size - 1
    //cout << hasla[j];

    Haslo = hasla[j];
    n = Haslo.size();

    for (int i = 0; i < n; i++)
    {
        if (Haslo[i] == ' ')
            maska[i] = 0;
        else
            maska[i] = 1;
    }
    
}

void haslo::print_haslo() {

    cout << "\033[2J";

    cout << "\033[47m" << "\033[31m";
    for (int i = 0; i < n; i++)
    {

        if (maska[i] == 1)
            cout << ".";
        else
            cout << Haslo[i];
    }

    cout << "\033[0m";
    cout << endl;



}

void haslo::print_maska() {

    cout << "\033[2J";

    cout << "\033[47m" << "\033[31m";
    for (int i = 0; i < n; i++)
    {

        if (maska[i] == 1)
            cout << ".";
        else
            cout << Haslo[i];
    }

    cout << "\033[0m";
    cout << endl;



}

