#include <iostream>
using namespace std;

int main() {
    int velocidad, tiempo;
    while (cin >> velocidad >> tiempo) {
        int desplazamiento = 2 * velocidad * tiempo;
        cout << desplazamiento << endl;
    }
    return 0;
}