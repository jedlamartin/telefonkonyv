//
// Created by Martin on 2022. 04. 09..
//

#ifndef TELEFONKONYV_STRING5_H
#define TELEFONKONYV_STRING5_H

#include <iostream>

class String {
    char* pData;
    size_t len;

public:
    static std::istream& getline(std::istream& in, String& target, char delimiter = '\n');

    String();

    String(String const& rhs);

    String(char c);

    String(char const* rhs);

    size_t length() const;

    char const* c_str() const;

    String operator=(String const& rhs);

    String operator+(String const& rhs) const;

    String operator+(char const rhs) const;

    char const operator[](int const rhs) const;

    char& operator[](int const rhs);

    bool operator>(String const& rhs) const;

    bool operator<(String const& rhs) const;

    String& erase(size_t pos, size_t len = 1);

    ~String();
};

String operator+(char const lhs, String const& rhs);

std::ostream& operator<<(std::ostream& lhs, String const& rhs);

#endif//TELEFONKONYV_STRING5_H
