#include"course.h"

Course :: Course():course_id("NA"),course_name("NA"),credit_hour(0){}
Course :: Course(const Course& other):course_id(other.course_id),course_name(other.course_name),credit_hour(other.credit_hour){}
Course :: Course(String C_id,String C_name,int C_hour):course_id(C_id),course_name(C_name),credit_hour(C_hour){}

Course & Course ::  operator = (const Course& other){
    if (this != &other) {
        course_id = other.course_id;
        course_name = other.course_name;
        credit_hour = other.credit_hour;
    }
    return *this;
}
void Course :: display ()const{
    cout<<"Course Id : "<<course_id<<endl
        <<"Course Name : "<<course_name<<endl
        <<"Credit Hour : "<<credit_hour
        <<endl;
}


String Course ::  getCourseID(){ return course_id; }


void Course::  addPost(String PID ,Person A ,String con){
    Post temp (PID,A,con);
    PostArray.push(temp);
}

void Course ::  displayPost(){
    for (int i = 0 ; i<PostArray.size();i++){
        PostArray[i].displayPost();
    }
}

void Course :: addComment(Comment & other ){ 
    bool flag = false;
   for (int i = 0 ;i<PostArray.size();i++)
   {
    if (PostArray[i].PostIDgetter() == other.PIDGetter()){
            PostArray[i].addComment(other);
            flag=true;
            break;
    }
   }
    if (!flag){
        cout<<"Post Id not found !";
    }
    
}