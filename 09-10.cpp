1.
#include<iostream>
using namespace std;
int tab[6] = {12, 4, 7, 7, 19, 90};


int main(){
   for(int i=0;i<6;i++){
       for(int j=0;j<6;j++){
           if(tab[j]%10>tab[j+1]%10)
               swap(tab[j], tab[j+1]);
       }
   }


   for(int i=0;i<6;i++){
       cout<<tab[i]<<' ';
   }
}


2.
#include<iostream>
using namespace std;
int tab[6] = {12, 4, 7, 7, 19, 90};


int main(){
   for(int i=0;i<6;i++){
       for(int j=0;j<6;j++){
           if(tab[j]%10>tab[j+1]%10)
               swap(tab[j], tab[j+1]);
       }
   }


   for(int i=0;i<6;i++){
       cout<<tab[i]<<' ';
   }


   int tab2[6];
   int j=5;
   for(int i=0;i<6;i++){
       tab2[i] = tab[j];
       j--;
   }


}


3. to chyba nie dziala do konca, od jonasza mozna wziac
#include<iostream>
using namespace std;


int tab[6] = {12, 4, 7, 7, 19, 90};


void sortowanieB(){
   for(int i=0;i<6;i++){
       bool zamiana = true;
       int j=1;
       while(j< 6-i && zamiana == true){
           zamiana = false;
           if(tab[j-1]>tab[j]){
               swap(tab[j-1], tab[j]);
               zamiana = false;
           }
           j++;
       }
       // if(!zamiana){
       //     break;
       // }
   }
}


int main(){
   sortowanieB();   


}


4.
#include <iostream>
#include <vector>
using namespace std;


int sumaCyfr(int n) {
   int s = 0;
   while (n > 0) {
       s += n % 10;
       n /= 10;
   }
   return s;
}


int main() {
   vector<int> tab = {45, 12, 30, 111, 9};


   for (int i = 0; i < tab.size() - 1; i++) {
       for (int j = 0; j < tab.size() - i - 1; j++) {
           if (sumaCyfr(tab[j]) > sumaCyfr(tab[j + 1])) {
               swap(tab[j], tab[j + 1]);
           }
       }
   }


   for (int i=0;i<5;i++) cout << tab[i] << " ";
   return 0;
}


5.
#include <iostream>
#include <vector>
using namespace std;


const int N = 6;


int liczbaJedynek(int n) {
   int licz = 0;
   while (n > 0) {
       if (n % 2 == 1) licz++;
       n /= 2;
   }
   return licz;
}


int main() {
   int tab[N] = {3, 7, 8, 5, 6, 9};


  
   for (int i = 0; i < N ; i++) {
       if (liczbaJedynek(tab[i]) > liczbaJedynek(tab[i + 1])) {
           swap(tab[i], tab[i + 1]);
       }
   }
   for (int i=0;i<N;i++) cout << tab[i] << " ";
   return 0;
}





6.
#include <iostream>
#include <vector>
using namespace std;


const int N=7;


int main() {
   int tab[N] = {4, 7, 2, 9, 6, 5, 8};


  
   for (int i = 0; i < N; i++) {
       if (tab[i] % 2 == 0 && tab[i + 1] % 2 != 0) {
           swap(tab[i], tab[i + 1]);
       }
   }


   for (int i= 0; i < N; i++){
       cout << tab[i] << " ";
   }
   return 0;
}

7.
#include <iostream>
#include <vector>
using namespace std;


const int N=14;


int binary(int tab[], int x, int l, int p) {
   while (l <= p) {
       int mid = (l + p) / 2;
       if (tab[mid] == x)
           return mid + 1;
       else if (tab[mid] < x)
           l = mid + 1;
       else
           p = mid - 1;
   }
   return l;
}


void wypisz(int tab[]){
   for (int i=0;i<N;i++) cout << tab[i] << " ";
}


void losuj(int tab[]){
   for(int i=0;i<N;i++){
       tab[i]=rand()%100;
   }
}






int main() {
   int tab[N];
   srand(time(NULL));
   losuj(tab);
   wypisz(tab);
   cout<<'\n';


   for (int i = 1; i < N; i++) {
       int x = tab[i];
       int j = i - 1;
       int m = binary(tab, x, 0, j);
       while (j >= m) {
           tab[j + 1] = tab[j];
           j--;
       }
       tab[j + 1] = x;
   }


   wypisz(tab);
  
   return 0;
}

