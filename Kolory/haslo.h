#include <fstream>
#include <cassert>
#include <locale>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>



using namespace std;



class haslo
{
public:
	int n;
	int maska[100];
	string Haslo;
	int sa_spolgloski = 0;
	int jestSamogloska(char c);
	char WczytajZnak();
	void print_haslo();


};

