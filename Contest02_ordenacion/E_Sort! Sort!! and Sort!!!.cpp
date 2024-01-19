#include <iostream>

using namespace std;

bool par(int num) {
    return num % 2 != 0;
}

int partition(int arr[], int indices[], int low, int high, int M) {
    int pivote = arr[indices[high]];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (abs(arr[indices[j]]) % M != abs(pivote) % M) {
            if (abs(arr[indices[j]]) % M < abs(pivote) % M) {
                i++;
                swap(indices[i], indices[j]);
            }
        } else {
            if (par(arr[indices[j]]) && !par(pivote)) {
                i++;
                swap(indices[i], indices[j]);
            } else if (!par(arr[indices[j]]) && par(pivote)) {
                // No hacer nada, mantener el orden original
            } else if (par(arr[indices[j]]) && par(pivote)) {
                if (arr[indices[j]] > pivote) {
                    i++;
                    swap(indices[i], indices[j]);
                }
            } else {
                if (arr[indices[j]] < pivote) {
                    i++;
                    swap(indices[i], indices[j]);
                }
            }
        }
    }

    swap(indices[i + 1], indices[high]);
    return i + 1;
}

void quicksort(int arr[], int indices[], int low, int high, int M) {
    if (low < high) {
        int pivotIndex = partition(arr, indices, low, high, M);
        quicksort(arr, indices, low, pivotIndex - 1, M);
        quicksort(arr, indices, pivotIndex + 1, high, M);
    }
}

int main() {
    int N, M;

    while (cin >> N >> M && !(N == 0 && M == 0)) {
        int numbers[N];
        int indices[N];

        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
            indices[i] = i;
        }

        quicksort(numbers, indices, 0, N - 1, M);

        cout << N << " " << M << endl;

        for (int i = 0; i < N; i++) {
            cout << numbers[indices[i]] << endl;
        }
    }

    cout << "0 0" << endl;

    return 0;
}
