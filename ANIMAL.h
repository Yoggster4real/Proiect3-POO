#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED
#include <cstring>
using namespace std;

class Animal
{
private:
	int durataDeViata;
	int dimensiune;
	char* regimAlimentar;
public:
	Animal();
	Animal(int);
	Animal(int, int);
	Animal(int, int, char[]);
	Animal(const Animal&);
	~Animal();
	void setDurataDeViata(int);
	void setDimensiune(int);
	void setRegimAlimentar(char[]);
	int getDurataDeViata();
	int getDimensiune();
	char* getRegimAlimentar();
	Animal& operator=(const Animal&);
	friend istream& operator >>(istream& in, Animal& ob);
	friend ostream& operator<<(ostream& out, Animal& ob);

};

Animal::Animal()
{
	cout << "Constructor fara parametri Animal." << endl;
	durataDeViata = 0;
	dimensiune = 0;
	regimAlimentar = NULL;
}

Animal::Animal(int x)
{
	cout << "Constructor cu un parametru int Animal." << endl;
	durataDeViata = x;
	dimensiune = 0;
	regimAlimentar = NULL;
}

Animal::Animal(int x, int y)
{
	cout << "Constructor cu doi parametri int Animal." << endl;
	durataDeViata = x;
	dimensiune = y;
	regimAlimentar = NULL;
}

Animal::Animal(int x, int y, char z[])
{
	cout << "Constructor cu doi parametri int si un parametru char[] Animal." << endl;
	durataDeViata = x;
	dimensiune = y;
	delete[] regimAlimentar;
	regimAlimentar = new char[strlen(z)];
	strcpy(regimAlimentar, z);
}

Animal::Animal(const Animal& ob)
{
	cout << "Constructor de copiere Animal." << endl;
	durataDeViata = ob.durataDeViata;
	dimensiune = ob.dimensiune;
	delete[]regimAlimentar;

	if (ob.regimAlimentar != NULL)
	{
		regimAlimentar = new char[strlen(ob.regimAlimentar)];
		strcpy(regimAlimentar, ob.regimAlimentar);
	}
	else regimAlimentar = NULL;
}

Animal::~Animal()
{
	cout << "Destructor Animal." << endl;
	delete[] regimAlimentar;
}

void Animal::setDurataDeViata(int x)
{
	durataDeViata = x;
}

void Animal::setDimensiune(int x)
{
	dimensiune = x;
}

void Animal::setRegimAlimentar(char c[])
{
	delete[]regimAlimentar;
	regimAlimentar = new char[strlen(c)];
	strcpy(regimAlimentar, c);
}

int Animal::getDurataDeViata()
{
	return durataDeViata;
}

int Animal::getDimensiune()
{
	return dimensiune;
}

char* Animal::getRegimAlimentar()
{
	return regimAlimentar;
}

Animal& Animal::operator=(const Animal& ob)
{
	durataDeViata = ob.durataDeViata;
	dimensiune = ob.dimensiune;
	delete[]regimAlimentar;

	if (ob.regimAlimentar != NULL)
	{
		regimAlimentar = new char[strlen(ob.regimAlimentar)];
		strcpy(regimAlimentar, ob.regimAlimentar);
	}
	else regimAlimentar = NULL;

	return *this;
}

istream& operator >>(istream& in, Animal& ob)
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

	return in;
}

ostream& operator<<(ostream& out, Animal& ob)
{
	out << "Durata de viata: " << ob.durataDeViata << endl << "Dimensiune: " << ob.dimensiune << endl << "Regim alimentar: " << ob.regimAlimentar << endl;
	return out;
}


#endif
