`timescale 1ns/1ns
`include "bcd2.v"

module bcd2_tb();
  reg[7:0]x,y;
  reg cin;
  wire[7:0]s;
  wire cout;
  
  bcd2 f0(x,y,cin,s,cout);
  initial
    begin
      $dumpfile("bcd2_tb.vcd");
      $dumpvars(0,bcd2_tb);
      
      cin=1'b0;
      x=8'b00010010; y=8'b00100011; #40;
      x=8'b01110101; y=8'b00110101; #40;
      
      $display("Test Complete");
    end
endmodule