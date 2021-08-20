#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// implicit vs explicit conversion

int main(int argc, char** argv) {
    double x{45.765};
    int y = static_cast<int>x;
    int b = true;
    int c = 'a';
    cout<<y<<", "<<b<<", "<<c<<endl;
    return 0;
}

// iomanip library
// setw(#) set width
// setfill('c') set fill character
// setprecision(#) set precision
// fixed set fixed decimal
// left align left
// right align right

// <<setw(15)<<"this has width of 15"
// <<fixed<<setprecision(2)<<4.00 declare once to get two decimal places
// <<left declare once applies to all, left aligned

int chal_1() {
    cout<<"What is the homeowner's name?\n";
string name;
getline(cin, name);
cout<<"What is the current listing price?\n";
int price;
cin>>price;
double sell_cost = 0.06*price;
double agent_com = 0.015*price;
cout<<"Name: "<<name<<", "<<"Price: "<<price<<", "<<"Seller's Cost: "<<sell_cost<<", "
    <<"Agent Commission: "<<agent_com<<endl;
return 0;
}

int chal_2() {
    float x{0.7};
    if (abs(x-0.7)<0.001)
        cout<<"They are the same";
    else
        cout<<"The numbers are different";
    return 0;
}

// compare strings
// if result less than 0 than first string comes before
// if result is equal to 0 then strings are the same
// if result is greater than 0 than second string comes first

int chal_3() {
    string s1, s2, s3;
    cout<<"Enter 3 strings: ";
    cin>>s1;
    cin>>s2;
    cin>>s3;
    if (s1.compare(s2) <= 0) {
        if (s2.compare(s3) <= 0)
            cout<<s1<<", "<<s2<<", "<<s3;
        else
            cout<<s1<<", "<<s3<<", "<<s2;
    }
    return 0;
}

int chal_4() {
    int choice;
    cout<<"Enter a choice: \n";
    cin>>choice;
    switch (choice) {
        case 1: 
            cout<<"Hotdog costs: 5$\n";
            break;
        case 2: 
            cout<<"Chillidog costs: 10$\n";
            break;
        case 3: 
            cout<<"Ham costs: 15$\n";
            break;
        default:
            cout<<"Invalid Choice\n";
    }
    return 0;
}

int chal_5() {
    cout<<"Welcome to the Bank!";
    cout<<"checking or savings?";
    string user_in;
    int cur_bal;
    int dep;
    int with;
    cin>>user_in;
    cout<<"What's the current Balance?";
    cin>>cur_bal;
    cout<<"What's the Deposits?";
    cin>>dep;
    cout<<"What's the withdrawals?";
    cin>>with;
    int final_bal = cur_bal + dep - with;
    if (user_in.compare("checking"))
        cout<<"Checking Account\n"; 
    else if (user_in.compare("savings"))
        cout<<"Savings Account\n";
    else {
        cout<<"Invalid Account\n";
        return 1;
    }
    cout<<"Final Balance: "<<final_bal;
    return 0;
}

int chal_6() {
    double balance, monthlypt;
    cout<<"Enter Balance";
    cin>>balance;
    cout<<"Enter Monthly Payment";
    cin>>monthlypt;
    int i = 1;
    while(balance > 0) {
        cout<<"Payment for Month"<<i<<endl;
        balance -= monthlypt;
        cout<<"Balance is "<<balance<<endl;    
    }
}

do {
    if (in != 1 || in != 2 || in != 3 || in != 4 || in != 5)
        done = false;

} while (done == false);

for (int i = 0; i < 10; i++) {
    if (i % 2 != 0)
        cout<<"Odd Number: "<<i<<endl;
}
cout<<"Name Please\n";
cin>>user_in;

while(user_in!='q') {
    cout<<user_in<<"\n";  
    cin>>user_in;
}

// the end





