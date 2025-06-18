#include"Mystr.h"

int String:: getlen(const char* array) {
    int len = 0;
    while (array[len] != '\0') {
        len++;
    }
    return len;
}
int String:: int_size(int Var) {
    int i = 0;
    while (Var > 0) {
        Var /= 10;
        i++;
    }
    return i;
}

String::String() : len(0), cap(0), Cs(nullptr) {}
String::String(const char* X) {
    len = getlen(X);
    Cs = new char[len + 1];
    for (int i = 0; i < len; i++) {
        Cs[i] = X[i];
    }
    Cs[len] = '\0';
    cap = len + 1;
}

String::String(int S, const char X) {
    len = S;
    Cs = new char[len];
    for (int i = 0;i < len;i++) {
        Cs[i] = X;
    }
    cap = len;
}
String::String(int Var) {
    len = int_size(Var);
    Cs = new char[len + 1];
    int temp;
    Cs[len] = '\0';
    for (int i = len - 1; i >= 0;i--) {
        temp = Var % 10;
        Cs[i] = temp + '0';
        Var /= 10;
    }
    cap = len + 1;
}
String::String(const String& S) {
    len = S.len;
    Cs = new char[len];
    for (int i = 0;i < len;i++) {
        Cs[i] = S.Cs[i];
    }
    cap = S.cap;
}
void  String::insert(int i, char ch) {
    if (i<0 || i>this->len) {
        cout << "Invalid Input\n";
        return;
    }

    this->Cs[i] = ch;
}
void  String::insert_at(int i, const String sub) {
    if (i < 0 || i > this->len) {
        cout << "Invalid Input\n";
        return;
    }
    int t = this->cap - i;
    if (t < sub.len) {
        char* newCs = new char[this->len + sub.len];
        for (int j = 0; j < i; j++) {
            newCs[j] = this->Cs[j];
        }
        for (int j = 0; j < sub.len; j++) {
            newCs[i + j] = sub.Cs[j];
        }
        for (int j = i; j < this->len; j++) {
            newCs[sub.len + j] = this->Cs[j];
        }
        delete[] this->Cs;
        this->Cs = newCs;
        this->len += sub.len;
        this->cap = this->len;
    }
    else {
        for (int j = 0; j < sub.len; j++) {
            this->Cs[i + j] = sub.Cs[j];
        }
    }
}
void  String:: display() {
    for (int i = 0;i < this->len;i++) {
        cout << this->Cs[i];
    }
    cout << endl;
}
String:: ~String() {
    delete[] Cs;
}

bool  String::is_equal(const String& M) const {
    int i = 0;
    while (Cs[i] != '\0' && M.Cs[i] != '\0') {
        if (Cs[i] != M.Cs[i]) {
            return false;
        }
        i++;
    }
    return Cs[i] == '\0' && M.Cs[i] == '\0';
}
bool String:: is_less(const String& M) const {
    int i = 0;
    while (Cs[i] != '\0' && M.Cs[i] != '\0') {
        if (Cs[i] < M.Cs[i]) {
            return true;
        }
        else if (Cs[i] > M.Cs[i]) {
            return false;
        }
        i++;
    }
    return Cs[i] == '\0' && M.Cs[i] != '\0';
}
bool   String:: is_greater(const String& M) const {
    int i = 0;
    while (Cs[i] != '\0' && M.Cs[i] != '\0') {
        if (Cs[i] > M.Cs[i]) {
            return true;
        }
        else if (Cs[i] < M.Cs[i]) {
            return false;
        }
        i++;
    }
    return Cs[i] != '\0' && M.Cs[i] == '\0';
}

