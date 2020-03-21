/**
 * \file CompteException.cpp
 * \brief Fichier d'implémentation de la classe CompteException
 * \date 2018-04-20
 * \author Arnaud Dorval et Eve Maheux
 */
#include "CompteException.h"
using namespace std;

CompteException::CompteException(const std::string& p_raison):
		runtime_error(p_raison){

}

CompteDejaPresentException::CompteDejaPresentException(const std::string& p_raison):
		CompteException(p_raison){

}

CompteAbsentException::CompteAbsentException(const std::string& p_raison):
		CompteException(p_raison){

}
