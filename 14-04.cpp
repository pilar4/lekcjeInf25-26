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
