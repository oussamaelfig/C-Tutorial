/*  Exercice complémentaire avec nuage de points.
 *  Lab3 -- Tableau dynamique générique
 *  INF3105 | Structures de données et algorithmes
 *  UQAM | Département d'informatique
 *  http://ericbeaudry.uqam.ca/INF3105/lab3/
 */
#include <string>
#include <iostream>
#include <fstream>
#include "nuage.h"

// Avant de compléter ce fichier, assurez-vous que tous les tests dans test_tableau.cpp réussissent.

int main(int argc, const char** args){
    if(argc<2){
        std::cout << "Syntaxe:\n  ./lab3 fichiernuage.txt" << std::endl;
        return 1;
    }
    
    Nuage nuage;
    std::ifstream in(args[1]);
    in >> nuage;
    
    while(std::cin){
        std::string cmd;
        Point point;
        std::cin >> cmd;
        if(!std::cin)
            break; // détection de la fin de l'entrée (Ctrl+D sur le clavier ou fin de fichier).
        
        if(cmd == "proche"){
            std::cin >> point;
            Point resultat = nuage.proche(point);
            std::cout << resultat << std::endl; 
        }else if(cmd == "proches"){
            std::cin >> point;
            double rayon;
            std::cin >> rayon;
            Nuage resultat = nuage.proches(point, rayon);
            std::cout << resultat << std::endl; 
        }else if(cmd == "nproches"){
            std::cin >> point;
            int n;
            std::cin >> n;
            Nuage resultat = nuage.nproches(point, n);
            std::cout << resultat << std::endl; 
        }else{
            std::cout << "Commande '" << cmd << "' non reconnue!" << std::endl;
            break;
        }
    }
    return 0;
}
