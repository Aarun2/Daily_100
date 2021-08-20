// pointers
#include <iostream>
using namespace std;

void chal_1();
void chal_2();
void chal_3();
void chal_4();
void chal_5();

int main(int argc, char** argv) {
    // stack fixed size
    // function args on stack
    // heap or free store used for dynamic variable creation
    // new operator is used for dynamic memory
    // returns the address of space allocated can be stored in a pointer
    // delete releases memory
    
    int * glob = new int(55);
    cout<< *glob << endl;
    delete glob;
    
    int *arr = new int[5];
    int copy[5] = { 10, 7, 15, 3, 11 };
    for (int i = 0; i < 5; i++) {
        arr[i] = copy[i];
        cout<<arr[i]<<endl;
    }
    delete[] arr;
    
    // int *array{ new int[5]{ 10, 7, 15, 3, 11 } };
    // int *pArray{ new int[5] {10, 20, 30, 40, 50}};
    // int *pArray = new int[5];
    //*pArray = {10, 20, 30, 40, 50};
    return 0;
}

void chal_1() {
    int number = 240;
    int * numPtr;
    numPtr = &number; // get address of number
    cout<<"The address of the number is: " <<numPtr<<endl;
    cout<<"The value is "<<*numPtr<<endl;
    // pointers are 4 bytes in length
    double number2 = 10.5;
    double * numPtr2 = &number2;
    cout<<"The address of the number is: " <<numPtr2<<endl;
    cout<<"The value is "<<*numPtr2<<endl;
}

void chal_2() {
    double values[10]; // if you print out values you get the first address
    double *iter = values; // so can directly set
    for (int i  = 0; i < 10; i++) {
        *(iter+(i)) = 11.0;
    }
    for (int i  = 0; i < 10; i++) {
        cout<<iter[i]<<endl;
    }
}

void chal_3() {
    char initial = 'A';
    char *pinit = &initial;
    // got to cast for char as not string
    cout << "Memory Address: " << (void *) pinit << endl; 
    // or static_cast <void *> (pinit)
    
    // strings are immutable, doesnt change over time
    // need to create new string and assign address
    
    const char * str = "This is a new string\n"; // need const for string
    cout << str << endl;
}

void chal_4() {
    // pointer to a pointer
    int num = 10;
    int* pnum = &num;
    int** p2num = &pnum;
    
    cout << "Address of num: "<< pnum << endl;
    cout << "Address of pnum: "<< &pnum << endl;
    cout << "Address of pnum: "<< p2num << endl;
    
    int test[10] = {10, 13, 15, 17, 18, 21, 35, 45, 67, 78};
    int* arr[10]; // array of pointers
    // int** arr_2;
    
    for (int i = 0; i < 10; i++) {
        arr[i] = &test[i];
    }
    
    for (int i = 0; i < 10; i++) {
        cout<<"Value: "<< *arr[i] <<endl;
        // or **(arr + i)
    }
}

double averageCost (double* priceArray, int* count) {
    double avg = 0.0;
    for (int i = 0; i < *count; i++) {
        avg += priceArray[i];
    }
    return avg/(*count);
}

void chal_5() {
    double prices[5] = {5.00, 4.50, 3.75, 3.10, 6.75};
    int count = 5;
    double average = averageCost(prices, &count);
    cout << average << endl;
}