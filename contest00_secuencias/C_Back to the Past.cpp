#include <iostream>
#include <ctime>
using namespace std;

int main() {
    struct tm fecha = {0};
    fecha.tm_year = 2013 - 1900;
    fecha.tm_mon = 5 - 1;
    fecha.tm_mday = 29;

    if (mktime(&fecha) != -1) {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%B %d, %Y %A", &fecha);
        cout << buffer << endl;
    } else {
        cout << "Error en el cálculo de la fecha." << endl;
    }

    return 0;
}

