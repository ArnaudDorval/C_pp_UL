/**
 * \file Client.h
 * \brief Fichier qui déclare le namespace client et la classe Client contenant les informations d'un client
 * 		  qui s'inscrit ou qui est inscrit dans une banque d'un banque.
 * \date 2018-02-20
 * \author Arnaud Dorval
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include <sstream>
#include <vector>
#include "Utilitaires/Date.h"
#include "Utilitaires/ContratException.h"
#include "Utilitaires/validationFormat.h"
#include "Compte.h"
#include "Cheque.h"
#include "Epargne.h"
#include "CompteException.h"

/**
 * \namespace banque
 * \brief Namespace qui contient la classe Client
 */
namespace banque {

/**
 * \class Client
 * \brief Classe Client qui contient les informations d'un client qui s'inscrit
 *		  ou qui est inscrit dans une banque d'un banque.
 *        Elle contient le nom complet, l e numéro de folio, le numero de téléphone et la date d'ouverture.
 *        Une méthode permet de renvoyer un client formatée et de changer le numéro de téléphone
 *
 */

class Client {

public:
	Client(int& p_noFolio, const std::string& p_nom, const std::string& p_prenom,
			const std::string& p_telephone, const util::Date& p_dateDeNaissance);


	const int& reqNoFolio() const;
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	const util::Date& reqDateDeNaissance() const;
	const std::string& reqTelephone() const;

	std::string reqClientFormate() const;


	void asgTelephone(const std::string& p_telephone);

	bool operator==(const Client& p_client) const;
	bool operator<(const Client& p_client) const;

	void ajouterCompte(const Compte& p_nouveauCompte);
	std::string reqReleves() const;

	virtual ~Client();

	void verifieInvariant() const;

	void supprimerCompte(int p_noCompte);

	std::vector <Compte*> m_vComptes;


private:


	int m_noFolio; //Le numéro de folio du client. Doit être dans l’intervalle [1000, 10000[
	std::string m_nom;
	std::string m_prenom; /*Des objets string. Le nom et le prénom du client. Doivent être dans un format valide tel que déterminé
	par la fonction util ::validerFormatNom. développée dans la première partie du projet (tp1).*/
	std::string m_telephone; /*Un objet string. Le numéro de telephone du client.
	Le numéro de téléphone doit être dans un format valide tel que déterminé par la fonction
	util::validerTelephone développée dans la première partie du projet (tp1).*/
	util::Date m_dateDeNaissance;


	bool compteEstDejaPresent(int p_noCompte) const;

};


} /* namespace banque */

#endif /* CLIENT_H_ */
