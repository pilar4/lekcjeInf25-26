zad 1
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const float EPS = 0.0001;

float f(float x)
{
    return x*x - 4;
}

int main()
{
    float a, b, x0, fa, fb, fx0;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;

    fa = f(a);
    fb = f(b);

    if (fa * fb >= 0)
    {
        cout << "Wartosci funkcji dla koncow przedzialu ";
        cout << "nie maja roznych znakow" << endl;
        return 0;
    }

    x0 = (a + b) / 2;
    fx0 = f(x0);

    while (abs(fx0) > EPS && (b - a) > EPS)
    {
        if (fa * fx0 < 0)
        {
            b = x0;
            fb = fx0;
        }
        else
        {
            a = x0;
            fa = fx0;
        }
        x0 = (a + b) / 2;
        fx0 = f(x0);
    }
    cout << "x0 = " << x0 << endl;
    return 0;
}


zad4
P ≈ 2.98

zad9
P ≈ 12.57
