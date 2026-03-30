#include <iostream>
#include <cmath>

using namespace std;

double sqrt_bisekcja(double c, double epsilon = 1e-6) {
    double a = 0.0;
    double b = 1.0;
    double m;

    while ((b - a) / 2 > epsilon) {
        m = (a + b) / 2;

        if (m * m - c == 0) {
            return m;
        } else if (m * m - c < 0) {
            a = m;
        } else {
            b = m;
        }
    }

    return (a + b) / 2;
}

int main() {
    double c;
    cout << "Podaj liczbe z przedzialu (0,1): ";
    cin >> c;

    double wynik = sqrt_bisekcja(c);
    cout << "Pierwiastek z " << c << " ≈ " << wynik << endl;

    return 0;
}
