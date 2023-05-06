#include <iostream>

void Display(int ans)
{
	std::cout << ans << std::endl;
}

int Multiply(int a, int b)
{
	return a * b;
}

void MultiplyandDisplay(int a, int b)
{
	int ans = Multiply(a, b);
	Display(ans);
}