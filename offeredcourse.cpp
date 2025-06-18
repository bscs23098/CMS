#include "OfferedCourse.h"

OfferedCourses::OfferedCourses() : Course() {}

OfferedCourses::OfferedCourses(const Course& course)
    : Course(course) {}

OfferedCourses::OfferedCourses(const String& course_id, const String& course_name, int credit_hour)
    : Course(course_id, course_name, credit_hour) {}

void OfferedCourses::addOffering(const String& teacherId, const Section& section) {
    offerings.push(TeacherSectionPair(teacherId, section));
}

void OfferedCourses::removeOffering(int index) {
    if (index >= 0 && index < offerings.size()) {
        offerings.delete_at(index);
    } else {
        cout << "Invalid offering index.\n";
    }
}

void OfferedCourses::displayCourseDetails() const {
    Course::display();
    cout << "Number of Offerings: " << offerings.size() << endl;
}

void OfferedCourses::displayOfferings() const {
    if (offerings.size() == 0) {
        cout << "No offerings available for this course.\n";
        return;
    }

    for (int i = 0; i < offerings.size(); ++i) {
        cout << "\nOffering #" << i + 1 << ":\n";
        cout << "Teacher ID: " << offerings[i].teacherId << endl;
        offerings[i].section.displaySectionDetails();
    }
}

void OfferedCourses::listStudentsByTeacher(const String& teacherId) const {
    bool found = false;
    for (int i = 0; i < offerings.size(); ++i) {
        if (offerings[i].teacherId == teacherId) {
            cout << "Students for Teacher ID: " << teacherId << endl;
            offerings[i].section.displayStudents();
            found = true;
        }
    }
    if (!found) {
        cout << "No offering found for Teacher ID: " << teacherId << endl;
    }
}

