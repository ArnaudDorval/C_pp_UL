/**
 * \file Client.cpp
 * \brief Fichier d'implémentation du namespace qui contient la classe Client
 * \date 2018-02-20
 * \author Arnaud Dorval
 */

#include "Client.h"

/**
 * \namespace banque
 * \brief Fichier d'implémentation du namespace qui contient la classe Client
 */
namespace banque {

/**
 * \brief Constructeur d'un nouvel objet de la classe Client
 * \param[in] p_noFolio numéro de folio du client
 * \param[in] p_nom nom du client
 * \param[in] p_prenom prenom du client
 * \param[in] p_telephone numéro de téléphone qui respecte le format national canadien
 * \param[in] p_dateDeNaissance date de naissance du client

 * \pre p_noFolio, p_nom, p_prenom, p_dateDeNaissance et p_telephone doivent correspondent à un format valide
 */
Client::Client(int& p_noFolio, const std::string& p_nom,
		const std::string& p_prenom, const std::string& p_telephone, const util::Date& p_dateDeNaissance) :
			m_noFolio(p_noFolio), m_nom(p_nom), m_prenom(p_prenom), m_telephone(p_telephone), m_dateDeNaissance(p_dateDeNaissance)
{
	PRECONDITION(m_noFolio >= 1000 && m_noFolio < 10000)
	PRECONDITION(util::validerFormatNom(m_nom));
	PRECONDITION(util::validerFormatNom(m_prenom));
	PRECONDITION(util::validerTelephone(m_telephone));

	POSTCONDITION(m_noFolio == p_noFolio);
	POSTCONDITION(m_nom == p_nom);
	POSTCONDITION(m_prenom == p_prenom);
	POSTCONDITION(m_telephone == p_telephone);
	POSTCONDITION(m_dateDeNaissance == p_dateDeNaissance);

	INVARIANTS();
}

/**
 * \brief Retourne le numéro de folio du client
 * \return numéro de folio du client
 */
const int& Client::reqNoFolio() const {
	return m_noFolio;
}

/**
 * \brief Retourne le nom du client
 * \return nom du client
 */
const std::string& Client::reqNom() const {
	return m_nom;
}

/**
 * \brief Retourne le prenom du client
 * \return prenom du client
 */
const std::string& Client::reqPrenom() const {
	return m_prenom;
}

/**
 * \brief Retourne la date d'ouverture de compte du client
 * \return la date d'ouverture de compte du client
 */
const util::Date& Client::reqDateDeNaissance() const {
	return m_dateDeNaissance;
}

/**
 * \brief Retourne le numéro de téléphone du client
 * \return le numéro de téléphone du client
 */
const std::string& Client::reqTelephone() const {
	return m_telephone;
}

/**
 * \brief Renvoie les informations du client dans un formatage adapté à la console
 * \return Informations du client dans un formatage texte adapté console
 */
std::string Client::reqClientFormate() const {

	std::ostringstream format;

	format << "Client no de folio : " << Client::reqNoFolio() << std::endl;
	format << Client::reqPrenom() << " " << Client::reqNom() << std::endl;
	format << Client::reqTelephone() << std::endl;
	format << "Date de naissance : " << Client::reqDateDeNaissance() << std::endl;

	return format.str();


}

/**
 * \brief Assigne un nouveau numéro de téléphone à un client
 * \param[in] p_telephone est le nouveau numéro de telephone qui respecte le format national canadien
 * \pre p_telephone doit correspondre à un numéro de téléphone valide
 */
void Client::asgTelephone(const std::string& p_telephone) {

	PRECONDITION(util::validerTelephone(m_telephone));
	m_telephone = p_telephone;
	POSTCONDITION(m_telephone == p_telephone);

	INVARIANTS();
}


/**
 * \brief Surcharge de l'opérateur == qui permet de vérifier si deux client sont identiques
 * \param[in] p_client objet client à comparer
 * \return valeur booléene de la comparaison des deux objets clients
 */
bool Client::operator ==(const Client& p_client) const {
	if (m_noFolio == p_client.m_noFolio && m_nom == p_client.m_nom && m_prenom == p_client.m_prenom
			&& m_dateDeNaissance == p_client.m_dateDeNaissance && m_telephone == p_client.m_telephone){
		return true;
	}
	else {
		return false;
	}
}

/**
 * \brief Surcharge de l'opérateur < qui permet de vérifier si le numéro de folio d'un client est inférieur
 * 		  à un autre client.
 * \param[in] p_client objet client à comparer
 * \return valeur booléene de la comparaison des deux objets clients
 */
bool Client::operator <(const Client& p_client) const {
	if (m_noFolio < p_client.m_noFolio){

		return true;
	}
	else {
		return false;
	}
}
/**
 * \brief Vérifie si un compte existant possède déjà ce numéro
 * \param[in] int p_nCompte
 * \return valeur booléene sur l'état d'Existance d'un compte
 */
bool Client::compteEstDejaPresent(int p_noCompte) const{
	bool validation = false;

	for (unsigned int i = 0 ; i < m_vComptes.size(); ++i){
		if (m_vComptes[i]->reqNoCompte() == p_noCompte){
			validation = true;
			break;
		}
	}
	return validation;
}

/**
 * \brief Permet d'ajouter des objets de type compte à la classe client
 * \param[in] p_nouveauCompte objet de type compte
 */
void Client::ajouterCompte(const Compte& p_nouveauCompte){
	if (!(compteEstDejaPresent(p_nouveauCompte.reqNoCompte()))){
		m_vComptes.push_back(p_nouveauCompte.clone());
	}
	else{
		throw(CompteDejaPresentException(p_nouveauCompte.reqCompteFormate()));
	}
	INVARIANTS();
}

/**
 * \brief Renvoies les informations du relevé de compte dans la console
 * \return un string du format de relevé
 */
std::string Client::reqReleves() const{
	std::ostringstream format;

	format << reqClientFormate() << std::endl;
	for (unsigned int i = 0 ; i < m_vComptes.size(); ++i){
		format << m_vComptes[i]->reqCompteFormate() << std::endl;
	}

	return format.str();

}

/**
 * \brief Permet de supprimer un compte
 */
void Client::supprimerCompte(int p_noCompte){

	PRECONDITION(p_noCompte);

	unsigned int dimension = m_vComptes.size();
	bool supprimer = false;
	std::string noCompte = std::to_string(p_noCompte);
	std::vector <Compte*>::iterator m_vIterateur;

	for(m_vIterateur = m_vComptes.begin(); m_vIterateur != m_vComptes.end(); ++m_vIterateur){

		if ((*m_vIterateur)->reqNoCompte() == p_noCompte){
			m_vComptes.erase(m_vIterateur);
			supprimer = true;
			break;
		}
	}

	if (!supprimer){
		throw(CompteAbsentException(noCompte));
	}

	POSTCONDITION(m_vComptes.size() < dimension);
	INVARIANTS();

}

/**
 * \brief Destructeur de la classe Client détruit les objet comptes à l'intérieur
 */
Client::~Client(){
	for (size_t i = 0; i < m_vComptes.size(); ++i)
	{
		delete m_vComptes[i];
	}
	m_vComptes.clear();
}

/**
 * \brief set les precondition de la classe client
 */
void Client::verifieInvariant() const{
	INVARIANT(m_noFolio >= 1000 && m_noFolio < 10000)
	INVARIANT(util::validerFormatNom(m_nom));
	INVARIANT(util::validerFormatNom(m_prenom));
	INVARIANT(util::validerTelephone(m_telephone));


}

} /* namespace banque */

