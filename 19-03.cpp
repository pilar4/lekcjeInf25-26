cw 1

#include <iostream>
#include <vector>

using namespace std;

float W(vector<float> A, float x)
{
    float y = A[0], z = 1;

    for (int i = 1; i < A.size(); i++)
    {
        z = z * x;       
        y = y + A[i] * z;
    }

    return y;
}

int main()
{
    int n;
    cout << "Podaj stopien wielomianu: ";
    cin >> n;

    vector<float> A(n + 1);

    cout << "Podaj wspolczynniki od A0 do A" << n << ":\n";
    for (int i = 0; i <= n; i++)
        cin >> A[i];

    float x;
    cout << "Podaj x: ";
    cin >> x;

    float wynik = W(A, x);

    cout << "Wartosc wielomianu = " << wynik << endl;

    return 0;
}

cw 2
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
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

int main(){
    vector<float> a;
    czytaj(a);
    float x;
    cin>>x;
    cout<<W (a,x);
}
cw 3

