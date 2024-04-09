using namespace std;
#include <iostream>
#include "peo.h"
#include "torre.h"
#include "alfil.h"
#include "cavall.h"
#include "rei.h"
#include "reina.h"
#include "enroc.h"
//Explico mas en detallo las funcionas en la funcion del alfil
void main() {
    //Inicio variables
    char respuesta;
    int columna2;
    int fila2;
    int columna;
    int fila;
    bool cambio = false;
    bool win = true;
    bool path = false;
    bool blanco;
    bool negro;
    bool enroquederecha = true;
    bool enroqueizquierda = true;
    bool enroquederechaN = true;
    bool enroqueizquierdaN = true;



    string Tablero[9][9] = {
        {" ","1", "2", "3", "4", "5", "6", "7", "8"},
        {"1","t", "h", "b", "q", "k", "b", "h", "t"},
        {"2","p", "p", "p", "p", "p", "p", "p", "p"},
        {"3","*", "*", "*", "*", "*", "*", "*", "*"},
        {"4","*", "*", "*", "*", "*", "*", "*", "*"},
        {"5","*", "*", "*", "*", "*", "*", "*", "*"},
        {"6","*", "*", "*", "*", "*", "*", "*", "*"},
        {"7","P", "P", "P", "P", "P", "P", "P", "P"},
        {"8","T", "H", "B", "K", "Q", "B", "H", "T"}
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << Tablero[i][j] << " ";
        }

        cout << endl;
    }
    //Solo se acaba partida cuando la variable win = false
    while (win == true) {
        //variables que se utilizan para ver si el rey aun esta en la tabla
        blanco = false;
        negro = false;

        cout << endl;
        if (cambio == false) { cout << "Toca a los blancos mover" << endl; }
        if (cambio == true) { cout << "Toca a los negros mover" << endl; }
        cout << "Que pieza quieres mover y su posicion actual?" << endl;
        cin >> respuesta;
        cin >> columna;
        cin >> fila;
        cout << "Donde lo quieres mover?" << endl;
        cin >> columna2;
        cin >> fila2;

        //funciones de todas las piezas
        if (respuesta == 'P' || respuesta == 'p') {
            peo(fila, columna, fila2, columna2, Tablero, path, cambio);
        }

        if (respuesta == 'T' || respuesta == 't') {
            torre(fila, columna, fila2, columna2, Tablero, path, cambio, enroquederecha,
                enroqueizquierda, enroquederechaN, enroqueizquierdaN);
        }

        if (respuesta == 'H' || respuesta == 'h') {
            cavall(fila, columna, fila2, columna2, Tablero, path, cambio);
        }

        if (respuesta == 'B' || respuesta == 'b') {
            alfil(fila, columna, fila2, columna2, Tablero, path, cambio);
        }

        if (respuesta == 'K' || respuesta == 'k') {
            rei(fila, columna, fila2, columna2, Tablero, path, cambio, enroquederecha, 
                enroqueizquierda, enroquederechaN, enroqueizquierdaN);
        }

        if (respuesta == 'Q' || respuesta == 'q') {
            reina(fila, columna, fila2, columna2, Tablero, path, cambio);
        }      



       if (respuesta == 'E' || respuesta == 'e') {
           enroc(fila, columna, fila2, columna2, Tablero, path,cambio,enroquederechaN,enroqueizquierdaN,enroquederecha,enroqueizquierda);
            }


            //Detecta si algun peon de cada banda ha llego al final para cambiarse a reina
            for (int col = 1; col <= 8; ++col) {
                if (Tablero[1][col] == "P") {
                    Tablero[1][col] = "Q";
                }
            }

            for (int col = 1; col <= 8; ++col) {
                if (Tablero[8][col] == "p") {
                    Tablero[8][col] = "q";
                }
            }


            //imprimir la mesa despues del movimiento
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    cout << Tablero[i][j] << " ";
                }
                cout << endl;
            }

            //Esto cambia el turno
            if (path == true && cambio == true) { cambio = false; path = false; }
            if (path == true) { cambio = true; }




            //Esta ultima parte detecta si el rei esta aun en juego o no
            for (int i = 1; i <= 8; ++i) {
                for (int j = 1; j <= 8; ++j) {
                    if (Tablero[i][j] == "K") {
                        blanco = true;
                    }

                    else if (Tablero[i][j] == "k") {
                        negro = true;
                    }
                }
            }

            if (blanco == false) { win = false; cout << "Los negros han ganado" << endl; }
            if (negro == false) { win = false; cout << "Los blancos han ganado" << endl; }

        }
    }
