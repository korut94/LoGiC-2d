#include "RenderManager.h"
#include <iostream>

int main()
{
    RenderManager renderMng;

    int error = renderMng.exec();

    if( error == 0 ) cout << "Nessun errore" << endl;

    return 0;
}
