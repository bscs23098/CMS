#ifndef ENROLLCOURSES_H
#define ENROLLCOURSES_H

#include <iostream>
#include "Mystr.h"
#include "Dynamic.h"
#include "offeredcourse.h"
#include "student.h" 

using namespace std;

struct EnrollmentRecord {
    String studentId;
    String courseId;
    String teacherId;
    Section section;
    String grade;     
    EnrollmentRecord() : grade("N/A") {}
    
    EnrollmentRecord(const String& sid, const String& cid, const String& tid, const Section& sec, const String& g = "N/A") 
        : studentId(sid), courseId(cid), teacherId(tid), section(sec), grade(g) {}
    void display() const {
        cout << "Student ID: " << studentId << endl;
        cout << "Course ID: " << courseId << endl;
        cout << "Teacher ID: " << teacherId << endl;
        cout << "Section: ";
        section.displaySectionDetails();
        cout << "Grade: " << grade << endl;
    }
};

class EnrollCourses {
private:
    Dynamic_array<EnrollmentRecord> enrollments;
    
public:
    EnrollCourses();
    void enrollStudent(const String& studentId, const String& courseId,const String& teacherId, const Section& section);
    void updateGrade(const String& studentId, const String& courseId,const String& teacherId, const Section& section,const String& grade);
    String getGrade(const String& studentId, const String& courseId,const String& teacherId, const Section& section) const;
    bool isEnrolled(const String& studentId, const String& courseId,const String& teacherId, const Section& section) const;
    Dynamic_array<EnrollmentRecord> getStudentCourses(const String& studentId) const;
    Dynamic_array<EnrollmentRecord> getCourseStudents(const String& courseId,const String& teacherId,const Section& section) const;
    void displayAllEnrollments() const;
    void displayStudentEnrollments(const String& studentId) const;    
    void displayCourseEnrollments(const String& courseId) const;
};

#endif