using namespace std;
#include <iostream>

void alfil(int fila, int columna, int fila2, int columna2, string Tablero[9][9], bool& path, bool& cambio) {
    //Primero verifico que la pieza selecionada es un alfil
    if (Tablero[fila][columna] == "B" || Tablero[fila][columna] == "b") {
        //luego verifico que esta dentro de la tabla
        if (columna >= 1 && columna <= 8 && fila >= 1 && fila <= 8 &&
            columna2 >= 1 && columna2 <= 8 && fila2 >= 1 && fila2 <= 8) {

            //Aqui verifico sus movimientos. Si detecta que el movimiento es erroneo dice un mensaje de error y termina
            
            //diagonal derecha
            if (columna2 > columna && fila2 < fila) {
                for (int i = 1; i < abs(columna2 - columna); i++) {
                    if (Tablero[fila - i][columna + i] != "*") {
                        path = false;
                        cout << "No se puede mover la pieza ahi" << endl;
                        return;
                    }
                }
            }
            //arriba a la izquierda
            else if (columna2 < columna && fila2 < fila) {
                for (int i = 1; i < abs(columna2 - columna); i++) {
                    if (Tablero[fila - i][columna - i] != "*") {
                        path = false;
                        cout << "No se puede mover la pieza ahi" << endl;
                        return;
                    }
                }
            }
            // abajo a la derecha
            else if (columna2 > columna && fila2 > fila) {
                for (int i = 1; i < abs(columna2 - columna); i++) {
                    if (Tablero[fila + i][columna + i] != "*") {
                        path = false;
                        cout << "No se puede mover la pieza ahi" << endl;
                        return;
                    }
                }
            }
            // abajo a la izquierda
            else if (columna2 < columna && fila2 > fila) {
                for (int i = 1; i < abs(columna2 - columna); i++) {
                    if (Tablero[fila + i][columna - i] != "*") {
                        path = false;
                        cout << "No se puede mover la pieza ahi" << endl;
                        return;
                    }
                }
            }
            else {
                path = false;
                cout << "Movimiento no es diagonal" << endl;
                return;
            }

            // Si todo bien, verifica que en el lugar destine haya una pieza enemiga y no una aliada. La primera parte es para mirar la de las negras y la segunda es para las blancas
            if (cambio == true) { 
                if (Tablero[fila][columna] == "B") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }

                if (Tablero[fila2][columna2] == "*" || Tablero[fila2][columna2] == "P" || Tablero[fila2][columna2] == "H" || Tablero[fila2][columna2] == "T" 
                    || Tablero[fila2][columna2] == "B" || Tablero[fila2][columna2] == "Q" || Tablero[fila2][columna2] == "K") 
                {
                    //Si todo va bien lo imprime
                    path = true;
                    Tablero[fila][columna] = "*";  
                    Tablero[fila2][columna2] = "b";  
                }
                else {
                    path = false;
                    cout << "No puedes mover la pieza ahi, hay una pieza de tu equipo" << endl;
                }
            }

            if (cambio == false) { 
                if (Tablero[fila][columna] == "b") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }

                if (Tablero[fila2][columna2] == "*" || Tablero[fila2][columna2] == "p" || Tablero[fila2][columna2] == "h" || Tablero[fila2][columna2] == "t" 
                    || Tablero[fila2][columna2] == "b" || Tablero[fila2][columna2] == "q" || Tablero[fila2][columna2] == "k") 
                {
                    path = true;
                    Tablero[fila][columna] = "*";  
                    Tablero[fila2][columna2] = "B";  
                }
                else {
                    path = false;
                    cout << "No puedes mover la pieza ahi, hay una pieza de tu equipo" << endl;
                }
            }
        }
        else {
            path = false;
            cout << "Movimiento fuera del tablero" << endl;
        }
    }
    else { cout << "No hay una pieza ahi" << endl; path = false; }
}
