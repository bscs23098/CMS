#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person {
private:
    String rollNumber;
    float gpa;

public:
    Student();
    Student(const Student& other);
    Student(float gpa, const String& rollNumber, const String& email,
            const Date& dob, const Name& name, const Address& addr);
    Student& operator=(const Student& other);
    String getStudentID() const;
    void display() const;
};

#endif