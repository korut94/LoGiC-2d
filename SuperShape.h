#ifndef SUPERSHAPE_H
#define SUPERSHAPE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;

class SuperShape
{
    public:
        SuperShape();
        virtual ~SuperShape();

        bool mouseFocus( const sf::Vector2i & posMouse );

        sf::FloatRect getDescRect();

        sf::Vector2f getCenter();

        void draw( sf::RenderWindow * const window );
        void move( const sf::Vector2f & offset );
        void setBorderBound( const sf::Color & color, float thickness );
        void setBoundVisible( bool visible );
        void setFill( const sf::Color & colorFill );
        void setPosition( float x, float y );
        void setRegionBound();
        void setShapeSize( const sf::IntRect & rectView );
        void setTextureShape( const std::string & pathTexture );

    protected:

    private:
        bool boundVisible;

        sf::RectangleShape regionBound;
        sf::Texture texture;
        sf::Sprite sprite;
};

#endif // SUPERSHAPE_H
