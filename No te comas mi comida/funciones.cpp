#include "funciones.h"
void frames(Sprite *sprite, int x, int y, int num_x, int num_y)
{
    IntRect posicion(x *(sprite->getTexture()->getSize().x / num_x),y * (sprite->getTexture()->getSize().y/ num_y),sprite->getTexture()->getSize().x / num_x, sprite->getTexture()->getSize().y / num_y);
    sprite->setTextureRect(posicion);
}
