#include "Comment.h"

Comment::Comment() : CommentID(""), PostID(""), Author(), Content("") {}
Comment::Comment(const Comment &other)
    : CommentID(other.CommentID), PostID(other.PostID),
      Author(other.Author), Content(other.Content) {}

Comment::Comment(String CID, String PID, Person A, String Con)
    : CommentID(CID), PostID(PID), Author(A), Content(Con) {}

void Comment::displayComments()  {
    cout << "Comment ID: " << CommentID << endl;
    cout << "Post ID: " << PostID << endl;
    cout << "Comment Author Gmail: ";
    cout << Author.get_email() << endl;
    cout << "Content: " << Content << endl;
}
