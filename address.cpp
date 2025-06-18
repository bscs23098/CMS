#include"address.h"

Address :: Address():city("N/A"),country("N/A"){}
Address :: Address(const String& f, const String& l):city(f),country(l){}
Address :: Address(const Address& other):city(other.city),country(other.country){}
Address& Address :: operator=(const Address& other){
    if (this != &other) {
        city = other.city;
        country = other.country;
    }
    return *this;
}

void Address :: display() const{
    cout<<"Address : "<<city<<" "<<country<<endl;
}