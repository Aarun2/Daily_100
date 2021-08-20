'timescale 1ns / 1ps
module triple_tb ();

    reg [3:0] a;

    wire [5:0] result;


    triple DUT_triple(.a(a), .result(result));

    // 0,1, 3, 5, 10, 15

    initial begin

        a = 4'd0;
        #1;
        $display("Result: %d",result);
        a = 4'd1;
        #1;
        $display("Result: %d",result);
        a = 4'd3;
        #1;
        $display("Result: %d",result);
        a = 4'd5;
        #1;
        $display("Result: %d",result);
        a = 4'd10;
        #1;
        $display("Result: %d",result);
        a = 4'd15;
        #1;
        $display("Result: %d",result);
        $stop;
    end

endmodule