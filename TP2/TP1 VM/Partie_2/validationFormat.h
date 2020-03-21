/*
 * validationFormat.h
 *
 *  Created on: 2018-02-12
 *      Author: Arnaud Dorval
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_


bool validerFormatNom(std::string& p_nom);
bool validerTelephone(std::string& p_telephone);
bool validerDate(std::string& p_date);

bool validerFormatFichier(std::istream& p_is);

#endif /* VALIDATIONFORMAT_H_ */
