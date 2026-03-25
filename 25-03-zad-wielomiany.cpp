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
