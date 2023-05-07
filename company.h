//
// Created by Martin on 2022. 04. 18..
//

#ifndef TELEFONKONYV_COMPANY_H
#define TELEFONKONYV_COMPANY_H

#include "record.h"

class Company : public Record {
    String owner;
    String field;
public:
    Company(const String& name, const String& number, const String& address, const String& owner, const String& type)
            : Record(name, number, address), owner(owner), field(type) {}

    ~Company() {}

    Type type() override {
        return company;
    }

    void print(std::ostream& os, String separator) override;
};


#endif //TELEFONKONYV_COMPANY_H
