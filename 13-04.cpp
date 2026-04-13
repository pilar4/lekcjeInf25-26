cw 1
#include <iostream>
#include <cmath>

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

bool PktPoTejSamStr(float A, float B, float C,
                    punkt P1, punkt P2)
{
    return((A*P1.x+B*P1.y+C)*(A*P2.x+B*P2.y+C)>0);
}

int main()
{
    float A, B, C;
    punkt P1, P2;
    cout<<"Podaj wartosc a, b i c ";
    cout<<"Rownanie prostej "<<endl;
    cout<<"A = "; cin>>A;
    cout<<"B = "; cin>>B;
    cout<<"C = "; cin>>C;
    CzytajPkt("Podaj wspolrzedne punktu p1. ", P1);
    CzytajPkt("Podaj wspolrzedne punktu p2. ", P2);
    if(PktPoTejSamStr(A,B,C,P1,P2))
        cout<<"Punkty leza po tej samej stronie";
    else
        cout<<"punkty leza nie po tej samej stronie";
    return 0;    


}

cw2
#include <iostream>
#include <cmath>

using namespace std;

struct punkt
{
    float x, y;
};

float det(float x1, float y1, float x2, float y2, float x3, float y3){
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

const float EPS = 0.000001;

bool PktWOdcinku(punkt A, punkt B, punkt P){
    float w = det(A.x, A.y, B.x, B.y, P.x, P.y);
    if (abs(w) > EPS) return false;
    return (P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
            P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y));
}

void CzytajPkt(string info, punkt &P)
{
    cout << info << endl;
    cout << "x = "; cin >> P.x;
    cout << "y = "; cin >> P.y;
}

bool PktPoTejSamStr(float A, float B, float C,
                    punkt P1, punkt P2)
{
    return ((A * P1.x + B * P1.y + C) * (A * P2.x + B * P2.y + C) > 0);
}

int main()
{
    // float A, B, C;
    punkt P1, P2, P3;
    // cout << "Podaj wartosc a, b i c ";
    // cout << "Rownanie prostej " << endl;
    // cout << "A = "; cin >> A;
    // cout << "B = "; cin >> B;
    // cout << "C = "; cin >> C;
    CzytajPkt("Podaj wspolrzedne punktu p1. ", P1);
    CzytajPkt("Podaj wspolrzedne punktu p2. ", P2);
    CzytajPkt("Podaj wspolrzedne punktu p3. ", P3);

    if (PktWOdcinku(P1, P2, P3))
        cout << "Punkt lezy na odcinku";
    else
        cout << "Punkt nie lezy na odcinku";

    return 0;
}
