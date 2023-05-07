//
// Created by Martin on 2022. 04. 09..
//

#ifndef TELEFONKONYV_RECORD_H
#define TELEFONKONYV_RECORD_H


#include "string5.h"

enum Type {
    human = 1, company = 2, all
};

class Record {
protected:
    String name;
    String number;
    String address;
public:
    Record(const String& name, const String& number, const String& address) : name(name), number(number),
                                                                              address(address) {}

    virtual ~Record() {}

    String const& getName() const {
        return this->name;
    }

    /*const String& getNumber() const{
        return this->number;
    }
    const String& getAddress() const{
        return this->address;
    }*/
    virtual Type type() = 0;

    virtual void print(std::ostream& os = std::cout, String separator = ";") = 0;
};

//std::ostream& operator<<(std::ostream& os, Record const& rhs);


#endif //TELEFONKONYV_RECORD_H