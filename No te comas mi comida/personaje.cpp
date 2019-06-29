#include "personaje.h"
#include "juego.h"
#include "funciones.h"
Personaje::Personaje(){

    direccion = 0;

    posicionEnPantalla_x = 400;
    posicionEnPantalla_y = 400;
    //pa darle animacion
    frameActual_x = 0;
    //para dibujar el sprite en pantalla posiciones
    spritePersonaje.setTexture(juego::personajeTexture);
    frames(&spritePersonaje,frameActual_x,0,9,4);
    spritePersonaje.setPosition(posicionEnPantalla_x,posicionEnPantalla_y);
}
void Personaje::dibujar()
{
    juego::ventana1->draw(spritePersonaje);
    if(frameActual_x < 9 - 1)
        frameActual_x++;
    else 
        frameActual_x = 0;

    for(list<Bala*>::iterator it = mylist.begin(); it!= mylist.end();++it){
        //if((*it)->colision_pantalla()>0){
        //    delete (*it);
        //    it = mylist.erase(it);
        //    continue;
        //}
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
            frames(&spritePersonaje, frameActual_x, 0, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x, spritePersonaje.getPosition().y - 3);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            direccion = 1;
            frames(&spritePersonaje, frameActual_x, 2, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x, spritePersonaje.getPosition().y + 3);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            direccion = 2;
            frames(&spritePersonaje, frameActual_x, 1, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x - 3, spritePersonaje.getPosition().y);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            direccion = 3;
            frames(&spritePersonaje, frameActual_x, 3, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x + 3, spritePersonaje.getPosition().y);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            mylist.push_back(new Bala(spritePersonaje.getPosition().x,spritePersonaje.getPosition().y, direccion));
        }
        break;
    default:
        break;
    }
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
