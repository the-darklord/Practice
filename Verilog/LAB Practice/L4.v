module onesin6(x,f);
input[5:0]x;
output[2:0]f;
wire c1,c2,s1,s2,c3;
fadder o0(x[0],x[1],x[2],s1,c1);
fadder o1(x[3],x[4],x[5],s2,c2);
fadder o2(s1,s2,1'b0,f[0],c3);
fadder o3(c1,c2,c3,f[1],f[2]);
endmodule

module bcd(x,y,s,Cout);
input[3:0]x,y;
output[3:0]s;
output Cout;
wire[3:0]z;
wire c,cc;
add_sub_4 b0(x,y,1'b0,z,c);
assign Cout=c|(z[3]&z[2]|z[3]&z[1]);
add_sub_4 b1({1'b0,cc,cc,1'b0},z,1'b0,s,cc);
endmodule

module mult2(x,y,p);
input[1:0]x,y;
output[3:0]p;
assign p[0]=x[0]&y[0];
adder2 m0({x[1]&y[1],x[0]&y[1]},{1'b0,x[1]&y[0]},1'b0,p[2:1],p[3]);
endmodule

module adder2(x,y,Cin,s,Cout);
input[1:0]x,y;
input Cin;
output[1:0]s;
output Cout;
wire c;
fadder a0(x[0],y[0],Cin,s[0],c);
fadder a1(x[1],y[1],c,s[1],Cout);
endmodule


module add_sub_4(x,y,Cin,s,Cout);
input [3:0]x,y;
input Cin;
output[3:0]s;
output Cout;
integer i;
wire [3:0]Y;
wire[2:0]c;
assign Y[0]=y[0]^Cin;
assign Y[1]=y[1]^Cin;
assign Y[2]=y[2]^Cin;
assign Y[3]=y[3]^Cin;
fadder s0(x[0],Y[0],Cin,s[0],c[0]);
fadder s1(x[1],Y[1],c[0],s[1],c[1]);
fadder s2(x[2],Y[2],c[1],s[2],c[2]);
fadder s3(x[3],Y[3],c[2],s[3],Cout);
endmodule

module fadder(x,y,Cin,s,Cout);
input x,y,Cin;
output s,Cout;
assign s = x^y^Cin;
assign Cout=(x&y)|(y&Cin)|(x&Cin);
endmodule