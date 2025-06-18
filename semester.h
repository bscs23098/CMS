#ifndef SEMESTER_H
#define SEMESTER_H

#include<iostream>
#include "Mystr.h"
#include "offeredcourse.h"
#include "dynamic.h"
using namespace std;

class Semester {
private:
    String SemID;
    OfferedCourses offeredCourse;

public:
    Semester(const String& id, const OfferedCourses& course);
    String getSemID() const;
    OfferedCourses getOfferedCourse() const;
    void displaySemesterDetails() const;
};

#endif
