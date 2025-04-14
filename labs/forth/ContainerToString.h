#ifndef CONTAINER_TO_STRING_H
#define CONTAINER_TO_STRING_H

#include <sstream>
#include <string>

template<typename Container>
std::string container_to_string(const Container& container) {
    std::ostringstream oss;
    oss << "{ ";
    for (const auto& element : container) {
        oss << element << " ";
    }
    oss << "}";
    return oss.str();
}

#endif // CONTAINER_TO_STRING_H