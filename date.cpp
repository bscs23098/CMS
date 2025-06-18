#include "date.h"


Date :: Date():day(1),month(1),year(1900){}
Date :: Date(int d, int m, int y):day(d),month(m),year(y){}
Date :: Date(const Date& other):day(other.day),month(other.month),year(other.year){}
Date& Date::operator=(const Date& other){
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}
void Date :: display() const{
cout<<"Date (dd/mm/yyyy) : "<<day<<" / "<<month<<" / "<<year<<endl;
}