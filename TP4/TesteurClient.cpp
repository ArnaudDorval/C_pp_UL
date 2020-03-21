/**
 * \file TesteurClient.cpp
 * \brief Test unitaire de la classe Client
 * \author Arnaud Dorval
 * \date 2018-04-09
 */


#include <gtest/gtest.h>
#include "Client.h"
#include <string>
#include <iostream>

using namespace std;
using namespace banque;



/**
 * \brief Test du constructeur avec paramètre Client(noFolio, nom, prenom, nbTelephone, uneDate);
 *     Cas valide: Création d'un objet Client et vérification de l'assignation de tous les attributs
 *     Cas invalide:
 *     				noFolio INVALIDE
 *     				nom INVALIDE
 *     				prenom INVALIDE
 *     				telephone INVALIDE
 */
TEST(Client,ConstructeurValide)
{
	util::Date uneDate(29, 01, 1997);

	int noFolio = 1100;
	string nom = "Arnaud";
	string prenom = "Dorval";
	string nbTelephone = "514 694-9361";

	Client nouveauClient(noFolio, nom, prenom, nbTelephone, uneDate);

	ASSERT_EQ(noFolio,nouveauClient.reqNoFolio());
	ASSERT_EQ(nom,nouveauClient.reqNom());
	ASSERT_EQ(prenom,nouveauClient.reqPrenom());
	ASSERT_EQ(nbTelephone,nouveauClient.reqTelephone());
}

TEST(Client,ConstructeurNoFolioInvalide)
{
	util::Date uneDate(29, 01, 1997);

	int noFolio = 999;
	string nom = "Arnaud";
	string prenom = "Dorval";
	string nbTelephone = "514 694-9361";

	ASSERT_THROW( Client nouveauClient(noFolio, nom, prenom, nbTelephone, uneDate),ContratException)
      << "Un Client n'accepte que des valeurs de folio entre 1 000 et 9 999 inclusivement";
}

TEST(Client,ConstructeurNomInvalide)
{
	util::Date uneDate(29, 01, 1997);

	int noFolio = 1100;
	string nom = "Arn9";
	string prenom = "Dorval";
	string nbTelephone = "514 694-9361";

	ASSERT_THROW( Client nouveauClient(noFolio, nom, prenom, nbTelephone, uneDate),ContratException)
      << "Un Client n'accepte que des nom composé de lettres";
}

TEST(Client,ConstructeurPrenomInvalide)
{
	util::Date uneDate(29, 01, 1997);

	int noFolio = 1100;
	string nom = "Arnaud";
	string prenom = "Dorva0";
	string nbTelephone = "514 694-9361";

	ASSERT_THROW( Client nouveauClient(noFolio, nom, prenom, nbTelephone, uneDate),ContratException)
      << "Un Client n'accepte que des nom composé de lettre";
}

TEST(Client,ConstructeurTelephoneInvalide)
{
	util::Date uneDate(29, 01, 1997);

	int noFolio = 1100;
	string nom = "Arnaud";
	string prenom = "Dorval";
	string nbTelephone = "5147694-9361";

	ASSERT_THROW( Client nouveauClient(noFolio, nom, prenom, nbTelephone, uneDate),ContratException)
      << "Un Client n'accepte que des numéro de téléphone au format canadien";
}

/**
 * \test Test de la surcharge de l'opérateur égal égal
 *
 * 		  Cas valides: Création de deux objets Client et vérification de la surcharge ==
 *		  Cas invalides:
 *		  		Deux objets non égaux
 */
TEST(Client, OperateurEgalEgalValide){

	util::Date UneDate(29, 01, 1997);

	int NoFolio = 1100;
	string Nom = "Arnaud";
	string Prenom = "Dorval";
	string NbTelephone = "514 694-9361";

	Client Client1(NoFolio, Nom, Prenom, NbTelephone, UneDate);
	Client Client2(NoFolio, Nom, Prenom, NbTelephone, UneDate);

	ASSERT_EQ(true, Client1 == Client2);
}

TEST(Client, OperateurEgalEgalInvalide){

	util::Date UneDate(29, 01, 1997);

	int NoFolio = 2000;
	int NoFolio2= 3000;
	string Nom = "Arnaud";
	string Prenom = "Dorval";
	string NbTelephone = "514 694-9361";

	Client Client1(NoFolio, Nom, Prenom, NbTelephone, UneDate);
	Client Client2(NoFolio2, Nom, Prenom, NbTelephone, UneDate);

	ASSERT_EQ(false, Client1 == Client2);
}

/**
 * \test Test de la surcharge de l'opérateur plus petit que
 *
 * 		  Cas valides: Création de deux objets Client et vérification de la surcharge <
 *		  Cas invalides:
 *		  		Deux objets plus grand que
 */
