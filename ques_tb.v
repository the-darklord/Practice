`timescale 1ns/1ns
`include "ques.v"

module ques_tb();
reg [2:0]i;
reg En;
wire f1,f2,f3;

ques d0(i,En,f1,f2,f3);

initial
begin

$dumpfile("ques_tb.vcd");
$dumpvars(0,ques_tb);

En=1'b1; i=3'b011; #20;
En=1'b1; i=3'b111; #20;

En=1'b0; i=3'b011; #20;

$display("Test Complete");

end
endmodule