#pragma once

#include <string>

class BCrypt {
public:
    static std::string generateHash(const std::string& password);

    static bool validatePassword(const std::string& password, const std::string& hash);
};
