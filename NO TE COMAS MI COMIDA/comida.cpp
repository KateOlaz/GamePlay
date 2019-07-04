#include "comida.h"
#include "juego.h"

#include <iostream>
#include <list> 

using namespace std;

const int totalNumeroDeComida = 32;
Comida::Comida(){
    //INICIAR RANDOM FUNCION
    srand (time(NULL));

    Comidas_en_juego.push_back(this);

    comidas.left = posicionEnPantalla_x;
    comidas.top = posicionEnPantalla_y;
    comidas.width = 20;
    comidas.height = 20;

    //Generar las posiciones mediante nums random
    //mejorar estas posiciones randoms
    posicionEnPantalla_x = rand()%750 +100;
    posicionEnPantalla_y = rand()%450 +100;
    //comida actual 
    //le da un valor del 0 a 31
    comidaActual = rand()%32;
    
    frameComidaActual = 0;
    //Dividiendo entre 4 devuleve la posicion en x e y
    //en el comidaSheet
    frameActual.y = (comidaActual/4) ;
    frameActual.x = (comidaActual%4) ;
    spriteComida.setTexture(juego::comidaTexture);

    spriteComida.setScale(1.5f,1.5f);
    //8FILAS Y 12 COLUMNAS 
    frames(&spriteComida,(frameActual.x+frameComidaActual),frameActual.y,12,8);
    //aca actualizamos la posicion del sprite en pantalla
    spriteComida.setPosition(posicionEnPantalla_x,posicionEnPantalla_y);
    //guardamos en timepoPantalla el momento en que aparece
    //el sprite
    tiempoEnPantalla = juego::reloj.getElapsedTime();

}
void Comida::dibujar(){
    //dibujamos en la pantalla
    juego::ventana1->draw(spriteComida);

    //convertimos el tiempo en pantalla a segundos
    //y con la resta conseguimos el timepo transcurrido
    //desde el momento que el sprite aparecio en pantalla hasta 
    //hasta el momento actual
    fltiempoEnPantalla = juego::reloj.getElapsedTime().asSeconds() - tiempoEnPantalla.asSeconds();
    //si esta menos de 3 segundos deberia
    //darle animacion 
    if(fltiempoEnPantalla <= 7.f)
    {   
        if(frameComidaActual<3)
            frameComidaActual++;
        else frameComidaActual = 0;
    }
    //si esta mas de 3 segundos se le asigna
    //nuevas posiciones se reinicia el tiempo en pantalla
    //las posiciones y el sprite
    else
    {   tiempoEnPantalla = juego::reloj.getElapsedTime();
        posicionEnPantalla_x = rand()%750 +100;
        posicionEnPantalla_y = rand()%450 +100;
        comidaActual = rand()%32;
        frameComidaActual = 0;
        frameActual.y = (comidaActual/4) ;
        frameActual.x = (comidaActual%4) ;
        spriteComida.setTexture(juego::comidaTexture);
        frames(&spriteComida,(frameActual.x+frameComidaActual),frameActual.y,12,8);
        spriteComida.setPosition(posicionEnPantalla_x,posicionEnPantalla_y);
    }
        comidas.left = posicionEnPantalla_x;
        comidas.top = posicionEnPantalla_y;
}

Comida::~Comida(){
    Comidas_en_juego.remove(this);
}
