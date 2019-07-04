#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "funciones.h"
#include "Bala.h"
#include <list> 

using namespace std;

class Bala;
//Clase encargada de manejar y controlar al personaje principal--
class Personaje{
    friend class Bala;
    private:
        int direccion;
        list<Bala*> mylist;
        //Posiciones donde se dibuja el sprite
        float posicionEnPantalla_x;
        float posicionEnPantalla_y;
        //Sprite del personaje
        Sprite spritePersonaje;
        //Encargado de cambiar el frame de una textura
        int frameActual_x;
        int ancho, largo;
        Personaje();
        static Personaje *instance;
    public:
        static Personaje* getInstancia();
        static void restart();
        IntRect personaje;

        void getSprite(int c);
        void dibujar();
        void eventos(Event e);
        void Colicion_pantalla();
        
};
#endif 