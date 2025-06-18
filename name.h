#ifndef NAME_H
#define NAME_H

#include "Mystr.h"
#include <iostream>
using namespace std;

class Name {
private:
    String firstName;
    String lastName;
public:
    Name();
    Name(const String& f, const String& l);
    Name(const Name& other);
    Name& operator=(const Name& other);

    void display() const;
};
#endif