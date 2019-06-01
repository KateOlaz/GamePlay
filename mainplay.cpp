#include "juego.h"
#include <iostream>

int main()
{
    srand(time(NULL));
    juego *partida1;
    partida1 = new juego(800, 500, "No te comas mi comida");
    return 0; 
}