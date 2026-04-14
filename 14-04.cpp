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

zandafeanie 2
#include <iostream>
#include <cmath>

using namespace std;

const int n = 10;

struct punkt
{
    float x, y;
};

void CzytajPkt(string info, punkt &P)
{
    cout << info << endl;
    cout << "x = "; cin >> P.x;
    cout << "y = "; cin >> P.y;
}

float det(float x1, float y1, float x2, float y2, float x3, float y3){
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

int main(){
    punkt A, B, P;
    CzytajPkt("Podaj wspolrzedne punktu A (od 1 do 9): ", A);
    CzytajPkt("Podaj wspolrzedne punktu B (od 1 do 9): ", B);

    int stron1 = 0;
    int stron2 = 0;
    const float EPS = 0.000001;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            P.x = i; 
            P.y = j;
            
            float w = det(A.x, A.y, B.x, B.y, P.x, P.y);
            
            if (w > EPS) {
                stron1++;
            } else if (w < -EPS) {
                stron2++;
            }
        }
    }
    cout<<stron1<<endl;
    cout<<stron2<<endl;
  
    return 0;
}
zad 3
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

zad 4

#include <iostream>
#include <cmath>

//program wlicza tez punkty pokrywajace sie z bokami trojkata

using namespace std;

struct punkt
{
    float x, y;
};

float det(float x1, float y1, float x2, float y2, float x3, float y3){
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

bool PktWTrojkacie(float xA,float yA, float xB, float yB, float xC, float yC,
                    int i, int j)
{
    float w1 = det(xA,yA,xB,yB,i,j);
    float w2 = det(xB,yB,xC,yC,i,j);
    if(w1*w2<0)
        return false;
    w2 = det(xC,yC,xA,yA,i,j);
    if(w1*w2<0)
        return false;
    return true;
}

void opiszKwadrat(float xA,float yA, float xB, float yB, float xC, float yC, float &xmin, float &xmax, float &ymin, float &ymax){
    if(xA>xB && xA>xC){
        xmax = xA;
        if(xB<xC) xmin = xB;
        else xmin = xC;
    }
    else if(xB>xC){
        xmax = xB;
        if(xA<xC) xmin = xA;
        else xmin = xC;
    }
    else{
        xmax = xC;
        if(xA<xB) xmin = xA;
        else xmin = xB;
    }

    if(yA>yB && yA>yC){
        ymax = yA;
        if(yB<yC) ymin = yB;
        else ymin = yC;
    }
    else if(yB>yC){
        ymax = yB;
        if(yA<yC) ymin = yA;
        else ymin = yC;
    }
    else{
        ymax = yC;
        if(yA<yB) ymin = yA;
        else ymin = yB;
    }

    return;
}


int main()
{
    float xA,yA,xB,yB,xC,yC;
    float xmin, xmax, ymin, ymax;
    int counter = 0;

    cout<<"wpisz x i y A: "; cin>>xA>>yA;
    cout<<"wpisz x i y B: "; cin>>xB>>yB;
    cout<<"wpisz x i y C: "; cin>>xC>>yC;

    opiszKwadrat(xA,yA,xB,yB,xC,yC,xmin,xmax,ymin,ymax);

    for(int i=xmin; i<xmax; i++){
        cout<<"B";
        for(int j=ymin; j<ymax;j++){
            cout<<"I";
            if(PktWTrojkacie(xA,yA,xB,yB,xC,yC,i,j)) counter++;
            cout<<counter;
        }
    }

    return 0;
}


zad 5
#include <iostream> 
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

struct punkt
{
    float x, y;
};


void CzytajWiel(vector<punkt> &W){
    int i, n;
    ifstream we("wielokat_1.txt");
    we>>n; W.resize(n);
    for(i=0;i<n;i++){
        we>>W[i].x>>W[i].y;
    }
    we.close();
}

float PoleWiel(vector<punkt> &W){
    float pole=0.0;
    int j;
    int n=W.size();
    for(int i=0;i<n;i++){
        j = (i+1)%n;
        pole += W[i].x * W[j].y;
        pole -= W[j].x * W[i].y;
    }
    return abs(pole/2);
}

int main(){
    vector<punkt> W;
    CzytajWiel(W);
    cout<<"Pole = "<<PoleWiel(W)<<endl;

    return 0;
}
zad 6
#include <iostream> 
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

struct punkt
{
    float x, y;
};


void CzytajWiel(vector<punkt> &W){
    int i, n;
    ifstream we("wielokat_2.txt");
    we>>n; W.resize(n);
    for(i=0;i<n;i++){
        we>>W[i].x>>W[i].y;
    }
    we.close();
}


bool CzyPunktWWielo(const vector<punkt>& polygon,
                      const punkt& p)
{
    // algorytm robi ray casting czyli rysuje od punktu
    // p prosta w prawo i sprawdza czy przecina jakas krawedz

    int n = polygon.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        punkt p1 = polygon[i];
        punkt p2 = polygon[(i + 1) % n];

        if ((p.y > min(p1.y, p2.y))
            && (p.y <= max(p1.y, p2.y))
            && (p.x <= max(p1.x, p2.x))) {
            double xIntersect = (p.y - p1.y)
                                    * (p2.x - p1.x)
                                    / (p2.y - p1.y)
                                + p1.x;
            if (p1.x == p2.x || p.x <= xIntersect) {
                count++;
            }
        }
    }
    return count % 2 == 1;
}

int main(){
    vector<punkt> W;
    punkt p;
    cout<<"Podaj wspolrzedne punktu ";
    cin>>p.x>>p.y;
    CzytajWiel(W);
    if(CzyPunktWWielo(W, p))
        cout<<"Punkt lezy w wielokacie "<<endl;
    else
        cout<<"Punkt nie lezy w wielokacie "<<endl;
    return 0;
}
