Ćwiczenie 1
Było na lekcji

Ćwiczenie 2
Było na lekcji

Ćwiczenie 3
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n;
    cout<<"Podaj rozmiar: ";
    cin>>n;

    vector<int> v(n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        v[i]=rand()%100;
    }

    cout<<"Wektor: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}


Ćwiczenie 4
Ćwiczenie 5
Ćwiczenie 6
Ćwiczenie 7
Ćwiczenie 8


