#include <iostream>
#include <vector>
#include "prime.h"
#include <string>
#include <stdlib.h>

using namespace std;

struct p_node {
    int data;
    p_node * next;
};

p_node * head = NULL;

p_node * add_node (int data) {
    p_node * add = new p_node;
    add->data = data;
    add->next = NULL;
    if (head == NULL) {
        head = add;
        return add;
    }    
    p_node * cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = add;
    return add;
}

void print_nodes() {
    p_node * cur = head;
    int i = 0;
    while (cur != NULL) {
        cout << cur->data << endl;
        cur = cur->next;
        i++;
    }
    cout << i << endl;
}

void del_all () {
    p_node * cur = head;
    p_node * temp;
    while (cur != NULL) {
        temp = cur;
        cout << temp->data << endl;
        cur = cur->next;
        delete temp;
    }
    head = NULL;
}

bool delete_node (p_node * del) {
    if (del == NULL || head == NULL) 
        return false;
    p_node * cur = head;
    p_node * prev = NULL;
    while (cur != del && cur != NULL) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        return false;
    if (prev == NULL) {
        head = NULL;
        return true;
    }
    prev->next = cur->next;
    delete cur;
    return true; 
}

int main(int argv, char** argc) {
    for (int i  = 0; i < 5; i++) {
        add_node(rand());
    }
    add_node(12);
    p_node * del = add_node(10);
    add_node(13);
    print_nodes();
    cout << endl;
    
    delete_node (del);
    print_nodes();
    cout << endl;
    
    del_all();
    print_nodes();
    del_all();
    return 0;
}

void fa() { cout << "A" << endl;}
void fb() { cout << "B" << endl;}
void fc() { cout << "C" << endl;}

void (*funcs[])() = {fa, fb, fc};

bool is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if ((n % i) == 0)
            return false;
    }
    return true;
}

string give_name () { // so don't pass address just return the string
    string me  = "I am Aditya\n";
    return me;
}

void print_str (string * s) { // pass the address
    cout << *s << endl;
}

void chal_1() {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i))
            cout << i << endl;
    }
    string me = "I am Aditya and I am the best";
    print_str(&me);
    cout << give_name();
    
    // function pointer
    // so just like the function signature and then call it after
    void (*pfunc)(string *) = print_str;
    (*pfunc)(&me);
    
    // also function pointer array
    for (int i = 0; i < 3; i++) {
        (*funcs[i])(); // then call all the functions
    }
}