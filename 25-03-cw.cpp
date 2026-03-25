cw1
cw5
#include <iostream>
#include <vector>
using namespace std;

float f(float x){
    return 1.0/6*x*x*x-x*x+0.5*x+5.0/0.3;
}

int main()
{
    float a, b, x, dx, s=0;
    int n;
    cout<<"A = "; cin>>a;
    cout<<"B = "; cin>>b;
    cout<<"N = "; cin>>n;
    dx=(b-a)/n;
    x=a;
    for(int i=1;i<=n;i++){
        x=x+dx;
        s=s+dx*f(x);
    }
    cout<<"Pole obszaru "<<s;
    cout<<endl;
    return 0;
}
