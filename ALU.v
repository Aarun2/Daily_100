`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/03/2019 09:19:27 PM
// Design Name: 
// Module Name: ALU
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


module ALU(
    input  [3:0] a,
    input  [3:0] b,
    input  [1:0] op,
    output [7:0] result
    );
  // Write your code here
  // 0: Add
  // 1: Mult
  // 2: Modulo
  // 3: AND
  wire [3:0] add, mult, mod, b_and;
  
  assign add = a + b;
  assign mult = a * b;
  assign mod = a % b;
  assign b_and = a & b;
  
  assign result = (op == 2'd0) ? {4'd0, add} : (op == 2'd1) ? mult : (op == 2'd2) ? {4'd0, mod} :
                  {4'd0, b_and};

endmodule
