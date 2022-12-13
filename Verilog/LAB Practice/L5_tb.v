`timescale  1ns/1ns
`include "L5.v"

module L5_tb();

// reg[4:0]a,b;
// wire aeqb,agtb,altb;
// comp5 f0(a,b,aeqb,agtb,altb);

parameter n=4;

// reg[n-1:0]g;
// wire[n-1:0]b;
// greytobin f1(g,b);

reg[n-1:0]b;
wire[n-1:0]g;
bintogrey f2(b,g);

initial begin
    $dumpfile("L5_tb.vcd");
    $dumpvars(0,L5_tb);

    // a=5'd10; b=5'd30; #20;
    // a=5'd10; b=5'd10; #20;
    // a=5'd30; b=5'd10; #20;

    // g=4'b0100; #20;
    // g=4'b0110; #20;

    b=4'b0111; #40;
    b=4'b0101; #40;

    $display("Test Complete");
end

endmodule