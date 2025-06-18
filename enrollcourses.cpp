#include "enrollcourses.h"

EnrollCourses::EnrollCourses() {
}

void EnrollCourses::enrollStudent(const String& studentId, const String& courseId, 
                              const String& teacherId, const Section& section) {
    if (isEnrolled(studentId, courseId, teacherId, section)) {
        cout << "Student " << studentId << " is already enrolled in course " << courseId << endl;
        return;
    }
    
    EnrollmentRecord record(studentId, courseId, teacherId, section);
    enrollments.push(record);
    cout << "Student " << studentId << " successfully enrolled in course " << courseId << endl;
}


void EnrollCourses::updateGrade(const String& studentId, const String& courseId,const String& teacherId, const Section& section,const String& grade) {
    for (int i = 0; i < enrollments.size(); i++) {
        EnrollmentRecord& record = enrollments[i];
        
        if (record.studentId == studentId && 
            record.courseId == courseId && 
            record.teacherId == teacherId && 
            record.section == section) {
            record.grade = grade;
            cout << "Grade updated !"<< endl;
            return;
        }
    }
    
    cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;
}

String EnrollCourses::getGrade(const String& studentId, const String& courseId, 
                          const String& teacherId, const Section& section) const {
    for (int i = 0; i < enrollments.size(); i++) {
        const EnrollmentRecord& record = enrollments[i];
        if (record.studentId == studentId && 
            record.courseId == courseId && 
            record.teacherId == teacherId && 
            record.section == section) {
            
            return record.grade;
        }
    }
    
    return "N/A";
}

bool EnrollCourses::isEnrolled(const String& studentId, const String& courseId, 
                           const String& teacherId, const Section& section) const {
    for (int i = 0; i < enrollments.size(); i++) {
        const EnrollmentRecord& record = enrollments[i];
        
        if (record.studentId == studentId && 
            record.courseId == courseId && 
            record.teacherId == teacherId && 
            record.section == section) {
            
            return true;
        }
    }
    
    return false;
}

Dynamic_array<EnrollmentRecord> EnrollCourses::getStudentCourses(const String& studentId) const {
    Dynamic_array<EnrollmentRecord> result;
    
    for (int i = 0; i < enrollments.size(); i++) {
        const EnrollmentRecord& record = enrollments[i];
        
        if (record.studentId == studentId) {
            result.push(record);
        }
    }
    
    return result;
}

Dynamic_array<EnrollmentRecord> EnrollCourses::getCourseStudents(const String& courseId,const String& teacherId, const Section& section) const {
    Dynamic_array<EnrollmentRecord> result;
    
    for (int i = 0; i < enrollments.size(); i++) {
        const EnrollmentRecord& record = enrollments[i];
        
        if (record.courseId == courseId && 
            record.teacherId == teacherId && 
            record.section == section) {
            
            result.push(record);
        }
    }
    
    return result;
}
void EnrollCourses::displayAllEnrollments() const {
    cout << "===== All Enrollments =====" << endl;
    
    if (enrollments.size() == 0) {
        cout << "No enrollments found." << endl;
        return;
    }
    
    for (int i = 0; i < enrollments.size(); i++) {
        cout << "Enrollment #" << (i + 1) << ":" << endl;
        enrollments[i].display();
        cout << "-----------------------" << endl;
    }
}

// Display enrollments for a specific student
void EnrollCourses::displayStudentEnrollments(const String& studentId) const {
    cout << "Enrollments for Student " << studentId << endl;
    
    bool found = false;
    for (int i = 0; i < enrollments.size(); i++) {
        const EnrollmentRecord& record = enrollments[i];
        
        if (record.studentId == studentId) {
            found = true;
            cout << "Course: " << record.courseId << endl;
            cout << "Teacher: " << record.teacherId << endl;
            cout << "Section: ";
            record.section.displaySectionDetails();
            cout << "Grade: " << record.grade << endl;
            cout << "-----------------------" << endl;
        }
    }
    
    if (!found) {
        cout << "No enrollments found for student " << studentId << endl;
    }
}
void EnrollCourses::displayCourseEnrollments(const String& courseId) const {
    cout << " Enrollments for Course " << courseId << endl;
    bool found = false;
    for (int i = 0; i < enrollments.size(); i++) {
        const EnrollmentRecord& record = enrollments[i];
        if (record.courseId == courseId) {
            found = true;
            cout << "Student: " << record.studentId << endl;
            cout << "Teacher: " << record.teacherId << endl;
            cout << "Section: ";
            record.section.displaySectionDetails();
            cout << "Grade: " << record.grade << endl;
            cout << "-----------------------" << endl;
        }
    }
    if (!found) {
        cout << "No enrollments found for course " << courseId << endl;
    }
}