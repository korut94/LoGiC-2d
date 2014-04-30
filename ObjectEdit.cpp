#include "ObjectEdit.h"

ObjectEdit::ObjectEdit()
{
    //Lega all'oggetto SuperShape la freccia perchè le traslazioni della freccia
    //avvengano anche all'oggetto legato
    arrowX.setAnchorObject( &shape );
    arrowY.setAnchorObject( &shape );

    drag = true;

    setEditMode( false );

    focusArrowX = false;
    focusArrowY = false;
    focusShape = false;

    arrowX.setDirection( X );
    arrowX.setColor( sf::Color( 200, 0, 0, 255 ) );
    arrowY.setDirection( Y );
    arrowY.setColor( sf::Color( 0, 0, 200, 255 ) );

    center.setRadius( 2.f );
    center.setFillColor( sf::Color::White );
}

ObjectEdit::~ObjectEdit()
{
    //dtor
}

/*============================================================================*/

void ObjectEdit::draw( sf::RenderWindow * const window )
{
    shape.draw( window );

    if( translate )
    {
        arrowX.draw( window );
        arrowY.draw( window );

        window->draw( center );
    }
}



void ObjectEdit::headerEvent( const sf::Event & event, sf::RenderWindow * const window )
{
    //Le freccie hanno priorita maggiore rispetto allo shape
    if( translate ) headerEventArrow( event, window );
    if( drag ) headerEventShape( event, window );
}



void ObjectEdit::headerEventArrow( const sf::Event & event, sf::RenderWindow * const window )
{
    sf::Vector2i posMouse = sf::Mouse::getPosition( *window );

    if( event.type == sf::Event::MouseButtonPressed )
    {
        if( arrowX.mouseFocus( posMouse ) )
        {
            drag = false;
            focusArrowX = true;
            arrowX.setColor( sf::Color::Red );
        }

        else if( arrowY.mouseFocus( posMouse ) )
        {
            drag = false;
            focusArrowY = true;
            arrowY.setColor( sf::Color::Blue );
        }
    }

    else if( event.type == sf::Event::MouseMoved )
    {
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            if( focusArrowX )
            {
                cout << "X" << endl;

            }

            else if( focusArrowY )
            {
                cout << "Y" << endl;
            }
        }

        else
        {
            focusArrowX = false;
            focusArrowY = false;

            drag = true;

            arrowX.setColor( sf::Color( 200, 0, 0, 255 ) );
            arrowY.setColor( sf::Color( 0, 0, 200, 255 ) );
        }
    }
}



void ObjectEdit::headerEventShape( const sf::Event & event, sf::RenderWindow * const window )
{
    sf::Vector2i posMouse = sf::Mouse::getPosition( *window );

    //Controllo statico di selezione dello shape
    if( event.type == sf::Event::MouseButtonPressed )
    {
        if( shape.mouseFocus( posMouse ) )
        {
            lastPosMouse = posMouse;

            setEditMode( true );
            //Mouse dentro lo shape
            focusShape = true;
        }

        else
        {
            focusShape = false;
        }
    }

    //Controllo statico del movimento del mouse
    else if( event.type == sf::Event::MouseMoved )
    {
        //Controllo real-time di mantenuta pressione del tasto sinistro del mouse
        //Il controllo conta sul fatto che l'evento MouseButtonPressed sia chiamato
        //almeno una volta.
        if( focusShape && sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            sf::Vector2i delta = posMouse - lastPosMouse;
            lastPosMouse = posMouse;

            move( ( sf::Vector2f ) delta );
        }
    }
}



void ObjectEdit::move( const sf::Vector2f & offset )
{
    shape.move( offset );
    arrowX.move( offset );
    arrowY.move( offset );
    center.move( offset );
}



void ObjectEdit::setEditMode( bool edit )
{
    translate = edit;
    shape.setBoundVisible( edit );
}



void ObjectEdit::setFill( const sf::Color & colorFill )
{
    shape.setFill( colorFill );
}



void ObjectEdit::setPosition( const sf::Vector2i & posXY )
{
    setPosition( ( float ) posXY.x, ( float ) posXY.y );
}



void ObjectEdit::setPosition( const sf::Vector2f & posXY )
{
    setPosition( posXY.x, posXY.y );
}



void ObjectEdit::setPosition( float x, float y )
{
    shape.setPosition( x, y );

    arrowX.setPosition();
    arrowY.setPosition();

    center.setPosition( shape.getCenter() - sf::Vector2f( 1.5f, 2.5f ) );
}



void ObjectEdit::setSize( int width, int height )
{
    sf::IntRect rectShape( 0, 0, width, height );
    shape.setShapeSize( rectShape );
}
