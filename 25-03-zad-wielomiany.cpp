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
