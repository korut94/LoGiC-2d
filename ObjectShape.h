#ifndef OBJECTSHAPE_H
#define OBJECTSHAPE_H

#include <SFML/Graphics.hpp>

enum typeShape{ circle, rectangle, convex, generic };

class ObjectShape
{
    public:
        ObjectShape( typeShape a );
        virtual ~ObjectShape();

    protected:

    private:
        sf::Sprite sprite;

        typeShape type;
};

#endif // OBJECTSHAPE_H
