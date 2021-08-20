class pkt;
    rand bit [7:0] addr;
    randc bit [7:0] data; // cycle through all values before repeating
    
    constraint addr_limit {addr <= 8'hB;};
    extern constraint addr_explicit;
endclass

constraint pkt::addr_explicit {data <= 8'hA;};

module tb;
    initial begin
        Packet pkt = new ();
        for (int i = 0; i < 10; i++) begin
            pkt.randomize();
            $display("itr=%0d data=0x%0h addr=0x%0h", i, pkt.data, pkt.addr);
        end
    end
endmodule

// constraint blocks

// Array of integers
// Array size between 5 and 15
// All elements are in descending order

class Packet;
    rand int d_array[]; // dynamic array
    
    constraint size_const {d_array.size() > 5; d_array.size() < 15;};
    constraint descend {for (int i = 0; i < d_array.size - 1; i++)
                            d_array[i] > d_array[i+1]};
    
    function void display();
        foreach (d_array[i])
            $display("d_array[%0d] = 0x%0h", i, d_array[i]);
    endfunction
endclass

module Packet_tb;
    Packet pkt;
    
    initial begin
        pkt = new();
        pkt.randomize();
        pkt.display();
    end
    
endmodule

//Arrays

bit [7:0] m_data; // 1D Packed or vector
bit [3:0][7:0] b_data; // 4 * 8 = 32 bit value all packed
bit [1:0][7:0][3:0] c_data; // 64 bit value

bit [15:0] m_mem [10:0]; // 11 item array, each item is 16 bits 

byte stack[8]; // 8 1 byte variables

byte stack_1 [2][4]; // 2 rows, 4 cols

bit [3:0][7:0] stack [2][4]; // 32 bit values, 2 rows and 4 cols

int m_data2[int]; // Associative Array, int key and int data

int m_name[string]; // string key and int data

int m_queue[$]; // queue, unbound no size

// FIFO

m_queue.push_back(23);

int data = m_queue.pop_front();

logic [7:0] ele[$:190]; // ele is 8 bit values with a maximum size of 190 elements

int q1 [$] = {1, 2, 3, 4, 5};
int tmp; 

tmp = q1[$]; // last item

q1 = {}; // empty queue

q1.insert(2, 15); // 15 at index 2

q1 = {q1, 99}; // append 99

q1 = {99, q1}; // add to top

q1 = q1[1:$]; // delete first item

q1 = q1[0:$-1]; // delete last item

$display("fruits = %p", q1[1:$]); //  slice expression

// Queue Methods

size();
insert(index, item);
delete(index);
delete(); // all
pop_front();
pop_back();
push_back(item);
push_front(item);

class Fruit;
    string name;
    
    function new (string name = "Unknown");
        this.name = name;
    endfunction

endclass

typedef int dyn_arr[]; // int dynamic array declaration

module fruit_tb;
    Fruit list[$];
    
    initial begin
        Fruit f = new ("Apple");
        list.push_back(f);
        Fruit b = new ("Banana");
        list.push_back(b);
        
        dyn_arr list2[$]; // queue of dynamic arrays
        dyn_arr marvel = {10, 11, 15};
        dyn_arr dc = {12, 19, 15};
        list2.puch_back(marvel);
        list2.push_front(dc);
        
        foreach(list[i])
            foreach(list[i][j])
                $display("list[%0d][%0d] = %0d", i, j, list[i][j]);
    end
    
endmodule

// dynamic array

int array[];

module dyn_arr_tb;
    array = new[9]; // initialize the size
    array = new[array.size()+1] (array); // one more slot and same contents
    initial begin
    
    end
endmodule

// Associative Array












































