/**
 * \file fonctionsUtilitaires.cpp
 * \brief
 * \author the
 * \version 0.1
 * \date 2018-01-08
 */
#include <istream>
#include "fonctionsUtilitaires.h"
#include <iostream>

using namespace std;

/**
 * \brief tri à bulle du tableau d'entiers passé en paramètre
 * \param[in] int tabDonnees[MAX_VALEURS] un tableau d'entiers à trier
 */
void triBulle(int tabDonnee[MAX_CAS][MAX_VALEURS], int p_ligne)
{
	int flag = 1;
	int temp;

	for (int i = 1; (i <= MAX_VALEURS) && flag; i++)
	{
		flag = 0;
		for (int j = 0; j < (MAX_VALEURS - 1); j++)
		{
			if (tabDonnee[p_ligne][j + 1] > tabDonnee[p_ligne][j])
			{
				temp = tabDonnee[p_ligne][j];
				tabDonnee[p_ligne][j] = tabDonnee[p_ligne][j + 1];
				tabDonnee[p_ligne][j + 1] = temp;
				flag = 1;
			}
		}
	}
}

/**
 * \brief tri à bulle du tableau 2d d'entiers passé en paramètre
 * \param[in] tabDonnees[][MAX_VALEURS] un tableau d'entiers à trier
 * \param[in] p_nombre-de-Lignes le nombre de lignes du tableau
 */

void tri2d(int tabDonnees[MAX_CAS][MAX_VALEURS])
{
	for (int i = 0; i < MAX_CAS; i++)
	{
		triBulle(tabDonnees, i);
	}
}

/**
 * \brief retourne le nombre de nombres plus grand que la valeur passée en paramètre
 * \param[in] int tabDonnees[][MAX_VALEURS] le tableau de valeurs à traiter
 * \pre chaque ligne du tableau doit être trié en ordre décroissant
 * \param[in]  p_valeur la valeur seuil
 * \pre p_valeur existe dans le tableau
 * \return le nombre de nombres plus grand que la valeur passée en paramètre
 */

int occurencesPlusGrand(int p_tabDonnees[MAX_CAS][MAX_VALEURS],int p_valeur)
{
	float nombreOccurencesPlusGrand;

	if (existe(p_tabDonnees, p_valeur))
	{
		cout<<p_valeur<<" est présent dans le tableau"<<endl;
	}

	for (int i = 0; i < MAX_CAS; ++i)
	{
		for (int j = 0; j < MAX_VALEURS; ++j)
		{
			if (p_tabDonnees[i][j] > p_valeur){
				nombreOccurencesPlusGrand++;
			}
		}
	}

	return nombreOccurencesPlusGrand;
}

/**
 * \brief affiche le contenu du tableau
 * \param[in] p_tabDonnees le tableau à afficher
 * \param[in] p_nombreLignes le nombre de lignes que contient le tableau
 */
void afficherTableau(int p_tabDonnees[MAX_CAS][MAX_VALEURS])
{
	for (int i = 0; i < MAX_CAS; i++)
	{
		cout << "Ligne " << i + 1 << " : " << endl;
		for (int j = 0; j < MAX_VALEURS; j++)
		{
			cout << p_tabDonnees[i][j] << endl ;
		}
	}

}

/*
 * Fonction qui prend en paramètre le tableau de donné et une valeur X et qui vérifie si cette valeur
 * est présente dans le tableau. Cette fonction retourne un booléen
 */
bool existe(int tabDonnees[MAX_CAS][MAX_VALEURS], int p_valeur){
	bool validation = false;

	for (int i = 0; i < MAX_CAS; i++)
	{
		for (int j = 0; j < MAX_VALEURS; j++)
		{
			if (tabDonnees[i][j] == p_valeur){
				validation = true;
				break;
			}
		}
	}

	return validation;
}

