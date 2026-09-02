ktore robice ???
nwm na pewno 1 i 2

cw 1
    a) pub (7,299) pryw (42,299)
    b) pub (5,323) pryw (173,323)

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

cw 3

C = 90^5  mod 299
C = 5904900000 mod 299 = 26

    
cw 4(chb)

#include <iostream>
#include <fstream>

using namespace std;

int RSA(int podst, int wykl, int n)
{
    int w = 1;

    while (wykl > 0)
    {
        if (wykl % 2 == 1)
            w = (w * podst) % n;

        wykl = wykl / 2;

        if (wykl > 0)
            podst = (podst * podst) % n;
    }

    return w;
}

int main()
{
    ifstream we("t_jawny_RSA.txt");
    ofstream wy("szyfrogram_RSA.txt");

    unsigned char ch;
    int e, n;

    cout << "Podaj klucz publiczny:" << endl;
    cout << "e = ";
    cin >> e;
    cout << "n = ";
    cin >> n;

    we >> noskipws;

    while (we >> ch)
        wy << RSA(ch, e, n) << " ";

    we.close();
    wy.close();

    cout << "Tekst zostal zaszyfrowany";

    return 0;
}
cw5
129^53mod299=90

    m = 129^53 mod 299 = 90

cw 6
#include <iostream>
#include <fstream>

using namespace std;

int RSA(int podst, int wykl, int n)
{
    int w = 1;

    while (wykl > 0)
    {
        if (wykl % 2 == 1)
            w = (w * podst) % n;

        wykl = wykl / 2;

        if (wykl > 0)
            podst = (podst * podst) % n;
    }

    return w;
}

int main()
{
    ifstream we("szyfrogram_RSA.txt");
    ofstream wy("tekst_odszyfrowany.txt");
    int d,n,x;

    cout << "Podaj klucz prywatny:" << endl;
    cout << "d = ";
    cin >> d;
    cout << "n = ";
    cin >> n;

    while (we >> x) wy<<char(RSA(x,d,n));
    we.close();
    wy.close();

    cout << "Tekst zostal odszyfrowany";

    return 0;
}
