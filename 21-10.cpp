//cw 1

n

//cw 2

beda tez liczby 53 59 61 83

//cw 3

podaj n
dla kazdej kolejnej liczby pierwszej k
    jezeli k^2 <= n 
      usun kazda liczbe i*k gdzie i!=0
    inaczej
  wypoisz prawda jezeli Pierwsze[] != 0, a inaczej falsz

//cw 4

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> pier(n + 1, true); 
    pier[0] = pier[1] = false;   

    for (int i = 2; i * i <= n; i++) {
        if (pier[i]) {
            for (int j = i * i; j <= n; j += i)
                pier[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (pier[i])
            cout << i << " ";
    }

    return 0;
}

//zad 1

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a,n;
    cin >> a >> n;

    vector<bool> pier(n + 1, true); 
    pier[0] = pier[1] = false;   

    for (int i = 2; i * i <= n; i++) {
        if (pier[i]) {
            for (int j = i * i; j <= n; j += i)
                pier[j] = false;
        }
    }

    for (int i = a; i <= n; i++) {
        if (pier[i])
            cout << i << " ";
    }

    return 0;
}


//zad 2

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> pier(n + 1, true); 
    pier[0] = pier[1] = false;   

    for (int i = 2; i * i <= n; i++) {
        if (pier[i]) {
            for (int j = i * i; j <= n; j += i)
                pier[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (pier[i] && pier[i+2])
            cout << i << " + " << i + 2 << endl;
    }

    return 0;
}

//zad 3

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> pier(n/2 + 1, true); 
    pier[0] = pier[1] = false;   

    for (int i = 1; i * i <= n; i+=2) {
        if (pier[i]) {
            for (int j = i * i; j <= n; j += i)
                pier[j] = false;
        }
    }

    for (int i = 1; i <= n; i+=2) {
        if (pier[i])
            cout << i << " ";
    }

    return 0;
}


//zad 4

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> pier(n + 1, true); 
    pier[0] = pier[1] = false;   

    for (int i = 2; i * i <= n; i++) {
        if (pier[i]) {
            for (int j = i * i; j <= n; j += i)
                pier[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (pier[i])
            for(int j = i; j <= n; j++)
                if(pier[j] && i*j <= n)
                    cout << i*j << " ";
    }

    return 0;
}

//zad 5 z internetem, bo podrecznik nie wytlumaczyl jak dziala set

#include <iostream>
#include <set>

using namespace std;

int main(){

    int n = 100; 
    set<int> pier;

    for(int i = 2; i < n+1; i++){
        pier.insert(i);
    }

    for (int i = 2; i * i <= n; i++) {
        if(pier.find(i) != pier.end()) //bo jak nie znajdzie i to jest wtedy pier.end(), czyli szukay istniejacego i ktore na pewno jest pierwsze
            for (int j = i * i; j <= n; j += i){
                pier.erase(j);
        }
    }


    set<int>::iterator it;
    for(it = pier.begin(); it != pier.end(); it++){
        cout<<*it<<" ";
    }
    return 0;
}
