#include"person.h"

Person :: Person():email("N/A"),birthDate(),fullName(),address(){}
Person :: Person(const Person& other):email(other.email),birthDate(other.birthDate),fullName(other.fullName),address(other.address){}
Person :: Person(const String& emal, const Date& dob, const Name& name, const Address& addr):email(emal),birthDate(dob),fullName(name),address(addr){}
Person& Person ::  operator=(const Person& other){
    if (this != &other) {
        email = other.email;
        birthDate = other.birthDate;
        fullName = other.fullName;
        address = other.address;
    }
    return *this;
}

void Person :: display() const{
    fullName.display();
    cout<<"Email : "<<email<<endl;
    birthDate.display();
    address.display();
}

String Person :: get_email(){ return email;}
