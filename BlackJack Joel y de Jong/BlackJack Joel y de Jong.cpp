#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Palo {
    CORAZONES,
    PICAS,
    TREBOLES,
    DIAMANTES
};

struct Carta {
    int valor;
    Palo palo;
};

Carta obtenerCartaAleatoria() {
    Carta carta;
    carta.valor = rand() % 13 + 1;
    carta.palo = static_cast<Palo>(rand() % 4);
    return carta;
}

void mostrarCarta(Carta carta) {
    string nombresCartas[] = { "AS", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    string nombresPalos[] = { "Corazones", "Picas", "Treboles", "Diamantes" };
    cout << nombresCartas[carta.valor - 1] << " de " << nombresPalos[carta.palo] << endl;
}

int calcularPuntuacion(Carta mano[], int tamanio) {
    int suma = 0;
    int numAses = 0;
    for (int i = 0; i < tamanio; i++) {
        if (mano[i].valor == 1) {
            suma += 11;
            numAses++;
        }
        else if (mano[i].valor > 10) {
            suma += 10;
        }
        else {
            suma += mano[i].valor;
        }
    }
    while (suma > 21 && numAses > 0) {
        suma -= 10;
        numAses--;
    }
    return suma;
}

int main() {
    srand(time(0));
    const int MAX_CARTAS = 10;
    Carta manoJugador[MAX_CARTAS];
    Carta manoMaquina[MAX_CARTAS];
    int indiceJugador = 0;
    int indiceMaquina = 0;
    manoJugador[indiceJugador++] = obtenerCartaAleatoria();
    manoJugador[indiceJugador++] = obtenerCartaAleatoria();
    manoMaquina[indiceMaquina++] = obtenerCartaAleatoria();

    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                    BIENVENIDOS AL BLACKJACK DEL CASINO ALTIJONG!" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    while (true) {
        cout << "Tu mano:" << endl;
        for (int i = 0; i < indiceJugador; i++) {
            mostrarCarta(manoJugador[i]);
        }

        cout << "(Total de tu mano: " << calcularPuntuacion(manoJugador, indiceJugador) << ")" << endl;
        if (calcularPuntuacion(manoJugador, indiceJugador) > 21) {
            cout << "Te has pasado de 21, has perdido" << endl;
            break;
        }

        char opcion;
        cout << "Quieres robar una carta? (s/n): ";
        cin >> opcion;
        if (opcion == 's') {
            Carta nuevaCarta = obtenerCartaAleatoria();
            manoJugador[indiceJugador++] = nuevaCarta;

            if (nuevaCarta.valor == 1) {
                cout << "Que valor queires que valga el AS? (1/11) ";
                int valorAs;
                cin >> valorAs;
                while (valorAs != 1 && valorAs != 11) {
                    cout << "El valor solo puede ser 1 u 11 ";
                    cin >> valorAs;
                }
                nuevaCarta.valor = valorAs;
            }
        }
        else {
            break;
        }
    }

    while (calcularPuntuacion(manoMaquina, indiceMaquina) < 17) {
        manoMaquina[indiceMaquina++] = obtenerCartaAleatoria();
    }
    cout << "\nMano del jugador:" << endl;
    for (int i = 0; i < indiceJugador; i++) {
        mostrarCarta(manoJugador[i]);
    }

    cout << "(Total de tu mano: " << calcularPuntuacion(manoJugador, indiceJugador) << ")" << endl;
    cout << "Mano de la maquina:" << endl;
    for (int i = 0; i < indiceMaquina; i++) {
        mostrarCarta(manoMaquina[i]);
    }

    cout << "(Total de la maquina: " << calcularPuntuacion(manoMaquina, indiceMaquina) << ")" << endl;
    int puntuacionJugador = calcularPuntuacion(manoJugador, indiceJugador);
    int puntuacionMaquina = calcularPuntuacion(manoMaquina, indiceMaquina);
    if (puntuacionJugador > 21 || (puntuacionMaquina <= 21 && puntuacionMaquina > puntuacionJugador)) {
        cout << "Eres tan malo que te ha ganado la maquina" << endl;
    }
    else if (puntuacionMaquina > 21 || puntuacionJugador > puntuacionMaquina) {
        cout << "Has ganado en el casino Altijong. FELICIDADES!!" << endl;
    }
    else {
        cout << "Acabas de empatar contra la maquina" << endl;
    }
    return 0;
}
