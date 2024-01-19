#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Soldado {
public:
    int tiempoBriefing;
    int tiempoTarea;

    Soldado(int instruccion, int tarea) : tiempoBriefing(instruccion), tiempoTarea(tarea) {}
};

bool compararSoldados(const Soldado &a, const Soldado &b) {
    return a.tiempoTarea > b.tiempoTarea;
}

class EscuadronComando {
private:
    vector<Soldado> soldados;
    int totalSoldados;

public:
    EscuadronComando() : totalSoldados(0) {}

    void agregarSoldado(int instruccion, int tarea) {
        soldados.emplace_back(instruccion, tarea);
        totalSoldados++;
    }

    int calcularTiempoTotal() {
        sort(soldados.begin(), soldados.end(), compararSoldados);

        int tiempoTotal = 0;
        int tiempoActual = 0;

        for (int i = 0; i < totalSoldados; ++i) {
            tiempoActual += soldados[i].tiempoBriefing;
            tiempoTotal = max(tiempoTotal, tiempoActual + soldados[i].tiempoTarea);
        }

        return tiempoTotal;
    }
};

int main() {
    int nCaso = 1;

    while (true) {
        int N;
        cin >> N;

        if (N == 0) {
            break;
        }

        EscuadronComando escuadron;

        for (int i = 0; i < N; ++i) {
            int instruccion, tarea;
            cin >> instruccion >> tarea;
            escuadron.agregarSoldado(instruccion, tarea);
        }

        int tiempoTotal = escuadron.calcularTiempoTotal();
        cout << "Case " << nCaso << ": " << tiempoTotal << endl;
        nCaso++;
    }

    return 0;
}
