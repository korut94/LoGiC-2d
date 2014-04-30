#include "RenderManager.h"

RenderManager::RenderManager()
{
    window = new sf::RenderWindow( sf::VideoMode( 600, 600 ), "Render Manager" );

    ObjectEdit * objEdit = new ObjectEdit();

    objEdit->setSize( 20, 30 );
    objEdit->setPosition( 100, 130 );
    objEdit->setFill( sf::Color::Green );

    ObjectEdit * objEdit1 = new ObjectEdit();

    objEdit1->setSize( 134, 20 );
    objEdit1->setPosition( 200, 50 );
    objEdit1->setFill( sf::Color::Cyan );

    listObject.push_back( objEdit );
    listObject.push_back( objEdit1 );
}



RenderManager::~RenderManager()
{
    delete window;
}

/*============================================================================*/

int RenderManager::exec()
{
    while( window->isOpen() )
    {
        processEvents();
        update();
        render();
    }

    return 0;
}

/*============================================================================*/


void RenderManager::headerInputKey( sf::Keyboard::Key key, bool isPressed )
{

}



void RenderManager::headerInputMouse( sf::Event::EventType event )
{

}



void RenderManager::processEvents()
{
    sf::Event event;

    while( window->pollEvent( event ) )
    {
        //Gestore degli eventi riguardanti il map editor
        if( event.type == sf::Event::Closed ) window->close();

        //Gestore degli eventi riguardanti gli oggetti renderizzati
        else
        {
            unsigned int numObject = listObject.size();

            //Passa l'evento catturato al gestore degle eventi di ogni oggeto
            //( scelta inefficiente ).
            for( unsigned int obj = 0; obj < numObject; obj++ )
            {
                listObject[obj]->headerEvent( event, window );
            }
        }
    }
}



void RenderManager::render()
{
    unsigned int numObject = listObject.size();

    window->clear( sf::Color::Black );
    //Renderizza tutti gli oggetti a schermo
    for( unsigned int i = 0; i < numObject; i++ ) listObject[i]->draw( window );
    window->display();
}



void RenderManager::update()
{

}
