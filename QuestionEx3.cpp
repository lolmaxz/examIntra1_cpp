#include <iostream>
#include <iomanip>
#include <fstream>
#include <fstream>
#include <array>
#include <sstream>
#include <string> 
using namespace std;

struct Livre {
    int ISBN;
    char titreLivre[100];
    char auteurLivre[50];
    double prix;
} unLivre ;

bool nombreDoubleValide(string const & n) {
    long double ld;
    return((std::istringstream(n) >> ld >> std::ws).eof());

}

template<class T, size_t N>
void lireInfos(T (&livre)[N]) {

    string ISBN;
    string prix;
    string text;
    
    char titre[100];
    char auteur[50];
    
    bool invalideISBN = true;
    
    int taille = (sizeof(livre)/sizeof(*livre));

    for (int i=0; i < taille; i++) {
        cout << "\nLivre #" << (i+1) << " : " << endl;
        do {
            std::cout << "entrez le ISBN" << endl;
            std::getline(std::cin, ISBN);
       
        } while ((!isValideISBN( ISBN )));

        livre[i].ISBN = std::stoi( ISBN );

        std::cout << "Entrez le titre du livre : ";

        cin.clear();
        cin.sync();
            getline(cin, text, '\n');

        strcpy(titre, text.c_str());
        for (int a = 0; a < 100; a++) {
            livre[i].titreLivre[a] = titre[a];
        }

        std::cout << "Entrez le nom de l'auteur du livre : ";

        cin.clear();
        cin.sync();
            getline(cin, text, '\n');

        strcpy(auteur, text.c_str());
        for (int a = 0; a < 50; a++) {
            livre[i].auteurLivre[a] = auteur[a];
        }

        std::cout << "Entrez le prix du livre ($) : " << endl;
        do {
            cin.clear();
            cin.sync();
            std::getline(std::cin, prix);
            
       
        } while ((!nombreDoubleValide( prix )));

        livre[i].prix = std::stod( prix );
    }
}

bool isValideISBN(string& ISBN) {

    int n = ISBN.length();

    // Longueur dois être de 9 nombre maximum sinon on retourne false et
    // Si on trouve moindrement un charactère qui n'est PAS un nombre on annule et retourne false
    if (n != 9) return false;
    if (!nombreDoubleValide(ISBN)) return false;

    // si tout les conditions son respecté, on retourne true
    return true;
}

// Afficher les Livres
template<class T, size_t N>
void afficherLivres(T (&livre)[N]) {
    int taille = (sizeof(livre)/sizeof(*livre));
    cout << " ****************** \n" << endl;

    for (int i = 0; i < taille; i++) {
        cout << "Information sur le livre #" << (i+1) << " : \n" << endl;
        cout << "ISBN du livre : " << (livre[i]).ISBN << endl;
        string strTitre = (livre[i]).titreLivre;
        cout << "Titre du livre : " << strTitre << endl;
        string strAuteur = (livre[i]).auteurLivre;
        cout << "Auteur du livre : " << strAuteur << endl;
        cout << fixed << setprecision(2) << "Prix du livre : " << (livre[i]).prix << "$\n" << endl;
    }
    cout << "\n****************** \n" << endl;
}

template<class T, size_t N>
void afficherPrix(T (&livre)[N]) {
    int taille = (sizeof(livre)/sizeof(*livre));
    cout << " *****  Section des Prix  ***** \n" << endl;
    double plusGrandTrouverPrix = livre[0].prix;
    double plusPetitTrouverPrix = livre[0].prix;
    int plusGrandTrouver = 0;
    int plusPetitTrouver = 0;

    for (int i = 0; i < taille; i++) {
        if (livre[i].prix > plusGrandTrouver) {
            plusGrandTrouverPrix = livre[i].prix;
            plusGrandTrouver = i;
        }
        if (livre[i].prix < plusPetitTrouver) {
            plusPetitTrouverPrix = livre[i].prix;
            plusPetitTrouver = i;
        }
    }

    cout << fixed << setprecision(2) << "Le livre le MOINS chere est le livre #" << (plusPetitTrouver+1) << " '" << livre[plusPetitTrouver].titreLivre << "' par " << livre[plusPetitTrouver].auteurLivre << ", coutant " << livre[plusPetitTrouver].prix << "$" << endl;
    cout << fixed << setprecision(2) << "Le livre le PLUS chere est le livre #" << (plusGrandTrouver+1) << " '" << livre[plusGrandTrouver].titreLivre << "' par " << livre[plusGrandTrouver].auteurLivre << ", coutant " << livre[plusGrandTrouver].prix << "$" << endl;
    cout << "\n****************** \n" << endl;
}

template<class T, size_t Taille>
void tailleTableau(T(&arr)[Taille]) {
    cout << " *****  Nombre de Livre et Prix Moyen  ****** \n" << endl;

    int tailleTableau = (sizeof(arr)/sizeof(*arr));
    double moyenne = 0;

    for (int i=0; i<tailleTableau; i++) {
        moyenne += arr[i].prix;
    }

    moyenne /= tailleTableau;

    cout << "Le nombre de livre est de : " << tailleTableau << endl;
    cout << fixed << setprecision(2) << "Le prix moyen des livres est de : " << moyenne << "$" << endl;
    cout << "\n****************** \n" << endl;
}