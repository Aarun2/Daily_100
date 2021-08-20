#include <iostream>
#include <cstdint>
using namespace std;

union ipv4 { // a data structure that lets you use the same memory for different types
    uint16_t i16;
    struct {
        uint8_t a;
        uint8_t b;
    } octets;
};

int main(int argc, char ** argv) {
    union ipv4 addr; 
    addr.octets = {10, 5};
    // two ways to print it as two 8 bits
    // can't directly print 8 bit values in cout
    cout << unsigned(addr.octets.a) << " " << unsigned(addr.octets.b) << endl;
    // or one 16 bit
    cout << addr.i16 << endl;
    return 0;
}

enum card_suit : uint8_t { SPD, HRT, DIA, CLB}; // 0,1,2 not guaranteed
enum card_rank : uint8_t { ACE = 1, DEUCE = 2, JACK = 11, QUEEN, KING};
// goes sequentially after that number

void print_card(int rank, int suit) {
    switch (rank) {
        case ACE: cout << "Ace of "; break;
        case DEUCE: cout << "Deuce of"; break;
        case JACK: cout << "Jack of"; break;
        case QUEEN: cout << "Queen of"; break;
        case KING: cout << "King of"; break;
        default: cout << "No Rank and ";
    }
    
    switch (suit) {
        case SPD: cout << "Spades" << endl; break;
        case HRT: cout << "Hearts" << endl; break;
        case DIA: cout << "Diamonds" << endl; break;
        case CLB: cout << "Clubs" << endl; break;
        default: cout << "No suit" << endl;
    }
}

struct bit_fields { //  so use less space
    bool likesMusic : 1; // number of bits used for that element
    bool hasHair : 1;
    unsigned int children : 4; // 16 options 0 - 15
};

void chal_3() {
    // Bitfields
    bit_fields bart;
    bart.likesMusic = true;
    bart.hasHair = true;
    bart.children = 5;
    // Enums
    print_card(ACE, SPD);
    // may run into trouble in concurrent programming
}

struct employee {
    int id;
    const char * name;
    const char * role;
};

void chal_2() {
    employee adi = {1212, "Aditya", "King"};
    employee *adi2  = &adi;
    
    cout << adi.id << endl;
    cout << adi.name << endl;
    cout << adi.role << endl;
    
    cout << adi2->id << endl;
    cout << adi2->name << endl;
    cout << adi2->role << endl;
}

int &f(int & i) {
    return ++i;
}

const int &b(const int & i) {
    return i;
}


void chal_1() {
    int i = 5;
    
    f(i) = 42; // changing the given reference
    // this works but wont work for b
    // use reference only with const
    // instead use pointers
    cout << i << endl;
}