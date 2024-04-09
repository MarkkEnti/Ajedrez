using namespace std;
#include <iostream>

void reina(int fila, int columna, int fila2, int columna2, string Tablero[9][9], bool& path, bool& cambio) {
    path = true; 
    if (Tablero[fila][columna] == "Q" || Tablero[fila][columna] == "q")     {  
        if (columna >= 1 && columna <= 8 && fila >= 1 && fila <= 8 && columna2 >= 1 && columna2 <= 8 && fila2 >= 1 && fila2 <= 8)     {
            //Movimiento horizontal
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
            //Movimiento vertical
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
            //Movimiento diagonal
            else if (abs(fila2 - fila) == abs(columna2 - columna)) {
                if (columna2 > columna && fila2 < fila) { 
                    for (int i = 1; fila - i > fila2 && columna + i < columna2; ++i) {
                        if (Tablero[fila - i][columna + i] != "*") {
                            path = false;
                            cout << "No se puede mover la pieza ahi" << endl;
                            break;
                        }
                    }
                }
                else if (columna2 < columna&& fila2 < fila) { 
                    for (int i = 1; fila - i > fila2 && columna - i > columna2; --i) {
                        if (Tablero[fila - i][columna - i] != "*") {
                            path = false;
                            cout << "No se puede mover la pieza ahi" << endl;
                            break;
                        }
                    }
                }
                else if (columna2 > columna && fila2 > fila) { 
                    for (int i = 1; fila + i < fila2 && columna + i < columna2; ++i) {
                        if (Tablero[fila + i][columna + i] != "*") {
                            path = false;
                            cout << "No se puede mover la pieza ahi" << endl;
                            break;
                        }
                    }
                }
                else if (columna2 < columna && fila2 > fila) { 
                    for (int i = 1; fila + i < fila2 && columna - i > columna2; --i) {
                        if (Tablero[fila + i][columna - i] != "*") {
                            path = false;
                            cout << "No se puede mover la pieza ahi" << endl;
                            break;
                        }
                    }
                }
            }
            else {
                path = false;
                cout << "Movimiento no valido" << endl;
            }           
            if (path == true) {
                if (cambio == true) {
                    if (Tablero[fila][columna] == "Q") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }
                    if (path == true) {
                        if (Tablero[fila2][columna2] == "*" ||   Tablero[fila2][columna2] == "P" ||  Tablero[fila2][columna2] == "H" || Tablero[fila2][columna2] == "T" ||
                            Tablero[fila2][columna2] == "B" ||   Tablero[fila2][columna2] == "Q" ||  Tablero[fila2][columna2] == "K") 
                        {
                            path = true;
                            Tablero[fila2][columna2] = "q";
                            Tablero[fila][columna] = "*";
                        }
                        else {
                            path = false;
                            cout << "No puedes mover la pieza ahi, hay una pieza de tu equipo" << endl;
                        }
                    }
                }
                if (cambio == false) {
                    if (Tablero[fila][columna] == "q") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }
                    if (path == true) {
                        if (Tablero[fila2][columna2] == "*" ||  Tablero[fila2][columna2] == "p" ||  Tablero[fila2][columna2] == "h" ||   Tablero[fila2][columna2] == "t" ||
                            Tablero[fila2][columna2] == "b" ||  Tablero[fila2][columna2] == "q" ||  Tablero[fila2][columna2] == "k") 
                        {
                            path = true;
                            Tablero[fila2][columna2] = "Q";
                            Tablero[fila][columna] = "*";
                        }
                        else {
                            path = false;
                            cout << "No puedes mover la pieza ahi, hay una pieza de tu equipo" << endl;
                        }
                    }
                }
            }     
           }
        else {
            cout << "Movimiento fuera del tablero" << endl;
            path = false;
        }
    }
    else {
        cout << "No hay una pieza ahi" << endl;
        path = false;
    }
}
