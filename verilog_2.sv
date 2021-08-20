// Associative Arrays
int a2[string]; // string key and int value
// Methods

module Assoc_tb;
    int fruits[string];
    initial begin
        fruits = {"apple" : 5, "orange" : 10};
        $display("Size: %0d", fruits.size());
        $display("Size: %0d", fruits.num());
        // delete index or whole
        if (fruits.exists("apple"))
            $display("Apple: %0d", fruits("apple"));
        else
            $display("Item not found\n");
        string f;
        if (fruits.first(f)) // store key of first in f, returns 1 if succeeded
            $display("First is %s with value %0d", f, fruits[f]);
        else
            $display("Empty Array\n");
        if (fruits.last(f)) // store key of last in f, returns 1 if succeeded
            $display("First is %s with value %0d", f, fruits[f]);
        else
            $display("Empty Array\n");
        // f = some key
        // .next(f) next smallest index with value larger than current
        // .prev(f) next largest index with value smaller than current
    end
endmodule

// Dynamic Array of Assoc Array

module dyn_assoc_tb;
    int fruits[][string];
    
    initial begin
        fruits[0]= {"apple": 1, "grape" : 2};
        fruits[1]= {"banana": 10, "grape" : 2};
        foreach(fruits[i])
            foreach(fruits[i][fruit])
                $display("fruits[%0d][%s] = %0d", i, fruit, fruit[i][fruit]);
    end
endmodule

// Associative array of dynamic array
// so value is dynamic array and key is int or string or whatever

typedef int int_da[];

module AA_DA_tb;
    int_da fruits [string];
    initial begin
        fruits["Apple"] = new [2];
        fruits["Apple"] = {4, 5};
        
        foreach(fruits[str1])
            foreach(fruits[str1][i])
                $display("Fruits[%s][%0d] = %0d", str1, i, fruits[str1][i]);
    end
endmodule

class Packet;
    rand bit [3:0] queue[$];
    
    constraint c_array {queue.size() == 4;};
endclass

module const_tb;
    Packet pkt;
    
    initial begin
        pkt = new();
        pkt.randomize();
        
        $display("queue = %p", pkt.queue);
    end  
endmodule

// Constraint Examples

class myClass;
    rand bit [3:0] min, typ, max;
    rand bit [3:0] fixed;
    
    constraint my_range {3 < min;};
    
    constraint c_fixed {fixed == 5;};
    
    constraint new_range {typ inside {[32:256]}; }; // inside this range inclusive
    
    constraint spec_range {typ inside {32, 64, 128}; }; // one of the following values
    
    constraint new_range {! (min inside [4:9]) ;}; // anything other than those values
    
    constraint dist1 {typ dist {0:=20, [1:5]:=50};}; // weights for each value fixed
    
    constraint dist2 {typ dist {0:/20, [1:5]:/50};}; // divide weights equally in range
    
    function string display();
        return $sformatf ("min=%0d, typ=%0d, max=%0d, fixed=%0d", min, typ, max, fixed);
    endfunction

endclass

module tb;
    initial begin
        myClass test = new();
         for (int i = 0; i < 10; i++)
            test.randomize();
            $display("%s\n", test.display());
         end
    end

endmodule

if (m_data inside {[4:100]})

constraint c_var {m_var inside {4, 5, 9, 10};};
constraint c_var { !(m_var inside {4, 5, 9, 10});};

constraint c_mode {mode == 2 -> len > 10 }; // if mode is 2 length should be greater than 10
// so if mode is 2 length must be greater than 10
// else for any other case length can be anything

// if else works using curly brackets

// foreach for dynamic arrays(can be any size) and queues(infinite size)
// must constrain size and then foreach loop
// or assign size

constraint c_qsize {queue.size() == 5};

// or

function new();
    darray = new [5];
endfunction

constraint c_array { foreach(queue[i])
                        queue[i] == i;
                    foreach(darray[i])
                        darray[i] == i;
}

rand bit [3:0] md_array[][];

constraint md_arr {
    // set the size for each
    md_array.size() == 2;
    
    foreach (md_array[i]) {
        // set the size for each
        md_array[i].size() == 2;
        foreach (md_array[i][j]) {
            md_array[i][j] == 10; // the actual constraint
        }
    }
}


// the end























