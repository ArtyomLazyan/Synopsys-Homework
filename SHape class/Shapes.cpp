#include "Shapes.h"

/************** Circle **************/
circle::circle()
{
    std::cout << "The Circle has been created." << std::endl;
}

void circle::create()
{
    std::cout << "This is a circle." << std::endl;
}

circle::~circle()
{
    std::cout << "The Circle has been deleted." << std::endl;
}


/************** Rectangle **************/
rectangle::rectangle()
{
    std::cout << "The Rectangle has been created." << std::endl;
}

void rectangle::create()
{
    std::cout << "This is a rectangle." << std::endl;
}

rectangle::~rectangle()
{
    std::cout << "The Rectangle has been deleted." << std::endl;
}


/************** Triangle **************/
triangle::triangle()
{
    std::cout << "The Triangle has been created." << std::endl;
}

void triangle::create()
{
    std::cout << "This is a triangle." << std::endl;
}

triangle::~triangle()
{
    std::cout << "The Triangle has been deleted." << std::endl;
}
