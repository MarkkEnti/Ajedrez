using namespace std;
#include <iostream>
void cavall(int fila, int columna, int fila2, int columna2, string Tablero[9][9], bool& path, bool& cambio)
{// detectar que la pieza es un caballo
    if (Tablero[fila][columna] == "H" || Tablero[fila][columna] == "h") {
        //Detectar que esta en la mesa
        if (columna >= 1 && columna <= 8 && fila >= 1 && fila <= 8 &&
            columna2 >= 1 && columna2 <= 8 && fila2 >= 1 && fila2 <= 8) {

            //Se calcula todas las posibles posiciones en la mesa desde su posicion
            if ((fila2 == fila + 2 && columna2 == columna + 1) || (fila2 == fila + 2 && columna2 == columna - 1) ||
                (fila2 == fila - 2 && columna2 == columna + 1) || (fila2 == fila - 2 && columna2 == columna - 1) ||
                (fila2 == fila + 1 && columna2 == columna + 2) || (fila2 == fila + 1 && columna2 == columna - 2) ||
                (fila2 == fila - 1 && columna2 == columna + 2) || (fila2 == fila - 1 && columna2 == columna - 2)) 
            {
                //Detectar por aliados blancos
                if (cambio == false) {
                    if (Tablero[fila][columna] == "h") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }
                    if (Tablero[fila2][columna2] == "*" || Tablero[fila2][columna2] == "p" || Tablero[fila2][columna2] == "t" || Tablero[fila2][columna2] == "h" || 
                        Tablero[fila2][columna2] == "b" ||  Tablero[fila2][columna2] == "q" ||  Tablero[fila2][columna2] == "k") 
                    {                     
                        path = true;
                        Tablero[fila2][columna2] = 'H';
                        Tablero[fila][columna] = '*'; 
                    }
                }
                //Detectar por aliados negros
                if (cambio == true) {
                    if (Tablero[fila][columna] == "H") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }
                    if (Tablero[fila2][columna2] == "*" || Tablero[fila2][columna2] == "P" || Tablero[fila2][columna2] == "T" || Tablero[fila2][columna2] == "H" || 
                        Tablero[fila2][columna2] == "B" || Tablero[fila2][columna2] == "Q" || Tablero[fila2][columna2] == "K") 
                    {                         
                        path = true;
                        Tablero[fila2][columna2] = 'h';
                        Tablero[fila][columna] = '*'; 
                    }
                }             
            }
            else {
                path = false;
                cout << "No se puede mover la pieza ahi" << endl;
            }
        }
        else {
            path = false;
            cout << "Movimiento fuera del tablero" << endl;
        }
    }
    else { cout << "No hay una pieza ahi" << endl; path = false; }
}