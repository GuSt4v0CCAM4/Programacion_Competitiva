#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int N, G;
    while (cin >> N >> G) {
        vector<int> diff;
        int S, R;
        int puntos = 0;

        for (int i = 0; i < N; i++) {
            cin >> S >> R;
            if (S == R) puntos += 1;
            if (S > R) puntos += 3;
            if (R - S < 0)
                diff.push_back(11111111);
            else
                diff.push_back(R - S);
        }

        sort(diff.begin(), diff.end());
        int I = 0;

        while (G > 0 && I < N) {
            int d = G - diff[I];
            if (d < 0) {

            } else if (d == G) {
                G--;
                puntos += 2;
            } else if (d == 0) {
                G--;
                puntos += 1;
            } else {
                G = G - diff[I];
                if (G > 0) {
                    G--;
                    if (diff[I] == 11111111)
                        puntos += 2;
                    else
                        puntos += 3;
                } else {
                    puntos += 1;
                }
            }
            I++;
        }
        cout << puntos << endl;
    }

    return 0;
}