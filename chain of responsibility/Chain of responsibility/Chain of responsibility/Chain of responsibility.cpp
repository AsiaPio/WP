#include "stdafx.h"

using namespace std;

class ListaProduktow
{
	ListaProduktow *next; // 1. "next" pointer in the base class
public:
	ListaProduktow()
	{
		next = 0;
	}
	void setNext(ListaProduktow *n)
	{
		next = n;
	}
	void add(ListaProduktow *n)
	{
		if (next)
			next->add(n);
		else
			next = n;
	}
	// 2. The "chain" method in the base class always delegates to the next obj
	virtual void handle(int i)
	{
		next->handle(i);
	}
};

class H_0_50 : public ListaProduktow
{
public:
	/*virtual*/void handle(int i)
	{
		if (i > 0 && i<50)
		{
			cout << "Zakres <0-50) ";
		}
		else
		{
			ListaProduktow::handle(i);
		}		
	}
};

class H_200_300 : public ListaProduktow
{
public:
	/*virtual*/void handle(int i)
	{
		if (i >= 200 && i<300)
		{
			cout << "Zakres <200-300) ";
		}
		else
		{
			ListaProduktow::handle(i);
		}
	}
};

class H_300_350 : public ListaProduktow
{
public:
	/*virtual*/void handle(int i)
	{
		if (i >= 300 && i<350)
		{
			cout << "Zakres <300-350) ";
		}
		else
		{
			ListaProduktow::handle(i);
		}
	}
};

class End : public ListaProduktow
{
public:
	/*virtual*/void handle(int i)
	{
		if (i!=0)
		{
			cout << "Nie jest w zakresie";
		}
		else
		{
			cout << "Koniec";
		}
		
	}
};

int main()
{
	H_0_50 one;
	H_200_300 two;
	H_300_350 three;
	End last;
	one.add(&two);
	one.add(&three);
	one.add(&last);
	//three.setNext(&one);
	int cena = 0;
	do
	{
		cout << "Podaj cene. 0 konczy prace";
		cout << '\n';
		cin >> cena;

		one.handle(cena);
		cout << '\n';
		cout << '\n';
	} while (cena != 0);
}