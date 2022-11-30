module fib(input clock, reset, input [4:0] n, output reg ready, output [12:0] value);

reg [12:0] previous, current,counter;

always @(posedge reset)
    begin
        previous <= 12'd0;
        current <= 12'd1;
        counter <= 5'd1;
		ready<=0;
    end
	
always @(posedge clock)
    begin
        if (counter == n)
           ready <= 1;
		else
		begin
			counter <= counter + 1;
			current <= current + previous;
			previous <= current;
		end
    end

assign value = previous;

endmodule