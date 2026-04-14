zadanie 1
#include <iostream> 
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

struct punkt
{
    float x, y;
};

void CzytajPkt(string info, punkt &P)
{
    cout<<info<<endl;
    cout<<"x = "; cin>>P.x;
    cout<<"y = "; cin>>P.y;
}

float PoleTroj(punkt a, punkt b, punkt c){
    return 0.5*(abs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y)));
}

int main(){
    punkt a, b, c;
    CzytajPkt("Podaj wspolrzedne punktu a. ", a);
    CzytajPkt("Podaj wspolrzedne punktu b. ", b);
    CzytajPkt("Podaj wspolrzedne punktu c. ", c);

    cout<<"Pole trojkata wynosi "<<PoleTroj(a, b, c)<<endl;
    
  
    return 0;
}
zad 2
#include <iostream>
#include <cmath>

using namespace std;

struct punkt
{
    float x, y;
};

const float EPS = 0.000001;

float det(float x1, float y1, float x2, float y2, float x3, float y3)
{
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

bool PktWOdcinku(punkt A, punkt B, punkt P)
{
    return (P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
            P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y));
}

void CzytajPkt(string info, punkt &P)
{
    cout << info << endl;
    cout << "x = "; cin >> P.x;
    cout << "y = "; cin >> P.y;
}

int main()
{
    punkt A, B, P;

    CzytajPkt("Podaj punkt A:", A);
    CzytajPkt("Podaj punkt B:", B);
    CzytajPkt("Podaj punkt P:", P);

    float w = det(A.x, A.y, B.x, B.y, P.x, P.y);

    if (abs(w) > EPS)
    {
        cout << "Punkt nie lezy na prostej";
        return 0;
    }

    if (PktWOdcinku(A, B, P))
    {
        cout << "Punkt nalezy do odcinka AB";
        return 0;
    }

    if (P.y < A.y)
        cout << "Punkt lezy na prostej ponizej punktu A";
    else
        cout << "Punkt lezy na prostej powyzej punktu B";

    return 0;
}
