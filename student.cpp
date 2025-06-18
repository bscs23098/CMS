#include"student.h"

Student::Student()
    : Person("", Date(), Name(), Address()), rollNumber(""), gpa(0.0f) {}

Student::Student(const Student& other)
    : Person(other), rollNumber(other.rollNumber), gpa(other.gpa) {}

Student::Student(float gpa, const String& rollNumber, const String& email,
                 const Date& dob, const Name& name, const Address& addr)
    : Person(email, dob, name, addr), rollNumber(rollNumber), gpa(gpa) {}

    Student& Student::operator=(const Student& other) {
        if (this != &other) {
            // Person::operator=(other);
            static_cast<Person&>(*this)=other;
            rollNumber = other.rollNumber;
            gpa = other.gpa;
        }
        return *this;
    }
    // obj1 = obj2

    void Student::display() const {
        Person::display();  
        cout << "Roll Number: " << rollNumber << std::endl;
        cout << "GPA: " << gpa << endl;
    }   


    String Student::getStudentID() const {
        return rollNumber;  
    }