`timescale 1ns/1ns
`include "fib.v"

module fib_tb();
reg clock, reset;
reg [4:0] n;
wire ready;
wire [12:0] value;

fib fib(clock,reset,n,ready,value);

initial begin
$dumpfile("fib_tb.vcd");
$dumpvars(0,fib_tb);

clock=0;
forever #10 clock=~clock;
end

initial begin
n=5'd20;
reset=1; #40;
reset=0; #420;
$display("Test Complete");
$finish;
end

endmodule