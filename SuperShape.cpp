#include "SuperShape.h"

SuperShape::SuperShape()
{
    boundVisible = true;

    setBorderBound( sf::Color::Yellow, 1.f );
}



SuperShape::~SuperShape()
{
    //dtor
}


/*============================================================================*/

bool SuperShape::mouseFocus( const sf::Vector2i & posMouse )
{
    sf::FloatRect posSprite = sprite.getGlobalBounds();

    bool isEnterX = ( posMouse.x >= posSprite.left
                       && posMouse.x <= posSprite.left + posSprite.width );

    bool isEnterY = ( posMouse.y >= posSprite.top
                       && posMouse.y <= posSprite.top + posSprite.height );

    return ( isEnterX && isEnterY );
}

/*============================================================================*/

sf::FloatRect SuperShape::getDescRect()
{
    sf::Vector2f posSprite = sprite.getPosition();
    sf::Vector2f dimSprite = ( sf::Vector2f ) texture.getSize();

    return sf::FloatRect( posSprite, dimSprite );
}

/*============================================================================*/

sf::Vector2f SuperShape::getCenter()
{
    sf::Vector2f posSprite = sprite.getPosition();
    sf::Vector2f dimHalfSprite = ( sf::Vector2f ) texture.getSize() / 2.f;

    return posSprite + dimHalfSprite;
}

/*============================================================================*/

void SuperShape::draw( sf::RenderWindow * const window )
{
    window->draw( sprite );
    if( boundVisible ) window->draw( regionBound );
}



void SuperShape::move( const sf::Vector2f & offset )
{
    sprite.move( offset );
    regionBound.move( offset );
}



void SuperShape::setBorderBound( const sf::Color & color, float thickness )
{
    regionBound.setFillColor( sf::Color::Transparent );
    regionBound.setOutlineThickness( thickness );
    regionBound.setOutlineColor( color );
}



void SuperShape::setBoundVisible( bool visible )
{
    boundVisible = visible;
}



void SuperShape::setFill( const sf::Color & colorFill )
{
    sf::IntRect rectTexture = sprite.getTextureRect();

    sf::Uint8 * pixelsFill = new sf::Uint8[ rectTexture.width * rectTexture.height * 4 ];

    //Associa ad ogni campo della matrice la combinazione del blu
    for( int p = 0; p < rectTexture.width * rectTexture.height * 4; p += 4 )
    {
        pixelsFill[p] = colorFill.r;
        pixelsFill[p+1] = colorFill.g;
        pixelsFill[p+2] = colorFill.b;
        pixelsFill[p+3] = colorFill.a;
    }

    texture.update( pixelsFill );

    delete[] pixelsFill;
}



void SuperShape::setPosition( float x, float y )
{
    sprite.setPosition( x, y );
    regionBound.setPosition( x, y );
}



void SuperShape::setRegionBound()
{
    sf::FloatRect rectBound = sprite.getLocalBounds();

    sf::Vector2f sizeBound( rectBound.width, rectBound.height );

    regionBound.setSize( sizeBound );
}



void SuperShape::setShapeSize( const sf::IntRect & rectView )
{
    if( sprite.getTexture() == NULL )
    {
        texture.create( rectView.width, rectView.height );
        sprite.setTexture( texture );
    }

    sprite.setTextureRect( rectView );

    setRegionBound();
}
