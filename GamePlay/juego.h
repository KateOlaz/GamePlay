#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "funciones.h"
#include "personaje.h"
#include "Enemigo.h"
#include "comida.h"
#include "Bala.h"

#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace sf;
using namespace std;

class juego{
    private:
        int fps;
        int puntos;
        int vidas;
        bool state;
        Texture *textura;
        Sprite *fondo;
        Event *evento1;
        Personaje* Jugador;
        Font *fuente1;
        Text text;
        Text lose;
        Text score;
   
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
        void ganaste();
        void personajes_juego();
        void colisiones();
};
#endif 