#include <iostream>

using namespace std;

int calc_mths(double bal, double mts);

int average(int& x, int& y, int& z);

int average(int x, int y, int z); // compiler will choose the right one

void get_info();

int calc_cost(int size);

int int_calc(int princ, int rate, int dur);

void getRainfall(double r[12]);

void add_colors(string c[7]) {
    for (int i = 0; i < 7; i++) {
        cout<<"Give me color";
        cin>>c[i];
    }
}

int main(int argc, char** argv) {
    string user_in;
    int goals = 0;
    cout<<"How many goals in this game(q for quit)?\n";
    cin>>user_in;
    while (user_in != 'q') {
        goals += (user_in - '0');
        cout<<"How many goals in this game(q for quit)?\n";
    }
    cout<<"Number of goals is "<<goals<<"\n";
    double rain[12];
    getRainfall(rain);
    double colors[7];
    add_colors(colors);
    for (int i = 0; i < 7; i++) {
        cout<<c[i]<<endl;
    }
    return 0;
}

int calc_mths(double bal, double mts) {
    i = 0;
    while (bal > 0) {
        bal -= mts;
        i++;
    }
    return i;
}

void get_info() {
    cout<<"Hellooo";
    int size;
    cout<<"What's the size of the room?";
    cin>>size;
    int cost = calc_cost(int size);
}

int calc_cost(int size) {
    int cost = 99;
    if (size > 120)
        cost += (size-120)*0.25;
    return cost; 
}

int int_calc(int princ, int rate, int dur) {
    return -1;
}

int average(int& x, int& y, int& z) { // pass by reference will actually change values
    a += 3;
    b += 4;
    c += 5;
    return (x+y+z)/3;
}

int array () {
    string seasons[] = {"Fall", "Winter", "Spring", "Summer"};
    int numbers[10];
    for (int i = 0; i< 10; i++) {
        cout<<"Enter a number\n";
        cin>>numbers[i];
    }
    for (int i = 0; i< 10; i++) {
        cout<<numbers[i]<<"\n";
    }
    int min = numbers[0];
    for (int i = 0; i< 10; i++) {
        if (numbers[i] < min){
            min = numbers[i];
        }
    }
    cout<<"Min: "<<min<<"\n";
    for (string s: seasons) { // another way to write the for loop
        cout<<s<<endl;
    }
    return 0;
}

void getRainfall(double r[12]) {
    for (int i = 0; i < 12; i++) {
        cout<<"Rainfall for month: "<<i+1<;
        cin>>r[i];
    }
}


// The End



















