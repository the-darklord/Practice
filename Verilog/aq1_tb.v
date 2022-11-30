`timescale 1ns/1ns
`include "aq1.v"
module aq1_tb();
reg a,b,c,d;
wire f;
aq1 a0(a,b,c,d,f);
initial
begin
$dumpfile("aq1_tb.vcd");
$dumpvars(0,aq1_tb);
a=1'b1; b=1'b1; c=1'b1; d=1'b1; #20;
$display("Test Complete");
end
endmodule