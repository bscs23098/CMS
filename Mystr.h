#ifndef MYSTR_H
#define MYSTR_H
#include <iostream>
using namespace std;


class String {
private:
    int getlen(const char* array);
    int len;
    int cap;
    char* Cs;
int int_size(int Var);
public:
    String();
    String(const char* X);
    String(int S, const char X);
    String(int Var);
    String(const String& S);
    void insert(int i, char ch);
    void insert_at(int i, const String sub);
    void display();
    ~String();
    bool is_equal(const String& M) const;
    bool is_less(const String& M) const;
    bool is_greater(const String& M) const;
    void remove_at(int i);
    String itos(int var);
    String& trim();
    //static String trim(const String& s);
    char operator[](int i) const;
    char& operator[](int i);
    String* split(char delim, int& count) const;
    int find_first(char ch);
    int find_first(const String& str) const;
    int find_last(char ch);
    int find_last(const String& str) const;
    void remove_first(char ch);
    void remove_last(char ch);
    void remove_all(char ch);
    String* tokenize(const char* delim, int& count) const;
    String concat(const String& s2) const;
    String& append(const String& s2);
    int* all_sub_strings(const char* sub, int& count) const;
    void clear();
    void ToUpper();
    void ToLower();
    void replace_first(const char ch);
    friend ostream& operator<<(ostream& os, const String& str);
    String& operator=(const String& str);
    bool operator==(const String& other) const;

};
#endif //MYSTR_H