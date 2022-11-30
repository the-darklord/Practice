`timescale 1ns/1ns
`include "decoder3to8.v"

module decoder3to8_tb();
reg [2:0]in;
reg En;
wire [0:7]y;

decoder3to8 d0(in,En,y);

initial
begin

$dumpfile("decoder3to8_tb.vcd");
$dumpvars(0,decoder3to8_tb);

En=1'b1; in=3'b011; #20;
En=1'b1; in=3'b111; #20;

En=1'b0; in=3'b011; #20;

$display("Test Complete");

end
endmodule