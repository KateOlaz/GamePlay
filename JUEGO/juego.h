#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "personaje.h"
#include "comida.h"
using namespace sf;

class juego{
    private:
        int fps;
        Texture *textura1;
        Texture *textura[4];
        Sprite *sprite1;
        Sprite *sprite[4];
        Event *evento1;
        personaje* Jugador;
        comida* Comida;

    public:
        juego(int ancho, int alto, std::string titulo);
    
        static RenderWindow *ventana1;
        static Texture personajeTexture;
        static Texture comidaTexture;
        //reloj
        static Clock reloj;
        void gameloop();  //repetir constantemente
        void dibujar();
        void eventos();
        
        void personajes();
        void colisiones();
        void cargar_graficos();
        int random(int x);
};
#endif 