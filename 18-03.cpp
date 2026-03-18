cw 1
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x=0;
    while (x<1.01){
        cout<<setprecision(10)<<fixed<<x<<endl;
        x = x + 0.1;
    }

    return 0;
}

cw 3. 

    a = 2147483648
	b = 5
	c = 2
cw 4.

#include <iostream>
#include <iomanip>
using namespace std;

const float EPS = 0.0000001;

int main() { float a, b, c, delta, pdelta, x1, x2;

cout << "a = "; cin >> a;
cout << "b = "; cin >> b;
cout << "c = "; cin >> c;

delta = b*b - 4*a*c;

if (delta < 0)
    cout << "Brak pierwiastkow";
else
{
    pdelta = sqrt(delta);

    if (b > 0)
        x1 = (-b - pdelta) / (2 * a);
    else
        x1 = (-b + pdelta) / (2 * a);

    if (abs(x1) > EPS)
        x2 = c / (a * x1);
    else
        x2 = 0;

    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2;
}

return 0;
}
