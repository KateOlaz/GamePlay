#include "personaje.h"
#include "juego.h"
#include "funciones.h"
#include <iostream>

using namespace std;

Personaje* Personaje::instance = NULL;

Personaje::Personaje(){
    direccion = 0;
    posicionEnPantalla_x = 400;
    posicionEnPantalla_y = 400;

    personaje.left = posicionEnPantalla_x;
    personaje.top = posicionEnPantalla_y;
    personaje.width = 44;
    personaje.height = 44;
   
    //pa darle animacion
    frameActual_x = 0;
    //para dibujar el sprite en pantalla posiciones
    spritePersonaje.setTexture(juego::personajeTexture);
    spritePersonaje.setScale(1.2f,1.2f);
    frames(&spritePersonaje,frameActual_x,0,9,4);
    spritePersonaje.setPosition(posicionEnPantalla_x,posicionEnPantalla_y);
}

Personaje* Personaje::getInstancia()
{
    if(!instance)
    {
        instance = new Personaje();
    }
    return instance;
}
void Personaje::restart()
{
    if(instance)
    {
        delete instance;
    }
}

void Personaje::dibujar()
{
    juego::ventana1->draw(spritePersonaje);
    if(frameActual_x < 9 - 1)
        frameActual_x++;
    else 
        frameActual_x = 0;

    
    for(list<Bala*>::iterator it = mylist.begin(); it != mylist.end();++it){
        bool colision = false;
        list<Enemigos*>::iterator ite2; 
        for(ite2 = Enemigos::Enemigos_en_juego.begin(); ite2 != Enemigos::Enemigos_en_juego.end(); ++ite2){
            if((*ite2)->enemigo.intersects((*it)->bala)){
                colision = true;
                //cout<<"COLISION"<<(*it);
                delete (*ite2);
                //new Enemigos;
                break;
            }
        }
        if(colision){
            //cout<<"DELETE"<<(*it)<<"\n";
            delete (*it);
            it = mylist.erase(it);
            continue;
        }
        (*it)->dibujar();
        (*it)->mover();
    }
}
void Personaje::eventos(Event e){
    switch (e.type)
    {
    case Event::KeyPressed:
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            direccion = 0;
            posicionEnPantalla_x = spritePersonaje.getPosition().x;
            posicionEnPantalla_y = spritePersonaje.getPosition().y - 4;
            frames(&spritePersonaje, frameActual_x, 0, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x, spritePersonaje.getPosition().y - 4);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            direccion = 1;
            posicionEnPantalla_x = spritePersonaje.getPosition().x;
            posicionEnPantalla_y = spritePersonaje.getPosition().y + 4;
            frames(&spritePersonaje, frameActual_x, 2, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x, spritePersonaje.getPosition().y + 4);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            direccion = 2;
            posicionEnPantalla_x = spritePersonaje.getPosition().x - 4;
            posicionEnPantalla_y = spritePersonaje.getPosition().y;
            frames(&spritePersonaje, frameActual_x, 1, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x - 4, spritePersonaje.getPosition().y);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            direccion = 3;
            posicionEnPantalla_x = spritePersonaje.getPosition().x + 4;
            posicionEnPantalla_y = spritePersonaje.getPosition().y;
            frames(&spritePersonaje, frameActual_x, 3, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x + 4, spritePersonaje.getPosition().y);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            mylist.push_back(new Bala(spritePersonaje.getPosition().x,spritePersonaje.getPosition().y, direccion));
        }
        break;
    default:
        break;
    }
    personaje.left = posicionEnPantalla_x;
    personaje.top = posicionEnPantalla_y;

    Colicion_pantalla();
}

void Personaje::Colicion_pantalla()
{
    ancho= spritePersonaje.getGlobalBounds().width;
    largo= spritePersonaje.getGlobalBounds().height;
    
    if(spritePersonaje.getPosition().x + ancho >= juego::ancho_) //limite der
    {
        frames(&spritePersonaje, frameActual_x, 1, 9, 4);
        spritePersonaje.setPosition(spritePersonaje.getPosition().x - 3, spritePersonaje.getPosition().y);
    }
    else if(spritePersonaje.getPosition().x <= 0) //limite izq
    {
        frames(&spritePersonaje, frameActual_x, 3, 9, 4);
        spritePersonaje.setPosition(spritePersonaje.getPosition().x + 3, spritePersonaje.getPosition().y);
    }
    else if(spritePersonaje.getPosition().y + largo >= juego::alto_) //limite inferior
    {
        frames(&spritePersonaje, frameActual_x, 0, 9, 4);
        spritePersonaje.setPosition(spritePersonaje.getPosition().x, spritePersonaje.getPosition().y - 3);
    }
    else if(spritePersonaje.getPosition().y <= 0) //limite sup
    {
        frames(&spritePersonaje, frameActual_x, 2, 9, 4);
        spritePersonaje.setPosition(spritePersonaje.getPosition().x, spritePersonaje.getPosition().y + 3);
    }
}
