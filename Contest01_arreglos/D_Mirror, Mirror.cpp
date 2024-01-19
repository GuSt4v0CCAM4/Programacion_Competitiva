#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Función para verificar si dos patrones son iguales
bool arePatternsEqual(vector<string>& original, vector<string>& transformed, int size) {
    for (int i = 0; i < size; i++) {
        if (original[i] != transformed[i]) {
            return false;
        }
    }
    return true;
}

// Función para verificar si dos patrones son reflejos verticales uno del otro
bool arePatternsVerticallyReflected(vector<string>& original, vector<string>& transformed, int size) {
    for (int i = 0; i < size; i++) {
        if (original[i] != transformed[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int patternID = 1;
    int size;

    while (cin >> size) {
        if (size == 0) break;

        // Leer el patrón original
        vector<string> originalPattern(size);
        vector<string> transformedPattern(size);

        for (int i = 0; i < size; i++) {
            cin >> originalPattern[i] >> transformedPattern[i];
        }

        if (arePatternsEqual(originalPattern, transformedPattern, size)) {
            cout << "Pattern " << patternID << " was preserved." << endl;
        } else if (arePatternsVerticallyReflected(originalPattern, transformedPattern, size)) {
            cout << "Pattern " << patternID << " was reflected vertically.";
            if (originalPattern == transformedPattern) {
                cout << " ";
            } else {
                cout << " and";
            }
            cout << " rotated 180 degrees." << endl;
        } else {
            // Try rotations
            bool rotated = false;
            for (int rotation = 1; rotation <= 3; rotation++) {
                vector<string> rotatedPattern(size);
                for (int i = 0; i < size; i++) {
                    rotatedPattern[i] = "";
                    for (int j = 0; j < size; j++) {
                        rotatedPattern[i] += originalPattern[size - j - 1][i];
                    }
                }

                if (rotatedPattern == transformedPattern) {
                    if (rotation == 1) {
                        cout << "Pattern " << patternID << " was rotated 90 degrees." << endl;
                    } else if (rotation == 2) {
                        cout << "Pattern " << patternID << " was rotated 180 degrees." << endl;
                    } else if (rotation == 3) {
                        cout << "Pattern " << patternID << " was rotated 270 degrees." << endl;
                    }
                    rotated = true;
                    break;
                }

                originalPattern = rotatedPattern; // Intenta con la siguiente rotación
            }

            if (!rotated) {
                cout << "Pattern " << patternID << " was improperly transformed." << endl;
            }
        }

        patternID++;
    }

    return 0;
}

