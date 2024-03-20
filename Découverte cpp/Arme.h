#ifndef DEF_ARME
#define DEF_ARME

#include <string>
#include <iostream>

class Arme
{
	public:

	Arme(); //constructeur
	Arme(std::string nom, int degats);
	void changer(std::string, int degats);
	void afficher() const;
	int getDegats() const;

private:
	std::string m_nom;
	int m_degats;
};
#endif
