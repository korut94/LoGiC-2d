#include "ListShape.h"

ListShape::ListShape()
{
    //Array di puntatori ad oggetti Shape
    listShape = new sf::Shape[10];

    cntShape = 0;
    maxSize = 10;
}

/*============================================================================*/

ListShape::~ListShape()
{
    delete[] listShape;
}

/*============================================================================*/

int ListShape::size()
{
    return cntShape;
}

/*============================================================================*/

sf::Shape * ListShape::operator[](  int pos )
{
    return listShape[ pos ];
}

/*============================================================================*/

void ListShape::allungaLista()
{
    //Raddoppia la lunghezza dell'array
    sf::Shape * newListShape = new sf::Shape[ maxSize * 2 ];

    //Copia gli elementi dal vecchio array a quello nuovo
    for( int i = 0; i < cntShape; i++ ) newListShape[i] = listShape[i];
    //Cancello il vecchio array
    delete[] listShape;
    //Punta al nuovo array
    listShape = newListShape;
    //La lunghezza dell'array è raddoppiata
    maxSize *= 2;
}

/*============================================================================*/

void ListShape::push( sf::Shape * shape )
{
    //La lista sarà allungata e aggiornato il valore di maxSize
    if( cntShape == maxSize ) allungaLista();
    listShape[ cntShape ] = shape;

    cntShape++;
}


