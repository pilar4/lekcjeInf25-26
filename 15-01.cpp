#include 

zad 1

#include <iostream>
#include <string>

using namespace std;

int main (){
    string a; cin>>a;
    int p=0;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='('){
            p++;
        }
        else if(p>0){
            p--;
        }
        else{
            cout<<"NIE";
            return 0;
        }
    }
    cout<<"TAK";
    return 0;
}

zad 2

