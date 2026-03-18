zad1
0,00156
zad2
  #include <iostream>
#include <iomanip>
using namespace std;

const float EPS = 0.0000001;

int main() { float a, b, c, delta, pdelta, x1, x2;

cout << "a = "; cin >> a;
cout << "b = "; cin >> b;
cout << "c = "; cin >> c;

delta = b*b - 4*a*c;

if (delta < 0){
    cout << "Brak pierwiastkow";
}
else if (delta=0)
{
    (-b)/(2*a);
}
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

zad3
zad 3

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a, b, c, delta, pdelta, x1, x2;
    cin>>a;cin>>b;cin>>c;

    delta=b*b-4*a*c;

    if(delta<0){
        cout<<"nie ma "<<endl;
    }
    else{
        pdelta=sqrt(delta);
        x1=(-b-pdelta)/(2*a);
        x2=(-b+pdelta)/(2*a);
        cout<<"x1 = "<<x1<<endl;
        cout<<"x2 = "<<x2<<endl	;
    }

    return 0;
}
