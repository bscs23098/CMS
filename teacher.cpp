#include "Teacher.h"

Teacher::Teacher() : Person(), designation("designation"), salary(0.0), teacher_id("") {}

Teacher::Teacher(const Teacher& other) : Person(other), designation(other.designation),
    salary(other.salary), teacher_id(other.teacher_id) {}

Teacher::Teacher(const String& teacher_id, const String& designation, double salary, const String& email,
                 const Date& dob, const Name& name, const Address& addr)
    : Person(email, dob, name, addr), designation(designation), salary(salary), teacher_id(teacher_id) {}

Teacher& Teacher::operator=(const Teacher& other) {
    if (this != &other) {
        static_cast<Person&>(*this) = other;
        designation = other.designation;
        salary = other.salary;
        teacher_id = other.teacher_id;
    }
    return *this;
}

void Teacher::display() const {
    cout << "Teacher ID: " << teacher_id << endl;
    Person::display();

    cout << "Designation: " << designation << endl;
    cout << "Salary: " << salary << endl;
}

String Teacher::getTeacherId() const {
    return teacher_id;
}