#include "personaje.h"
#include "juego.h"
#include "funciones.h"
personaje::personaje(){

    posicionEnPantalla_x = 400;
    posicionEnPantalla_y = 400;
    //pa darle animacion
    frameActual_x = 0;
    //para dibujar el sprite en pantalla posiciones
    spritePersonaje.setTexture(juego::personajeTexture);
    frames(&spritePersonaje,frameActual_x,0,9,4);
    spritePersonaje.setPosition(posicionEnPantalla_x,posicionEnPantalla_y);
}
void personaje::dibujar(){
    juego::ventana1->draw(spritePersonaje);
    if(frameActual_x < 9 - 1)
        frameActual_x++;
    else frameActual_x = 0;
}
void personaje::eventos(Event e){
    switch (e.type)
    {
    case Event::KeyPressed:
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            frames(&spritePersonaje, frameActual_x, 0, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x, spritePersonaje.getPosition().y - 3);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            frames(&spritePersonaje, frameActual_x, 2, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x, spritePersonaje.getPosition().y + 3);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            frames(&spritePersonaje, frameActual_x, 1, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x - 3, spritePersonaje.getPosition().y);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            frames(&spritePersonaje, frameActual_x, 3, 9, 4);
            spritePersonaje.setPosition(spritePersonaje.getPosition().x + 3, spritePersonaje.getPosition().y);
        }
        break;
    default:
        break;
    }
}