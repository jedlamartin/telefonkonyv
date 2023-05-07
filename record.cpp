//
// Created by Martin on 2022. 04. 09..
//

#include "record.h"

/*std::ostream &operator<<(std::ostream &os, const Record &rhs) {
    os<<rhs.getName()<<";"<<rhs.getNumber()<<";"<<rhs.getAddress()<<std::endl;
    return os;
}*/

void Record::print(std::ostream& os, String separator) {
    os << this->name << separator << this->number << separator << this->address << separator;
}
