#include "PhoneBook.hpp"

void Contact::setFirstName(const std::string &value) { 
    firstName = value;
}
void Contact::setLastName(const std::string &value) {
    lastName = value;
}
void Contact::setNickName(const std::string &value) {
    nickName = value;
}
void Contact::setPhoneNumber(const std::string &value) {
    phoneNumber = value;
}
void Contact::setDarkSecret(const std::string &value) {
    darkSecret = value;
}

const std::string& Contact::getFirstName() const {
    return firstName;
}
const std::string& Contact::getLastName() const {
    return lastName;
}
const std::string& Contact::getNickName() const {
    return nickName;
}
const std::string& Contact::getPhoneNumber() const {
    return phoneNumber;
}
const std::string& Contact::getDarkSecret() const {
    return darkSecret;
}