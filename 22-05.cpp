ktore robice ???
nwm na pewno 1 i 2
cw 2
#include <iostream>
using namespace std;

int NWD(int a, int b){
    int pom;
    while(b!=0){
        pom=b;
        b=a%b;
        a=pom;
    }
    return a;
}

pair<int, int> NWDRoz(int a, int b){
    if(b==0) return make_pair(1,0);
    pair<int, int> pom=NWDRoz(b,a%b);
    return make_pair(pom.second,pom.first-(a/b)*pom.second);
}

int main(){
    int s, z, y, m, o, n;
    cout<<"Podaj dwie liczby pierwsze p i 1:"<<endl;
    cout<<"p = "; cin>>o;
    cout<<"q = "; cin>>n;
    y = o*n;
    m=(o-1)*(n-1);
    z=3;
    while(NWD(z,m)!=1) z=z+2;
    s=NWDRoz(z,m).first;
    if (s<0) s=s+m;
    cout<<"Klucz publiczny: "<<z<<" "<<n<<endl;
    cout<<"Klucz prywatny: "<<s<<" "<<y<<endl;
    return 0;
}
