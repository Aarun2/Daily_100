#include <iostream>
using namespace std;

template <typename T>

int size_in_bits(const T& a) {

    return sizeof(a)*8;
}


int principal = 500;
double rate = .02;
int time = 5;

double interest = principal * rate * time;

 cout<<interest<<"\n";
 
class MyClass {
    public:
        int myNum;
        string myString;
};

MyClass myObj;

myObj.myNum = 15;
myObj.myString = "abc";

class Car {
    public:
        string brand;
        int id;
        int year;
        Car(string b, int id, int year) {
            brand = b;
            id = id;
            year = year;
            cout << "New Car!";
        }
        void drive() {
            cout << "I am driving a " << brand;
        }
        void buy();
        int getYear() {
            return year;
        }
};

class Suzuki : public Car {
    public:
        string model = "Suzuki";
}

void Car::buy() {
    cout << "I bought a " << brand;
}

Car honda("Honda", 567, 1999);

honda.brand = "Honda";
honda.id = 12345;
honda.year = 1999;

hond.drive();