#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "Arme.h"
#include "Sort.h"

class Personnage
{
public:

    Personnage(); //constructeur
    void setNom(const std::string& n);
    std::string getNom() const;
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void sort(Personnage& cible, int coutMana);
    void boirePotionDeVie(int quantitePotion);
    void boirePotionMana(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    void changerSort(std::string nomNouveauSort, int degatsNouveauSort);
    bool estVivant();
    Personnage(std::string nomArme, int degatsArme, std::string nomSort, int degatsSort);
    void afficherEtat() const;

    ~Personnage();

private:

    int m_vie;
    int m_mana;
    std::string nom;
    int m_nombrePotionVie;
    int m_nombrePotionMana;
    

    Arme m_arme;
    Sort m_sort;
};
#endif
