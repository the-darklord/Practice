module decoder3to8(i,En,y);
input [2:0]i;
input En;
output [0:7]y;

assign y[0] = (En&~i[2]&~i[1]&~i[0]);
assign y[1] = (En&~i[2]&~i[1]&i[0]);
assign y[2] = (En&~i[2]&i[1]&~i[0]);
assign y[3] = (En&~i[2]&i[1]&i[0]);
assign y[4] = (En&i[2]&~i[1]&~i[0]);
assign y[5] = (En&i[2]&~i[1]&i[0]);
assign y[6] = (En&i[2]&i[1]&~i[0]);
assign y[7] = (En&i[2]&i[1]&i[0]);

endmodule