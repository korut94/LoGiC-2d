#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#include "ObjectEdit.h"

using namespace std;

class RenderManager
{
    public:
        RenderManager();
        virtual ~RenderManager();

        int exec();

        void processEvents();
        void render();
        void update();

    protected:

    private:
        void headerInputKey( sf::Keyboard::Key key, bool isPressed );
        void headerInputMouse( sf::Event::EventType typeEvent );

        //Indice dell'oggetto che si vuole inserire in una delle tre liste
        int indexShapeModify;

        sf::RenderWindow * window;

        vector<ObjectEdit *> listObject;
};

#endif // RENDERMANAGER_H
