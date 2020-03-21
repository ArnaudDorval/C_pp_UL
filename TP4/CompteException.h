/**
 * \file CompteException.h
 * \brief Fichier qui déclare la classe CompteException. Cette classe permet de gerer l'exception liee aux comptes.
 * \date 2018-04-20
 * \author Arnaud Dorval et Eve Maheux
 */
#ifndef COMPTEEXCEPTION_H_
#define COMPTEEXCEPTION_H_

/**
 * \class CompteException
 * \brief Classe CompteException qui permet de gerer l'exception liee aux comptes.
 *		  Attributs : p_raison
 */
class CompteException: public std::runtime_error {
public:
	CompteException(const std::string& p_raison);
};

/**
 * \class CompteDejaPresentException
 * \brief Classe qui permet de gerer l'exception de l'ajout d'un doublon de compte dans le client
 *		  Attributs : p_raison
 */
class CompteDejaPresentException: public CompteException {
public :
	CompteDejaPresentException(const std::string& p_raison);
}

/**
 * \class CompteAbsent Exception
 * \brief Classe qui permet de gerer l'exception de la tentative d'effacement d'un compte absent dans le Client
 *		  Attributs : p_raison
 */
class CompteAbsentException: public CompteException {
public :
	CompteAbsentException(const std::string& p_raison);
}

#endif /* COMPTEEXCEPTION_H_ */
