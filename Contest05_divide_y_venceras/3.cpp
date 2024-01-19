#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <random>
#include <algorithm>
using namespace std;
using namespace std::chrono;
//COLA
class Cola {
private:
    struct Nodo {
        vector<int> datos;
        Nodo* siguiente;
    };

    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    void encolar(const vector<int>& valores) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->datos = valores;
        nuevoNodo->siguiente = nullptr;

        if (estaVacia()) {
            frente = nuevoNodo;
            final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }

        //cout << "Se ha encolado el vector de elementos." << endl;
    }

    void desencolar() {
        if (estaVacia()) {
            //cout << "La cola está vacía. No se puede desencolar." << endl;
        } else {
            Nodo* temp = frente;
            frente = frente->siguiente;
            //cout << "Se ha desencolado el vector de elementos." << endl;
            delete temp;

            if (frente == nullptr) {
                final = nullptr;
            }
        }
    }
};
//PILA
class Pila {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
    };

    Nodo* cima;

public:
    Pila() : cima(nullptr) {}

    ~Pila() {
        vector<int> elementosDesapilados;
        while (!estaVacia()) {
            Nodo* temp = cima;
            cima = cima->siguiente;
            elementosDesapilados.push_back(temp->dato);
            delete temp;
        }

        //cout << "Se han desapilado todos los elementos de la pila." << endl;

        for (int elemento : elementosDesapilados) {
            cout << "Elemento desapilado: " << elemento << endl;
        }
    }

    bool estaVacia() {
        return cima == nullptr;
    }

    void apilar(vector<int> &elementos) {
        for (int elemento : elementos) {
            Nodo* nuevoNodo = new Nodo;
            nuevoNodo->dato = elemento;
            nuevoNodo->siguiente = cima;
            cima = nuevoNodo;

            //cout << "Se ha apilado el elemento " << elemento << endl;
        }
    }

    void desapilar(vector<int> &elementos) {
        if (estaVacia()) {
            cout << "La pila está vacía. No se puede desapilar." << endl;
        } else {
            while (!estaVacia()) {
                Nodo* temp = cima;
                cima = cima->siguiente;
                elementos.push_back(temp->dato);
                delete temp;
            }

            //cout << "Se han desapilado todos los elementos de la pila." << endl;
        }
    }
};
//LISTA DOBLEMENTE ENLAZADA
class NodoListaDoble {
public:
    int dato;
    NodoListaDoble* siguiente;
    NodoListaDoble* anterior;

    NodoListaDoble(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

class ListaDoblementeEnlazada {
private:
    NodoListaDoble* cabeza;
    NodoListaDoble* cola;

public:
    ListaDoblementeEnlazada() : cabeza(nullptr), cola(nullptr) {}

    void insertar(const vector<int>& valores) {
        for (int valor : valores) {
            NodoListaDoble* nuevoNodo = new NodoListaDoble(valor);

            if (cabeza == nullptr) {
                cabeza = nuevoNodo;
                cola = nuevoNodo;
            } else {
                cola->siguiente = nuevoNodo;
                nuevoNodo->anterior = cola;
                cola = nuevoNodo;
            }

            //cout << "Se ha insertado el elemento " << valor << " en la lista doblemente enlazada." << endl;
        }
    }

    bool buscar(const vector<int>& valores) {
        for (int valor : valores) {
            bool encontrado = false;
            NodoListaDoble* actual = cabeza;
            while (actual != nullptr) {
                if (actual->dato == valor) {
                    encontrado = true;
                    break;
                }
                actual = actual->siguiente;
            }
            if (!encontrado) {
                return false; // Si uno de los valores no se encuentra, retornar false
            }
        }
        return true; // Si todos los valores se encuentran, retornar true
    }
};
//ARBOL BINARIO
class NodoArbolBinario {
public:
    int dato;
    NodoArbolBinario* izquierda;
    NodoArbolBinario* derecha;

    NodoArbolBinario(int valor) : dato(valor), izquierda(nullptr), derecha(nullptr) {}
};

class ArbolBinario {
private:
    NodoArbolBinario* raiz;

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertar(const vector<int>& valores) {
        for (int valor : valores) {
            raiz = insertarRecursivo(raiz, valor);
            //cout << "Se ha insertado el elemento " << valor << " en el árbol binario." << endl;
        }
    }

    bool buscar(const vector<int>& valores) {
        for (int valor : valores) {
            if (!buscarRecursivo(raiz, valor)) {
                return false; // Si uno de los valores no se encuentra, retornar false
            }
        }
        return true; // Si todos los valores se encuentran, retornar true
    }

private:
    NodoArbolBinario* insertarRecursivo(NodoArbolBinario* nodo, int valor) {
        if (nodo == nullptr) {
            return new NodoArbolBinario(valor);
        }

        if (valor < nodo->dato) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        } else if (valor > nodo->dato) {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }

        return nodo;
    }

    bool buscarRecursivo(NodoArbolBinario* nodo, int valor) {
        if (nodo == nullptr) {
            return false;
        }

        if (nodo->dato == valor) {
            return true;
        }

        if (valor < nodo->dato) {
            return buscarRecursivo(nodo->izquierda, valor);
        } else {
            return buscarRecursivo(nodo->derecha, valor);
        }
    }
};

// Función para llenar el vector
void fillRandom(vector<int> &vec, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, size - 1);

    vec.clear();
    for (int i = 0; i < size; ++i) {
        vec.push_back(dis(gen));
    }
}


