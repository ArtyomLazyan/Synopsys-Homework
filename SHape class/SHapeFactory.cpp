#include "SHapeFactory.h"

shape* ShapeFactory::createShape(int type)
{
    shape *sp = NULL;

    switch (type)
    {
        case 1:
            sp = new circle;
            break;

        case 2:
            sp = new rectangle;
            break;

        case 3:
            sp = new triangle;
            break;

        default:
            std::cout << "Invalid shape type re-enter type." << std::endl;
            return 0;
    }

    return sp;

}
