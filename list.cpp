//
// Created by Martin on 2022. 04. 09..
//

#include "list.h"
#include "human.h"
#include "company.h"
#include "string5.h"
#include <cstring>
#include <fstream>


List::iterator& List::iterator::operator++() {
    if (element != NULL)
        this->element = element->next;
    return *this;
}

List::iterator List::iterator::operator++(int) {
    iterator masolat = *this; // !
    ++(*this);
    return masolat;
}

List::ListElement* List::iterator::next() { //!!!!!!!!!!!!!!!!!!!!!!!!!   it.next()->adat="asd";
    return this->element->next;
}

void List::print(std::ostream& os, String separator, bool numbered, Type type) {
    List::iterator it;
    int i = 1;
    if (type == all) {
        if (numbered) {
            for (it = this->begin(); it != NULL; ++it) {
                // os<<*it;
                //if (numbered)
                os << i << ". ";

                (*it).print(os, separator);
                os << std::endl;
                i++;
            }
        } else {
            for (it = this->begin(); it != NULL; ++it) {
                // os<<*it;
                os << (*it).type() << separator;
                (*it).print(os, separator);
                os << separator << std::endl;
                i++;
            }
        }
    } else {
        for (it = this->begin(); it != NULL; ++it) {
            // os<<*it;
            if ((*it).type() == type) {
                if (numbered)
                    std::cout << i << ". ";
                (*it).print(os, separator);
                os << std::endl;

                i++;
            }
        }
    }


}

void List::insert(Record* rec) {

    /*if(pos.element==this->first){
        List::ListElement* data=new List::ListElement(rec, this->first);
        this->first=data;
    }
    else if(pos.element==this->last) {
        List::ListElement* data=new List::ListElement(rec, pos.element->next);
        this->last = data;
        pos.element->next=data;
    }
    else{
        List::ListElement* data=new List::ListElement(rec, pos.element->next);
        pos.element->next=data;
    }*/
    this->len++;
    if (this->first == NULL) {
        List::ListElement* data = new List::ListElement(rec, NULL);
        this->first = this->last = data;
        return;
    }
    if (this->first == NULL || this->first->data->getName() > rec->getName()) {
        List::ListElement* data = new List::ListElement(rec, this->first);
        this->first = data;
        return;
    }

    for (iterator it = this->begin(); it != this->end(); ++it) {
        if (it.element->next->data->getName() > rec->getName()) {
            List::ListElement* data = new List::ListElement(rec, it.element->next);
            it.element->next = data;
            return;
        }
    }
    List::ListElement* data = new List::ListElement(rec, NULL);
    ListElement* tmp = this->last;
    this->last = data;
    tmp->next = this->last;
}

void List::erase(size_t pos) {
    if (this->len == 0 || this->len < pos || pos < 1)
        throw std::out_of_range("Out of range");
    this->len--;
    if (this->len == 0) {
        ListElement* tmp = this->first;
        this->first = this->last = NULL;
        delete tmp->data;
        delete tmp;
        return;
    }

    if (pos == 1) {
        List::iterator it = this->begin();
        ++it;
        ListElement* tmp = this->first;
        this->first = it.element;
        delete tmp->data;
        delete tmp;
        return;
    }

    List::iterator it = this->begin();
    size_t i = 1;
    while (i < pos - 1) {
        ++it;
        i++;
    }

    ListElement* tmp = it.element->next;
    it.element->next = it.element->next->next;
    //it.next()=it.next()->next;
    delete tmp->data;
    delete tmp;
}

List::~List() {
    if (this->len == 0) return;
    List::iterator it = this->begin();
    while (it != NULL) {
        List::iterator tmp = it;
        tmp++;
        delete it.element->data;
        delete it.element;
        it = tmp;
    }
    //delete it.element->data;
    //delete it.element;
}

void List::config() {
    std::ifstream in("records.txt");
    if (in.good()) {
        String line;
        while (String::getline(in, line)) {
            this->insert(splitter(line));
        }

    }
    in.close();
}

Record* List::splitter(String& line) {
    char type = line[0];
    line.erase(0, 2);

    char const* namePtr = strchr(line.c_str(), ';');
    char* tmp = new char[namePtr - line.c_str()+1];
    strncpy(tmp, line.c_str(), namePtr - line.c_str());
    tmp[namePtr - line.c_str()] = '\0';
    String name(tmp);
    delete[] tmp;
    line.erase(0, namePtr - line.c_str() + 1);

    char const* numberPtr = strchr(line.c_str(), ';');
    tmp = new char[numberPtr - line.c_str()+1];
    strncpy(tmp, line.c_str(), numberPtr - line.c_str());
    tmp[numberPtr - line.c_str()] = '\0';
    String number(tmp);
    delete[] tmp;
    line.erase(0, numberPtr - line.c_str() + 1);

    char const* addressPtr = strchr(line.c_str(), ';');
    tmp = new char[addressPtr - line.c_str()+1];
    strncpy(tmp, line.c_str(), addressPtr - line.c_str());
    tmp[addressPtr - line.c_str()] = '\0';
    String address(tmp);
    delete[] tmp;
    line.erase(0, addressPtr - line.c_str() + 1);

    switch (type) {
        case '1': {
            char const* nickNamePtr = strchr(line.c_str(), ';');
            tmp = new char[nickNamePtr - line.c_str()+1];
            strncpy(tmp, line.c_str(), nickNamePtr - line.c_str());
            tmp[nickNamePtr - line.c_str()] = '\0';
            String nickname(tmp);
            delete[] tmp;
            line.erase(0, nickNamePtr - line.c_str() + 1);

            char const* companyNumberePtr = strchr(line.c_str(), ';');
            tmp = new char[companyNumberePtr - line.c_str()+1];
            strncpy(tmp, line.c_str(), companyNumberePtr - line.c_str());
            tmp[companyNumberePtr - line.c_str()] = '\0';
            String companyNumber(tmp);
            delete[] tmp;
            //line.erase(0, companyNumberePtr - line.c_str()+1);

            Human* human = new Human(name, number, address, nickname, companyNumber);
            return human;

            break;
        }

        case '2': {
            char const* ownerPtr = strchr(line.c_str(), ';');
            tmp = new char[ownerPtr - line.c_str()+1];
            strncpy(tmp, line.c_str(), ownerPtr - line.c_str());
            tmp[ownerPtr - line.c_str()] = '\0';
            String owner(tmp);
            delete[] tmp;
            line.erase(0, ownerPtr - line.c_str() + 1);

            char const* typePtr = strchr(line.c_str(), ';');
            tmp = new char[typePtr - line.c_str()+1];
            strncpy(tmp, line.c_str(), typePtr - line.c_str());
            tmp[typePtr - line.c_str()] = '\0';
            String type(tmp);
            delete[] tmp;
            //line.erase(0, typePtr - line.c_str()+1);

            Company* company = new Company(name, number, address, owner, type);
            return company;

            break;
        }
        default:{
            Company* company = new Company(name, number, address, "owner", "type");
            return company;
            break;
        }
    }
}
