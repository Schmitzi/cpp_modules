#include "Serializer.hpp"

int main() {
    Data* data = new Data;
    
    data->str = "FortyTwo";
    data->num = 42;
    data->dub = 42.42;

    uintptr_t serial = Serializer::serialize(data);
    Data* data2 = Serializer::deserialize(Serializer::serialize(data));

    std::cout << "\t----- Output -----\n" << std::endl;

    std::cout << "Original str:\t\t\t" << data->str << std::endl;
    std::cout << "Original num:\t\t\t" << data->num << std::endl;
    std::cout << "Original dub:\t\t\t" << data->dub << std::endl;
    std::cout << "Original pointer address:\t" << data << std::endl;
    std::cout << "Pointer as uintptr_t:\t\t" << serial << std::endl;
    std::cout << "Converted as uintptr_t:\t\t" << data2 << std::endl;
    std::cout << "Str from converted pointer:\t" << data2->str << std::endl;
    std::cout << "Num from converted pointer:\t" << data2->num << std::endl;
    std::cout << "Dub from converted pointer:\t" << data2->dub << std::endl;

    delete data;

    return 0;
}