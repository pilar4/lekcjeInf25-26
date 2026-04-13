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

