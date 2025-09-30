#include<iostream>
#include<cstdlib>
#include<ctime>

//zad4
int main(){

    int n; std::cin>>n;
    int array[n];
    srand(time(0));
    for(auto& obj : array){
        obj = rand()%10;
    }

    for(auto& obj : array){
        for(auto& secondObj : array){
            if(obj==secondObj){
                std::cout<<"Powtarza sie "<<obj<<std::endl;
            }
        }
    }

}



#include<iostream>

int main(){

    int a, b; std::cin>>a>>b;
    int c = (b-a+1)*(b+a)/2;
    std::cout<<c;
}
