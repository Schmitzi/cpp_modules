#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& cont, int value) {
    typename T::iterator it = std::find(cont.begin(), cont.end(), value);
    if (it == cont.end()) {
        throw NotFoundException();
    }
    return it;
}
