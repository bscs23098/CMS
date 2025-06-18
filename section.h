#ifndef SECTION_H
#define SECTION_H

#include<iostream>
#include"Mystr.h"
#include"student.h"
#include"Dynamic.h"
using namespace std;

class Section {
private:
    String sectionName;
    int batchnumber;
    Dynamic_array<Student> students;

public:
    Section();
    Section(String name, int batch);
    void addStudent(const Student& newStudent);
    void removeStudent(const String& studentID);
    void displayStudents() const;
    void displaySectionDetails() const;
    int getStudentCount() const;
    bool operator == (const Section & other)const ;
};

#endif // SECTION_H