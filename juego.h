#include <SFML/Graphics.hpp>

using namespace sf;

class juego{
    private:
        RenderWindow *ventana1;
        int fps;
        Texture *textura1;
        Texture *textura2;
        Texture *textura3;
        Texture *textura[4];

        Sprite *sprite1;
        Sprite *sprite2;
        Sprite *sprite3;
        Sprite *sprite[4];

        Event *evento1;
        Vector2i frame_actual;

        Clock *reloj1;
        Time *tiempo1;
        float tiempo2;

    public:
        juego(int ancho, int alto, std::string titulo);
        void gameloop();  //repetir constantemente
        void dibujar();
        void eventos();
        void frames(Sprite &sprite, int x, int y, int num_x, int num_y);
        void personajes();
        void colisiones();
        void cargar_graficos();
        int random(int x);
};