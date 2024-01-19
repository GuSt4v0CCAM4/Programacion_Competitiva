#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int N, x, T, K, teaCharge, maxPayment, maxDishes;
int price[101], favour[101], memo[101][22][1001];

double getFavour(int payment, int dishes, int available) {
    int totalPayment = ceil((double)(payment + teaCharge) * 1.1);

    if (maxPayment < totalPayment || maxDishes < dishes)
        return -1e9;

    if (maxPayment == totalPayment || available < 0 || maxDishes == dishes)
        return 0;

    int &c = memo[available][dishes][payment];

    if (c != -1)
        return c;

    return c = max(
            favour[available] + getFavour(payment + price[available], dishes + 1, available - 1),
            max((favour[available] << 1) + getFavour(payment + (price[available] << 1), dishes + 2, available - 1),
                getFavour(payment, dishes, available - 1)));
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool firstOutput = true;

    while (cin >> N >> x >> T >> K && (N || x || T || K)) {
        if (!firstOutput) {
            cout << "\n";
        } else {
            firstOutput = false;
        }

        for (int i = 0; i < K; ++i) {
            favour[i] = 0;
            cin >> price[i];

            for (int j = 0; j < N + 1; ++j) {
                int f;
                cin >> f;
                favour[i] += f;
            }
        }

        memset(memo, -1, sizeof(memo));

        teaCharge = T * (N + 1);
        maxPayment = x * (N + 1);
        maxDishes = (N + 1) << 1;

        cout.precision(2);
        cout << fixed << getFavour(0, 0, K - 1) / (double)(N + 1);
    }

    return 0;
}

