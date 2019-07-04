#ifndef COMIDA_H
#define COMIDA_H

#include "funciones.h"
#include <list> 

using namespace std;

class Comida{
    private:
        //COMIDA ACTUAL DEL SHEET
        int comidaActual;
        int ancho,largo;
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
        static list<Comida*> Comidas_en_juego;
        IntRect comidas;
        
        Comida();
        void dibujar();
        ~Comida();
};
#endif