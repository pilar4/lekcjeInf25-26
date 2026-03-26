Archiwizacja
wszystkich
kodow
z
informatyki 
2
0
2
5
/
2
0
2
6


## disclaimer: I, nor any contributor take responsibility for abominations you can find here 


brakuje nam 1, 3, 10, 12, 13, 14, 16, 17, 24, 31




#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n, n0 = 0;
    float x, y;

    cout << "Liczba punktow: ";
    cin >> n;

    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        x = -1 + 2 * (float(rand()) / RAND_MAX);
        y = -1 + 2 * (float(rand()) / RAND_MAX);

        if (x * x + y * y <= 1)
            n0++;
    }

    cout << "Przyblizenie pi: " << 4 * (float(n0) / n);

    return 0;
}