#include <iostream>
#include <cmath>

using namespace std;

class EjercitoEtrusco {
private:
    long long numeroGuerreros;

public:
    EjercitoEtrusco(long long n) {
        numeroGuerreros = n;
    }

    void calcularFilas() {
        long long filas = (long long)(-1 + sqrt(1 + 8 * numeroGuerreros)) / 2;
        cout <<filas << endl;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        EjercitoEtrusco ejercito(n);
        ejercito.calcularFilas();
    }

    return 0;
}
