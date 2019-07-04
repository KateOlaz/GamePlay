#include "juego.h"

juego::juego(int ancho, int alto, string titulo)
{
    fps = 60;
    puntos = 0;
    vidas = 4;
    state = 1;
    this->ancho_=ancho;
    this->alto_=alto;
    ventana1 = new RenderWindow(VideoMode(ancho,alto), titulo);
    ventana1->setFramerateLimit(fps);

    fuente1 = new Font();
    fuente1->loadFromFile("The Bomb.ttf");

    //SCORE
    score.setFont(*fuente1);
    score.setScale(0.5,0.5);
    score.setPosition(600,100);
    score.setColor(Color::White);

    //TITULO
    text.setFont(*fuente1);
    text.setString("No te comas mi Comida");
    text.setPosition(100,50);
    text.setColor(Color::White);

    //PERDISTE
    lose.setFont(*fuente1);
    lose.setString("Game Over!");
    lose.setPosition(300,250);
    lose.setColor(Color::White);

    //FONDO
    textura = new Texture;
    textura->loadFromFile("piso.jpg");
    fondo = new Sprite(*textura);
    fondo->setScale(((float)ventana1->getSize().x / fondo->getTexture()->getSize().x), ((float)ventana1->getSize().y / fondo->getTexture()->getSize().y));

    personajes_juego();
    gameloop();
}

void juego::gameloop()
{
    
    while (ventana1->isOpen())
    {
        dibujar();
        colisiones();
        eventos();
    }

    
}

void juego::personajes_juego()
{
    
    //Jugador
    personajeTexture.loadFromFile("posible.png");
    Jugador = Personaje::getInstancia();

    //Enemigo
    enemigoTexture.loadFromFile("fantasmas.png");
    new Enemigos;
    new Enemigos;
    new Enemigos;
    new Enemigos;


    //Comidas
    comidaTexture.loadFromFile("comidaSheet.png");
    new Comida;
    new Comida;
    new Comida;
    new Comida;
    new Comida;
    new Comida;

    //Bala
    balaTexture.loadFromFile("disparo.png");

    evento1 = new Event;  

}


void juego::dibujar()
{
    ventana1->clear();
    ventana1->draw(*fondo);
    ventana1->draw(text);
    ventana1->draw(score);
    if(state == 0)
    {
        ventana1->clear();
        ventana1->draw(*fondo);
        ventana1->draw(lose);
        ventana1->display();
        return;
    }
    
    Jugador->dibujar();

    list<Enemigos*>::iterator at;
    for(at = Enemigos::Enemigos_en_juego.begin(); at != Enemigos::Enemigos_en_juego.end(); ++at){
        (*at)->dibujar();
    }
    
    list<Comida*>::iterator itt;
    for(itt = Comida::Comidas_en_juego.begin(); itt != Comida::Comidas_en_juego.end(); ++itt){
        (*itt)->dibujar();
    }

    ventana1->display();
}

void juego::colisiones()
{
    string Result;          
    ostringstream convert;  
    convert << vidas;      
    Result = convert.str();
    score.setString("Score: "+ Result);

    //COLICION ENEMIGOS-COMIDA
    list<Enemigos*>::iterator iter2; 
    for(iter2 = Enemigos::Enemigos_en_juego.begin(); iter2 != Enemigos::Enemigos_en_juego.end(); ++iter2){
        list<Comida*>::iterator itr;
        for(itr = Comida::Comidas_en_juego.begin(); itr != Comida::Comidas_en_juego.end();++itr){
            if((*iter2)->enemigo.intersects((*itr)->comidas)){
                delete (*itr);
                new Comida;
                vidas = vidas - 1;
                if(vidas == 0)
                {
                    state = 0;
                }

                break;
            }
        }
    }

    //COLISION PERSONAJE-COMIDA
    list<Comida*>::iterator co;
    for(co = Comida::Comidas_en_juego.begin(); co != Comida::Comidas_en_juego.end();++co){
        if(Personaje::getInstancia()->personaje.intersects((*co)->comidas)){
            delete (*co);
            new Comida;
            vidas = vidas + 1;
            if(vidas == 0)
            {
                state = 0;
            }
            break;
        }
    }

    //COLISION PERSONAJE-ENEMIGOS
    list<Enemigos*>::iterator ene;
    for(ene = Enemigos::Enemigos_en_juego.begin(); ene != Enemigos::Enemigos_en_juego.end();++ene){
        if((*ene)->enemigo.intersects(Personaje::getInstancia()->personaje))
        {
            puntos = puntos + 1;
            if(puntos>90)
            {
                puntos = 0;
                vidas = vidas - 1;
                if(vidas == 0)
                    {
                        state = 0;
                    }
            }
            break;
        }
    }
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
            delete fuente1;
            delete fondo;
            cout<<"AQUI:ENEMIGOS antes->"<<Enemigos::Enemigos_en_juego.size()<<endl;
            while(!Enemigos::Enemigos_en_juego.empty())
            {
                delete Enemigos::Enemigos_en_juego.front();
            }
            cout<<"AQUI:ENEMIGOS despues->"<<Enemigos::Enemigos_en_juego.size()<<endl;
            cout<<"AQUI:comida antes->"<<Comida::Comidas_en_juego.size()<<endl;
            while(!Comida::Comidas_en_juego.empty())
            {
                delete Comida::Comidas_en_juego.front();
            }
            cout<<"AQUI:COMIDA despues->"<<Comida::Comidas_en_juego.size()<<endl;

            exit(1);
            break;
        }
        Jugador->eventos(*evento1);
    }
}


