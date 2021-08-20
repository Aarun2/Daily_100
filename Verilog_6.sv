module start_tb (input clk, 
'ifdef INCLUDE_RSTN // so a compiler directive that includes a piece of code till the next else or endif
    input rstn;
'endif // as seen here, the give macro should be defined using the 'define directive
// 'ifndef is used like ifdef only if not defined by 'define directive
// Another example

'ifdef INCLUDE_RSTN
    .rstn(rstn),
'endif 
)
endmodule
// $display appends a new line to the end of text
// $write does not
$write("I liked the woman I just saw, she seemed to be a fun person\n");

a = 10;
b = 9;

b <= a + 1;

$display("b=0x%0h", b); // shows b is 9
$strobe("b=0x%0h", b); // shows b is 10

#1;

$display("b=0x%0h", b); // shows b is 10
$strobe("b=0x%0h", b); // shows b is 10

// so strobe always shows the final value but display shows the value at that time

$monitor("Prints value whenever varibale changes 0x%0h", a);
// a task that runs in the background and monitors and displays value

// h, d, b, m, s, t, f, e
// hexadecimal, decimal, binary, hierarchical name, string, time format, real in decimal format, exponential in

module tb;
    bit a, clk;
    
    sequence s_a
        @(posedge clk) $rose(a); // posedge of a should be seen at every posedge of clk
    endsequence
    // so checks for 0 on first edge and 1 on next edge
    
    sequence s_b
        @(posedge clk) $fell(a); // negedge of a should be seen at every posedge of clk
    endsequence
    // once again checks for 1 then 0 at the various edges
    
    assert property(s_a);
    
    // @(posedge clk) $stable(a); // so a should be stable at posedge of clk no fluctuations
    // a ##1 b; // once a is high b should be high 1 clock cycle later
endmodule

// Functional Coverage
    // measure of what functionalities/features have been exercised by the tests
    // useful in constrained random verification (CRV) to know what features have been covered by a set of tests
    // in regression
    
    // covergroups
    
class myTrns;
    rand bit [3:0] mode;
    rand bit [1:0] key;
    
    function display();
        $display("[%0tns] mode = 0x%0h, key = 0x%0h", $time, mode, key);
    endfunction
    
    // Coverpoints create a covergroup
    // Multiple covergroups can be created to sample variables with different set of bins
    covergroup CovGrp; // variables are mentioned as coverpoints
        coverpoint mode { // bins are hit/covered when variable reaches the corresponding values
            bins featureA = {0};
            bins featureB = {[1:3]};
            bins common [] = {4:$}; // 12 bins one for each value from 4 to F
            bins reserve = default; // a bin if variable reaches any other value
        }
        coverpoint key;
    endgroup
    
    covergroup CovGrp;
        coverpoint mode iff (!reset) { // conditional cover mode if and only if not of reset
            // bins to add
        }
    endgroup
    
endclass

// Way #1 to begin sampling
module tb_top;
    myTrns myCov0 = new ();
    
    initial begin
        myCov0.CovGrp.sample(); // triggers coverage collection in a covergroup
        // another way for conditional coverage
        if (reset)
            myCov0.stop();
        else if (!reset)
            myCov0.start();
    end
endmodule
    
// Way #2 to begin sampling mention event to begin sampling
covergroup CovGrp @ (posedge clk);
covergroup CovGrp @ (eventA); // trigger with ->eventA

// next time on verilog code