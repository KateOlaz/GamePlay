#include "juego.h"
#include <iostream>

Texture juego::personajeTexture;
Texture juego::comidaTexture;
RenderWindow* juego::ventana1;
Clock juego::reloj;
int main()
{
    srand(time(NULL));
    juego *partida1;
    partida1 = new juego(800, 500, "No te comas mi comida");
    return 0; 
}