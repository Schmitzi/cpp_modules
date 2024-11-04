#pragma once

#include "PhoneBook.hpp"

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkSecret;
	public:
		// Setters
		void setFirstName(const std::string &value);
		void setLastName(const std::string &value);
		void setNickName(const std::string &value);
		void setPhoneNumber(const std::string &value);
	    void setDarkSecret(const std::string &value);

		// Getters
		const std::string &getFirstName() const;
		const std::string &getLastName() const;
		const std::string &getNickName() const;
		const std::string &getPhoneNumber() const;
		const std::string &getDarkSecret() const;
};