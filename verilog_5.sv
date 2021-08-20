module start
endmodule
// can even have nested fork and join

fork
    // only one will be printed multiple times as no automatic keyword used in task
    print(20, "Thread1_0");
    print(30, "Thread1_1");
    print(10, "Thread2");
join

task print (int time, string t_name);
    #(time) $display("[%0t] %s\n", $time, t_name);
endtask

fork
    $display("a\n");
    $display("b\n");
    $display("c\n");
    $display("d\n");
join_any

disable fork; // kills of all active threads started by fork join to stop them from continuing

wait fork; // wait till all forked threads complete

// Assertions

assert property(@(posedge clk) a && b); // property must be true in design

// assume -> Given property is an assumption and helps generate input stimulus

// cover -> to evaluate the property for functional coverage

// restrict -> constraint on formal verification computations

// sequence -> a small event that can then be used to create properties

// property -> complex sequences, should have a clocking element to assert it

module tb;
    bit a, b, c, d;
    bit clk;
    
    always #10 clk = ~clk;
    
    initial begin
        for (int i = 0; i < 20; i++) begin
            {a, b, c, d} =  $random; // or <= $random
            $display("%0t a=%0d b=%0d c=%0d d=%0d", $time, a, b, c, d);
            @(posedge clk);
        end
        #10 $finish;
    end
    
    // so b must be high after a
    sequence s_ab
        a ##1 b;
    endsequence

    // d must be high after c
    sequence s_cd
        c ##2 d;
    endsequence

    // sequence must occur one after the other
    property p_expr
        @(posedge clk) s_ab ##1 s_cd; // this is a concurrent assertion as it is evaluated every time at the posedge clock
    endproperty
    // will always check property is true at preponed region of clock edge
    // so delta cycle before given edge of clock
    assert property (p_expr); 
endmodule

always @(a)
    // immediate assertion, executed like a statment follows the code flow
    // like an if statement during simulation
    // pass if statement is true and fail if X, Z or 0
    // simple assert statement
    // will throw error just like concurrent when fails
    $assert(!fifo_empty); // verify immediate property during simulation
    assert(!fifo_empty); //  also works
    assert () begin
        // if true do this
    end else begin
        // if false do this
    end
    a_pop : assert (! empty) begin // optional name
        $display("B");
    end else begin
        $display("A");
    end
end

// also best practice involves using
assert(m_pkt.randomize()); // so test fails in the case of error and doesn't propogate

m_pkt.randomize();

// The End



