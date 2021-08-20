#include <iostream> 
#include <cstdlib>
#include <string>
using namespace std;

int count_ele(const char inp []) {
    int count = 0;
    while (inp[count] != 0) {
        count++;
    }
    return count;
}

class S {
    public:
        int static_value() {
            static int x = 7;
            return ++x;       
        }
};

int func() {
    static int x = 7;
    return ++x;
}

int main(int argc, char ** argv) 
{
    // escape characters are special chars like \' quotation mark
    // CV qualifiers examples const mutable volatile
    // constant read only
    // mutable used on data member of const object to make it modifiable
    // volatile so can be used by various processes
    // storage duration qualifiers examples static register extern
    // lifetime of variable
    // static live for the duration of the program used for keeping state
    // in static space
    // register stored in processor registers (a suggestion for compiler)
    // extern in separate translation unit and linked with code
	int i = func();
	i = func();
	i = func(); // so becomes 10 because of static variable
	cout << i << endl;
	
	S s1;
	S s2;
	S s3;
	// goes to 8, 9 , 10 because of static variable so shared
	cout << s1.static_value() << endl;
	cout << s2.static_value() << endl;
	cout << s3.static_value() << endl;
	return 0;
}

struct s {
    int i;
    double d;
    const char * a;
};

class C {
    int i = 0;
    public:
        void setvalue (int value) {
            i = value;
        }
        int getvalue() {
            return i;
        }
};

void chal_5() {
    const char str1[] = "This is a null-terminated string.";
    cout << count_ele(str1) << endl;
}

void chal_4() {
    C obj1;
    obj1.setvalue(10);
    cout << obj1.getvalue() << endl;
}

int chal_3() {
        s s1 = {3, 5.0, "ABCD"};
       
       cout << s1.i << endl;
       cout << s1.d << endl;
       cout << s1.a  << endl;
       return 0;
}

int chal_1() { // ways to define strings
    // string yourName = "Phillip";

	// printf("Hello, %s", yourName);

	// cin.ignore(); cin.get();
	
	char s[] = "String";
	const char * c3string = "String";	
    cout << s << endl;
    for (char * p = s; *p; ++p) {
        cout << *p << endl;
    } 
    
    const char * cstring = "String";
    const char * const C2string  = "abcdedf"; // constant pointer
    cout << cstring << endl;
    cout << C2string << endl;
    cstring = "agdfhfhf"; // but can change this
    cout << cstring << endl;
    cstring = "ahfhf" " ahdhf"; // concatenation
    cout << cstring << endl;
	return 0;
}

int chal_2() {
    int x = 42;
	int & y = x; // no need to dereference
	cout << y << " and " << x << endl; // same value
	// y is a reference of x change one will change the other
	int ia[5] = {1, 2, 3, 4, 5}; // primitive array
	for (int item : ia) {   // range for loop
	    cout << item << endl;
	} 
	return 0;
}