#include "juego.h"
#include "funciones.h"
#include "personaje.h"
#include "Enemigo.h"
#include "Bala.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

juego::juego(int ancho, int alto, string titulo)
{
    fps = 60;
    this->ancho_=ancho;
    this->alto_=alto;
    ventana1 = new RenderWindow(VideoMode(ancho,alto), titulo);
    ventana1->setFramerateLimit(fps);

    personajes_juego();
    gameloop();
}

void juego::gameloop()
{
    while (ventana1->isOpen())
    {
        dibujar();
        eventos();
    }

}

void juego::personajes_juego()
{
    
    //Jugador
    personajeTexture.loadFromFile("posible.png");
    Jugador = new Personaje;

    //Enemigo
    enemigoTexture.loadFromFile("fantasmas.png");
    Enemigo = new Enemigos;
    Enemigo1 = new Enemigos;

    //Comidas
    comidaTexture.loadFromFile("comidaSheet.png");
    Comida1 = new Comida;
    Comida2 = new Comida;
    Comida3 = new Comida;

    //Bala
    balaTexture.loadFromFile("disparo.png");

    evento1 = new Event;  

}


void juego::dibujar()
{
    ventana1->clear();

    Jugador->dibujar();
    Enemigo->dibujar();
    Enemigo1->dibujar();
    Comida1->dibujar();
    Comida2->dibujar();
    Comida3->dibujar();
    //Balas->dibujar();

    ventana1->display();
}

void juego::colisiones()
{
    
}

void juego::eventos()
{
    while(ventana1->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::Closed:
            ventana1->close();
            delete Jugador;
            delete Enemigo;
            delete Enemigo1;
            delete Comida1;
            delete Comida2;
            delete Comida3;
            exit(1);
            break;
        }
        Jugador->eventos(*evento1);
    }
}

