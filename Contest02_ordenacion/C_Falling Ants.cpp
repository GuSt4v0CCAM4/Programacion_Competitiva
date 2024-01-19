#include <iostream>
using namespace std;

int main() {
    int n, l, w, h, vol, mxH;

    while (cin >> n && n) {
        mxH = vol = 0;

        while (n--) {
            cin >> l >> w >> h;

            if (mxH < h) {
                mxH = h;
                vol = l * w * h;
            } else if (mxH == h) {
                vol = max(vol, l * w * h);
            }
        }

        cout << vol << endl;
    }

    return 0;
}