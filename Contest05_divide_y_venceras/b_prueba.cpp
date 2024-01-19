#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef unsigned long long ull;

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(void) {
    int t;
    int p, c;
    const int MAX_SIZE = 1000;

    cin >> t;

    while (t--) {
        cin >> p >> c;
        int producers[MAX_SIZE];
        int consumers[MAX_SIZE];
        int values[MAX_SIZE * 2];

        for (int i = 0; i < p; ++i) {
            cin >> producers[i];
            values[i] = producers[i];
        }

        for (int i = 0; i < c; ++i) {
            cin >> consumers[i];
            values[p + i] = consumers[i];
        }

        values[p + c] = 0;

        quickSort(producers, 0, p - 1);
        quickSort(consumers, 0, c - 1);
        quickSort(values, 0, p + c);

        if (p == 0) {
            cout << "0 0" << endl;
            continue;
        }

        if (c == 0) {
            cout << producers[p - 1] << " 0" << endl;
            continue;
        }

        int minAngry = 1e9 + 5;
        int bestValue = 1e9 + 5;

        for (int i = 0; i < p + c + 1; ++i) {
            int idx = upper_bound(producers, producers + p, values[i]) - producers;
            int angry = p - idx;

            idx = lower_bound(consumers, consumers + c, values[i]) - consumers;
            angry += idx;

            if (angry < minAngry) {
                minAngry = angry;
                bestValue = values[i];
            } else if (angry == minAngry && values[i] < bestValue) {
                bestValue = values[i];
            }
        }

        cout << bestValue << " " << minAngry << endl;
    }

    return 0;
}
