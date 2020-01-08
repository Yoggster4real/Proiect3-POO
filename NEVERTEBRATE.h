#ifndef NEVERTEBRATE_H_INCLUDED
#define NEVERTEBRATE_H_INCLUDED
#include <cstring>
#include "ANIMAL.h"
using namespace std;

class Nevertebrate : protected Animal
{
private:
	bool exoschelet;
public:
	Nevertebrate();
	Nevertebrate(int);
	Nevertebrate(int, int);
	Nevertebrate(int, int, char[]);
	Nevertebrate(int, int, char[], bool);
	Nevertebrate(const Nevertebrate&);
	~Nevertebrate();
	void setExoschelet(bool);
	bool getExoschelet();
	Nevertebrate& operator=(const Nevertebrate&);
	friend istream& operator >>(istream& in, Nevertebrate& ob);
	friend ostream& operator<<(ostream& out, Nevertebrate& ob);
};
Nevertebrate::Nevertebrate(): Animal()
{
	cout << "Constructor fara parametri Nevertebrate." << endl;
	exoschelet = -1;
}

Nevertebrate::Nevertebrate(int x): Animal(x)
{
	cout << "Constructor cu un parametru int Nevertebrate." << endl;
	exoschelet = -1;
}

Nevertebrate::Nevertebrate(int x, int y): Animal(x, y)
{
	cout << "Constructor cu doi parametri int Nevertebrate." << endl;
	exoschelet = -1;
}

Nevertebrate::Nevertebrate(int x, int y, char z[]): Animal(x, y, z)
{
	cout << "Constructor cu doi parametri int si un parametru char[] Nevertebrate." << endl;
	exoschelet = -1;
}

Nevertebrate::Nevertebrate(int x, int y, char z[], bool t): Animal(x, y, z)
{
	cout << "Constructor cu doi parametri int, un parametru char[] si un parametru bool Nevertebrate." << endl;
	exoschelet = t;
}

Nevertebrate::Nevertebrate(const Nevertebrate& ob): Animal(ob)
{
	cout << "Constructor de copiere Nevertebrate." << endl;
	exoschelet = ob.exoschelet;
}

Nevertebrate::~Nevertebrate()
{
	cout << "Destructor Nevertebrate" << endl;
}

void Nevertebrate::setExoschelet(bool t)
{
	exoschelet = t;
}

bool Nevertebrate::getExoschelet()
{
	return exoschelet;
}

Nevertebrate& Nevertebrate::operator=(const Nevertebrate& ob)
{
	this->Animal::operator=(ob);
	exoschelet = ob.exoschelet;
	return *this;
}

istream& operator >>(istream& in, Nevertebrate& ob)
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

	cout << "Nevertebrata are exoschelet? (Da=1 / Nu=0): ";
	cin >> x;

	try
	{
		if (x > 1 || x < 0)
			throw 0;
		else ob.setExoschelet(x);
	}
	catch (int x)
	{
		cout << "Introduceti 1 pentru Da sau 0 pentru Nu!" << endl;
	}

	return in;
}

ostream& operator<<(ostream& out, Nevertebrate& ob)
{
	out << "Durata de viata: " << ob.getDurataDeViata() << endl << "Dimensiune: " << ob.getDimensiune() << endl << "Regim alimentar: " << ob.getRegimAlimentar() << endl;
	out << "Exoschelet: " << ob.exoschelet << endl;
	return out;
}

#endif
