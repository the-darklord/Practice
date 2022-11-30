module signedcomp4(a,b,aeqb,agtb,altb);
input [3:0]a,b;
inout aeqb,agtb,altb;
reg [3:0]c,d;
always@(a,b)
begin
    if(a[3]==0&&b[3]==0)
    begin
        c = a;
        d = b;
    end
    else if(a[3]==1&&b[3]==1)
    begin
        d = ~a + 4'b0001;
        c = ~b + 4'b0001;
    end
    else if(a[3]==1&&b[3]==0)
    begin
        d = ~a + 4'b0001;
        c = b;
    end
    else if(a[3]==0&&b[3]==1)
    begin
        d  =a;
        c = ~b + 4'b0001;
    end
end
comp3 stage0(c[2:0],d[2:0],aeqb,agtb,altb);
endmodule

module comp3(a,b,aeqb,agtb,altb);
input [2:0]a,b;
inout aeqb,agtb,altb;
wire [5:0]s;
assign s[0]=~(a[2]^b[2]);
assign s[1]=~(a[1]^b[1]);
assign s[2]=~(a[0]^b[0]);
assign s[3]=a[2]&~b[2];
assign s[4]=a[1]&~b[1];
assign s[5]=a[0]&~b[0];
assign aeqb = s[0]&s[1]&s[2];
assign agtb = s[3]|(s[0]&s[4])|(s[0]&s[1]&s[5]);
assign altb = ~(aeqb|agtb);
endmodule