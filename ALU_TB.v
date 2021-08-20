`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2019 09:22:35 PM
// Design Name: 
// Module Name: ALU_TB
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module ALU_TB();
  reg [3:0] a;
  reg [3:0] b;
  reg [1:0] op;
  wire [7:0] res;
  
  ALU DUT_ALU(a,b,op,res);
  
  initial begin
    a = 5;
    b = 3;
    op = 0;
    #2
    if (res != 8) begin
        $display("Error\n");
        $stop;
    end
    op = 1;
    #2
    if (res != 15) begin
        $display("Error\n");
        $stop;
    end
    op = 2;
    #2
    if (res != 2) begin
        $display("Error\n");
        $stop;
    end
    op = 3;
    #2
    if (res != 1) begin
        $display("Error\n");
        $stop;
    end
    $display("Success!\n"); 
    $stop;
  end
endmodule
