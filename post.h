#ifndef POST_H
#define POST_H

#include <iostream>
#include "person.h"
#include "Mystr.h"
#include "dynamic.h"
#include "comment.h"
using namespace std;

class Post {
private:
    String PostID;
    Person Author;
    String Content;
    Dynamic_array<Comment> CommentArray;
public:
    // String getID();
    Post();
    Post(const Post & other);
    Post(String PID, Person A, String Con);
    void addComment(Comment c);
    void displayPost();
    String PostIDgetter () {return PostID;}
};

#endif
