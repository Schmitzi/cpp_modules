#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>
#include <functional>
#include "Contact.hpp"
#include "Utils.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int		contactCount;
		bool		notEmpty;
		int		totalContacts;

	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContacts();
		void	incrementCounters();

		// Getters
		int getTotalContacts() const;
		int getNotEmpty() const;
};
