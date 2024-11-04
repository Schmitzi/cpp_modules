#pragma once

#include "PhoneBook.hpp"

void		writer( const std::string& str);
int			displayContacts(int count);
void 		isNum(Contact& contact, void (Contact::*setter)(const std::string&));
void 		inputCheck(Contact& contact, void (Contact::*setter)(const std::string&));
