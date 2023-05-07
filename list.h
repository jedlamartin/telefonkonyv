//
// Created by Martin on 2022. 04. 09..
//

#ifndef TELEFONKONYV_LIST_H
#define TELEFONKONYV_LIST_H

#include "record.h"


class List {
private:
    struct ListElement {
        Record* data;
        ListElement* next;

        ListElement(Record* rec, ListElement* next = NULL) : data(rec), next(next) {}

        ListElement() {}
    };

    ListElement* first;
    ListElement* last;
    size_t len;

    static Record* splitter(String& line);

public:

    class iterator {
        friend class List;

        ListElement* element;
    public:
        iterator(ListElement* element = NULL) : element(element) {}

        iterator& operator++();

        iterator operator++(int);

        Record& operator*() const {
            return *this->element->data;
        }

        bool operator==(iterator rhs) const {
            return this->element == rhs.element;
        }

        bool operator!=(iterator rhs) const {
            return this->element != rhs.element;
        }

        ListElement* next();
    };

    iterator begin() {
        return iterator(first);
    }

    iterator end() {
        return iterator(last);
    }


    List() : first(NULL), last(NULL), len(0) {}

    List(Record* rec) {
        ListElement* first = new ListElement(rec);
        this->first = this->last = first;
        this->len = 1;
    }

    size_t size() const {
        return this->len;
    }

    void insert(Record* rec);

    void erase(size_t pos);

    void print(std::ostream& os = std::cout, String separator = ";", bool numbered = false, Type type = all);

    void config();

    ~List();
};


#endif //TELEFONKONYV_LIST_H
