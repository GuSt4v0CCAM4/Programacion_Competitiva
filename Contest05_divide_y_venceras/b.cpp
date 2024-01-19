#include <iostream>
#include <climits>
using namespace std;
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int findAngryPersons(int* producers, int* consumers, int p, int c) {
    int minAngry = INT_MAX;
    int min = 0;
    const int MAX_SIZE = 20000;
    int combined[MAX_SIZE];

    for (int i = 0; i < p; ++i) {
        combined[i] = producers[i];
    }

    for (int i = 0; i < c; ++i) {
        combined[p + i] = consumers[i];
    }

    quicksort(combined, 0, p + c - 1);
    if (p == 0) {
        cout << "0 0" << endl;
        return 0;
    }

    if (c == 0) {
        cout << producers[p - 1] << " 0" << endl;
        return producers[p - 1];
    }
    for (int i = 0; i < p + c + 1; ++i) {
        int currentPrice = combined[i];
        int angryProducers = 0;
        int angryConsumers = 0;

        for (int j = 0; j < p; ++j) {
            if (producers[j] > currentPrice) {
                angryProducers++;
            }
        }

        for (int k = 0; k < c; ++k) {
            if (consumers[k] < currentPrice) {
                angryConsumers++;
            }
        }

        int totalAngry = angryProducers + angryConsumers;

        if (totalAngry < minAngry || (totalAngry == minAngry && currentPrice < min)) {
            minAngry = totalAngry;
            min = currentPrice;
        }
    }

    cout << min << " " << minAngry << endl;
    return min;
}


int main() {
    int a;
    cin >> a;

    while (a--) {
        int p, c;
        cin >> p >> c;

        int* producers = new int[p];
        int* consumers = new int[c];

        for (int i = 0; i < p; i++) {
            cin >> producers[i];
        }

        for (int i = 0; i < c; i++) {
            cin >> consumers[i];
        }

        quicksort(producers, 0, p - 1);
        quicksort(consumers, 0, c - 1);

        findAngryPersons(producers, consumers, p, c);

        delete[] producers;
        delete[] consumers;
    }

    return 0;
}
