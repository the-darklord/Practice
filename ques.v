module ques(i,En,f1,f2,f3);
input [2:0]i;
input En;
output f1,f2,f3;
wire [0:7]y;

assign y[0] = (En&~i[2]&~i[1]&~i[0]);
assign y[1] = (En&~i[2]&~i[1]&i[0]);
assign y[2] = (En&~i[2]&i[1]&~i[0]);
assign y[3] = (En&~i[2]&i[1]&i[0]);
assign y[4] = (En&i[2]&~i[1]&~i[0]);
assign y[5] = (En&i[2]&~i[1]&i[0]);
assign y[6] = (En&i[2]&i[1]&~i[0]);
assign y[7] = (En&i[2]&i[1]&i[0]);

assign f1=y[2]|y[5]|y[7];
assign f2=y[2]|y[3]|y[5];
assign f3=y[1]|y[6]|y[7];

endmodule