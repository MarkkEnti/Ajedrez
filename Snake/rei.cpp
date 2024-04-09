using namespace std;
#include <iostream>
void rei(int fila, int columna, int fila2, int columna2, string Tablero[9][9], bool& path, bool& cambio, bool& enroqueizquierdaN, bool& enroquederechaN,bool& enroqueizquierda, bool& enroquederecha) 
{
    if (Tablero[fila][columna] == "K" || Tablero[fila][columna] == "k") 
    {        
        if (columna >= 1 && columna <= 8 && fila >= 1 && fila <= 8 &&
            columna2 >= 1 && columna2 <= 8 && fila2 >= 1 && fila2 <= 8) 
        {
            if (cambio == false) 
            {
                if (Tablero[fila][columna] == "k") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }

                if ((abs(fila2 - fila) <= 1) && (abs(columna2 - columna) <= 1)) 
                {                   
                    if (Tablero[fila2][columna2] == "*" ||  Tablero[fila2][columna2] == "p" || Tablero[fila2][columna2] == "h" ||  Tablero[fila2][columna2] == "t" ||
                        Tablero[fila2][columna2] == "b" ||  Tablero[fila2][columna2] == "q" || Tablero[fila2][columna2] == "k") 
                    {
                        path = true;
                        Tablero[fila][columna] = "*"; 
                        Tablero[fila2][columna2] = "K"; 
                        return;
                    }
                    else {
                        path = false;
                        cout << "No puedes mover la pieza ahi, hay una pieza de tu equipo" << endl;
                    }
                }
            }
            if (cambio == true) {
                if (Tablero[fila][columna] == "K") { path = false;cout << "No puedes mover las piezas de tu rival" << endl; return; }
                if ((abs(fila2 - fila) <= 1) && (abs(columna2 - columna) <= 1)) 
                {                    
                    if (Tablero[fila2][columna2] == "*" || Tablero[fila2][columna2] == "P" || Tablero[fila2][columna2] == "H" || Tablero[fila2][columna2] == "T" ||
                        Tablero[fila2][columna2] == "B" || Tablero[fila2][columna2] == "Q" || Tablero[fila2][columna2] == "K") 
                    {
                        path = true;
                        Tablero[fila][columna] = "*"; 
                        Tablero[fila2][columna2] = "k"; 
                        return;
                    }
                    else {
                        path = false;
                        cout << "No puedes mover la pieza ahi, hay una pieza de tu equipo" << endl;
                    }
                }
            }
            else {
                path = false;
                cout << "Movimiento no es valido para el rey" << endl;
            }
        }
        else {
            path = false;
            cout << "Movimiento fuera del tablero" << endl;
        }    
    
   } else { cout << "No hay una pieza ahi" << endl; path = false; }

   if (Tablero[1][5] != "k") {

       enroqueizquierdaN = false;
       enroquederechaN = false;
   }
   
  
   if (Tablero[8][4] != "K") {

       enroqueizquierda = false;
       enroquederecha = false;
   }

}