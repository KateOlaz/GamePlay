#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "personaje.h"
#include "Enemigo.h"
#include "comida.h"
#include "Bala.h"

using namespace sf;

class juego{
    private:
        int fps;

        Event *evento1;
        Personaje* Jugador;
        Enemigos* Enemigo;
        Enemigos* Enemigo1;
        Comida* Comida1;
        Comida* Comida2;
        Comida* Comida3;
        Bala* Balas;
        
        
    public:
        juego(int ancho, int alto, std::string titulo);
    
        static RenderWindow *ventana1;
        static Texture personajeTexture;
        static Texture enemigoTexture;
        static Texture comidaTexture;
        static Texture balaTexture;
        static Clock reloj;
        static int ancho_;
        static int alto_;

        void gameloop();  
        void dibujar();
        void eventos();
        void personajes_juego();
        void colisiones();
};
#endif 