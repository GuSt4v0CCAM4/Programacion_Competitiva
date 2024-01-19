#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main()
{
    int n, pos;
    vector<int> lista;
    while(cin>>n){
        lista.push_back(n);
        sort(lista.begin(), lista.end());
        pos = lista.size();
        if(pos%2==0){
            int cas = lista[pos/2]+lista[pos/2 - 1];
            cout<<cas/2<<endl;
        }else{
            cout<<lista[int(pos/2)]<<endl;
        }
    }

    return 0;
}