TEST(Client, OperateurPlusPetitValide){

	util::Date UneDate(29, 01, 1997);

	int NoFolio = 2000;
	int NoFolio2= 3000;
	string Nom = "Arnaud";
	string Prenom = "Dorval";
	string NbTelephone = "514 694-9361";

	Client Client1(NoFolio, Nom, Prenom, NbTelephone, UneDate);
	Client Client2(NoFolio2, Nom, Prenom, NbTelephone, UneDate);

	ASSERT_EQ(true, Client1 < Client2);
}

TEST(Client, OperateurPlusPetitInvalide){

	util::Date UneDate(29, 01, 1997);

	int NoFolio = 3000;
	int NoFolio2= 2000;
	string Nom = "Arnaud";
	string Prenom = "Dorval";
	string NbTelephone = "514 694-9361";

	Client Client1(NoFolio, Nom, Prenom, NbTelephone, UneDate);
	Client Client2(NoFolio2, Nom, Prenom, NbTelephone, UneDate);

	ASSERT_EQ(false, Client1 < Client2);
}

/**
 * \brief Création d'une fixture à utiliser pour les méthodes de la classe Client
 */
class UnClient: public ::testing::Test
{
public:
	int noFolio = 1100;
	string nom = "Arnaud";
	string prenom = "Dorval";
	string nbTelephone = "514 694-9361";
	util::Date uneDate;

	UnClient() :
		ClientTest(noFolio, nom, prenom, nbTelephone, uneDate)
	{};
	Client ClientTest;

protected:

	int NoCompte1 = 1;
	double TauxInteret1 = 2.0;
	double Solde1 = 3000.0;
	string Description1 = " La Biere";

	int NoCompte2 = 2;
	double TauxInteret2 = 2.0;
	double Solde2 = 3000.0;
	int NbTransaction = 5;
	double TauxInteretMinimum = 0.3;
	string Description2 = " La Vie";

	virtual void SetUp(){
		ClientTest.ajouterCompte(Epargne( NoCompte1, TauxInteret1, Solde1, Description1));
		ClientTest.ajouterCompte(Cheque( NoCompte2, TauxInteret2, Solde2, NbTransaction, TauxInteretMinimum, Description2));
	}
};

/**
 * \test Test de la méthode reqNoFolio()
 *
 *     Cas valide: vérifier le retour des informations du Client
 *     Cas invalide: aucun
 */
TEST_F(UnClient, reqNoFolio)
{
	ASSERT_EQ(1100, ClientTest.reqNoFolio());
}

/**
 * \test Test de la méthode reqNom()
 *
 *     Cas valide: vérifier le retour des informations du Client
 *     Cas invalide: aucun
 */
TEST_F(UnClient, reqNom)
{
	ASSERT_EQ("Arnaud", ClientTest.reqNom());
}
/**
 * \test Test de la méthode reqPrenom()
 *
 *     Cas valide: vérifier le retour des informations du Client
 *     Cas invalide: aucun
 */
TEST_F(UnClient, reqPrenom)
{
	ASSERT_EQ("Dorval", ClientTest.reqPrenom());
}
/**
 * \test Test de la méthode reqDateNaissance()
 *
 *     Cas valide: vérifier le retour des informations du Client
 *     Cas invalide: aucun
 */
TEST_F(UnClient, reqDateNaissance)
{
	util::Date aujourdhui;
	ASSERT_EQ(aujourdhui, ClientTest.reqDateDeNaissance());
}
/**
 * \test Test de la méthode reqTelephone()
 *
 *     Cas valide: vérifier le retour des informations du Client
 *     Cas invalide: aucun
 */
TEST_F(UnClient, reqTelephone)
{
	ASSERT_EQ("514 694-9361", ClientTest.reqTelephone());
}
/**
 * \test Test de la méthode asgTelephone()
 *
 *     Cas valide: vérifier le l'assignation à un attribut de la classe Client
 *     Cas invalide: aucun
 */
TEST_F(UnClient, asgTelephone){
	ClientTest.asgTelephone("514 123-9361");
	ASSERT_EQ("514 123-9361",ClientTest.reqTelephone());
}
/**
 * \test Test de la méthode reqReleves()
 *
 *     Cas valide: vérifier le retour des informations du Client
 *     Cas invalide: aucun
 */
TEST_F(UnClient, reqReleves){

	ostringstream format;
	format << ClientTest.reqClientFormate() << endl;
	format << Epargne( NoCompte1, TauxInteret1, Solde1, Description1).reqCompteFormate() << endl;
	format << Cheque( NoCompte2, TauxInteret2, Solde2, NbTransaction, TauxInteretMinimum, Description2).reqCompteFormate() << endl;

	ASSERT_EQ(format.str(), ClientTest.reqReleves());

}

/**
 * \test Test de la méthode compteDejaPresentException()
 *
 *     Cas invalide: essayer d'ajouter un compte qui existe déjà
 */
TEST_F(UnClient, compteDejaPresentException){
	EXPECT_THROW(ClientTest.ajouterCompte(Epargne(NoCompte1, TauxInteret1, Solde1, Description1)), compteDejaPresentException);

};
