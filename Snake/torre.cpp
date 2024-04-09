using namespace std;
#include <iostream>

void torre(int fila, int columna, int fila2, int columna2, string Tablero[9][9], bool& path, bool& cambio, bool& enroqueizquierdaN, bool& enroquederechaN, bool& enroqueizquierda, bool& enroquederecha) 
{    if ((Tablero[fila][columna] == "T" && !cambio) || (Tablero[fila][columna] == "t" && cambio)) {
        if (columna >= 1 && columna <= 8 && fila >= 1 && fila <= 8 &&
            columna2 >= 1 && columna2 <= 8 && fila2 >= 1 && fila2 <= 8) {

            if (fila2 == fila) {
                if (columna < columna2) {
                    for (int i = columna + 1; i < columna2; ++i) {
                        if (Tablero[fila][i] != "*") {
                            path = false;
                            cout << "No puedes mover la pieza ahi" << endl;
                            break;
                        }
                    }
                }
                else {
                    for (int i = columna - 1; i > columna2; --i) {
                        if (Tablero[fila][i] != "*") {
                            path = false;
                            cout << "No puedes mover la pieza ahi" << endl;
                            break;
                        }
                    }
                }
            }
            else if (columna == columna2) {
                if (fila < fila2) {
                    for (int i = fila + 1; i < fila2; ++i) {
                        if (Tablero[i][columna] != "*") {
                            path = false;
                            cout << "No puedes mover la pieza ahi" << endl;
                            break;
                        }
                    }
                }
                else {
                    for (int i = fila - 1; i > fila2; --i) {
                        if (Tablero[i][columna] != "*") {
                            path = false;
                            cout << "No puedes mover la pieza ahi" << endl;
                            break;
                        }
                    }
                }
            }
            else if (abs(fila2 - fila) == abs(columna2 - columna)) {
                int distance = abs(fila2 - fila);
                for (int i = 1; i < distance; ++i) {
                    int rowOffset = (fila2 > fila) ? i : -i;
                    int colOffset = (columna2 > columna) ? i : -i;
                    if (Tablero[fila + rowOffset][columna + colOffset] != "*") {
                        path = false;
                        cout << "No se puede mover la pieza ahi" << endl;
                        break;
                    }
                }
            }

            if (cambio == true) {
                
                if (Tablero[fila2][columna2] == "*" ||  Tablero[fila2][columna2] == "P" ||  Tablero[fila2][columna2] == "H" ||  Tablero[fila2][columna2] == "T" ||
                    Tablero[fila2][columna2] == "B" ||  Tablero[fila2][columna2] == "Q" ||  Tablero[fila2][columna2] == "K")
                {
                    path = true;
                    Tablero[fila2][columna2] = "t";
                    Tablero[fila][columna] = "*";
                }
            }
            if (cambio == false) {                
                if (Tablero[fila2][columna2] == "*" ||   Tablero[fila2][columna2] == "p" ||  Tablero[fila2][columna2] == "h" ||  Tablero[fila2][columna2] == "t" ||
                    Tablero[fila2][columna2] == "b" ||   Tablero[fila2][columna2] == "q" ||  Tablero[fila2][columna2] == "k")
                {
                    path = true;
                    Tablero[fila2][columna2] = "T";
                    Tablero[fila][columna] = "*";
                }
            }
                else {
                    path = false;
                    cout << "No puedes mover la pieza ahi, hay una pieza de tu equipo" << endl;
                }            
        }
        else {
            path = false;
            cout << "Movimiento fuera del tablero" << endl;
        }
    }
    else {
        cout << "No hay una pieza ahi " << endl;
        path = false;
    }
    if (Tablero[1][8] != "t") {
        enroquederechaN = false;        
    }

    if (Tablero[1][1] != "t") {       
        enroqueizquierdaN = false;
    }

    if (Tablero[8][8] != "T") {
        enroquederecha = false;     
    }

    if (Tablero[8][1] != "T") {       
        enroqueizquierda = false;
    }
}
