module bcd2(x,y,cin,s,cout);
  input [7:0]x,y;
  input cin;
  output [7:0]s;
  output cout;
  wire c;
  bcd1 b0(x[3:0],y[3:0],cin,s[3:0],c);
  bcd1 b1(x[7:4],y[7:4],c,s[7:4],cout);
endmodule

module bcd1(x,y,cin,s,cout);
  input [3:0]x,y;
  input cin;
  output [3:0]s;
  output cout;
  wire[3:0]z;
  wire c,k;
  adder4 a0(x,y,cin,z,c);
  assign cout = c|(z[3]&z[2])|(z[3]&z[1]);
  adder4 a1({1'b0,cout,cout,1'b0},z,1'b0,s,k);
endmodule

module adder4(x,y,cin,s,cout);
  input [3:0]x,y;
  input cin;
  output [3:0]s;
  output cout;
  wire[2:0]c;
  fulladd s0(x[0],y[0],cin,s[0],c[0]);
  fulladd s1(x[1],y[1],c[0],s[1],c[1]);
  fulladd s2(x[2],y[2],c[1],s[2],c[2]);
  fulladd s3(x[3],y[3],c[2],s[3],cout);
endmodule

module fulladd(x,y,cin,s,cout);
  input x,y,cin;;
  output s,cout;
  assign s=x^y^cin;
  assign cout = (x&y)|(x&cin)|(y&cin);
endmodule