void  String::remove_at(int i) {
    if (i < 0 || i >= this->len) return;
    char* array = new char[this->len - 1];
    int k = 0;
    for (int j = 0;j < this->len; j++) {
        if (i == j) {
            continue;
        }
        array[k++] = this->Cs[j];
    }
    this->len -= 1;
    delete[] this->Cs;
    this->Cs = new char[this->len];
    for (int i = 0;i < this->len;i++) {
        this->Cs[i] = array[i];
    }
    delete[] array;
}
String  String::itos(int var) {
    return String(var);
}
String&  String::trim() {
    int start = 0;
    int end = len - 1;
    while (start <= end && (Cs[start] == ' ' || Cs[start] == '\t' || Cs[start] == '\n')) {
        start++;
    }
    while (end >= start && (Cs[end] == ' ' || Cs[end] == '\t' || Cs[end] == '\n')) {
        end--;
    }
    int new_len = end - start + 1;
    char* new_Cs = new char[new_len + 1];
    for (int i = 0; i < new_len; i++) {
        new_Cs[i] = Cs[start + i];
    }
    new_Cs[new_len] = '\0';
    delete[] Cs;
    Cs = new_Cs;
    len = new_len;
    cap = new_len + 1;
    return *this;
}
//static  String trim(const String& s) {
//    String result = s;
//    return result.trim();
//}
char  String::operator[](int i) const {
    if (i < 0 || i >= len) {
        throw out_of_range("index out  range");
    }
    return Cs[i];
}

char& String:: operator[](int i) {
    if (i < 0 || i >= len) {
        throw out_of_range("index out  range");
    }
    return Cs[i];
}
String* String::split(char delim, int& count) const {
    count = 1;
    for (int i = 0; i < len; i++) {
        if (Cs[i] == delim) count++;
    }

    String* result = new String[count];
    int start = 0, part = 0;

    for (int i = 0; i < len; i++) {
        if (Cs[i] == delim) {
            result[part] = String(i - start, '\0');
            for (int k = 0; k < i - start; k++) {
                result[part].Cs[k] = Cs[start + k];
            }
            part++;
            start = i + 1;
        }
    }

    result[part] = String(len - start, '\0');
    for (int k = 0; k < len - start; k++) {
        result[part].Cs[k] = Cs[start + k];
    }

    return result;
}
int  String::find_first(char ch) {
    for (int i = 0;i < this->len;i++) {
        if (this->Cs[i] == ch) {
            return i;
        }
    }
    return -1;
}
int String::find_first(const String& str) const {
    for (int i = 0;i < this->len - str.len;i++) {
        int j = 0;
        while (j < str.len && this->Cs[i + j] == str.Cs[j]) {
            j++;
        }
        if (j == str.len) {
            return i;
        }
    }
    return -1;
}
int  String::find_last(char ch) {
    for (int i = len - 1;i >= 0;i++) {
        if (this->Cs[i] == ch) {
            return i;
        }
    }
    return -1;
}
int String::find_last(const String& str) const {
    for (int i = this->len - str.len;i >= 0;i++) {
        int j = 0;
        while (j < str.len && this->Cs[i + j] == str.Cs[j]) {
            j++;
        }
        if (j == str.len) {
            return i;
        }
    }
    return -1;
}
void  String::remove_first(char ch) {
    int index = -1;
    for (int i = 0;i < this->len;i++) {
        if (this->Cs[i] == ch) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Invalid char \n";
    }
    char* array = new char[this->len - 1];
    int j = 0;
    for (int i = 0;i < this->len;i++) {
        if (i == index) {
            continue;
        }
        array[j++] = this->Cs[i];
    }
    delete[] this->Cs;
    this->len -= 1;
    this->Cs = new char[this->len];
    for (int i = 0;i < len;i++) {
        this->Cs[i] = array[i];
    }
    delete[] array;
}
void String::remove_last(char ch) {
    int index = -1;
    for (int i = this->len - 1;i >= 0;i++) {
        if (this->Cs[i] == ch) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Invalid char \n";
    }
    char* array = new char[this->len - 1];
    int j = 0;
    for (int i = 0;i < this->len;i++) {
        if (i == index) {
            continue;
        }
        array[j++] = this->Cs[i];
    }
    delete[] this->Cs;
    this->len -= 1;
    this->Cs = new char[this->len];
    for (int i = 0;i < len;i++) {
        this->Cs[i] = array[i];
    }
    delete[] array;
}
void  String::remove_all(char ch) {
    int count = 0;
    for (int i = this->len - 1;i >= 0;i++) {
        if (this->Cs[i] == ch) {
            count += 1;
        }
    }
    char* array = new char[count + 1];
    int j = 0;
    for (int i = 0;i < this->len;i++) {
        if (this->Cs[i] == ch) {
            continue;
        }
        array[j++] = this->Cs[i];
    }
    delete[] this->Cs;
    this->len = count;
    this->Cs = new char[this->len + 1];
    for (int i = 0;i < len;i++) {
        this->Cs[i] = array[i];
    }
    delete[] array;
}

