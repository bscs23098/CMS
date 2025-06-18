#include "Post.h"


Post :: Post():PostID("NA"),Author(),Content("NA"){}
Post :: Post(const Post & other):PostID(other.PostID),Author(other.Author),Content(other.Content){}


Post::Post(String PID, Person A, String Con)
    : PostID(PID), Author(A), Content(Con) {}

void Post::addComment(Comment c) {
    CommentArray.push(c);
}

void Post::displayPost() {
    cout << "Post ID: " << PostID << endl;
    cout << "Post Author gmail: ";
    cout<<Author.get_email()<<endl;
    cout << "Content: " << Content << endl;
    if (CommentArray.size()>0){
        cout << "-----------  Comments: -----------" << endl;
    for (int i = 0; i < CommentArray.size(); i++) {
        CommentArray[i].displayComments();
    }
}
    else 
        cout<<"No Comments yet\n";
}


// String Post::getID() {
//     return PostID;
// }