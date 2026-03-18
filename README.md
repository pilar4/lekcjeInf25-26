Archiwizacja
wszystkich
kodow
z
informatyki 
2
0
2
5
/
2
0
2
6


## disclaimer: I, nor any contributor take responsibility for abominations you can find here 


brakuje nam 1, 3, 10, 12, 13, 14, 16, 17, 19, 24, 26, 31


#include <iostream>
#include <cmath>
using namespace std;

const float EPS = 0.0000001;

int main()
{
    float a, b, c, delta, pdelta, x1, x2;

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