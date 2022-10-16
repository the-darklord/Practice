`timescale 1ns/1ns
`include "q1.v"
module q1_tb();
reg [3:0]c,d;
wire aeqb,agtb,altb;
signedcomp4 signedcomp4(c,d,aeqb,agtb,altb);
initial
begin
$dumpfile("q1_tb.vcd");
$dumpvars(0,q1_tb);
c=4'b1001; d=4'b1001; #20;
c=4'b1010; d=4'b1001; #20;
c=4'b0010; d=4'b0001; #20;
c=4'b1010; d=4'b0001; #20;
c=4'b0010; d=4'b1001; #20;
c=4'b0010; d=4'b0010; #20;
$display("Test Complete");
end
endmodule