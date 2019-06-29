#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "funciones.h"
#include <list> 

using namespace std;
//Clase encargada de manejar al enemigo--
class Enemigos{
    private:
        int a;
        //Posiciones donde se dibuja el sprite
        float posicionEnPantalla_x;
        float posicionEnPantalla_y;
        //Sprite del enemigo
        Sprite spriteEnemigo;
        //Encargado de cambiar el frame de una textura
        int frameActual_x;

        Time tiempoEnPantalla;
        float fltiempoEnPantalla;

        int ancho,largo;
        
    public:
        static list<Enemigos*> Enemigos_en_juego;
        IntRect enemigo;

        Enemigos();
        void dibujar();
        void Colicion_pantalla();
        ~Enemigos();
};
#endif 