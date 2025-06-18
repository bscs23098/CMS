#ifndef OFFEREDCOURSE_H
#define OFFEREDCOURSE_H

#include<iostream>
#include "Mystr.h"       
#include "section.h"
#include "Dynamic.h"
#include "course.h"
using namespace std;

// joining teacherid , section (making new datatype)
struct TeacherSectionPair {
    String teacherId;
    Section section;
    TeacherSectionPair() = default;
    TeacherSectionPair(const String& tid, const Section& sec)
        : teacherId(tid), section(sec) {}
};

class OfferedCourses : public Course {
private:
    Dynamic_array<TeacherSectionPair> offerings;

public:
    OfferedCourses();
    OfferedCourses(const Course& course);
    OfferedCourses(const String& course_id, const String& course_name, int credit_hour);
    void addOffering(const String& teacherId, const Section& section);
    void removeOffering(int index);
    void displayCourseDetails() const;
    void displayOfferings() const;
    void listStudentsByTeacher(const String& teacherId) const;
};

#endif
