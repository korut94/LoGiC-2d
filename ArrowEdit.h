#ifndef ARROWEDIT_H
#define ARROWEDIT_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "SuperShape.h"

using namespace std;

enum Direction{ X, Y };

class ArrowEdit
{
    public:
        ArrowEdit();
        virtual ~ArrowEdit();

        bool mouseFocus( const sf::Vector2i & posMouse );

        void draw( sf::RenderWindow * const window );
        void move( const sf::Vector2f & offset );
        void setAnchorObject( SuperShape * const shapeObject );
        void setColor( const sf::Color & color );
        void setDirection( const Direction & direction );
        void setPosition();

    protected:

    private:
        void createTexture( const sf::Color & color );

        Direction dirArrow;

        sf::Texture textureArrow;
        sf::Sprite spriteArrow;

        SuperShape * anchorShape;
};

#endif // ARROWEDIT_H
