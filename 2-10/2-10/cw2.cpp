#include <iostream>
using namespace std;

string przestaw(string tj, string kl){
    string szyfrogram="";
    int i, j;
    while(tj.size()%kl.size()!=0){
        tj = tj + 'X';
    }

    for(j=0;j<kl.size();j++){
        for(i=0;i<tj.size()/kl.size();i++){
            szyfrogram+=tj[i*kl.size()+kl[j]-'0'];
        }
    }
    return szyfrogram;
}

int main(){
    string k; 
    string s;
    getline(cin, s);
    getline(cin, k);

    string newS = przestaw(s, k);
    cout<<newS<<'\n';
}