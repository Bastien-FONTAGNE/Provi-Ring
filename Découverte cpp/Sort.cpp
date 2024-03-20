#include "Personnage.h"
#include <string>
#include <iostream>
#include "Arme.h"
#include "Sort.h"
using namespace std;

Sort::Sort() : m_nom("Boule de feu"), m_degats(20) 
{

}

Sort::Sort(string nom, int degats) : m_nom(nom), m_degats(degats)
{

}

void Sort::changer(string nom, int degats)
{
	m_nom = nom;
	m_degats = degats;

}

void Sort::afficher() const
{
	cout << "Sort : " << m_nom << "(Degats : " << m_degats << ")" << endl;
}

int Sort::getDegats() const
{
	return m_degats;
}





