zad1
#include <iostream>
#include <vector>

using namespace std;

void czytaj(vector<float> &a, vector<float> &sum, int &tmp)
{
   int n;
   float x;
   cout << "stopien wielomianu: ";
   cin >> n;
   a.resize(n+1,0.0f);
   if(n>tmp)
   {
        sum.resize(n+1,0.0f);
        tmp = n;
   }
   for(int i = n;i>=0;i--)
   {
       cout << "a" << i << " = ";
       cin >> x;
       a[i]=x;
       sum[i] += x;
   }
}



int main()
{
    int tmp=0;
    vector<float> a;
    vector<float> b;
    vector<float> sum;
    cout << "wielomian 1\n___________ \n";
    czytaj(a,sum,tmp);
    cout << "wielomian 2\n___________ \n";
    czytaj(b,sum,tmp);
    
    for(int i=sum.size()-1;i>=0;i--)
    {
        if(i>0)
        {
            cout << sum[i] << "*x^" << i << " + ";
        }
        else
        {
            cout << sum[i] << "*x^" << i;
        }
    }
}

zad2
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void czytaj_z_pliku(vector<float> &a, const string &nazwa)
{
    ifstream plik(nazwa);

    int n;
    plik >> n;

    a.resize(n + 1);

    for (int i = 0; i <= n; i++)
    {
        plik >> a[i];
    }

    plik.close();
}

float horner(vector<float> a, float x)
{
    int n = a.size() - 1;
    float wynik = a[0];

    for (int i = 1; i <= n; i++)
    {
        wynik = wynik * x + a[i];
    }

    return wynik;
}

int main()
{
    vector<float> a;
    string nazwa_pliku = "wielomian.txt";

    czytaj_z_pliku(a, nazwa_pliku);

    float x;
    cout << "Podaj x: ";
    cin >> x;

    cout << "W(" << x << ") = " << horner(a, x) << endl;

    return 0;
}

zad3
#include <iostream>
#include <vector>

using namespace std;

void czytaj(vector<int> &a, int &podstawa)
{
    int n;
    cout << "Podaj podstawe systemu (2-9): ";
    cin >> podstawa;

    cout << "Podaj liczbe cyfr: ";
    cin >> n;

    a.resize(n);

    for(int i = 0; i < n; i++)
    {
        cout << "cyfra " << i << " = ";
        cin >> a[i];
    }
}

int horner(vector<int> a, int podstawa)
{
    int wynik = a[0];

    for(int i = 1; i < a.size(); i++)
    {
        wynik = wynik * podstawa + a[i];
    }

    return wynik;
}

int main()
{
    vector<int> a;
    int podstawa;

    czytaj(a, podstawa);

    cout << "Wartosc dziesietna = " << horner(a, podstawa) << endl;
}

zad4
#include <iostream>
#include <vector>

using namespace std;

void czytaj(vector<float> &A){
    int n;
    cout<<"stopien wielomianu";
    cin>>n;
    A.resize(n+1);
    for(int i=n;i>=0;i--){
        cout<<"a"<<i<<" = ";
        cin>>A[i];
    }
}

float W(vector<float> A, float  x){
    int n=A.size()-1;
    float y=A[n];
    for(int i=n-1;i>=0;i--)
        y=x*y+A[i];
    return y;
}
int i=0;

float horner(vector<float>& A, float x, int i){
    if(i == A.size()-1)
        return A[i];

    return horner(A, x, i+1) * x + A[i];
}

int main(){
    vector<float> a;
    czytaj(a);

    float x;
    cin >> x;

    cout << horner(a, x, 0) << endl;
}

zad 5

#include <iostream>
#include <vector>

using namespace std;

void czytaj(vector<float> &A){
    int n;
    cout<<"stopien wielomianu: ";
    cin>>n;
    A.resize(n+1);
    for(int i=n;i>=0;i--){
        cout<<"a"<<i<<" = ";
        cin>>A[i];
    }
}

vector<float> W(const vector<float>& A, const vector<float>& B) {
    int n = A.size();
    int m = B.size();

    vector<float> wynik(n + m - 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            wynik[i + j] += A[i] * B[j];
        }
    }
    return wynik;
}

int main(){
    vector<float> a;
    vector<float> b;
    czytaj(a);
    czytaj(b);

    vector<float> wynik = W(a, b);

    for (int i = 0; i < wynik.size(); i++) {
        cout << "x^" << i << ": " << wynik[i] << endl;
    }
}

zad7
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double sinusinfection(double x)
{
    const int n = 6;
    double silnia[2*n];
    
    silnia[0] = 1;
    for(int i = 1; i < 2*n; i++)
    {
        silnia[i] = silnia[i-1] * i;
    }

    double wynik = 0;

    for(int i = n-1; i >= 0; i--)
    {
        int wyk = 2*i;
        double wsp = ((i % 2 == 0) ? 1 : -1) / silnia[wyk];
        wynik = wynik * x * x + wsp;
    }

    return wynik;
}

int main()
{
    double x;
    cin >> x;

    cout << fixed << setprecision(4);
    cout << sinusinfection(x) << endl;

    return 0;
}


cw 8

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() { int n, n0 = 0; float x, y;

cout << "Liczba punktow: ";
cin >> n;

srand(time(NULL));

for (int i = 0; i < n; i++)
{
    x = -1 + 2 * (float(rand()) / RAND_MAX);
    y = -1 + 2 * (float(rand()) / RAND_MAX);

    if (x * x + y * y <= 1)
        n0++;
}

cout << "Przyblizenie pi: " << 4 * (float(n0) / n) << endl;

return 0;
}
