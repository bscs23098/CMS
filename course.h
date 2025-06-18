#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include "Mystr.h"
#include "dynamic.h"
#include "post.h"
#include "person.h"
using namespace std;
class Course{
private:
    String course_id;
    String course_name;
    int credit_hour;
    Dynamic_array <Post> PostArray; 
public:
    Course();
    Course(const Course& other);
    Course(String C_id,String C_name,int C_hour);
    Course & operator = (const Course& other);
    void display()const;
    String getCourseID();
    void addPost(String PID ,Person A ,String con);
    void displayPost();
    void addComment(Comment & other);
};

#endif 