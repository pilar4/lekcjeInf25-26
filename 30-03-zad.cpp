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
zad 2

#include <iostream>
#include <cmath>

using namespace std;

double sqrt_bisekcja(double c, double E = 1e-6) {
    double a = 0.0;
    double b = 1.0;
    double m;

    while ((b - a) / 2 > E) {
        m = (a + b) / 2;

        if (m * m - c == 0) {
            return m;
        } else if (m * m - c < 0) {
            a = m;
        } else {
            b = m;
        }
    }

    return (a + b) / 2;
}

int main() {
    double c;
    cout << "Podaj liczbe z przedzialu (0,1): ";
    cin >> c;

    double wynik = sqrt_bisekcja(c);
    cout << "pierwiastek z " << c << " ≈ " << wynik << endl;

    return 0;
}

Zad 3
(prostokat)
#include <iostream>
#include <cmath> 
using namespace std;

float f(float x) {
  return 1.0/6*x*x*x - x*x + 0.5*x + 5.0/3.0;
}

int main() {
  float a, b, x, dx, s = 0;
  int n;
  cout << "A = "; cin >> a;
  cout << "B = "; cin >> b;
  cout << "N = "; cin >> n;
  
  dx = (b - a) / n;
  x = a;
  
  for(int i = 1; i <= n; i++) {
      x = x + dx;
      s = s + dx * abs(f(x)); 
  }
  
  cout << "Pole obszaru " << s << endl;
  return 0;
}

(trapez)
#include <iostream>
#include <cmath> // Dodana biblioteka matematyczna dla funkcji abs()
using namespace std;

float f(float x) {
  // Poprawiłem literówkę na końcu (było 5.0/0.3, jest 5.0/3.0)
  return 1.0/6*x*x*x - x*x + 0.5*x + 5.0/3.0; 
}

int main() {
  float a, b, x, dx, s = 0, f1, f2;
  int n;
  cout << "A = "; cin >> a;
  cout << "B = "; cin >> b;
  cout << "N = "; cin >> n;
  
  dx = (b - a) / n;
  x = a;
  f1 = f(x);
  
  for(int i = 1; i <= n; i++) {
      x = x + dx;
      f2 = f(x);
      // Zmiana tutaj: bierzemy wartości bezwzględne z obu podstaw trapezu (f1 i f2)
      s = s + dx * (abs(f1) + abs(f2)) / 2; 
      f1 = f2;
  }
  
  cout << "Pole obszaru " << s << endl;
  return 0;
}

zad4
P ≈ 2.98

zad5
    #include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <vector>

using namespace std;


double sqrtNewton(double x, double guess, double epsilon) {

    if (fabs(guess * guess - x) < epsilon) {
        return guess;
    }

 
    double newGuess = (guess + x / guess) / 2;

    return sqrtNewton(x, newGuess, epsilon);
}

int main() {
    double liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;

    double epsilon = 0.00001;
    double start = liczba / 2; 

    double wynik = sqrtNewton(liczba, start, epsilon);

    cout << "Przyblizony pierwiastek: " << wynik << endl;

    return 0;
}

zad7
    #include <iostream>
using namespace std;

double horner(double wsp[], int n, double x)
{
    double wynik = wsp[0];

    for (int i = 1; i <= n; i++)
    {
        wynik = wynik * x + wsp[i];
    }

    return wynik;
}

int main()
{
    int n;
    cout << "Podaj stopien wielomianu: ";
    cin >> n;

    double wsp[n + 1];

    cout << "Podaj wspolczynniki od najwyzszej potegi:\n";
    for (int i = 0; i <= n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> wsp[i];
    }

    double a, b;
    cout << "Podaj przedzial [a, b]: ";
    cin >> a >> b;

    double eps = 0.0001;

    if (horner(wsp, n, a) * horner(wsp, n, b) > 0)
    {
        cout << "Brak miejsca zerowego w tym przedziale.\n";
        return 0;
    }

    double s;

    while ((b - a) > eps)
    {
        s = (a + b) / 2.0;

        if (horner(wsp, n, s) == 0)
        {
            break;
        }

        if (horner(wsp, n, a) * horner(wsp, n, s) < 0)
        {
            b = s;
        }
        else
        {
            a = s;
        }
    }

    cout << "Przyblizone miejsce zerowe: " << (a + b) / 2.0 << endl;

    return 0;
}
zad 8
#include <iostream>
using namespace std;

double times_three(double n){
    return n*n*n;
}

int main()
{
    int n;
    cin >> n;

    double nbli;
    for(double i=0;i<n;i = i+1){
        if(times_three(i)<n)
            nbli=i;
        else if (times_three(i)==n){
            cout<<"wynik pierwiastka 3 stopnia to: "<<i<<endl;
            return 0;
        }
    }
    double i=nbli;
    while(times_three(i)<n){
        i = i + 0.0001;
    }

    cout<<"wynik pierwiastka 3 stopnia to: "<<i<<endl;

    return 0;
}


zad9
P ≈ 12.57

Zad 10 (wkleicc to do exela 1 komorki)
Krok	Kąt (radiany)	X	Y
0		0	0
1	=LOS()*2*PI()	=C2+COS(B3)	=D2+SIN(B3)
2	=LOS()*2*PI()	=C3+COS(B4)	=D3+SIN(B4)
3	=LOS()*2*PI()	=C4+COS(B5)	=D4+SIN(B5)
4	=LOS()*2*PI()	=C5+COS(B6)	=D5+SIN(B6)
5	=LOS()*2*PI()	=C6+COS(B7)	=D6+SIN(B7)
6	=LOS()*2*PI()	=C7+COS(B8)	=D7+SIN(B8)
7	=LOS()*2*PI()	=C8+COS(B9)	=D8+SIN(B9)
8	=LOS()*2*PI()	=C9+COS(B10)	=D9+SIN(B10)
9	=LOS()*2*PI()	=C10+COS(B11)	=D10+SIN(B11)
10	=LOS()*2*PI()	=C11+COS(B12)	=D11+SIN(B12)

zad 11

P ≈ 0.67
