#include"section.h"

Section::Section() {
    sectionName = "NA";   
    batchnumber = 0; 
}
Section::Section(String name, int batch):sectionName(name),batchnumber(batch) {}

void Section::addStudent(const Student& newStudent) {
    students.push(newStudent);
}

void Section::removeStudent(const String& studentID) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getStudentID() == studentID) {
            students.delete_at(i);
            return;
        }
    }
}

void Section::displayStudents() const {
    for (int i = 0; i < students.size(); i++) {
        students[i].display();
    }
}

void Section::displaySectionDetails() const {
    cout << "Section: " << sectionName << "\nBatch Number: " << batchnumber <<endl;
}

int Section::getStudentCount() const {
    return students.size();
}

bool Section :: operator == (const Section & other) const {
    if (this->batchnumber == other.batchnumber && this->sectionName == other.sectionName){  return true; }
    return false;
}