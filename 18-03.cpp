cw 1
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double x=0;
    while (x<1.01){
        cout<<setprecision(10)<<fixed<<x<<endl;
        x = x + 0.1;
    }

    return 0;
}
