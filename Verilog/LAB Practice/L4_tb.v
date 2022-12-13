`timescale  1ns/1ns
`include "L4.v"

module L4_tb();
//reg[3:0]x,y;
//reg Cin;
//wire[3:0]s;
//wire Cout;
//add_sub_4 f0(x,y,Cin,s,Cout);

// reg[1:0]x,y;
// wire[3:0]p;
// mult2 f1(x,y,p);

// reg[3:0]x,y;
// wire[3:0]s;
// wire Cout;
// bcd f2(x,y,s,Cout);

reg[5:0] x;
wire[2:0]f;

onesin6 f3(x,f);

initial begin
    $dumpfile("L4_tb.vcd");
    $dumpvars(0,L4_tb);

    // x=4'd9; y=4'd5;
    // Cin=1'b0; #20;
    // Cin=1'b1; #20;

    // x=2'd2; y=2'd3; #20;
    // x=2'd3; y=2'd3; #20;

    // x=4'b0111; y=4'b1001; #20;
    // x=4'b0011; y=4'b0101; #20;

    x=6'd20; #40;
    x=6'd60; #40;

    $display("Test Complete");
end

endmodule