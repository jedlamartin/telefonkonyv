//
// Created by Martin on 2022. 04. 18..
//

#include "company.h"

void Company::print(std::ostream& os, String separator) {
    Record::print(os, separator);
    os << this->owner << separator << this->field;
}




