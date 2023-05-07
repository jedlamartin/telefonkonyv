//
// Created by Martin on 2022. 04. 18..
//

#include "human.h"

void Human::print(std::ostream& os, String separator) {
    Record::print(os, separator);
    os << this->nickname << separator << this->companyNumber;
}



