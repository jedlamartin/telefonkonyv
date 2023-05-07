//
// Created by Martin on 2022. 04. 09..
//

#include "string5.h"

#include <cstring>

String::String() : len(0) {
    this->pData = new char[1];
    *this->pData = '\0';
}

String::String(String const& rhs) : len(rhs.len) {
    this->pData = new char[this->len + 1];
    strcpy(this->pData, rhs.pData);
}

String::String(char c) : len(1) {
    this->pData = new char[this->len + 1];
    this->pData[0] = c;
    this->pData[1] = '\0';
}

String::String(char const* rhs) {
    char const* veg = strchr(rhs, '\0');
    this->len = veg - rhs;
    this->pData = new char[this->len + 1];
    strcpy(this->pData, rhs);
}

size_t String::length() const {
    return this->len;
}

char const* String::c_str() const {
    return this->pData;
}

String String::operator=(String const& rhs) {
    if (this == &rhs)
        return *this;
    delete[] this->pData;
    this->len = rhs.len;
    this->pData = new char[this->len + 1];
    strcpy(this->pData, rhs.pData);
    return *this;
}

String String::operator+(String const& rhs) const {
    String newString;
    delete newString.pData;
    newString.len = this->len + rhs.len;
    newString.pData = new char[newString.len + 1];
    strcpy(newString.pData, this->pData);
    strcat(newString.pData, rhs.pData);
    return newString;
}

String String::operator+(char const rhs) const {
    String newString;
    delete[] newString.pData;
    newString.len = this->len + 1;
    newString.pData = new char[newString.len + 1];
    strcpy(newString.pData, this->pData);
    newString.pData[newString.len - 1] = rhs;
    newString.pData[newString.len] = '\0';
    return newString;
}

char const String::operator[](int const rhs) const {
    if (rhs >= (int) this->len || rhs < 0)
        throw std::out_of_range("Out of range");
    return this->pData[rhs];
}

char& String::operator[](int const rhs) {
    if (rhs >= (int) this->len || rhs < 0)
        throw std::out_of_range("Out of range");
    return this->pData[rhs];
}

String::~String() {
    delete[] this->pData;
}

bool String::operator>(String const& rhs) const {
    if (strcmp(this->c_str(), rhs.c_str()) >= 0)
        return true;
    return false;
}

bool String::operator<(String const& rhs) const {
    if (strcmp(this->c_str(), rhs.c_str()) < 0)
        return true;
    return false;
}

String& String::erase(size_t pos, size_t len) {
    if (pos + len > this->length())
        throw std::out_of_range("Out of range");
    int length=this->length() - len + 1;
    char* c = new char[this->length() - len + 1];
    if (pos == 0) {
        strcpy(c, (this->pData + pos + len));
    } else {
        strncpy(c, this->pData, pos);
        strcat(c, (this->pData + pos + len));
    }
    delete[] this->pData;
    this->pData=new char[length];
    strcpy(this->pData,c);
    delete[] c;
    this->len=length-1;
    return *this;
}

String operator+(char const lhs, String const& rhs) {
    char* c = new char[rhs.length() + 2];
    c[0] = lhs;
    c[1] = '\0';
    strcat(c, rhs.c_str());
    String eredmeny(c);
    delete[] c;
    return eredmeny;
}

std::ostream& operator<<(std::ostream& lhs, String const& rhs) {
    lhs << rhs.c_str();
    return lhs;
}

std::istream& String::getline(std::istream& in, String& target, char delimiter) {
    char ch;
    target = "";
    while (in.get(ch)) {
        if (ch == delimiter)
            break;
        target = target + ch;
    }
    return in;
}
