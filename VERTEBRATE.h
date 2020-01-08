#ifndef VERTEBRATE_H_INCLUDED
#define VERTEBRATE_H_INCLUDED
#include "ANIMAL.h"
#include <cstring>
using namespace std;
class Vertebrate: protected Animal
{
private:
	int nrVertebre;
public:
	Vertebrate();
	Vertebrate(int);
	Vertebrate(int, int);
	Vertebrate(int, int, char[]);
	Vertebrate(int, int, char[], int);
	Vertebrate(const Vertebrate&);
	~Vertebrate();
	void setNrVertebre(int);
	int getNrVertebre();
	Vertebrate& operator=(const Vertebrate&);
	friend istream& operator >>(istream& in, Vertebrate& ob);
	virtual afisare(ostream & out)
	{
	    out << "Durata de viata: " << getDurataDeViata() << endl << "Dimensiune: " <<getDimensiune() << endl << "Regim alimentar: " <<getRegimAlimentar() << endl;
	out << "Nr de vertebre: " << nrVertebre << endl;
	return out;
	};
	friend ostream& operator<<(ostream& out, Vertebrate& ob);
};
Vertebrate::Vertebrate(): Animal()
{
	cout << "Constructor fara parametri Vertebrate." << endl;
	nrVertebre = 0;
}

Vertebrate::Vertebrate(int x): Animal(x)
{
	cout << "Constructor cu un parametru int Vertebrate." << endl;
	nrVertebre = 0;
}

Vertebrate::Vertebrate(int x, int y): Animal(x, y)
{
	cout << "Constructor cu doi parametri int Vertebrate." << endl;
	nrVertebre = 0;
}

Vertebrate::Vertebrate(int x, int y, char z[]): Animal(x, y, z)
{
	cout << "Constructor cu doi parametri int si un parametru char[] Vertebrate." << endl;
	nrVertebre = 0;
}

Vertebrate::Vertebrate(int x, int y, char z[], int t): Animal(x, y, z)
{
	cout << "Constructor cu doi parametri int, un parametru char[] si un parametru bool Vertebrate." << endl;
	nrVertebre = t;
}

Vertebrate::Vertebrate(const Vertebrate& ob): Animal(ob)
{
	cout << "Constructor de copiere Vertebrate." << endl;
	nrVertebre = ob.nrVertebre;
}

Vertebrate::~Vertebrate()
{
	cout << "Destructor Vertebrate" << endl;
}

void Vertebrate::setNrVertebre(int n)
{
	nrVertebre = n;
}

int Vertebrate::getNrVertebre()
{
	return nrVertebre;
}

Vertebrate& Vertebrate::operator=(const Vertebrate& ob)
{
	this->Animal::operator=(ob);
	nrVertebre = ob.nrVertebre;
	return *this;
}

istream& operator >>(istream& in, Vertebrate& ob)
{
	int x;
	char s[1000];
	cout << "Introduceti durata de viata a animalului: ";
	in >> x;
	ob.setDurataDeViata(x);
	cout << "Introduceti dimensiunea animalului in cm: ";
	in >> x;
	ob.setDimensiune(x);
	cout << "Introduceti regimul alimentar al animalului: ";
	in >> s;

	try
	{
		if (strlen(s) > 100)
			throw 0;
		else ob.setRegimAlimentar(s);
	}
	catch (int x)
	{
		cout << "Regimul alimentar trebuie sa fie un singur cuvant de maxim 100 de caractere!" << endl;
	}

	cout << "Introduceti nr de vertebre: ";
	cin >> x;
	ob.setNrVertebre(x);
	return in;
}

ostream& operator<<(ostream& out, Vertebrate& ob)
{
	ob.afisare(out);
	return out;
}

#endif
