#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    int a = 5, b =7, c = 11;
    double average = (a + b + c) /3.0;
    cout<<average<<endl;
    function_1();
    return 0;
}

int b = 100;

void function_1 () {
    int a = 10;
    int sum = a + b;
    cout<< "sum: " << sum << endl;
}

int function_2 (int c) {
    return c + b;
}

int function_3() {
    string name;
    int year;
    cout<<"Enter your name: ";
    getline(cin, name);
    cout<<"When did your highness grace this world?";
    cin>> year;
    //cin.ignore();
    cout<<name<<" "<<year<<endl;
    return 0;
}