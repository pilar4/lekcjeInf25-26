#include <iostream>
using namespace std;

string przestaw(string tj, int kl){
    string szyfrogram="";
    int i, j;
    while(tj.size()%kl!=0){
        tj = tj + 'X';
    }

    for(j=0;j<kl;j++){
        for(i=0;i<tj.size()/kl;i++){
            szyfrogram+=tj[i*kl+j];
        }
    }
    return szyfrogram;
}

int main(){
    int k; 
    string s;
    getline(cin, s);
    cin>>k;

    string newS = przestaw(s, k);
    cout<<newS<<'\n';
}