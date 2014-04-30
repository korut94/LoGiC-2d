#ifndef OBJECTEDIT_H
#define OBJECTEDIT_H

#include <SFML/Graphics.hpp>

#include "ArrowEdit.h"
#include "SuperShape.h"

class ObjectEdit
{
    public:
        ObjectEdit();
        virtual ~ObjectEdit();

        void draw( sf::RenderWindow * const window );
        void headerEvent( const sf::Event & event, sf::RenderWindow * const window );
        void move( const sf::Vector2f & offset );
        void setEditMode( bool edit );
        void setFill( const sf::Color & colorFill );
        void setPosition( const sf::Vector2i & posXY );
        void setPosition( const sf::Vector2f & posXY );
        void setPosition( float x, float y );
        void setSize( int width, int height );

    protected:

    private:
        void headerEventArrow( const sf::Event & event, sf::RenderWindow * const window );
        void headerEventShape( const sf::Event & event, sf::RenderWindow * const window );

        ArrowEdit arrowX;
        ArrowEdit arrowY;

        bool drag;
        bool focusArrowX;
        bool focusArrowY;
        bool focusShape;
        bool resize;
        bool rotation;
        bool scale;
        bool translate;

        sf::CircleShape center;

        SuperShape shape;

        sf::Vector2i lastPosMouse;
};

#endif // OBJECTEDIT_H
