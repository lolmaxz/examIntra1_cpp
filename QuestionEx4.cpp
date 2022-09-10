#include <iostream>
#include <iomanip>
#include <fstream>
#include <fstream>
#include <array>
#include <sstream>
#include <string> 

using namespace std;

class Etudiant {       // The class
  public:             // Access specifier
  Etudiant() {
    this->age = 18;
    this->nbrCreditReussis = 0;
  }
  Etudiant(int age) {
    this->age = age;
    this->nbrCreditReussis = 0;
  }
    int age, nbrCreditReussis;        // Attribute (int variable)
    char nom[50];  // Attribute (string variable)

};

int numberOfCharsInArray(char* array){
 int numberOfChars = 0;
   while (*array++){
       numberOfChars++;
   }
   return numberOfChars;
}

void afficherEtudiant(Etudiant (&listeEtudiant)[8]) {
    for (int i = 0; i < 8; i++) {
        string strNom;
        int size = numberOfCharsInArray(listeEtudiant[i].nom);
        for (int a = 0; a < size-1; a++) {
            strNom += listeEtudiant[i].nom[a];
        }
        cout << "Etudiant #" << (i+1) << " : " << "\nNom: " << strNom << " - Age: " << (listeEtudiant[i]).age << " - Credit: " << (listeEtudiant[i]).nbrCreditReussis << endl;
        cout << "\n" << endl;
    }

}

void afficherMeilleurEtudiant(Etudiant (&listeEtudiant)[8]) {
    int meilleurNote1 = listeEtudiant[0].nbrCreditReussis;
    int meilleurNote2 = listeEtudiant[0].nbrCreditReussis;
    int meilleurNote3 = listeEtudiant[0].nbrCreditReussis;
    int mauvaiseNote = listeEtudiant[0].nbrCreditReussis;
    int indexMeilleur1 = 0;
    int indexMeilleur2 = 0;
    int indexMeilleur3 = 0;
    int indexMauvaise = 0;
    string strNom1,strNom2,strNom3,strNom4;
    
    for (int i = 0; i < 8; i++) {
        
        if (listeEtudiant[i].nbrCreditReussis > meilleurNote1) {
            meilleurNote1 = listeEtudiant[i].nbrCreditReussis;
            indexMeilleur1 = i;
            int size = numberOfCharsInArray(listeEtudiant[i].nom);
            strNom1 = "";
            for (int a = 0; a < size-1; a++) {
                strNom1 += listeEtudiant[indexMeilleur1].nom[a];
            }
        }
        if (listeEtudiant[i].nbrCreditReussis > meilleurNote2 && i != indexMeilleur1) {
            meilleurNote2 = listeEtudiant[i].nbrCreditReussis;
            indexMeilleur2 = i;
            int size = numberOfCharsInArray(listeEtudiant[i].nom);
            strNom2 = "";
            for (int a = 0; a < size-1; a++) {
                strNom2 += listeEtudiant[indexMeilleur1].nom[a];
            }
        }
        if (listeEtudiant[i].nbrCreditReussis > meilleurNote3 && i != indexMeilleur1 && i != indexMeilleur2) {
            meilleurNote3 = listeEtudiant[i].nbrCreditReussis;
            indexMeilleur3 = i;
            int size = numberOfCharsInArray(listeEtudiant[i].nom);
            strNom3 = "";
            for (int a = 0; a < size-1; a++) {
                strNom3 += listeEtudiant[indexMeilleur1].nom[a];
            }
        }
        if (listeEtudiant[i].nbrCreditReussis < mauvaiseNote) {
            mauvaiseNote = listeEtudiant[i].nbrCreditReussis;
            indexMauvaise = i;
            int size = numberOfCharsInArray(listeEtudiant[i].nom);
            strNom4 = "";
            for (int a = 0; a < size-1; a++) {
                strNom4 += listeEtudiant[indexMeilleur1].nom[a];
            }
        }

    }
    

    cout << "Les 3 Etudiants qui ont reussis sont: " << "\n" << endl;
    cout << strNom1 << " avec " << meilleurNote1 << " Points!" << endl;
    cout << strNom2 << " avec " << meilleurNote2 << " Points!" << endl;
    cout << strNom3 << " avec " << meilleurNote3 << " Points!" << endl;
    cout << "\nL'etudiant qui a le moins reussi est: " << "\n" << endl;
    cout << strNom4 << " avec " << mauvaiseNote << " Points!" << endl;
}