#include <iostream>
using namespace std;
int main(){
    string cadena;
    int cont, dist, max;
    while (cin>>cadena){
        cont = dist = max = 0;
        while (cont < cadena.length()){
            if (cadena[cont] == '.') max++;
            else break;
            cont++;
        }
        cont ++;
        max = 2*max -1;
        while (cont < cadena.length()){
            if (cadena[cont] == '.') dist++;
            else
            {
                if (dist > max) max = dist;
                dist = 0;
            }
            cont++;
        }
        if ((dist*2 - 1) > max) max = dist*2 - 1;
        cout << (max-1)/2 << endl;
    }
    return 0;
}
