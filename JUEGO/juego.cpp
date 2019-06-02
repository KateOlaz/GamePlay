#include "juego.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

juego::juego(int ancho, int alto, string titulo)
{
    fps = 60;
    ventana1 = new RenderWindow(VideoMode(ancho,alto), titulo);
    ventana1->setFramerateLimit(fps);

    personajes();
    gameloop();
}

void juego::gameloop()
{
    while (ventana1->isOpen())
    {
       dibujar();
       eventos();
       colisiones();
    }

}

void juego::cargar_graficos()
{
    string path;
    int ruta;
    string hola;
    for(int i = 0; i < 5; i++)
    {
        ruta = (i + 1);
        hola = ruta+'0';
        path = "comida" + hola+ ".png";
        textura[i]->loadFromFile(path);
        sprite[i]->setTexture(*textura[i]);
    }
}

void juego::personajes()
{
    textura1 = new Texture;
    textura1->loadFromFile("mounstros.png");
    sprite1 = new Sprite(*textura1);
    
    personajeTexture.loadFromFile("posible.png");
    Jugador = new personaje;

    comidaTexture.loadFromFile("comidaSheet.png");
    Comida = new comida;

    evento1 = new Event;  

    frames(sprite1, 0, 1, 3, 3);

}


void juego::dibujar()
{
    ventana1->clear();

    ventana1->draw(*sprite1);
    
    Jugador->dibujar();
    Comida->dibujar();
    ventana1->display();
}

void juego::colisiones()
{
    if(sprite2->getGlobalBounds().intersects(sprite1->getGlobalBounds()))
        sprite1->setColor(Color::Magenta);
    else 
        sprite1->setColor(Color::Green);
    
}

void juego::eventos()
{
    while(ventana1->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::Closed:
            ventana1->close();
            exit(1);
            break;
        }
        Jugador->eventos(*evento1);
    }


}

int juego::random(int x)
{
    int num, c;
    srand(time(NULL));
    for(c = x; c <= 10; c++)
    {
        num = 1 + rand() % (500 - 1);
    }

}