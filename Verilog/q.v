module q;
integer a=10,i;
real f = 10.75;
time c;
reg [8*5:1] str1;
reg [8*10:1] str2;
reg [8*20:1] str3;
integer arr[3:0];
initial
begin
#20;
#20;
c=$time;
str1="Mihir Nath";
str2="Mihir Nath";
str3="Mihir Nath";
arr[0]=5;
arr[1]=10;
arr[2]=1023;
arr[3]=10100101;
$display("Hello World\n%d\n%.2f\n%t\n%s\n%s\n%s",a,f,c,str1,str2,str3);
for(i=0;i<4;i=i+1)
begin
    $display("arr[%0d] = %0d",i,arr[i]);
end
end
endmodule