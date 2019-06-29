#ifndef COMIDA_H
#define COMIDA_H

#include "funciones.h"

class Comida{
    private:
        //COMIDA ACTUAL DEL SHEET
        int  comidaActual;
        //frame actual(posicion de x e y en la imagen comidaSheet.png)
        Vector2i frameActual;
        
        int frameComidaActual;
        //Posiciones donde se dibuja el sprite
        float posicionEnPantalla_x;
        float posicionEnPantalla_y;
        //Sprite de la comida
        Sprite spriteComida;
        //COntrolador del tiempo del sprite en pantalla
        Time tiempoEnPantalla;
        float fltiempoEnPantalla;
        //funcion para generar un numero random aun no implementada 
        void generarRandom();
    public:
        Comida();
        void dibujar();
};
#endif