// module signedcomp4(a,b,aeqb,agtb,altb);
// input[3:0]a,b;
// output aeqb,agtb,altb;
// endmodule

module bintogrey(b,g);
parameter n=4;
input[n-1:0]b;
output reg [n-1:0]g;
integer i;

always @ (g,b)
begin
    g[n-1]=b[n-1];
    for(i=n-2;i>=0;i=i-1)
    begin
        g[i]=b[i]^b[i+1];
    end
end
endmodule

module greytobin(g,b);
parameter n=4;
input[n-1:0]g;
output reg [n-1:0]b;
integer i;

always @(g,b)
begin
    b[n-1]=g[n-1];
    for(i=n-2;i>=0;i=i-1)
    begin
        b[i]=b[i+1]^g[i];
    end
end

endmodule

module comp5(a,b,aeqb,agtb,altb);
input[4:0]a,b;
output aeqb,agtb,altb;
wire[9:0]c;
assign c[0]=~(a[0]^b[0]);
assign c[1]=~(a[1]^b[1]);
assign c[2]=~(a[2]^b[2]);
assign c[3]=~(a[3]^b[3]);
assign c[4]=~(a[4]^b[4]);
assign c[5]=a[0]&~b[0];
assign c[6]=a[1]&~b[1];
assign c[7]=a[2]&~b[2];
assign c[8]=a[3]&~b[3];
assign c[9]=a[4]&~b[4];

assign aeqb=c[0]&c[1]&c[2]&c[3]&c[4];
assign agtb=c[9]|(c[4]&c[8])|(c[4]&c[3]&c[7])|(c[4]&c[3]&c[2]&c[6])|(c[4]&c[3]&c[2]&c[1]&c[5]);
assign altb=~(aeqb|agtb);

endmodule