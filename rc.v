module rc(clock,Resetn,Q);
input clock,Resetn;
output [3:0]Q;
wire [1:0]c1;
count2 s0(clock,Resetn,c1);
dec24 s1(c1,1'b1,Q);
endmodule

module count2(clock,Resetn,y);
input clock,Resetn;
output [1:0]y;
tff s0(1'b1,clock,Resetn,y[0]);
tff s1(y[0],clock,Resetn,y[1]);
endmodule

module dec24(in,En,y);
input [1:0]in;
input En;
output reg [3:0]y;
integer i;
always @ (in)
for(i=0;i<4;i=i+1)
begin
    if(En)
        y[i]=(in==i)?1:0;
    else
        y=4'd0;
end
endmodule

module tff(T,clock,Resetn,Q);
input T,clock,Resetn;
output reg Q;
always @ (posedge clock)
begin
if(!Resetn)
	Q <= 0;
else
	if(T)
		Q <= ~Q;
	else
		Q <= Q;
end
endmodule