#ifndef BALA_H
#define BALA_H

#include "funciones.h"
#include "personaje.h"
#include "Enemigo.h"

using namespace sf;

class Bala{
    private:
        
        int x, y, dir;
        int ancho,largo;

        Sprite spriteBala;
       
        int p, q;

    public:
        Bala(int _x, int _y, int _dir);
        IntRect bala;
        void dibujar();
        void mover();
        int colision_pantalla();
        void colisiones();       
    
};

#endif 