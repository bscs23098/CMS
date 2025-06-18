#include "Semester.h"

Semester::Semester(const String& id, const OfferedCourses& course) 
    : SemID(id), offeredCourse(course) {}

String Semester::getSemID() const {
    return SemID;
}

OfferedCourses Semester::getOfferedCourse() const {
    return offeredCourse;
}

void Semester::displaySemesterDetails() const {
    cout << "Semester ID: " << SemID << endl;
    offeredCourse.displayOfferings();
}
