Zadania wykonane samodzielnie bardzo samodzielnie

Zad. 1
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 20;

void losuj(int A[]){
    for(int i=0; i<N; i++){
        A[i] = rand() % 100;
    }
}

void wypisz(int A[]){
    for(int i=0; i<N; i++){
        cout << A[i] << " ";
    }
}

void quickSort(int A[], int p, int k){
    if (p >= k) return;

    int pivotIndex = rand() % (k - p + 1) + p;
    swap(A[pivotIndex], A[k]);

    int m = A[k];  
    int i = p - 1;
    for (int j = p; j < k; j++){
        if (A[j] <= m){
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[k]);  
    int pivotPos = i + 1;

    quickSort(A, p, pivotPos - 1);
    quickSort(A, pivotPos + 1, k);
}

int main(){
    int A[N];
    srand(time(NULL));

    losuj(A);
    wypisz(A);
    quickSort(A, 0, N - 1);

    cout << "Tablica po sortowaniu" << endl;
    wypisz(A);
    cout << endl;

    return 0;
}

Zad. 2

    #include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 10;

void Losuj(int A[]){
    for (int i = 0; i < N; i++){
        A[i] = rand() % 100;
    }
}

void Wypisz(int A[]){
    for (int i = 0; i < N; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int combine(int A[], int B[], int C[]){
    
    int i=0, j=0, np=N;
    while(np>0){
        if(A[i]<=B[j]){
            C[N-np] = A[i];
            i++; np--;
        }
        else {
            C[N-np] = B[j];
            j++; np--;
        }
    }
}



int main(){

    int A[N]; int B[N]; int C[N];
    srand(time(NULL));
    Losuj(A); Losuj(B);
    Wypisz(A); Wypisz(B);
    sort(A, A + N); sort(B, B + N);

    combine(A, B, C);

    Wypisz(C);

    return 0;
}

Zad. 3
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 10;

void Losuj(int A[])
{
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 100;
    }
}

void Wypisz(int A[])
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Merge_insitu(int A[], int p, int s, int k)
{
    int i, j, pom;
    for (i = p; i <= s; i++)
        if (A[s + 1] > A[i])
        {
            pom = A[i];
            A[i] = A[s + 1];
            j = s + 2;
            while (j <= k && A[j] > pom)
            {
                A[j - 1] = A[j];
                j++;
            }
            A[j - 1] = pom;
        }
}

void MergeSort(int A[], int p, int k)
{
    if (p >= k) return;

    int s = (p + k) / 2;

    MergeSort(A, p, s);
    MergeSort(A, s + 1, k);

    Merge_insitu(A, p, s, k);
}

int main()
{
    int A[N];
    srand(time(NULL));
    Losuj(A);
    Wypisz(A);
    MergeSort(A, 0, N - 1);
    Wypisz(A);

    return 0;
}

Zad. 4
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N=10;

void losuj(int A[]){
for(int i=0;i<N;i++){
A[i]=rand()%10;
}
}

void wypisz(int A[]){
for(int i=0;i<N;i++){
cout<<A[i]<<" ";
}
}

void SorPrzWst(int A[], int p, int k){
    for(int i = p+1; i <= k; i++){
        int key = A[i];
        int j = i - 1;
        while(j >= p && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

void QuiSot(int A[], int p, int k){
   int i, j, m;
   while(p<k){
        if(k-p+1<5){
            SorPrzWst(A, p, k);
            break;
        }
        else{
       i=p; j=k; m=A[(p+k)/2];
       while(i<=j){
           while(A[i]<m){
               i++;
           }
           while(A[j]>m){
               j--;
           }
           if(i<=j){
               swap(A[i],A[j]);
               i++; j--;
           }
       }
       if(j-p<k-i){
           QuiSot(A,p,j);
           p=i;
       }
       else{
           QuiSot(A,i,k);
           k=j;
       }
        }
   }
}

int main(){

   int A[N];

   srand(time(NULL));
   losuj(A);
   wypisz(A);

   cout<<endl<<endl;

   QuiSot(A,0,N-1);
   wypisz(A);

   return 0;
}

Zad. 5

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 10;

void Losuj(int A[])
{
    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 6 + 1;
    }
}

void Wypisz(int A[])
{
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void zliczSort(int A[], int B[]){
    int oczka[6] = {0};
    for(int i=0; i<N; i++){
        oczka[A[i]-1]++;
    }
    int idx = 0;
    for (int i=0; i<6; i++) {
        for (int j=0; j<oczka[i]; j++) {
            B[idx++] = i+1;
        }
    }
}



int main()
{
    int A[N], B[N];
    srand(time(NULL));
    Losuj(A);
    Wypisz(A);
    zliczSort(A, B);
    Wypisz(B);

    return 0;
}


Zad. 6
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 20;

void losuj(int A[]){
    for(int i=0; i<N; i++){
        A[i] = rand() % 100;
    }
}

void wypisz(int A[]){
    for(int i=0; i<N; i++){
        cout << A[i] << " ";
    }
}

void quickSort(int A[], int p, int k){
    if (p >= k) return;

    int pivotIndex = rand() % (k - p + 1) + p;
    swap(A[pivotIndex], A[k]);

    int m = A[k];  
    int i = p - 1;
    for (int j = p; j < k; j++){
        if (A[j] <= m){
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[k]);  
    int pivotPos = i + 1;

    quickSort(A, p, pivotPos - 1);
    quickSort(A, pivotPos + 1, k);
}

int main(){
    int A[N];
    int B[N];
    srand(time(NULL));
    losuj(A);
    quickSort(A, 0, N - 1);
    cout<<"Tablica A: ";
    wypisz(A);
    cout<<endl;

    losuj(B);
    quickSort(B, 0, N-1);
    cout<<"tablica B: ";
    wypisz(B);
    cout<<endl;

    cout<<"tablica AB: ";
    int AB[N * 2];
    int i = 0, j = 0, k = 0;

    while (i < N && j < N) {
        if (A[i] <= B[j]) {
            AB[k++] = A[i++];
        } else {
            AB[k++] = B[j++];
        }
    }

    while (i < N) AB[k++] = A[i++];
    while (j < N) AB[k++] = B[j++];

    for (int t = 0; t < 2 * N; t++)
        cout << AB[t] << " ";

    cout << endl;

    return 0;
}

Zad. 7
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 20;

int sumaCyfr(int x) {
    int s = 0;
    while(x > 0){
        s += x % 10;
        x /= 10;
    }
    return s;
}

void losuj(int A[]){
    for(int i = 0; i < N; i++){
        A[i] = rand() % 100;  
    }
}

void wypisz(int A[]){
    for(int i = 0; i < N; i++){
        cout << A[i] << " ";
    }
}

void quickSort(int A[], int p, int k){
    int i = p, j = k;
    int pivot = A[(p + k) / 2];
    int pivotSum = sumaCyfr(pivot);

    while(i <= j){
        while( (sumaCyfr(A[i]) < pivotSum) ||
               (sumaCyfr(A[i]) == pivotSum && A[i] < pivot) )
            i++;

        while( (sumaCyfr(A[j]) > pivotSum) ||
               (sumaCyfr(A[j]) == pivotSum && A[j] > pivot) )
            j--;

        if(i <= j){
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }

    if(p < j) quickSort(A, p, j);
    if(i < k) quickSort(A, i, k);
}

int main(){
    int A[N];
    srand(time(NULL));

    losuj(A);
    cout << "Tablica przed sortowaniem:\n";
    wypisz(A);

    cout << "\n\nTablica po sortowaniu wg sumy cyfr:\n";
    quickSort(A, 0, N - 1);
    wypisz(A);

    cout << endl;
    return 0;
}

Zad. 8

Zad. 9

Zad. 10




