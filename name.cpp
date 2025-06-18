#include"name.h"

Name :: Name():firstName("N/A"),lastName("N/A"){}
Name :: Name(const String& f, const String& l):firstName(f),lastName(l){}
Name :: Name(const Name& other):firstName(other.firstName),lastName(other.lastName){}
Name& Name :: operator=(const Name& other ){
    if (this != &other) {
        firstName = other.firstName;
        lastName = other.lastName;
    }
    return *this;
}

void Name :: display() const{
    cout<<"Name : "<<firstName<<" "<<lastName<<endl;
}