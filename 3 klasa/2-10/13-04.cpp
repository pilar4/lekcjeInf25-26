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

cwianc 3
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

float det(float x1, float y1, float x2, float y2, float x3, float y3){
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

bool PktPoTejSamStr(punkt A, punkt B, punkt P1, punkt P2){
    float w1, w2;
    w1=det(A.x,A.y,B.x,B.y,P1.x,P1.y);
    w2=det(A.x,A.y,B.x,B.y,P2.x,P2.y);
    return (w1*w2>0);
}

int main(){
    punkt A, B, P1, P2;
    CzytajPkt("Podaj wspolrzedne punktu A. ", A);
    CzytajPkt("Podaj wspolrzedne punktu B. ", B);
    CzytajPkt("Podaj wspolrzedne punktu P1. ", P1);
    CzytajPkt("Podaj wspolrzedne punktu P2. ", P2);

    if(PktPoTejSamStr(A,B,P1,P2)){
        cout<<"Tak";
    }
    else{
        cout<<"nie ";
    }

    return 0;
}
cw 4

#include <iostream>

using namespace std;

const double EPS = 1e-9;

struct point{
   public:
   
   float x;
   float y;
};

float det(float x1, float y1,
          float x2, float y2,
          float x3, float y3)
{
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

bool PktWodcinku(point A, point B, point P)
{
    float w = det(A.x, A.y, B.x, B.y, P.x, P.y);
    
    if (abs(w) > EPS)
        return false;

    return P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
           P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y);
}

bool PrzecOdcinki(point A, point B, point C, point D)
{
    float w1, w2, w3, w4;

    w1 = det(A.x, A.y, B.x, B.y, C.x, C.y);
    w2 = det(A.x, A.y, B.x, B.y, D.x, D.y);
    w3 = det(C.x, C.y, D.x, D.y, A.x, A.y);
    w4 = det(C.x, C.y, D.x, D.y, B.x, B.y);

    if (w1 * w2 < 0 && w3 * w4 < 0) return true;

    if (PktWodcinku(A, B, C)) return true;
    if (PktWodcinku(A, B, D)) return true;
    if (PktWodcinku(C, D, A)) return true;
    if (PktWodcinku(C, D, B)) return true;

    return false;
}

int main(){

   point A, B, C, D;

      cout<<"podaj wartosci x y punktow: ";
      cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;

      if(PrzecOdcinki(A,B,C,D)) cout <<"tak";
      else cout<<"NIE";

   return 0;
}

cw 5
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

bool PktWTrojkacie(float xA,float yA, float xB, float yB, float xC, float yC,
                    punkt P1)
{
    float w1 = det(xA,yA,xB,yB,P1.x,P1.y);
    float w2 = det(xB,yB,xC,yC,P1.x,P1.y);
    if(w1*w2<0)
        return false;
    w2 = det(xC,yC,xA,yA,P1.x,P1.y);
    if(w1*w2<0)
        return false;
    return true;
}

int main()
{
    float xA,yA,xB,yB,xC,yC;
    punkt P1;
    // cout << "Podaj wartosc a, b i c ";
    // cout << "Rownanie prostej " << endl;
    // cout << "A = "; cin >> A;
    // cout << "B = "; cin >> B;
    // cout << "C = "; cin >> C;
    cout<<"wpisz x i y A: "; cin>>xA>>yA;
    cout<<"wpisz x i y B: "; cin>>xB>>yB;
    cout<<"wpisz x i y C: "; cin>>xC>>yC;
    CzytajPkt("Podaj wspolrzedne punktu p1. ", P1);

    if(PktWTrojkacie(xA,yA,xB,yB,xC,yC,P1)){
        cout<<"Jest w trojkacie";
        return 0;
    }
    cout<<"Nie jest w trojkacie";

    return 0;
}


ciancao afvacnie 6
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

float det(float x1, float y1, float x2, float y2, float x3, float y3){
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

void CzytajWiel(vector<punkt> &W){
    int i, n;
    ifstream we("wielwyp.txt");
    we>>n; W.resize(n);
    for(i=0;i<n;i++){
        we>>W[i].x>>W[i].y;
    }
    we.close();
}

bool PktWWielWyp(vector<punkt> W, punkt P){
    int n=W.size();
    float w1,w2;
    w1 = det(W[0].x,W[0].y,W[1].x,W[1].y,P.x,P.y);
    for(int i=1;i<n;i++)
    {
        w2=det(W[i].x,W[i].y,W[(i+1)%n].x,W[(i+1)%n].y,P.x,P.y);
        if(w1*w2<0) return false;
    }
    return true;
}

int main(){
    punkt P;
    vector<punkt> W;
    CzytajPkt("Podaj wspolrzedne punktu P. ", P);

    CzytajWiel(W);

    if(PktWWielWyp(W,P)){
        cout<<"tak ";
    }
    else{
        cout<<"nie";
    }
  
    return 0;
}
