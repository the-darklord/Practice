module mux16to1(i,s,f);
input [15:0]i;
input [3:0]s;
output f;
wire[3:0]c;

function mux4to1;
input [3:0]i;
input [1:0]s;

case(s)
0:mux4to1=i[0];
1:mux4to1=i[1];
2:mux4to1=i[2];
3:mux4to1=i[3];

endcase

endfunction

assign c[0] = mux4to1(i[3:0],s[1:0]);
assign c[1] = mux4to1(i[7:4],s[1:0]);
assign c[2] = mux4to1(i[11:8],s[1:0]);
assign c[3] = mux4to1(i[15:12],s[1:0]);
assign f = mux4to1(c,s[3:2]);

endmodule