int main() {

    int choice, rep=50, estab=10, pr;
    string name_doc, name_doc2;
    Pila p;
    Cola q;
    ListaDoblementeEnlazada l;
    ArbolBinario a;
    do {
        cout << "\nMenu:\n"
                  << "1. Pilas\n"
                  << "2. Colas\n"
                  << "3. Listas Doblemente Enlazadas\n"
                  << "4. Árboles Binarios\n"
                  << "0. Salir\n"
                  << "Ingrese su elección: ";
        cin >> choice;
        name_doc = "datos03_a.txt";
        name_doc2 = "datos04_a.txt";
        std::ofstream archivo(name_doc, std::ios::app);
        std::ofstream archivo2(name_doc2, std::ios::app);
        switch (choice) {
            case 1:
                for (int i = 1; i <= rep; ++i) {
                    int pr1 = 0,pr2 = 0;
                    int size = i * 1000;
                    vector<int> vec(size);
                    fillRandom(vec, size);
                    for (int j = 0; j < estab; ++j) {
                        auto start = high_resolution_clock::now();
                        p.apilar(vec);
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start);
                        pr1 += duration.count();
                        auto start2 = high_resolution_clock::now();
                        p.desapilar(vec);
                        auto stop2 = high_resolution_clock::now();
                        auto duration2 = duration_cast<microseconds>(stop2 - start2);
                        //cout << "Tiempo de ejecución para la función y tamaño del vector (" << size << "): " << duration.count() << " microsegundos" << endl;
                        pr2 += duration2.count();
                        //cout << duration.count() << endl;
                    }
                    pr1 = pr1 / estab;
                    pr2 = pr2 / estab;
                    cout << size << " a " << pr1 << endl;
                    cout << size << " d " << pr2 << endl;
                    archivo <<size<<" "<<pr1<<endl;
                    archivo2 <<size<<" "<<pr2<<endl;
                }
                archivo.close();
                archivo2.close();

                break;
            case 2:
                for (int i = 1; i <= rep; ++i) {
                    int pr1 = 0,pr2 = 0;
                    int size = i * 1000;
                    vector<int> vec(size);
                    fillRandom(vec, size);
                    for (int j = 0; j < estab; ++j) {
                        auto start = high_resolution_clock::now();
                        q.encolar(vec);
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start);
                        pr1 += duration.count();
                        auto start2 = high_resolution_clock::now();
                        int i= 0;
                        while(i++ < size) {
                            q.desencolar();
                        }
                        auto stop2 = high_resolution_clock::now();
                        auto duration2 = duration_cast<microseconds>(stop2 - start2);
                        //cout << "Tiempo de ejecución para la función y tamaño del vector (" << size << "): " << duration.count() << " microsegundos" << endl;
                        pr2 += duration2.count();
                        //cout << duration.count() << endl;
                    }
                    pr1 = pr1 / estab;
                    pr2 = pr2 / estab;
                    cout << size << " a " << pr1 << endl;
                    cout << size << " d " << pr2 << endl;
                    archivo <<size<<" "<<pr1<<endl;
                    archivo2 <<size<<" "<<pr2<<endl;
                }
                archivo.close();
                archivo2.close();

                break;
            case 3:

                for (int i = 1; i <= rep; ++i) {
                    int pr1 = 0,pr2 = 0;
                    int size = i * 1000;
                    vector<int> vec(size);
                    fillRandom(vec, size);
                    for (int j = 0; j < estab; ++j) {
                        auto start = high_resolution_clock::now();
                        l.insertar(vec);
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start);
                        pr1 += duration.count();
                        auto start2 = high_resolution_clock::now();
                        l.buscar(vec);
                        auto stop2 = high_resolution_clock::now();
                        auto duration2 = duration_cast<microseconds>(stop2 - start2);
                        //cout << "Tiempo de ejecución para la función y tamaño del vector (" << size << "): " << duration.count() << " microsegundos" << endl;
                        pr2 += duration2.count();
                        //cout << duration.count() << endl;
                    }
                    pr1 = pr1 / estab;
                    pr2 = pr2 / estab;
                    cout << size << " a " << pr1 << endl;
                    cout << size << " d " << pr2 << endl;
                    archivo <<size<<" "<<pr1<<endl;
                    archivo2 <<size<<" "<<pr2<<endl;
                }
                archivo.close();
                archivo2.close();

                break;
            case 4:
                for (int i = 1; i <= rep; ++i) {
                    int pr1 = 0,pr2 = 0;
                    int size = i * 1000;
                    vector<int> vec(size);
                    fillRandom(vec, size);
                    for (int j = 0; j < estab; ++j) {
                        auto start = high_resolution_clock::now();
                        a.insertar(vec);
                        auto stop = high_resolution_clock::now();
                        auto duration = duration_cast<microseconds>(stop - start);
                        pr1 += duration.count();
                        auto start2 = high_resolution_clock::now();
                        a.buscar(vec);
                        auto stop2 = high_resolution_clock::now();
                        auto duration2 = duration_cast<microseconds>(stop2 - start2);
                        //cout << "Tiempo de ejecución para la función y tamaño del vector (" << size << "): " << duration.count() << " microsegundos" << endl;
                        pr2 += duration2.count();
                        //cout << duration.count() << endl;
                    }
                    pr1 = pr1 / estab;
                    pr2 = pr2 / estab;
                    cout << size << " a " << pr1 << endl;
                    cout << size << " d " << pr2 << endl;
                    archivo <<size<<" "<<pr1<<endl;
                    archivo2 <<size<<" "<<pr2<<endl;
                }
                archivo.close();
                archivo2.close();

                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}