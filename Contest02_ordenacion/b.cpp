#include "iostream"
using namespace std;
int main()
{
    int num_cases;
    cin>>num_cases;
    for(int i=0;i<num_cases;i++){
        string caso;
        cin>>caso;
        int posibles_lugares = 0;
        int n = caso.length();
        for(int j=0;j<n;j++){
            if(caso[j]=='-'){

                bool ok = true;
                if (j > 0 && (caso[j - 1] == 'B' || caso[j - 1] == 'S'))
                    ok = false;
                if (j > 1 && (caso[j - 2] == 'B'))
                    ok = false;
                if (j < n - 1 && (caso[j + 1] == 'S'))
                    ok = false;
                if (j < n - 2 && (caso[j + 2] == 'S'))
                    ok = false;
                if (ok) {
                    posibles_lugares++;
                }

            }
        }
        cout << "Case " << i+1 << ": " << posibles_lugares<<endl;

    }
    return 0;
}
