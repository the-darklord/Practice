`timescale 1ns/1ns
`include "mux2to1.v"

module mux2to1_tb();
reg [3:0]i;
wire f;

mux2to1 s0(i,f);

initial
begin
$dumpfile("mux2to1_tb.vcd");
$dumpvars(0,mux2to1_tb);

i=4'b1010; #20;
i=4'b0101; #20;

$display("Test Complete");
end
endmodule