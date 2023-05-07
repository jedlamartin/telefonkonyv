//
// Created by Martin on 2022. 04. 18..
//

#ifndef TELEFONKONYV_HUMAN_H
#define TELEFONKONYV_HUMAN_H

#include "record.h"


class Human : public Record {
    String nickname;
    String companyNumber;
public:
    Human(const String& name, const String& number, const String& address, const String& nickname,
          const String& companyNumber)
            : Record(name, number, address), nickname(nickname), companyNumber(companyNumber) {}

    ~Human() {}

    Type type() override {
        return human;
    }

    void print(std::ostream& os, String separator = ";") override;

};


#endif //TELEFONKONYV_HUMAN_H
