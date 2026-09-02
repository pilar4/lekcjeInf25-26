//zad 1

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> tab = {25, 42, 13, 57, 96, 30};

    for (int i = 0; i < tab.size() - 1; i++) {
        for (int j = 0; j < tab.size() - i - 1; j++) {
            if (tab[j] % 10 > tab[j + 1] % 10) {
                swap(tab[j], tab[j + 1]);
            }
        }
    }

    for (int x : tab) cout << x << " ";
    return 0;
}

//zad 2

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> tab = {9, 3, 7, 1, 4, 2};

    for (int i = 0; i < tab.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < tab.size(); j++) {
            if (tab[j] < tab[minIdx]) minIdx = j;
        }
        swap(tab[i], tab[minIdx]);
    }

    for (int x : tab) cout << x << " ";
    return 0;
}

//zad 3

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> tab = {5, 2, 8, 3, 1};

    bool zamiana;
    for (int i = 0; i < tab.size() - 1; i++) {
        zamiana = false;
        for (int j = 0; j < tab.size() - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                swap(tab[j], tab[j + 1]);
                zamiana = true;
            }
        }
        if (!zamiana) break;
    }

    for (int x : tab) cout << x << " ";
    return 0;
}

//zad 4

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

    for (int x : tab) cout << x << " ";
    return 0;
}

//zad 5

#include <iostream>
#include <vector>
using namespace std;

int liczbaJedynek(int n) {
    int licz = 0;
    while (n > 0) {
        if (n % 2 == 1) licz++;
        n /= 2;
    }
    return licz;
}

int main() {
    vector<int> tab = {3, 7, 8, 5, 6, 9};

    for (int i = 0; i < tab.size() - 1; i++) {
        for (int j = 0; j < tab.size() - i - 1; j++) {
            if (liczbaJedynek(tab[j]) > liczbaJedynek(tab[j + 1])) {
                swap(tab[j], tab[j + 1]);
            }
        }
    }
    for (int x : tab) cout << x << " ";
    return 0;
}

//zad 6

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> tab = {4, 7, 2, 9, 6, 5, 8};

    for (int i = 0; i < tab.size() - 1; i++) {
        for (int j = 0; j < tab.size() - i - 1; j++) {
            if (tab[j] % 2 == 0 && tab[j + 1] % 2 != 0) {
                swap(tab[j], tab[j + 1]);
            }
        }
    }

    for (int x : tab) cout << x << " ";
    return 0;
}

//zad 7

#include <iostream>
#include <vector>
using namespace std;

int binary(vector<int> tab, int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (tab[mid] == x)
            return mid + 1;
        else if (tab[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
    vector<int> tab = {9, 5, 2, 7, 1};

    for (int i = 1; i < tab.size(); i++) {
        int x = tab[i];
        int j = i - 1;
        int m = binary(tab, x, 0, j);
        while (j >= m) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = x;
    }

    for (int x : tab) cout << x << " ";
    return 0;
}
