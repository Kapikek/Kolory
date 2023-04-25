

#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;


class kolo
{
public:

	int kwota = 0;
	int kolejka = 0;
	int wartosci[16] = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };

	int krecenie();

};

