#include "Enemigo.h"
#include "juego.h"
//#include "funciones.h"
#include <iostream>
using namespace std;

Enemigos::Enemigos(){

    Enemigos_en_juego.push_back(this);

    enemigo.left = posicionEnPantalla_x;
    enemigo.top = posicionEnPantalla_y;
    enemigo.width = 32;
    enemigo.height = 32;
    
    srand (time(NULL));

    posicionEnPantalla_x = rand()%700 +100;
    posicionEnPantalla_y = rand()%400 +100;
    a = 0;
   
    //pa darle animacion
    frameActual_x = 0;
    //para dibujar el sprite en pantalla posiciones
    spriteEnemigo.setTexture(juego::enemigoTexture);
    spriteEnemigo.setScale(1.2f,1.2f);
    frames(&spriteEnemigo,frameActual_x,1,3,4);
    spriteEnemigo.setPosition(posicionEnPantalla_x,posicionEnPantalla_y);
    tiempoEnPantalla = juego::reloj.getElapsedTime();
}

//Movimiento Aleatorio del enemigo
void Enemigos::dibujar()
{
    juego::ventana1->draw(spriteEnemigo);
    fltiempoEnPantalla = juego::reloj.getElapsedTime().asSeconds() - tiempoEnPantalla.asSeconds();
    if(fltiempoEnPantalla <=2)
    {
        switch (a)
        {
            case 0:
            {
                //up
                posicionEnPantalla_x = spriteEnemigo.getPosition().x;
                posicionEnPantalla_y = spriteEnemigo.getPosition().y - 0.5;
                frames(&spriteEnemigo, frameActual_x, 3, 3, 4);
                spriteEnemigo.setPosition(spriteEnemigo.getPosition().x, spriteEnemigo.getPosition().y - 0.5);
            }
            break;
            case 1:
            {
                //down
                posicionEnPantalla_x = spriteEnemigo.getPosition().x;
                posicionEnPantalla_y = spriteEnemigo.getPosition().y + 0.5;
                frames(&spriteEnemigo, frameActual_x, 0, 3, 4);
                spriteEnemigo.setPosition(spriteEnemigo.getPosition().x, spriteEnemigo.getPosition().y + 0.5);
            }
            break;
            case 2:
            {
                //left
                posicionEnPantalla_x = spriteEnemigo.getPosition().x - 0.5;
                posicionEnPantalla_y = spriteEnemigo.getPosition().y;
                frames(&spriteEnemigo, frameActual_x, 1, 3, 4);
                spriteEnemigo.setPosition(spriteEnemigo.getPosition().x - 0.5, spriteEnemigo.getPosition().y);
            }
            break;
            case 3:
            {
                //right
                posicionEnPantalla_x = spriteEnemigo.getPosition().x + 0.5;
                posicionEnPantalla_y = spriteEnemigo.getPosition().y;
                frames(&spriteEnemigo, frameActual_x, 2, 3, 4);
                spriteEnemigo.setPosition(spriteEnemigo.getPosition().x + 0.5, spriteEnemigo.getPosition().y);
            }
            break;
            default:
            break;
        }
    }
    else
    {
        a = rand()%4;
        tiempoEnPantalla = juego::reloj.getElapsedTime();
    } 

    enemigo.left = posicionEnPantalla_x;
    enemigo.top = posicionEnPantalla_y;

    Colicion_pantalla();
}

void Enemigos::Colicion_pantalla()
{
    ancho= spriteEnemigo.getGlobalBounds().width;
    largo= spriteEnemigo.getGlobalBounds().height;

    //cout<<ancho<<endl; 32
    //cout<<largo<<endl; 32
    
    if(spriteEnemigo.getPosition().x + ancho >= juego::ancho_) //limite der
    {
        a = 2;
    }
    else if(spriteEnemigo.getPosition().x <= 0) //limite izq
    {
        a = 3;
    }
    else if(spriteEnemigo.getPosition().y + largo >= juego::alto_) //limite inferior
    {
        a = 0;
    }
    else if(spriteEnemigo.getPosition().y <= 0) //limite sup
    {
        a = 1;
    }
}

Enemigos::~Enemigos(){
    Enemigos_en_juego.remove(this);
}