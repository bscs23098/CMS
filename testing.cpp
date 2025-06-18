#include <iostream>
#include "Mystr.h"
#include "course.h"
#include "student.h"
#include "section.h"
#include "teacher.h"
#include "offeredcourse.h"
#include "semester.h"
#include "enrollcourses.h"
#include "comment.h"
#include "post.h"
// #include "discussion.h"
using namespace std;






int main() {

    Course course1("CS101", "Introduction to Programming", 3);
    Course course2("CS102", "Data Structures", 4);
    Date dob1(14, 4, 2000);
    Name name1("Ahmed", "Mehmood");
    Address addr1("Lahore", "Pakistan");
    Student student1(3.8, "BSCS-24-001", "ahmed@example.com", dob1, name1, addr1);
    Date dob2(23, 7, 2001);
    Name name2("Sara", "Ali");
    Address addr2("Islamabad", "Pakistan");
    Student student2(3.5, "BSCS-24-002", "sara@example.com", dob2, name2, addr2);
    Section section1("CS23A", 2023);
    Section section2("CS23B", 2023);
    section1.addStudent(student1);
    section2.addStudent(student2);
    Date tDob1(5, 9, 1985);
    Name tName1("Sarah", "Khan");
    Address tAddr1("Karachi", "Pakistan");
    Teacher teacher1("TCS001", "Professor", 85000.0, "sarah@example.com", tDob1, tName1, tAddr1);
    Date tDob2(12, 3, 1978);
    Name tName2("Ali", "Ahmed");
    Address tAddr2("Lahore", "Pakistan");
    Teacher teacher2("TCS002", "Associate Professor", 75000.0, "ali@example.com", tDob2, tName2, tAddr2);
    OfferedCourses offer1(course1);
    OfferedCourses offer2(course2);
    offer1.addOffering(teacher1.getTeacherId(), section1);
    offer1.addOffering(teacher2.getTeacherId(), section2);
    offer2.addOffering(teacher1.getTeacherId(), section2);
    Semester sem("Fall2023", offer1);
    cout << "TESTING ENROLLCOURSES CLASS\n";
    EnrollCourses enrollments;
    cout << "1. Initial enrollment state:\n";
    enrollments.displayAllEnrollments(); // no students 
    cout << "\n2. Enrolling students in courses:\n";
    enrollments.enrollStudent("BSCS-24-001", "CS101","TCS001", section1);
    enrollments.enrollStudent("BSCS-24-001", "CS102","TCS001", section2);
    enrollments.enrollStudent("BSCS-24-002", "CS101","TCS002", section2);
    cout << "\n3. All enrollments after adding students:\n";
    enrollments.displayAllEnrollments();
    cout << "\n4. Updating grades:\n";
    // result 
    enrollments.updateGrade("BSCS-24-001", "CS101","TCS001", section1, "A");
    enrollments.updateGrade("BSCS-24-001", "CS102","TCS001", section2, "B+");
    enrollments.updateGrade("BSCS-24-002", "CS101","TCS002", section2, "A-");    
    cout << "\n5. Displaying enrollments for student1 (Ahmed):\n";
    enrollments.displayStudentEnrollments("BSCS-24-001");
    cout << "\n6. Displaying enrollments for course1 (CS101):\n";
    enrollments.displayCourseEnrollments("CS101");


    // Post testing
    cout << "\n7. Displaying posts for course1 (CS101):\n";
    course1.addPost("23333", student1, "hy how are you!");
    Comment obj1("45678", "23333", student1, "I am fine how are you !");
    course1.addComment(obj1);
    course1.displayPost();
    cout << "\n8. Displaying posts for course2 (CS102):\n";
    course2.addPost("12345", student2, "Hello everyone!");
    Comment obj2("67890", "12345", student2, "Welcome to the course!");
    course2.addComment(obj2);
    course2.displayPost();
    cout << "\n9. Displaying section1 (CS23A) details:\n";
    section1.displaySectionDetails();

    
    return 0;
}