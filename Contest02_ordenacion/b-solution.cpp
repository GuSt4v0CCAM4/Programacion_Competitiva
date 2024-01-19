#include <iostream>
#include <string>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;
    for(int c=0;c<num_cases;c++) {
        string caso;
        cin >> caso;
        int n = caso.length();
        caso = "-" + caso + "--";

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (caso[i] == '-') {
                bool ok= true;

                if (caso[i + 1] == 'B' || caso[i + 2] == 'B' || caso[i - 1] == 'S' || caso[i + 1] == 'S') {
                    ok = false;
                }

                if (ok) {
                    count++;
                }
            }
        }

        cout << "Case " << c+1 << ": " << count << endl;
    }
    return 0;
}
