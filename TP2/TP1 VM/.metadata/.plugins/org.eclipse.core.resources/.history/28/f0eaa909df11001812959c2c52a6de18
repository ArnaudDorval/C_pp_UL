/*
 * validationFormat.cpp
 *
 *  Created on: 2018-02-12
 *      Author: Arnaud Dorval
 */
#include <istream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <fstream>

using namespace std;

/*
 * Fonction qui permet de valider si le format du prénom&nom entré en paramètre est valide
 *  */
bool validerFormatNom(string& p_nom){
	bool validation = true;// variable de retour
	int longueur = p_nom.length();//determiner le nombre de charactère dans le nom
	int valeur;//variable pour contenir le code ASCII des différents caractères

	for (int i = 0; i < longueur; ++i){
		valeur = (int)p_nom[ i ];//convertir le charactère en decimal ascii

		if (!((valeur==32)||((valeur>=65)&&(valeur<=90))||((valeur>=97)&&(valeur<=122)))){
			validation = false;//valide si la lettre est une lettre majuscule ou minuscule et si c'est un espace
			break;
		}
	}
	return validation;
}

/*
 * Fonction qui permet de valider si le format du numéro de téléphone entré en paramètre est valide selon le format canadien
 *  */
bool validerTelephone(string& p_telephone){
	bool validation = true;// variable de retour
	int longueur = p_telephone.length();//determiner le nombre de charactère dans le numéro de téléphone
	int valeur;//variable pour contenir le code ASCII des différents caractères

	if (longueur!=12){ // valider que la longueur du numéro
		validation = false;

	}
	else {
		for (int i = 0; i < longueur; ++i){
				valeur = (int)p_telephone[ i ];//convertir le charactère en decimal ascii


				if ( (((i == 3) && (valeur != 32))||((i == 7) && (valeur != 45))) ||( (!((i==3)||(i==7))) && (!((valeur >=48) && (valeur<=57))) ) ){ //valider que le 3ieme caractère est un " "
					validation = false;//valider que le 3ieme caractère est un " " & le 8ieme caractère est un "-" & si les autres caractère sont des chiffres
					break;
				}
		}
	}

	return validation;
}

/*
 * Fonction qui permet de valider si le format de la date entré en paramètre est valide
 *  */
bool validerDate(string& p_date){
	bool validation = true;
	int longueur = p_date.length();
	int valeur;
	string str_date[ 3 ]; // tableau jj mm annee
	int selection = 0; // permet de selectionner jj, mm ou annee dans le tableau
	int int_date[ 3 ]; // tableau jj mm annee

	for (int i = 0; i < longueur; ++i){
			valeur = (int)p_date[ i ];



			if (valeur == 32){ //tant que tu ne rencontre pas un espace ajoute le prochain caractère à la liste ou tu es rendu
				selection += 1;
			}
			else {
				str_date[ selection ] = str_date[ selection ] + p_date[ i ];
			}
	}

		/*Test de output
		cout<< str_date[ 0 ] <<endl;
		cout<< str_date[ 1 ] <<endl;
		cout<< str_date[ 2 ] <<endl;
		*/

		stringstream s(str_date[ 0 ]); //convertir string en int si la date contient des caractère non numérique val_p_date va retourner 0 donc sera invalidé dans le prochain test
		s >> int_date[ 0 ];
		stringstream ss(str_date[ 1 ]);
		ss >> int_date[ 1 ];
		stringstream sss(str_date[ 2 ]);
		sss >> int_date[ 2 ];

		/*test de output
		cout<<"string"<<endl;
		cout<<str_date[ 0 ]<<endl;
		cout<<str_date[ 1 ]<<endl;
		cout<<str_date[ 2 ]<<endl;
		cout<<"val"<<endl;
		cout<<int_date[ 0 ]<<endl;
		cout<<int_date[ 1 ]<<endl;
		cout<<int_date[ 2 ]<<endl;
		*/

		if ( (int_date[ 0 ] == 0) || (int_date[ 0 ] > 31) ){
			validation = false;
		}
		else if ( (int_date[ 1 ] == 0) || (int_date[ 1 ] > 12) ){
			validation = false;
		}
		else if ( (int_date[ 2 ] == 0) ){
			validation = false;
		}

	return validation;
}

/*
 * Fonction qui permet de valider si le format d'un document est valide selon l'énoncé du tp1
 * Cette fonction prend en paramètre un stream de donné selon la forme suivante:
 * 	 ifstream monfichier ("Jean_Louis_Info.txt");
	 if (monfichier.is_open())
	 {
		etat = validerFormatFichier(monfichier);
		monfichier.close();
	 }

	 else {
		 cout << "Unable to open file";
	 }
 *  */
bool validerFormatFichier(istream& p_is) {
	bool validation = true;
	string ligne; //variable qui contient l'information d'une ligne d'un document
	string mot; //variable qui contient l'information d'une ligne sans le endl
	int compteur = 0; //variable qui garde le compte des lignes
	int longueur; //variable qui donne la longueur d'une ligne
	int deCompte = 0; // variable qui contient le decompte des lignes qui ne sont pas à valider
	string cheque ("cheque"); //variables qui tiennent le string de comparaison pour les types de compte
	string epargne ("epargne");

	while  (getline (p_is,ligne) ) //permet de lire chacune des lignes d'un document
	{

		//cout << compteur << endl; //ceci est un test

		mot = ""; //réinitialiser la variable mot
		longueur = (ligne.length())-1;
		for (int i = 0; i < longueur; ++i){ //permet de retirer le endl à chaque ligne
			mot = mot + ligne[ i ];
		}


		if (deCompte != 0){
			deCompte = deCompte - 1;
		}
		else {
			//cout << mot << endl;
			if (compteur <= 1){//valider le nom
				validation = validerFormatNom(mot);
				cout << mot << endl;
			}
			else if (compteur == 2){//valider la date
				validation = validerDate(mot);
				cout << mot << endl;
			}
			else if (compteur == 3){//valider le numéro de telephone
				validation = validerTelephone(mot);
				cout << mot << endl;
			}
			else if (compteur == 4){
				//validation de numéro de folio
			}
			else {
				//detecter le type de compte et engage un compteur afin de sauter les informations qui ne sont pas a valider
				if (cheque.compare(mot) == 0 ){
				    // cout << "Nouveau compte detecté" << endl; //ceci est un test
				    deCompte = 6;
				}
				else if (epargne.compare(mot) == 0 ){
				    //cout << "Nouveau compte detecté" << endl; // ceci est un test
				    deCompte = 5;
				}
				else {
					validation = false;
				}
			}
		}

	    if (validation == false){
	    	  break;
	    }
	    compteur = compteur + 1;


	}


	return validation;
}


