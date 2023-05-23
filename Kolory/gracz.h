
#include <iostream>
using namespace std;


class gracz
{
	

public:
	
	string imie;
	int kasa = 0;
	int portfel = 0;

	friend istream& operator >> (istream& is, gracz& gracz) {
		cout << "Podaj imie:" << endl;
		is >> gracz.imie;
		cout << endl;
		return is;
	}

	friend ostream& operator << (ostream& os, gracz* gracz) {
		os << gracz->imie << "\t" << gracz->kasa << endl;
		return os;
	}


};