String* String::tokenize(const char* delim, int& count) const {
    count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; delim[j] != '\0'; j++) {
            if (Cs[i] == delim[j]) count++;
        }
    }
    count++;

    String* result = new String[count];
    int start = 0, part = 0;

    for (int i = 0; i < len; i++) {
        for (int j = 0; delim[j] != '\0'; j++) {
            if (Cs[i] == delim[j]) {
                result[part++] = String(len - start, '\0');
                for (int k = 0; k < i - start; k++) {
                    result[part - 1].Cs[k] = Cs[start + k];
                }
                start = i + 1;
            }
        }
    }
    result[part] = String(len - start, '\0');
    for (int k = 0; k < len - start; k++) {
        result[part].Cs[k] = Cs[start + k];
    }
    return result;
}
String  String::concat(const String& s2) const {
    String result(len + s2.len, '\0');
    for (int i = 0; i < len; i++) result.Cs[i] = Cs[i];
    for (int i = 0; i < s2.len; i++) result.Cs[len + i] = s2.Cs[i];
    return result;
}

String& String::append(const String& s2) {
    int new_len = len + s2.len;
    char* new_Cs = new char[new_len];
    for (int i = 0; i < len; i++) new_Cs[i] = Cs[i];
    for (int i = 0; i < s2.len; i++) new_Cs[len + i] = s2.Cs[i];
    delete[] Cs;
    Cs = new_Cs;
    len = new_len;
    cap = new_len;
    return *this;
}

int* String::all_sub_strings(const char* sub, int& count) const {
    int s_len = 0;
    while (sub[s_len] != '\0') s_len++;
    count = 0;

    for (int i = 0; i <= len - s_len; i++) {
        bool match = true;
        for (int j = 0; j < s_len; j++) {
            if (Cs[i + j] != sub[j]) {
                match = false;
                break;
            }
        }
        if (match) count++;
    }
    int* new_array = new int[count];
    int idx = 0;
    for (int i = 0; i <= len - s_len; i++) {
        bool match = true;
        for (int j = 0; j < s_len; j++) {
            if (Cs[i + j] != sub[j]) {
                match = false;
                break;
            }
        }
        if (match) new_array[idx++] = i;
    }
    return new_array;
}
void  String::clear() {
    delete[] this->Cs;
    len = 0;
    cap = 0;
    Cs = nullptr;
}
void String::ToUpper() {
    for (int i = 0; i < len; i++) {
        if (Cs[i] >= 'a' && Cs[i] <= 'z') {
            Cs[i] -= 32;
        }
    }
}
void  String::ToLower() {
    for (int i = 0; i < len; i++) {
        if (Cs[i] >= 'A' && Cs[i] <= 'Z') {
            Cs[i] += 32;
        }
    }
}
void  String::replace_first(const char ch) {
    this->Cs[0] = ch;
}

ostream& operator<<(ostream& os, const String& str) {
    for (int i = 0; i < str.len; i++) {
        os << str.Cs[i];
    }
    return os;
}



String& String::operator=(const String& str) {
    if (this != &str) {
        delete[] Cs;
        len = str.len;
        cap = str.cap;
        Cs = new char[cap];

        for (int i = 0; i < len; i++) {
            Cs[i] = str.Cs[i];
        }
        Cs[len] = '\0';
    }
    return *this;
}



bool String::operator==(const String& other) const {
    if (len != other.len) return false;
    for (int i = 0; i < len; ++i) {
        if (Cs[i] != other.Cs[i]) {
            return false;
        }
    }
    return true;
}
