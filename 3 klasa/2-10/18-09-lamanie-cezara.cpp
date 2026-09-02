#include<iostream>

int array[25];
int zliczLitery(int array[], std::string napis){
    
    char ch;
    for(int i=0;i<napis.size();i++){
        ch=toupper(napis[i]);
        if(ch>='A' &&ch<='Z'){
            array[ch-'A']++;
        }
    }
    for(int i=0;i<26;i++){
        char c='A' + i;
        // cout<<"DDDD";
        if(array[i]>0) std::cout<<array[i]<<" -"<<c<<"\n";
    }
    int h= -1;
    for(int i=0;i<25;i++){
        char c='A' + i;
        if(array[i]>h) h = c;
    }

    return h;
}







void zad1(std::string s){
    int tab[10] = {0};
    for(auto& obj : s){
        tab[obj - '0']++;
    }
    int i=0;
    for(auto& obj: tab){
        std::cout<<i<<": ";
        std::cout<<obj<<std::endl;
        i++;
    }
}




void zad3(std::string s, int obrot){
    for(auto obj : s){
        obj = toupper(obj);
        
        if(obj+char(obrot)>'Z'){
            obj += char(obrot) - 26;
        }else{
            obj += char(obrot);
        }
        
    }
    
}

void zad4(std::string s){
    char obrot = zliczLitery(array, s) - 'A';
    for(auto obj : s){
        obj = toupper(obj);
        
        if(obj+obrot>'Z'){
            obj += obrot - 26;
        }else{
            obj += obrot;
        }
        
    }
    
}

int zad5Array[10];
void zad5(int n){
    zad5Array[n+1]++;
}



int main(){
    /*zad1
    std::string s; std::cin>>s;
    zad1(s);
    */


    /*
    zad2

    int n = -1;
    int najwieksza=-1;
    while(n!=0){
        std::cin>>n;
        if(n>najwieksza) najwieksza=n;
    }
    std::cout<<najwieksza;

    */

    
    // zad3
    // std::string s; 
    // std::getline(std::cin, s);
    // int n = 1;
    // bool TorF = 1;
    // while(TorF){
    //     zad3(s,n);
    //     n++;
    //     std::cin>>TorF;
    // }

    
    //zad4
    //std::string s; std::cin>>s;
    //zliczLitery(array, s);




    /* zad5
    int n=-1;
    while(n!=0){
        std::cin>>n;
        zad5(n);
    }
    int highest=-1;

    for(int i=0;i<9;i++){
        if(zad5Array[i]>highest) highest=i;
    }
    std::cout<<highest-1;
    */


}

