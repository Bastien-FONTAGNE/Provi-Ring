#include "Personnage.h"
#include <string>
#include <iostream>
#include "Arme.h"
#include "Sort.h"
using namespace std;


Personnage::Personnage() : m_vie(100), m_mana(100), m_arme("Epee rouille", 10), m_sort("Boule de feu", 20), m_nombrePotionMana(1), m_nombrePotionVie(2)
{
    
}

void Personnage::setNom(const std::string& n) 
{
    nom = n;
}

string Personnage::getNom() const
{
    return nom;
}

Personnage::Personnage(string nomArme, int degatsArme, string nomSort, int degatsSort) : m_vie(100), m_mana(100), m_arme(nomArme, degatsArme), m_sort(nomSort, degatsSort)
{
    
}

void Personnage::afficherEtat() const
{

    cout << nom << " : " << endl;
    cout << "Vie: " << m_vie << endl;
    cout << "Mana: " << m_mana << endl;
    m_arme.afficher();
    m_sort.afficher();
    cout << endl;
}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;

    if (m_vie < 0) {
        m_vie = 0;
    }
    
    if (!estVivant())
    {
        cout << nom << " est mort!" << endl;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    int degatsInfliges = m_arme.getDegats();
    cible.recevoirDegats(m_arme.getDegats());
    cout << cible.nom << " a subi " << degatsInfliges << " de degats" << endl;
    
}

void Personnage::sort(Personnage& cible, int coutMana)
{
    int degatsInfliges = m_sort.getDegats();
    if (m_mana >= coutMana) {
        m_mana -= coutMana;
        cible.recevoirDegats(m_sort.getDegats());
        cout << cible.nom << " a subi " << degatsInfliges << " de degats de sorts" << endl;
    }
    else {
        cout << nom << " n'a plus assez de mana pour lancer de sort!" << endl;
    }
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    if (m_nombrePotionVie > 0) {
        m_vie += quantitePotion;

        if (m_vie > 100)
        {
            m_vie = 100;
        }

        cout << nom << " Utilise une potion de vie" << endl << endl;
        m_nombrePotionVie--;
    }

    else {
        cout << nom << "n'a plus de potion de vie!" << endl << endl;
    }


    
    
}

void Personnage::boirePotionMana(int quantitePotion)
{
    if (m_nombrePotionMana > 0) {
        m_mana += quantitePotion;

        if (m_mana > 100) 
        {
            m_mana = 100;
        }

        cout << nom << "Utilise une potion de mana" << endl << endl;
    }

    else
    {
        cout << nom << "n'a plus de potion de mana!" << endl << endl;
    }
}

bool Personnage::estVivant()
{
    return m_vie > 0;
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

void Personnage::changerSort(std::string nomNouveauSort, int degatsNouveauSort)
{
    m_sort.changer(nomNouveauSort, degatsNouveauSort);
}

Personnage::~Personnage()
{

}

