module ques(in,En,f1,f2,f3);
input [2:0]in;
input En;
output f1,f2,f3;
reg [0:7]y;
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

assign f1=y[2]|y[5]|y[7];
assign f2=y[2]|y[3]|y[5];
assign f3=y[1]|y[6]|y[7];

endmodule