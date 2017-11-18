#include "Shapes.h"

/************** Circle **************/
circle::circle(int x, int y, int r)
    : m_x(x), m_y(y), m_r(r)
{
    std::cout << "The Circle has been created." << std::endl;
}

void circle::draw()
{
    std::cout << std::endl;
    std::cout << "******* CIRCLE *******" << std::endl;
    std::cout << "X = " << m_x  << " | Y = " << m_y << std::endl;
    std::cout << "Radius = " << m_r << std::endl << std::endl;
}

void circle::move(int x, int y)
{
    m_x += x;
    m_y += y;
}

circle::~circle()
{
    std::cout << "Destructor of the Circle." << std::endl;
}


/************** Rectangle **************/
rectangle::rectangle(int x1, int y1, int x2, int y2)
    : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2)
{
    std::cout << "The Rectangle has been created." << std::endl;
}

void rectangle::draw()
{
    std::cout << std::endl;
    std::cout << "******* RECTANGLE *******" << std::endl;
    std::cout << "X1 = " << m_x1  << " | Y1 = " << m_y1 << std::endl;
    std::cout << "X2 = " << m_x2  << " | Y2 = " << m_y2 << std::endl << std::endl;
}

void rectangle::move(int x, int y)
{
    m_x1 += x;
    m_y1 += y;
    m_x2 += x;
    m_y2 += y;
}

rectangle::~rectangle()
{
    std::cout << "Destructor of the Rectangle." << std::endl;
}


/************** Triangle **************/
triangle::triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3)
{
    std::cout << "The Triangle has been created." << std::endl;
}

void triangle::draw()
{
    std::cout << std::endl;
    std::cout << "******* TRIANGLE *******" << std::endl;
    std::cout << "X1 = " << m_x1  << " | Y1 = " << m_y1 << std::endl;
    std::cout << "X2 = " << m_x2  << " | Y2 = " << m_y2 << std::endl;
    std::cout << "X3 = " << m_x3  << " | Y3 = " << m_y3 << std::endl << std::endl;
}

void triangle::move(int x, int y)
{
    m_x1 += x;
    m_y1 += y;
    m_x2 += x;
    m_y2 += y;
    m_x3 += x;
    m_y3 += y;
}

triangle::~triangle()
{
    std::cout << "Destructor of the Triangle" << std::endl;
}
