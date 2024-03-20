#ifndef DEF_SORT
#define DEF_SORT

#include <string>
#include <iostream>

class Sort {

public:

	Sort();
	Sort(std::string nom, int degats);
	void changer(std::string, int degats);
	void afficher() const;
	int getDegats() const;

private:

	int m_degats;
	std::string m_nom;
};

#endif // !1
