
// parametrization = generic class
// can be instantiated multiple ways to achieve different array sizes or data types
// avoids the needs to rewrite code
// parameters are like constants local to specified class
// can be overridden during class instantiation

class abc #(int size = 8)
    bit [size-1:0] out; // size parameter used to define out variable
endclass

// so size can be changed during instantiation

module tb;
    abc #(16) sth1; // override default value with 16
    abc #(.size (8)) sth2; // pass 8 as size to class
    
    typedef abc #(4) nibble; // define class as definition to later use or alias
    nibble nibs;
    
    // $bits(nibs.out) will return number of bits in a given variable
    
endmodule

class stack #(type T = int); // parametrized the data type
    T item;
    
    function T add_a (T a);
        return item + a;
    endfunction
    
endclass

module tb;
    stack st; // by default item is an int
    stack #(bit[3:0]) bs; // now a 4 bit value
    stack #(real) rs; // now a real number
endmodule

// virtual classes can not be directly instantiated and is an abstract class
// it's meant to be extended by other classes which can then be instantiated
// base classes are usually virtual

virtual class BaseClass;
    int data;
    function new();
        data = 5'd10;
    endfunction
endclass

class child extends BaseClass;
    bit[3:0] rate;
    
    function new();
        super.new();
        rate = 4'd3;
    endfunction
endclass

// Pure Virtual Method
// virtual function inside a virtual class
// Prototype is specified and implementation is done by child
// should have same arguments and same return type

virtual class ethernet;
    bit[4:0] rdata;
    
    pure virtual function int access_data();
    extern function void change_data(); // means definition is outside of class
endclass

class child;
    bit [7:0] rate;
    
    virtual function int access_data();
        return data;
    endfunction
endclass

function void ethernet::change_data();
    rdata = 5'd10;
endfunction

// Array manipulation
// Iterate through the array elements and each element is used to evaluate the expression
// specified by the with clause
// item is the name used by default in the expression

// with clause mandatory for find(), find_index(), find_first(), find_first_index(),
// find_last(), find_last_index()

module tb;
    int array[9] = {4, 6, 6, 16, 89, 90, 65, 1, 2};
    int res[$];
    int result;
    
    // remeber %p represents arrays
    
    initial begin
        res = array.find() with (x > 3); // returns all elements satisfying a given equation
        res  = array.find_index() with (x > 5 & x < 10); // returns index of all elements satisfying equation
        // find_first() returns first element satisfying given equation
        // find_first_index() returns first element index satisfying given equation
        // find_last() returns last element satisfying given equation
        // find_last_index() returns last element index satisfying given equation
        
        result = array.min(); // returns the minimum element in array
        result = array.max(); // returns the maximum element in array
        result = array.unique(); // returns all the unique options in array
        result = array.unique_inndex(); // returns the indices of all the unique items in array
        
        // array ordering methods
        array.reverse();
        array.sort(); // ascending order and can be used with with clause
        array.reverse(); // descending order can be used with with clause
        array.shuffle(); // randomizes the order of elements in array, cannot use with clause
        
        // array reduction methods
        result  = array.sum(); // sum of all array elements
        result  = array.product(); // product of all array elements
        // bitwise operations
        result  = array.and(); // and of all array elements
        result  = array.or(); // or of all array elements
        result  = array.xor(); // xor of all array elements
    end
endmodule

class Register;
    rand bit[4:0] data;
    rand bit[2:0] rate;
    rand bit[3:0] flags;
    string name;
    
    function new (string name)
        this.name = name;
    endfunction
    
    function void print();
        $display("name=%s, rate=%0d, data=%0d, flags=%0d\n", name, rate, data, flags);
    endfunction
endclass

module new_tb;
    Register regT[3];
    string name[3] = {"Aditya", "Matt", "Pranav"};
    
    initial begin
        foreach(regT[i]) begin
            regT[i] = new (name[i]);
            regT[i].randomize();
            regT[i].print();
        end
        
        regT.sort(x) with (x.name); // so sort this array of registers by the name
        
        foreach(regT[i])
            regT[i].print();
    end
endmodule

// next time on verilog continue here















