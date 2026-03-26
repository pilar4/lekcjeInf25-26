ćw.1
#include <iostream>
#include <cmath>

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

ćw.2
#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 0.0001;

double f(double t, double x)
{
    return t * t - x;
}

int main()
{
    double x;
    cout << "Podaj liczbe x > 1: ";
    cin >> x;

    if (x <= 1)
    {
        cout << "`niepoprawna liczba" << endl;
        return 0;
    }

    double a = 1;
    double b = x;
    double x0, fa, fb, fx0;

    fa = f(a, x);
    fb = f(b, x);

    x0 = (a + b) / 2;
    fx0 = f(x0, x);

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
        fx0 = f(x0, x);
    }

    cout << "Przyblizony pierwiastek = " << x0 << endl;

    return 0;
}

cw3
#include <iostream>
#include <cmath>
using namespace std;

double pierwiastek(double a)
{
    double x = a;
    const double eps = 0.000001;

    while (fabs(x * x - a) > eps)
    {
        x = 0.5 * (x + a / x);
    }

    return x;
}

int main()
{
    double a;
    cout << "Podaj liczbe dodatnia: ";
    cin >> a;

    cout << "Pierwiastek = " << pierwiastek(a) << endl;

    return 0;
}

cw5
#include <iostream>
#include <vector>
using namespace std;

float f(float x){
    return 1.0/6*x*x*x-x*x+0.5*x+5.0/3.0;
}

int main()
{
    float a, b, x, dx, s=0;
    int n;
    cout<<"A = "; cin>>a;
    cout<<"B = "; cin>>b;
    cout<<"N = "; cin>>n;
    dx=(b-a)/n;
    x=a;
    for(int i=1;i<=n;i++){
        x=x+dx;
        s=s+dx*f(x);
    }
    cout<<"Pole obszaru "<<s;
    cout<<endl;
    return 0;
}


cw6
#include <iostream>
#include <vector>
using namespace std;




float f(float x){
  return 1.0/6*x*x*x-x*x+0.5*x+5.0/3.0;
}




int main()
{
  float a, b, x, dx, s=0, f1, f2;
  int n;
  cout<<"A = "; cin>>a;
  cout<<"B = "; cin>>b;
  cout<<"N = "; cin>>n;
  dx=(b-a)/n;
  x=a;
  f1=f(x);
  for(int i=1;i<=n;i++){
      x=x+dx;
      f2=f(x);
      s=s+dx*(f1+f2)/2;
      f1=f2;
  }
  cout<<"Pole obszaru "<<s;
  cout<<endl;
  return 0;
}
