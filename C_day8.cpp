#include <iostream>
#include <vector>
using namespace std;

#ifndef NULL
#define NULL (0LL) // common c++ definition, so won't let function accept unless long long as parameter
#endif

// but can define above as ((void*)0) or ((int)0) so functions with func (int i) will accept

// better yet don't use null

// use nullptr that can be automatically converted to a pointer value of any type
// so functions with func (... * i) will be called

int main (int argv, char ** argc) {
    
    return 0;
}

vector<int> getArr (int num) {
    // percent 10 gives me the last number 
    // divide by 10 to remove last number
    vector<int> ret;
    num++;
    while (num != 0) {
        ret.push_back(num % 10);
        num = num / 10;
    }
    return ret;
}

int * getArr (int num, int * retSize) { // best is to have size as input and not return array
    // calc size of array needed
    // then add items
    num++;
    int temp = num;
    int size = 0;
    while (temp != 0) {
        temp = temp / 10;
        size++;
    }
    int * ret = new int[size];
    int i = 0;
    while (num != 0) {
        ret[i] = num % 10;
        num = num / 10;
        i++;
    }
    *retSize = size;
    return ret;
}

void chal_2() {
    // vectors
    // can increase or reduce size dynamically
    // can store any data type
    // not very efficient and not in c   
    vector<int> vi = {1, 2, 3, 4, 5};
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); ++it) {
        cout << *it;
    }
    cout << endl;
    
    
    int userIn;
    cout << "Enter number: " << endl;
    cin >> userIn;
    vector<int> userArr = getArr(userIn);
    for (vector<int>::reverse_iterator it = userArr.rbegin(); it != userArr.rend(); it++) {
        cout << *it;
    }
    
    // using arrays but have to allocate memory
    int userIn;
    cout << "Enter number: " << endl;
    cin >> userIn;
    int size  = 0;
    int * ret = getArr(userIn, &size);
    for (int i = size-1; i >= 0; i--) {
        cout << ret[i];
    }
    cout << endl;
    delete [] ret;
    
    // using auto affects compilation time but not the run time
    // using auto makes it easier
}

typedef unsigned char points_t;
typedef unsigned char rank_t;

struct score { // to typedef for clarity
    points_t points;
    rank_t rank;
};

void chal_1 (void) { // no input or ()
    score s = {5, 1};
    // got to cast for unsigned char to print out value
    cout << static_cast<unsigned>(s.points) << " " << static_cast<unsigned>(s.rank) << endl;
    auto x = 10; // figures out what type to set it as
}