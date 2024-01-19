#include <iostream>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

Node* buildKuPellaKeSBST(int arr[], int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildKuPellaKeSBST(arr, start, mid - 1);
    root->right = buildKuPellaKeSBST(arr, mid + 1, end);

    return root;
}

void printRepresentation(Node* root) {
    if (root != nullptr) {
        std::cout << root->value;
        if (root->left != nullptr || root->right != nullptr) {
            std::cout << "(";
            printRepresentation(root->left);
            if (root->right != nullptr) {
                std::cout << ",";
                printRepresentation(root->right);
            }
            std::cout << ")";
        }
    }
}

int main() {
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; ++t) {
        int n;
        std::cin >> n;
        int* values = new int[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> values[i];
        }

        quicksort(values, 0, n - 1);

        Node* root = buildKuPellaKeSBST(values, 0, n - 1);

        std::cout << "Case #" << t << ": ";
        printRepresentation(root);
        std::cout << std::endl;

        delete[] values;
        // Liberar memoria del árbol si es necesario
        // (no se ha incluido en este ejemplo por simplicidad)
    }

    return 0;
}
