#include <iostream>
#include <algorithm>
using namespace std;
class Block {
private:
    int left;
    int middle;

public:
    Block() : left(0), middle(0) {}
    Block(int l, int m) : left(l), middle(m) {}
    bool operator<(const Block& other) const {
        return left < other.left || (left == other.left && middle < other.middle);
    }
    int Middle() const {
        return middle;
    }

};

int main() {
    int n;
    while (cin >> n && n) {
        Block *blocks = new Block[n];
        for (int i = 0; i < n; ++i) {
            int l, m;
            cin >> l >> m;
            blocks[i] = Block(l, m);
        }

        sort(blocks, blocks + n);

        int size = 0;
        int *seq = new int[n];
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(seq, seq + size, blocks[i].Middle());
            int j = it - seq;
            if (it == seq + size)
                seq[size++] = blocks[i].Middle();
            else
                seq[j] = blocks[i].Middle();
            if (j == size)
                ++size;
        }
        cout << size << "\n";
        delete[] blocks;
        delete[] seq;
    }
    cout << "*\n";
    return 0;
}
