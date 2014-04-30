#include "ArrowEdit.h"

ArrowEdit::ArrowEdit()
{
    textureArrow.create( 11, 80 );
    spriteArrow.setOrigin( 5.f, 0.f );
}



ArrowEdit::~ArrowEdit()
{
    //dtor
}

/*============================================================================*/

bool ArrowEdit::mouseFocus( const sf::Vector2i & posMouse )
{
    sf::Vector2f posSprite = spriteArrow.getPosition();
    sf::Vector2u dimSprite = textureArrow.getSize();

    bool limiteX, limiteY;

    if( dirArrow == X )
    {
        limiteX = ( posMouse.x >= posSprite.x + 10
                    && posMouse.x <= posSprite.x + dimSprite.y );
        limiteY = ( posMouse.y >= posSprite.y
                    && posMouse.y <= posSprite.y + dimSprite.x );
    }

    else
    {
        limiteX = ( posMouse.x >= posSprite.x
                    && posMouse.x <= posSprite.x + dimSprite.x );
        limiteY = ( posMouse.y >= posSprite.y + 10
                    && posMouse.y <= posSprite.y + dimSprite.y );
    }

    return ( limiteX && limiteY );
}

/*============================================================================*/

void ArrowEdit::createTexture( const sf::Color & color )
{
    sf::Uint8 * pixelsArrow = new sf::Uint8[ 11 * 80 * 4 ];

    int index = 0;

    /*
    Modello della freccia

    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    1 1 1 1 1 1 1 1 1 1 1
    0 1 1 1 1 1 1 1 1 1 0
    0 0 1 1 1 1 1 1 1 0 0
    0 0 0 1 1 1 1 1 0 0 0
    0 0 0 0 1 1 1 0 0 0 0
    0 0 0 0 0 1 0 0 0 0 0
    */

    //Setta tutti i pixel trasparenti evitando la visualizzazione di colori causuali
    for( register int i = 0; i < 11 * 80 * 4; i += 4 )
    {
        pixelsArrow[i] = 0; //r
        pixelsArrow[i+1] = 0; //g
        pixelsArrow[i+2] = 0; //b
        pixelsArrow[i+3] = 0; //a
    }

    //Creazione della coda della freccia ( larghezza: 1px, altezza: 75px )
    for( register int h = 0; h < 74; h++ )
    {
        index = 5 * 4 + h * 4 * 11;

        //La freccia è di colore rosso
        pixelsArrow[index] = color.r; //r
        pixelsArrow[index+1] = color.g; //g
        pixelsArrow[index+2] = color.b; //b
        pixelsArrow[index+3] = color.a; //a
    }

    int switchPixel = 0;

    //Creazione della punta della freccia ( larghezza: 10px, altezza: 5px )
    for( int h = 74; h < 80; h++ )
    {
        for( int w = switchPixel; w < 5; w++ )
        {
            index = w * 4 + h * 4 * 11;

            //Parte sinistra
            pixelsArrow[index] = color.r; //r
            pixelsArrow[index+1] = color.g; //g
            pixelsArrow[index+2] = color.b; //b
            pixelsArrow[index+3] = color.a; //a

            index = ( 10 - w ) * 4 + h * 4 * 11;

            //Parte destra
            pixelsArrow[index] = color.r; //r
            pixelsArrow[index+1] = color.g; //g
            pixelsArrow[index+2] = color.b; //b
            pixelsArrow[index+3] = color.a; //a
        }

        index = 5 * 4 + h * 4 * 11;

        //Parte centrale della punta
        pixelsArrow[index] = color.r; //r
        pixelsArrow[index+1] = color.g; //g
        pixelsArrow[index+2] = color.b; //b
        pixelsArrow[index+3] = color.a; //a

        switchPixel++;
    }

    textureArrow.update( pixelsArrow );

    spriteArrow.setTexture( textureArrow );

    spriteArrow.setTextureRect( sf::IntRect( 0, 0, 11, 80 ) );

    delete[] pixelsArrow;
}



void ArrowEdit::draw( sf::RenderWindow * const window )
{
    window->draw( spriteArrow );
}



void ArrowEdit::move( const sf::Vector2f & offset )
{
    spriteArrow.move( offset );
}



void ArrowEdit::setAnchorObject( SuperShape * const shapeObject )
{
    anchorShape = shapeObject;
}


void ArrowEdit::setColor( const sf::Color & color )
{
    createTexture( color );
}



void ArrowEdit::setDirection( const Direction & direction )
{
    dirArrow = direction;
    if(  dirArrow == X ) spriteArrow.rotate( 270.f );
}



void ArrowEdit::setPosition()
{
    sf::FloatRect descShape = anchorShape->getDescRect();

    //Posiona la freccia al centro dello sprite
    float posX = descShape.left + descShape.width / 2;
    float posY = descShape.top + descShape.height / 2;

    spriteArrow.setPosition( posX, posY );
}
