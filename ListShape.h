#ifndef LISTSHAPE_H
#define LISTSHAPE_H

#include <SFML/Graphics.hpp>

class ListShape
{
    public:
        ListShape();
        virtual ~ListShape();

        int size();

        sf::Shape * operator[]( int pos );

        void push( sf::Shape * shape );

    protected:

    private:
        void allungaLista();

        int cntShape;
        int maxSize;
        sf::Shape ** listShape;
};

#endif // LISTSHAPE_H
