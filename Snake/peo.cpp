using namespace std;
#include <iostream>
//El peo puede tenir 3 movimientos distintos, avanzar hacia delante normal o atacar en diagonal hacia el lado izquierda o derecha
void peo(int fila, int columna, int fila2, int columna2, string Tablero[9][9], bool& path, bool& cambio) {
    if (Tablero[fila][columna] == "P" || Tablero[fila][columna] == "p") {
        {
            if (cambio == false) {
                if (Tablero[fila][columna] == "p") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }
                if (columna >= 1 && columna <= 8 && fila >= 1 && fila <= 8) {  
                    
                    //Movida hacia delante, blancas
                    if (columna == columna2 && fila2 == fila - 1 && Tablero[fila2][columna] == "*") {
                        Tablero[fila2][columna] = "P";
                        Tablero[fila][columna] = "*";
                        path = true;
                    }

                   //Ataque diagonal izquierda, blancas
                    else if (columna2 == columna - 1 && fila2 == fila - 1 &&
                        (Tablero[fila2][columna2] == "p" || Tablero[fila2][columna2] == "t" ||
                            Tablero[fila2][columna2] == "h" || Tablero[fila2][columna2] == "b" ||
                            Tablero[fila2][columna2] == "q" || Tablero[fila2][columna2] == "k")) 
                    {
                        path = true;
                        Tablero[fila2][columna2] = "P";
                        Tablero[fila][columna] = "*";
                    }

                    //Ataque diagonal derecha, blancas
                    else if (columna2 == columna + 1 && fila2 == fila - 1 &&
                        (Tablero[fila2][columna2] == "p" || Tablero[fila2][columna2] == "t" ||
                            Tablero[fila2][columna2] == "h" || Tablero[fila2][columna2] == "b" ||
                            Tablero[fila2][columna2] == "q" || Tablero[fila2][columna2] == "k")) 
                    {
                        path = true;
                        Tablero[fila2][columna2] = "P";
                        Tablero[fila][columna] = "*";
                    }
                    else {
                        path = false;
                        cout << "No se puede mover la pieza ahi" << endl;
                    }
                }
                else {
                    path = false;
                    cout << "Movimiento no valido" << endl;
                }
            }
            //Lo mismo pero para los negros
            if (cambio == true) {
                if (Tablero[fila][columna] == "P") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }
                if (columna >= 1 && columna <= 8 && fila >= 2 && fila <= 8) 
                {                   
                    if (columna == columna2 && fila2 == fila + 1 && Tablero[fila2][columna] == "*") {
                        Tablero[fila2][columna] = "p";  
                        path = true;
                        Tablero[fila][columna] = "*";
                    }
                 
                    else if (columna2 == columna - 1 && fila2 == fila + 1 && (Tablero[fila2][columna2] == "P" || Tablero[fila2][columna2] == "T" ||
                            Tablero[fila2][columna2] == "H" || Tablero[fila2][columna2] == "B" ||
                            Tablero[fila2][columna2] == "Q" || Tablero[fila2][columna2] == "K")) 
                    {
                        path = true;
                        Tablero[fila2][columna2] = "p";
                        Tablero[fila][columna] = "*";
                    }
                  
                    else if (columna2 == columna + 1 && fila2 == fila + 1 &&
                        (Tablero[fila2][columna2] == "P" || Tablero[fila2][columna2] == "T" ||
                            Tablero[fila2][columna2] == "H" || Tablero[fila2][columna2] == "B" ||
                            Tablero[fila2][columna2] == "Q" || Tablero[fila2][columna2] == "K")) 
                    {
                        path = true;
                        Tablero[fila2][columna2] = "p";
                        Tablero[fila][columna] = "*";
                    }
                    else {
                        path = false;
                        cout << "No se puede mover la pieza aho" << endl;
                    }
                }
                else {
                    path = false;
                    cout << "Movimiento no valido" << endl;
                }
            }
        }
    } else { cout << "No hay una pieza ahi" << endl; path = false;  }
}