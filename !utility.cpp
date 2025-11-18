#include <iostream>

using namespace std;

int x, y;

int euklides(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        x = x1; x1 = x - q * x1;
        y = y1; y1 = y - q * y1;
        a1 = b1; b1 = a1 - q * b1;
    }
    return a1;
}

int main()
{
	x = 1, y = 0;
	int a, b;
	
	cout<<"Podaj liczby: ";
	cin>>a>>b;
	
	euklides(a, b, x, y);
	
	cout<<"nwd("<<a<<", "<<b<<") = "
	<<a<<" * "<<x<<" + "<<b<<" * "<<y<<" = "
	<<a*x+b*y<<endl;
	
	return 0;
}
