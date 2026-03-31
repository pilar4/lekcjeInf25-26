#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const int N = 20;

void init(vector<int>& A){
    for(int i=0; i<N; i++){
        A.push_back(rand() % 100);
    }
}


int main(){

    vector<int> A;
    srand(time(NULL));

    init(A);

    for(int i=0; i<N; i++){
        cout<<A[i]<<" ";
    }

    for (int i = 1; i < A.size(); ){
        if(A[i] < A[i - 1]){
            A.erase(A.begin() + i);
        }
        else{
            i++;
        }
    }

    cout<<endl<<endl;

        for(int i=0; i<A.size(); i++){
        cout<<A[i]<<" ";
    }

    return 0;
}
