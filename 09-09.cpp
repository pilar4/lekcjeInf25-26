#include <iostream>
#include <vector>
using namespace std;

void changeNum(int n, int p){
    string r;
    while (n>0){
        if(n%p<=9){
            char x = n%p + '0';
            r = x + r;
        }
        else{
            char y = n%p - 10 + 'A';
            r = y + r;
        }
        n = n/p;
    }
    cout<<r;
    cout<<endl;
}

void triangles(double a, double b,double c){
    if(a+b<c || b+c<a || c+a<b){
        cout<<"NIE";
        return;
    }
    cout<<"TAK";
}

int main(){
    
    

}
