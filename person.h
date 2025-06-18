#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include "Date.h"
#include "Name.h"
#include "Address.h"
#include "Mystr.h"

using namespace std;

class Person {
protected:
    String email;
    Date birthDate;
    Name fullName;
    Address address;

public:
    Person();
    Person(const Person& other);
    Person(const String& emal, const Date& dob, const Name& name, const Address& addr);
    Person& operator=(const Person& other);
    void display() const;
    String get_email();
};

#endif