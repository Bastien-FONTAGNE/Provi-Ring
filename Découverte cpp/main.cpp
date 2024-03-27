#include "Personnage.h"
#include <string>
#include <iostream>
#include "Arme.h"
#include "Sort.h"
using namespace std;

void afficherMenu() {
    std::cout << "Actions disponibles :" << std::endl;
    std::cout << "1. Attaquer" << std::endl;
    std::cout << "2. Lancer un sort" << std::endl;
    std::cout << "3. Boire une potion de vie (+20PV)" << std::endl;
    std::cout << "4. Boire une potion de mana (+50Mana)" << std::endl;
    std::cout << "5. Quitter le jeu" << std::endl;
    
}

int main()
{
    Personnage joueur1, joueur2; //création du joueur 1 et 2

    std::string nomJoueur1, nomJoueur2;

    std::cout << "Bienvenue sur " << std::endl << std::endl;
    std::cout << " ____                 _       ____  _             " << std::endl;
    std::cout << "|  _ \\ _ __ _____   _(_)     |  _ \\(_)_ __   __ _ " << std::endl;
    std::cout << "| |_) | '__/ _ \\ \\ / / |_____| |_) | | '_ \\ / _` |" << std::endl;
    std::cout << "|  __/| | | (_) \\ V /| |_____|  _ <| | | | | (_| |" << std::endl;
    std::cout << "|_|   |_|  \\___/ \\_/ |_|     |_| \\_\\_|_| |_|\\__, |" << std::endl;
    std::cout << "                                            |___/ " << std::endl;

    //Le joueur 1 choisit son nom
    std::cout << "Nom du joueur 1 : ";
    std::cin >> nomJoueur1;
    joueur1.setNom(nomJoueur1);

    //Le joueur 2 choisit son nom
    std::cout << "Nom du joueur 2 : ";
    std::cin >> nomJoueur2;
    joueur2.setNom(nomJoueur2);

    //Initialisation du combat
    bool finCombat = false;
    while (!finCombat) {

        //Tour du joueur 1
        joueur1.afficherEtat();
        joueur2.afficherEtat();
        cout << "Au tour de " << joueur1.getNom() << endl << endl;
        afficherMenu();
        int choix = 0;
        cin >> choix;

        if (choix == 1) {
            joueur1.attaquer(joueur2);
            
        }
        if (choix == 2) {
            joueur1.sort(joueur2, 20);
            
        }
        if (choix == 3) {
            joueur1.boirePotionDeVie(20);
        }
        if (choix == 4) {
            joueur1.boirePotionMana(50);
        }
        if (choix == 5) {
            cout << joueur1.getNom() << " a declare forfait, victoire de " << joueur2.getNom() << endl << endl;
            break;
        }
        if (choix < 1 || choix > 5) {
            cout << "action invalide" << endl << endl;
            
        }

        if (!joueur2.estVivant()) {
            cout << joueur2.getNom() << " a etait vaincu!" << endl << endl;
            finCombat = true;
            break;
        }

        //Tour du joueur 2
        joueur2.afficherEtat();
        joueur1.afficherEtat();
        cout << "Au tour de " << joueur2.getNom() << endl << endl;
        afficherMenu();
        cin >> choix;

        if (choix == 1) {
            joueur2.attaquer(joueur1);
            
        }
        if (choix == 2) {
            joueur2.sort(joueur1, 20);
            
        }
        if (choix == 3) {
            joueur2.boirePotionDeVie(20);
        }
        if (choix == 4) {
            joueur2.boirePotionMana(50);
        }
        if (choix == 5) {
            cout << joueur2.getNom() << " a declare forfait, victoire de " << joueur1.getNom() << endl << endl;
            break;
        }
        if (choix < 1 || choix > 5) {
            cout << "action invalide" << endl << endl;
            
        }

        if (!joueur1.estVivant()) {
            cout << joueur1.getNom() << " a etait vaincu!" << endl << endl;
            finCombat = true;
            break;
        }
    }


    return 0;
}