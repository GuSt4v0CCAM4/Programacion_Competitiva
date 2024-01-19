#include <iostream>
#include <string>
using namespace std;

struct nodo {
    string n;
    struct nodo* sgte;
};

typedef nodo* ptrPila;

void sleep(ptrPila& p, string person) {
    ptrPila aux;
    aux = new (struct nodo);
    aux->n = person;
    aux->sgte = p;
    p = aux;
}

bool kick(ptrPila& p) {
    if (p == NULL) {
        return false;
    }
    ptrPila aux = p;
    p = aux->sgte;
    delete (aux);
    return true;
}

string test(ptrPila p) {
    if (p != NULL) {
        return p->n;
    } else {
        return "Not in a dream";
    }
}

int main() {
    ptrPila p = NULL;
    int opc;
    cin >> opc;
    while (opc--) {
        string consulta;
        cin >> consulta;
        if (consulta == "Sleep") {
            string persona;
            cin >> persona;
            sleep(p, persona);
        } else if (consulta == "Kick") {
            kick(p);
        } else if (consulta == "Test") {
            cout << test(p) << endl;
        }
    }
    return 0;
}
