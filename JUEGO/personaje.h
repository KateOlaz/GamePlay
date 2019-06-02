#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "funciones.h"
//Clase encargada de manejar y controlar al personaje principal--
class personaje{
    private:
        //Posiciones donde se dibuja el sprite
        float posicionEnPantalla_x;
        float posicionEnPantalla_y;
        //Sprite del personaje
        Sprite spritePersonaje;
        //Encargado de cambiar el frame de una textura
        int frameActual_x;
        
    public:
        personaje();
        void dibujar();
        void eventos(Event e);
        
};
#endif 