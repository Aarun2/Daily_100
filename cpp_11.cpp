// Generic Programming
// specifying data types at variable definition of object instantiation is 
// polymorphism resolved at compile time as happens once
// more efficient than runtime polymorphism

#include <iostream>

using namespace std;

int main (int argv, char ** argc) {
    // containers examples vectors, stacks, queues, maps, pairs
    // 1. sequence containers that store data elements vectors, list, deques, stacks, queues
    // 2. Associative storage of associative pairs implemented as trees sets, maps, multisets, multimaps
    // 3. Unordered Associative associative pairs stored as hash tables sets, maps, multisets, multimaps
    // so balance binary trees vs hash tables
    
    // Sequence Containers
    // Example 1: Vectors, Dynamic size array
    // Supports random access for insertion and deletion of elements
    // Elements are stored contiguously in memory
    // Dynamically resizes as needed
    
    // Example 2: List
    // Doubly linked list
    // Does not support random access so sequential access as it is a linked list
    // Not stored contiguously in memory
    // Different performance than a vector
    // insertion and deletion is cheaper for a list
    // forward_list for singly linked list
    
    // Example 3: Deque
    // Double Ended Queue
    // Push and pop on both ends
    // Supports random access if needed
    // elements are not all stored contiguously
    
    
    return 0;
}

template <typename T>

int size_in_bytes (const T &a) {
    return sizeof(a);
}

void chal_1() {
    cout << size_in_bytes(21) << endl;
    cout << size_in_bytes(10.0) << endl;
    cout << size_in_bytes("Abcd") << endl;
    cout << size_in_bytes('f') << endl;
    // containers: Array like data structures that store collections of objects
    // Iterators: Pointers like objects that allow traversal of containers
    // Algorithms: A collection of algo implementations for search sort etc..
    // Functors: Function objects that can be parametrized in their constructors
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head;
        ListNode * cur;
        head = new ListNode();
        cur = head;
        bool carry = false;
        int cur_val;
        while (1) {
            // cout << "Turn" << endl;
            if (l1 == NULL && l2 == NULL && !carry) {
                cur->next = NULL;
                break;
            }
            if (l1 != NULL) {
                cur->val += l1->val;
                l1 = l1->next;
            }  
            if (l2 != NULL) {
                cur->val += l2->val;
                l2 = l2->next;
            }
            if (carry)
                cur->val++;
            if (cur->val >= 10) {
                carry = true;
                cur->val = cur->val - 10;
            }
            else
                carry = false;
            if (l1 != NULL || l2 != NULL || carry) {
                cur->next = new ListNode();
                cur = cur->next;
            }
        }
        return head;
    }
};