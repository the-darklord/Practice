`timescale 1ns/1ns
`include "L6.v"

module L6_tb();
reg[15:0]i;
reg[3:0]s;
wire f;
integer j;

mux16to1 m0(i,s,f);
initial
begin
    $dumpfile("L6_tb.vcd");
    $dumpvars(0,L6_tb);

    i=16'hAFAF;
    for(j=0;j<16;j=j+1)
    begin
        s=j; #20;
    end

    $display("Test Complete");
end
endmodule