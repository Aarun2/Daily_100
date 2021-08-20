#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

struct A {int x;};
struct B {int y;};

A a1;
A a2;
B b1;
B b2;

int main(int argv, char ** argc) {
    // returns type of object
    if (typeid(a1) == typeid(A)) { // same as same type
        cout << "Same1\n";
    }
    if (typeid(a1) == typeid(B)) { // not same as diff objects
        cout << "Same2\n";
    }
    // not a standard just different will compare this
    cout << typeid(A).name() << endl; // 1A
    cout << typeid(B).name() << endl; // 1B
    return 0;
}

struct lib_card {
    string title;
    string author;
    string publisher;
    string subject;
    
    int isbn;
    int year_pub;
    int year_acq;
    int quantity;
};

class libCard {
    string title;
    string author;
    string publisher;
    string subject;
    
    int isbn;
    int year_pub;
    int year_acq;
    int quantity;
    public:
        libCard (string text[4], int nums[4]) {
            title = text[0];
            author = text[1];
            publisher = text[2];
            subject = text[3];
            
            isbn = nums[0];
            year_pub = nums[1];
            year_acq = nums[2];
            quantity = nums[3];
        }
        int * get_nums () {
            int * ret = new int [4];
            ret[0] = isbn;
            ret[1] = year_pub;
            ret[2] = year_acq;
            ret[3] = quantity;
            return ret;
        }
        string * get_text () {
            string * ret  = new string [4];
            ret[0] = title;
            ret[1] = author;
            ret[2] = publisher;
            ret[3] = subject;
            return ret;
        }
};

void chal_1() {
    lib_card harry = {"Harry Potter and the Deathly Hallows", "J.K. Rowling", "Penguin", "Fiction", 1234, 1956, 1979, 10};
    cout << harry.title << " " << harry.author << " " << harry.publisher << " " << harry.subject << endl;
    cout << harry.isbn << " " << harry.year_pub << " " << harry.year_acq << " " << harry.quantity << endl;
    
    string text[4] = {"Harry Potter and the Deathly Hallows", "J.K. Rowling", "Penguin", "Fiction"};
    int nums[4] = {1234, 1956, 1979, 10};
    libCard harry2 = libCard(text, nums);
    
    int * ret_nums = harry2.get_nums();
    string * ret_text = harry2.get_text();
    for (int i = 0; i < 4; i++) {
        cout << ret_nums[i] << " " << ret_text[i] << endl;
    }
    delete [] ret_nums;
    delete [] ret_text;
    
    int * ip;
    // either use try catch block or
    ip  = new(nothrow) int[2];
    if (!ip) {
        cout << "Cannot Allocate Space\n";
    }
    else {
        // init array
        ip[0] = 1;
        delete[] ip;
    }
    
    int x = 5;
    size_t y = sizeof x; // always return of type size_t
    // const unsigned long int  = size_t
    // 4 bytes, returns in number of bytes
    // also sizeof(x) works!
    // sizeof(int) needed for type name
    cout << y << endl;
    cout << sizeof(lib_card) << endl; // 112 bytes
}

















