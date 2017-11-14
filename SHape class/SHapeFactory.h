#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "Shapes.h"

class ShapeFactory
{
public:
    static shape* createShape(int type);
};

#endif /* ifndef SHAPE_FACTORY_H */
