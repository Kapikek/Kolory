
#include <iostream>
#include <string> 
#include <Windows.h>


using namespace std;


#include "gracz.h"
#include "haslo.h"
#include "kolo.h"


class gra
{

private:
	
	
	haslo haslo;
	string Haslo = haslo.Haslo;
	string proba;
	kolo Kolo;
	gracz gracze[3];
	int suma = 0;

public:

	void gra_init();
	void print_board();
	char WczytajWybor();
	void zgaduj_haslo();

};

