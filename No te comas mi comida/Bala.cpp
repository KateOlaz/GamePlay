#include "Bala.h"
#include "juego.h"
#include "personaje.h"
#include "Enemigo.h"

#include <iostream>
#include <list> 
using namespace std;

Bala::Bala(int _x, int _y, int _dir){
    x = _x;
    y = _y;
    dir = _dir;

    bala.left = x;
    bala.top = y;
    bala.width = 9;
    bala.height = 9;

    spriteBala.setTexture(juego::balaTexture);

    dibujar();
}

void Bala::dibujar(){
    ancho= spriteBala.getGlobalBounds().width;
    largo= spriteBala.getGlobalBounds().height;

    //cout<<ancho<<endl;
    //cout<<largo<<endl;

    juego::ventana1->draw(spriteBala);
    //tiempo = juego::reloj.getElapsedTime().asSeconds() - tiempoEnPantalla.asSeconds();
    mover();
}

void Bala::mover()
{
    switch (dir)
    {
        case 0:
        {
            //up
            x += 0;
            y -= 5;
            spriteBala.setPosition(x,y);
        }
        break;
        case 1:
        {
            //down
            x += 0;
            y += 5;
            spriteBala.setPosition(x,y);
        }
        break;
        case 2:
        {
            //left
            x -= 5;
            y += 0;
            spriteBala.setPosition(x,y);
        }
        break;
        case 3:
        {
            //right
            x += 5;
            y += 0;
            spriteBala.setPosition(x,y);
        }
        break;
        default:
        break;
    } 

    bala.left = x;
    bala.top = y;

    list<Enemigos*>::iterator it;
    for(it = Enemigos::Enemigos_en_juego.begin(); it != Enemigos::Enemigos_en_juego.end(); ++it){
        //if(bala.intersects((*it)->enemigo))
            delete (*it);
    }
}

//NO FUNCIONA :"V
int Bala::colision_pantalla()
{    
    if(x >= juego::ancho_) //limite der
    {
        return 1;
    }
    else if(x <= 0) //limite izq
    {
        return 1;
    }
    else if(y >= juego::alto_) //limite inferior
    {
        return 1;
    }
    else if(y <= 0) //limite sup
    {
        return 1;
    }
}
