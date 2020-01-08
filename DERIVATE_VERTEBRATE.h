#ifndef DERIVATE_VERTEBRATE_H_INCLUDED
#define DERIVATE_VERTEBRATE_H_INCLUDED
#include <cstring>
#include "VERTEBRATE.h"
#include "ANIMAL.h"


class Pesti: protected Vertebrate
{
private:
	char* tipulApei;
public:
    Pesti();
Pesti(int);
Pesti(int,int);
Pesti(int,int, char[]);
Pesti(int,int,char[],int);
Pesti(int,int,char[],int,char[]);
Pesti(const Pesti&);
~Pesti();
Pesti& operator=(const Pesti&);

};


class Mamifere: protected Vertebrate
{
private:
	int perioadaGestatie;
public:
    Mamifere();
Mamifere(int);
Mamifere(int,int);
Mamifere(int,int,int);
Mamifere(int,int,int,int);
Mamifere(int,int,int,int,int);
Mamifere(const Mamifere&);
~Mamifere();
Mamifere& operator=(const Mamifere&);





};

class Reptile: protected Vertebrate
{
private:
	char* formaCorpului;
public:
    Reptile();
Reptile(int);
Reptile(int,int);
Reptile(int,int, char[]);
Reptile(int,int,char[],int);
Reptile(int,int,char[],int,char[]);
Reptile(const Reptile&);
~Reptile();
Reptile& operator=(const Reptile&);

};

class Pasari: protected Vertebrate
{
private:
	char* culoare;
public
    Pasari();
Pasari(int);
Pasari(int,int);
Pasari(int,int, char[]);
Pasari(int,int,char[],int);
Pasari(int,int,char[],int,char[]);
Pasari(const Pasari&);
~Pasari();
Pasari& operator=(const Pasari&);
};

#endif
