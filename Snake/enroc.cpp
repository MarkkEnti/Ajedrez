using namespace std;
#include <iostream>
//La funcion del enroque cuenta con las 4 variables: enroquederechaN,  enroqueizquierdaN, enroquederecha, enroqueizquierda para asegurar que las torres no se han movido
void enroc(int fila, int columna, int fila2, int columna2, string Tablero[9][9], bool& path, bool& cambio, bool& enroquederechaN, bool& enroqueizquierdaN, bool& enroquederecha, bool& enroqueizquierda) {
    //La primera parte detecta si hay piezas entre la torre y el rey, si encuentra que no, hace el enroque.
    //Para negros
    if (cambio == true) {
        if (enroquederechaN == true) {
            for (int i = 6; i <= 7; ++i) {
                if (Tablero[1][i] != "*") {
                    path = false;
                    break;
                }
                else {
                    Tablero[1][5] = "*";
                    Tablero[1][8] = "*";
                    Tablero[1][7] = "k";
                    Tablero[1][6] = "t";
                    path = true;
                    enroquederechaN = false;
                    enroqueizquierdaN = false;
                    break;
                }
            }
        }

        if (enroqueizquierdaN == true) {
            for (int i = 2; i <= 4; ++i) {
                if (Tablero[1][i] != "*") {
                    path = false;
                }
                else {
                    Tablero[1][1] = "*";
                    Tablero[1][3] = "k";
                    Tablero[1][4] = "t";
                    path = true;
                    enroqueizquierdaN = false;
                    enroquederechaN = false;
                    break;
                }
            }
        }
    }
    //Para blancos
    else {
        if (enroquederecha == true) {
            for (int i = 5; i <= 7; ++i) {
                if (Tablero[8][i] != "*") {
                    path = false;
                    break;
                }
                else {
                    Tablero[8][4] = "*";
                    Tablero[8][8] = "*";
                    Tablero[8][7] = "K";
                    Tablero[8][6] = "T";
                    path = true;
                    enroquederecha = false;
                    enroqueizquierda = false;
                    break;
                }
            }
        }

        if (enroqueizquierda == true) {
            for (int i = 2; i <= 4; ++i) {
                if (Tablero[8][i] != "*") {
                    path = false;
                }
                else {
                    Tablero[8][1] = "*";
                    Tablero[8][3] = "K";
                    Tablero[8][4] = "T";
                    path = true;
                    enroqueizquierda = false;
                    enroquederecha = false;
                    break;
                }
            }
        }
    }
}