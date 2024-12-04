#include "Serializer.hpp"

Serializer::Serializer() {
    std::cout << "Serializer default constructed" << std::endl;
}

Serializer::Serializer(const Serializer&) {
    std::cout << "Serializer copy constructed" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& S) {
    if (this != &S) {
        //nothing to do
    }
    return *this;
}

Serializer::~Serializer() {
    std::cout << "Serializer deconstructed" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr) {
    uintptr_t intRep = reinterpret_cast<uintptr_t>(ptr);
    return intRep;
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data* ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}