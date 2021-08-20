constraint c_array { foreach (array[i]) {
                        array[i] == i;
                        }
                    }
// Array Reduction Iterative Constraint
// single value used as constraint
constraint c_sum { array.sum() with (int (item)) == 20} // so sum of items in array need to be 20

constraint no_repeat {unique {nibbles};} // unique values to all items in array

randc // for repeat after cycling through all values

constraint c_ab {a -> b == 3'h3; } // problem is a and b are determined together
// so probability of both is taken into account not individually

constraint c_ab {a -> b == 3'h3; 
                 solve a before b;} // so this way probabilities are separated

// Exceptions randc variables are not allowed as they are always solved first
// should be integral values
// no circular dependency solve a before b and solve b before a

// static and constraint_mode()
// when mode turned off on non static constraint only that instance constraint turnned off
// when mode turned off on static constraint turned off for all instances
// as static is shared between instances

static constraint c_arr {arr[10] == 5;};

ABC obj1 = new;
obj1.c1.constraint_mode(0); // turn off constraint

// Memory Partitioning

// Bus Constraints

// inline constraints
bt.randomize() with {m_addr >= slave_start;}; // like a constraint

// randomize() returns 0 if failed else 1
// can fail due to conflicting constraints, solver couldn't come up with a value

class Beverage;
    rand bit [7:0] beer_id;
    
    constraint c_beer_id {};
    
    // overriding randomize functions
    // can't declare as virtual as already are virtual
    
    function void pre_randomize();
        $display("Called before randomize\n");
    endfunction
    
    // not called if randomize fails
    function void post_randomize();
        $display("Called after randomize\n");
    endfunction
endclass

constraint restrict_soft {soft m_data >= 4;};
// soft constraint so if conflict

bt.randomize() with {m_data == 2; }; // will allow and data is always 2

// if it was a hard constraint solver would fail

bt.restrict_soft.constraint_mode(0); // turn off constraint or on with 1

status = bt.restrict_soft.constraint_mode(); // to get constraint mode status 0 or 1

bt.beer_id.rand_mode(0) // To disable random variable randomization and 1 otherwise

// rand_mode() to check if enabled

// weights and that decides their probability
// 1/9 for the first in this case
// if 0 branch not taken
// to randomize branch ti take
// al zero's results in a runtime warning
for (int i = 0; i < 10; i++)
    randcase
        1 : $display("Wt 1");
        3 : $display("Wt 5");
        5 : $display("Wt 3");
    endcase
end

// system verilog threads

module tb_top
    initial begin
        fork
            // all single lines are threads
            $display("Thread 1\n");
            begin
                $display("Thread 2\n");
                $display("Also, Thread 2\n");
            end
            $display("Thread 3\n");
        join
    end
endmodule

fork
join_any // waits until any one of the threads completes

fork
join_none // doesn't wait for any thread and runs in the background






















// The end