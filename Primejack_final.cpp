#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Inicializar la semilla para la generación de números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Mensaje de bienvenida
    cout << "********************************\n";
    cout << "   ¡Bienvenido a PrimeJack!\n";
    cout << "********************************\n\n";

    // Solicitar la cantidad de jugadores
    int n;
    cout << "¿Cuántos jugadores participarán? ";
    cin >> n;

    // Variables para almacenar el mejor puntaje y el ganador
    int mejor_puntaje = 0;
    int ganador = 0;
    bool empate = false;

    // Ciclo para manejar los turnos de cada jugador
    for (int jugador = 1; jugador <= n; jugador++) {
        cout << "\nTurno del Jugador " << jugador << endl;
        int puntaje = 0;
        bool primer_lanzamiento = true;
        bool seguir_jugando = true;

        // Ciclo interno para los lanzamientos de un jugador
        while (seguir_jugando) {
            // Lanzamiento de los dados
            cout << "Presiona Enter para lanzar los dados...";
            cin.ignore();
            cin.get();
            int dado1 = rand() % 6 + 1;
            int dado2 = rand() % 6 + 1;
            cout << "Lanzaste " << dado1 << " y " << dado2 << endl;

            // Caso de lanzar dos números iguales en el primer lanzamiento
            if (primer_lanzamiento && dado1 == dado2) {
                if (dado1 == 6) {
                    int opcion;
                    cout << "¿Deseas 1) seguir normalmente, 2) dividir tu lanzamiento o 3) realizar un último lanzamiento con un dado? (1/2/3): ";
                    cin >> opcion;
                    if (opcion == 2) {
                        int puntaje_total_1, puntaje_total_2;
                        cout << "Lanzamiento 1 con tres dados:\n";
                        cout << "Presiona Enter para lanzar tres dados...";
                        cin.ignore();
                        cin.get();
                        int dado1_1 = rand() % 6 + 1;
                        int dado1_2 = rand() % 6 + 1;
                        int dado1_3 = rand() % 6 + 1;
                        puntaje_total_1 = dado1_1 + dado1_2 + dado1_3 + dado1;
                        cout << "Lanzaste " << dado1_1 << ", " << dado1_2 << ", " << dado1_3 << " y tu puntaje total es: " << puntaje_total_1 << endl;

                        cout << "Lanzamiento 2 con tres dados:\n";
                        cout << "Presiona Enter para lanzar tres dados...";
                        cin.ignore();
                        cin.get();
                        int dado2_1 = rand() % 6 + 1;
                        int dado2_2 = rand() % 6 + 1;
                        int dado2_3 = rand() % 6 + 1;
                        puntaje_total_2 = dado2_1 + dado2_2 + dado2_3 + dado1;
                        cout << "Lanzaste " << dado2_1 << ", " << dado2_2 << ", " << dado2_3 << " y tu puntaje total es: " << puntaje_total_2 << endl;

                        puntaje = max(puntaje_total_1, puntaje_total_2);
                        cout << "Tu mejor puntaje es: " << puntaje << endl;
                        break;
                    } else if (opcion == 3) {
                        cout << "Presiona Enter para lanzar un dado...";
                        cin.ignore();
                        cin.get();
                        int dado_unico = rand() % 6 + 1;
                        puntaje += (12 + dado_unico);  // Sumar el valor del dado al puntaje
                        cout << "Lanzaste " << dado_unico << " y tu puntaje final es: " << puntaje << endl;
                        break;
                    }
                } else {
                    int opcion;
                    cout << "¿Deseas 1) seguir normalmente o 2) dividir tu lanzamiento? (1/2): ";
                    cin >> opcion;
                    if (opcion == 2) {
                        int puntaje_total_1, puntaje_total_2;
                        cout << "Lanzamiento 1 con tres dados:\n";
                        cout << "Presiona Enter para lanzar tres dados...";
                        cin.ignore();
                        cin.get();
                        int dado1_1 = rand() % 6 + 1;
                        int dado1_2 = rand() % 6 + 1;
                        int dado1_3 = rand() % 6 + 1;
                        puntaje_total_1 = dado1_1 + dado1_2 + dado1_3 + dado1;
                        cout << "Lanzaste " << dado1_1 << ", " << dado1_2 << ", " << dado1_3 << " y tu puntaje total es: " << puntaje_total_1 << endl;

                        cout << "Lanzamiento 2 con tres dados:\n";
                        cout << "Presiona Enter para lanzar tres dados...";
                        cin.ignore();
                        cin.get();
                        int dado2_1 = rand() % 6 + 1;
                        int dado2_2 = rand() % 6 + 1;
                        int dado2_3 = rand() % 6 + 1;
                        puntaje_total_2 = dado2_1 + dado2_2 + dado2_3 + dado1;
                        cout << "Lanzaste " << dado2_1 << ", " << dado2_2 << ", " << dado2_3 << " y tu puntaje total es: " << puntaje_total_2 << endl;

                        puntaje = max(puntaje_total_1, puntaje_total_2);
                        cout << "Tu mejor puntaje es: " << puntaje << endl;
                        break;
                    }
                }
            }

            // Acumulación del puntaje en los casos normales
            puntaje += dado1 + dado2;
            cout << "Puntaje acumulado: " << puntaje << endl;

            // Caso de pasar de 23 puntos
            if (puntaje > 23) {
                cout << "Te pasaste de 23, ¡has perdido!" << endl;
                puntaje = 0;
                break;
            }

            // Preguntar si el jugador desea seguir lanzando
            if (puntaje == 23) {
                break;
            } else {
                char respuesta;
                cout << "¿Quieres seguir lanzando? (s/n): ";
                cin >> respuesta;
                if (respuesta != 's') {
                    break;
                }
            }

            primer_lanzamiento = false;
        }

        // Verificación de si el puntaje actual es primo (sin funciones)
        bool es_primo_actual = true;
        if (puntaje <= 1) {
            es_primo_actual = false;
        } else {
            for (int i = 2; i * i <= puntaje; i++) {
                if (puntaje % i == 0) {
                    es_primo_actual = false;
                    break;
                }
            }
        }

        // Verificación de si el mejor puntaje es primo (sin funciones)
        bool es_primo_mejor = true;
        if (mejor_puntaje <= 1) {
            es_primo_mejor = false;
        } else {
            for (int i = 2; i * i <= mejor_puntaje; i++) {
                if (mejor_puntaje % i == 0) {
                    es_primo_mejor = false;
                    break;
                }
            }
        }

        // Comparar el puntaje del jugador actual con el mejor puntaje
        if (puntaje > 0) {
            if (mejor_puntaje == 0) {
                mejor_puntaje = puntaje;
                ganador = jugador;
                empate = false;
            } else {
                if (puntaje == mejor_puntaje) {
                    empate = true;
                } else if (es_primo_actual && es_primo_mejor) {
                    if (puntaje > mejor_puntaje) {
                        mejor_puntaje = puntaje;
                        ganador = jugador;
                        empate = false;
                    }
                } else if (!es_primo_actual && !es_primo_mejor) {
                    if (puntaje > mejor_puntaje) {
                        mejor_puntaje = puntaje;
                        ganador = jugador;
                        empate = false;
                    }
                } else if (es_primo_actual) {
                    mejor_puntaje = puntaje;
                    ganador = jugador;
                    empate = false;
                }
            }
        }
    }

    // Final del juego, mostrar resultado
    if (empate) {
        cout << "\nEl juego ha terminado en empate." << endl;
    } else {
        cout << "\nEl ganador es el Jugador " << ganador << " con un puntaje de " << mejor_puntaje << "." << endl;
    }

    return 0;
}