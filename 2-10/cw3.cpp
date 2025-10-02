//jak przeczytalem cw to od razu zrobilem tak
//bez sortowania bo wydawalo sie to naturalne
//a nie ma w poleceniu ze trzeba urzywac sortowania

#include<iostream>
using namespace std;
int tab[128];


int main(){
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

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
    cout<<"TAK";

}
