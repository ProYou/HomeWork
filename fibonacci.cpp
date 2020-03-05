#include<iostream>
using namespace std;
int Fibonacci_of(int n) 
{ 
	int a = 1, b = 1, temp;
	if (n == 1 || n == 2)
		return b;
	for (int i = 3; i <= n; i++) {
		temp = b;
		b = a + b;
		a = temp;
	}
	return b;
}

int main() 
{	int a = 0; 
	for (int i = 1; i <= 200; i++) 
	{ 
		a = Fibonacci_of(i); 
		cout << "Fibonacci_of" << "(" << i << ")" << a << endl;
	} 
	return 0;
}