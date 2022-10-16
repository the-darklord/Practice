module mux2to1(i,f);
input [3:0]i;
output f;
wire [2:0]s;
assign s[2]=i[2]^i[1];
assign s[1]=~i[3]&i[0];
assign s[0]=~s[1];

twotoone stage0(s[1:0],s[2],f);

endmodule

module twotoone(i,s,f);
input [1:0]i;
input s;
output f;
reg f;
always @(i,s)
begin
if(s)
f=i[1];
else
f=i[0];
end
endmodule