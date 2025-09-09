#include <iostream>
#include <vector>
using namespace std;

string changeNum(int n, int p){
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
    return r;
}

void triangles(double a, double b,double c){
    if(a+b<c || b+c<a || c+a<b){
        cout<<"NIE";
        return;
    }
    cout<<"TAK";
}

void czySiePowtarza(string s){
    int array[128];
    for(int i=0;i<128;i++){
        array[i]=0;
    }
    for(int i=0;i<s.size();i++){
        if(array[toupper(s[i])]==1){
            cout<<"TAK";
            return;
        }
        array[toupper(s[i])]=1;

    }
    cout<<"NIE";
}

void ileCyfrDoslownie(int n){
    string binary = changeNum(n, 2);
    string czworkowy = changeNum(n, 4);
    string osemkowy = changeNum(n, 8);

    cout<<binary.size()<<" "<<czworkowy.size()<<" "<<osemkowy.size()<<endl;
}

void ileCyfrBezLiczenia(int n){
    if(n%2==1) cout<<n/2+1<<endl;
    else cout<<n/2<<endl;
    if(n%3>0) cout<<n/3+1<<endl;
    else cout<<n/2<<endl;
    if(n%4>0) cout<<n/4+1<<endl;
    else cout<<n/2<<endl;
}
//nwm co to dokonca lepiej to na gorze uzywac
int main(){


}
