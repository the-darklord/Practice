`timescale 1ns/1ns
`include "rc.v"
module rc_tb();
reg clock, Resetn;
wire[3:0] Q;
rc f1(clock,Resetn, Q);

initial
begin
$dumpfile("rc_tb.vcd");
$dumpvars(0, rc_tb);
clock=0;
forever #10 clock = ~clock;
end

initial
begin
Resetn=0; #20;
Resetn=1; #300;
$display("Test complete");
$finish;
end

endmodule