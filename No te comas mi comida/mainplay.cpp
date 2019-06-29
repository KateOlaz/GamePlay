#include "juego.h"
#include <iostream>
#include <list>

Texture juego::personajeTexture;
Texture juego::enemigoTexture;
Texture juego::comidaTexture;
Texture juego::balaTexture;
std::list<Enemigos*> Enemigos::Enemigos_en_juego;
RenderWindow* juego::ventana1;
Clock juego::reloj;
int juego::ancho_;
int juego::alto_;

int main()
{
    srand(time(NULL));
    juego *partida1;
    partida1 = new juego(800, 500, "No te comas mi comida");
    return 0; 
}