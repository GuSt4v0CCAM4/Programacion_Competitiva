#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct MatchResult {
    int s;
    int r;
};

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int n, g;
        if (!(ss >> n >> g)) {
            break;
        }


        if (n == 0 && g == 0) {
            break; // Termina la ejecución si n y g son ambos 0
        }

        vector<MatchResult> matches(n);
        for (int i = 0; i < n; i++) {
            int s, r;
            getline(cin, line);
            stringstream ss_match(line);
            ss_match >> s >> r;
            matches[i] = {s, r};
        }

        int maxPoints = 0;

        // Calcula los puntos sin comprar goles
        for (const auto &match : matches) {
            if (match.s > match.r) {
                maxPoints += 3; // Gana el partido
            } else if (match.s == match.r) {
                maxPoints += 1; // Empata el partido
                if (g != 0) {
                    g--;
                    maxPoints += 2;
                }
            }
        }

        // Calcula los puntos comprando goles
        for (const auto &match : matches) {
            if (match.s < match.r && g >= match.r - match.s) {
                // Compra suficientes goles para ganar el partido
                maxPoints += 3;       // Gana el partido
                g -= (match.r - match.s); // Reduce la cantidad de goles disponibles
            }
        }
        cout << maxPoints << endl;
    }

    return 0;
}
