#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

class Teacher : public Person {
private:
    String designation;
    float salary;
    String teacher_id;


public:
    Teacher();
    Teacher(const Teacher& other);
    Teacher(const String& teacher_id, const String& designation, double salary, const String& email,
            const Date& dob, const Name& name, const Address& addr);
    Teacher& operator=(const Teacher& other);
    void display() const;
    String getTeacherId() const;
};

#endif