module decoder3to8(in,En,y);
input [2:0]in;
input En;
output reg [0:7]y;
integer i;
reg [2:0]c=0;
always @ (in,c)
begin
for(i=0;i<8;i=i+1)
begin
if(En)
begin
y[i]=(in==c)?1:0;
end
else
begin
y[i]=0;
end
c=c+3'b001;
end
end
endmodule