#include "juego.h"

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

    frame_actual.x = 0;
    frame_actual.y = 0;

    reloj1 = new Clock();
    tiempo1 = new Time();

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
       *tiempo1 = reloj1->getElapsedTime();
       cout<< tiempo1->asSeconds()<<endl;
       tiempo2 = tiempo1->asSeconds();
       
    }

}

void juego::cargar_graficos()
{
    string path;
    string ruta;
    for(int i = 0; i < 5; i++)
    {
        ruta = (i + 1);
        hola = ruta.str();
        path = "comida" + hola+ ".png";
        textura[i]->loadFromFile(ruta);
        sprite[i]->setTexture(*textura[i]);
    }
}

//Cargo lo necesario para mis personajes 
void juego::personajes()
{
    textura1 = new Texture;
    textura1->loadFromFile("mounstros.png");
    sprite1 = new Sprite(*textura1);

    textura2 = new Texture;
    textura2->loadFromFile("posible.png");
    sprite2 = new Sprite(*textura2);
    sprite2->setPosition(400,400);

    textura3 = new Texture;
    textura3->loadFromFile("comida2.png");
    sprite3 = new Sprite(*textura3);
       
    evento1 = new Event;

    

    frames(*sprite1, 0, 1, 3, 3);
    frames(*sprite2, frame_actual.x, frame_actual.y, 9, 4);

}

//Esta funcion divide mi textura en diferentes rectuangulos, devolviendome en que yo quiero especificamente
//(int x,int y)son la pocicion del rectangulo en especifico que requiero 
void juego::frames(Sprite &sprite, int x, int y, int num_x, int num_y)
{
    IntRect posicion(x * (sprite.getTexture()->getSize().x / num_x),y * (sprite.getTexture()->getSize().y/ num_y),sprite.getTexture()->getSize().x / num_x, sprite.getTexture()->getSize().y / num_y);
    sprite.setTextureRect(posicion);
}

void juego::dibujar()
{
    ventana1->clear();
    ventana1->draw(*sprite1);
    
    if(frame_actual.x < 9 - 1)
    {          
        frame_actual.x++;
    }
    else
        frame_actual.x=0;


    int aleatorio;
    aleatorio = rand()% 400 + 50 ;

    ventana1->draw(*sprite2);
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

        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Up))
            {
                frames(*sprite2, frame_actual.x, 0, 9, 4);
                sprite2->setPosition(sprite2->getPosition().x, sprite2->getPosition().y - 3);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Down))
            {
                frames(*sprite2, frame_actual.x, 2, 9, 4);
                sprite2->setPosition(sprite2->getPosition().x, sprite2->getPosition().y + 3);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Left))
            {
                frames(*sprite2, frame_actual.x, 1, 9, 4);
                sprite2->setPosition(sprite2->getPosition().x - 3, sprite2->getPosition().y);
            }
            else if(Keyboard::isKeyPressed(Keyboard::Right))
            {
                frames(*sprite2, frame_actual.x, 3, 9, 4);
                sprite2->setPosition(sprite2->getPosition().x + 3, sprite2->getPosition().y);
            }
            break;
        }

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
