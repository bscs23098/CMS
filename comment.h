#ifndef COMMENT_H
#define COMMENT_H
#include <iostream>
#include "Mystr.h"
#include "person.h"
using namespace std;
class Comment{
private:
    String CommentID;
    String PostID;
    Person Author;
    String Content;
public:
    Comment();
    Comment(const Comment & other);
    Comment (String CID,String PID,Person A,String Con);
    void displayComments() ;
    String PIDGetter(){ return PostID;}

};
#endif