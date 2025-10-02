#include<iostream>
using namespace std;
int tab[128] = {0};


int main(){
    string s1;
    string s2;
    string s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    if(s1.size()!=s2.size()){
        cout<<"NIE";
        return 0;
    }

    for(const auto &obj : s1){
        tab[obj]++;
    }

    for(const auto &obj : s2){
        tab[obj]--;
    }

    for(const auto &obj : tab){
        if(obj!=0){
            cout<<"NIE";
            return 0;
        }
    }

    for(const auto &obj : s3){
        tab[obj]++;
    }

    for(const auto &obj : s1){
        tab[obj]--;
    }

    for(const auto &obj : tab){
        if(obj!=0){
            cout<<"NIE";
            return 0;
        }
    }

    cout<<"TAK";
    return 0;

}