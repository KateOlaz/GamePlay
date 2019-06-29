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

    posicionEnPantalla_x = rand()%750 +200;
    posicionEnPantalla_y = rand()%450 +100;
    a = 0;
   
    //pa darle animacion
    frameActual_x = 0;
    //para dibujar el sprite en pantalla posiciones
    spriteEnemigo.setTexture(juego::enemigoTexture);
    frames(&spriteEnemigo,frameActual_x,1,3,4);
    spriteEnemigo.setPosition(posicionEnPantalla_x,posicionEnPantalla_y);
    tiempoEnPantalla = juego::reloj.getElapsedTime();
}

//Movimiento Aleatorio del enemigo
void Enemigos::dibujar()
{
    juego::ventana1->draw(spriteEnemigo);
    fltiempoEnPantalla = juego::reloj.getElapsedTime().asSeconds() - tiempoEnPantalla.asSeconds();
    if(fltiempoEnPantalla <=0.5)
    {
        switch (a)
        {
            case 0:
            {
                //up
                frames(&spriteEnemigo, frameActual_x, 3, 3, 4);
                spriteEnemigo.setPosition(spriteEnemigo.getPosition().x, spriteEnemigo.getPosition().y - 0.5);
            }
            break;
            case 1:
            {
                //down
                frames(&spriteEnemigo, frameActual_x, 0, 3, 4);
                spriteEnemigo.setPosition(spriteEnemigo.getPosition().x, spriteEnemigo.getPosition().y + 0.5);
            }
            break;
            case 2:
            {
                //left
                frames(&spriteEnemigo, frameActual_x, 1, 3, 4);
                spriteEnemigo.setPosition(spriteEnemigo.getPosition().x - 0.5, spriteEnemigo.getPosition().y);
            }
            break;
            case 3:
            {
                //right
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