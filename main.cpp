#include <iostream>
#include <iomanip>
#include <fstream>
#include <fstream>
#include <array>
#include <sstream>
#include <string> 

// Question #1.2 VOIR FICHIER ↓
#include "QuestionEx1-2.cpp"

// Question #3 VOIR FICHIER ↓
#include "QuestionEx3.cpp"

// Question #4 VOIR FICHIER ↓
#include "QuestionEx4.cpp"

using namespace std;

int main() {

    // Question # 1.2
    int unInt = 20;
    float unDble = 4.8;
    Test(unInt, unDble);
    cout << "unInt = " << unInt << " et unDble = " << unDble << endl;

    // Question #2 - tests
    test2(true, true,false,false);
    cout << " " << endl;

    // Question #3 //- --------------
    Livre livre[3];
    cout << "Entrez les informations pour chaque livre:" << endl;
    
    lireInfos(livre);
    
    afficherLivres(livre);
    afficherPrix(livre);
    tailleTableau(livre);
    
    Etudiant etu1,etu2,etu3,etu4,etu5,etu6,etu7,etu8;
    Etudiant listeEtu[] = {etu1,etu2,etu3,etu4,etu5,etu6,etu7,etu8};

    for (int i=0; i<8; i++) {
        listeEtu[i].nbrCreditReussis = ( rand() % 100 + 1 );
        listeEtu[i].age = ( rand() % 60 + 18 );
        char nom[4] = {'M','a','x',std::to_string(i+1)[0]};
        strncpy(listeEtu[i].nom, nom, 50);
    }

    afficherEtudiant(listeEtu);
    afficherMeilleurEtudiant(listeEtu);
}




