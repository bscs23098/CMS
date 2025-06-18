#ifndef ADDRESS_H
#define ADDRESS_H

#include "Mystr.h"
#include<iostream>
using namespace std;

class Address {
private:
    String city;
    String country;
public:
    Address();
    Address(const String& c, const String& co);
    Address(const Address& other);
    Address& operator=(const Address& other);
    void display() const;
};

#endif