#include "commands.h"

/* *** class create *** */
create::create(char c, int index, shape ** sp)
    : m_shape_type(c), m_index(index), m_shapes_list(sp) {}

void create::execute()
{
    int x1, y1, x2, y2, x3, y3, r;

    switch (m_shape_type)
    {
        case 'c':
            std::cout << "Set cordinates for Circle(x, y, r) : ";
            std::cin >> x1 >> y1 >> r;
            if (std::cin.fail())
            {
                std::cout << "Invalid arguments." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                break;
            }
            m_shapes_list[m_index] = new circle(x1, y1, r);
            break;

        case 'r':
            std::cout << "Set cordinates for Rectangle(x1, y1, x2, y2) : ";
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (std::cin.fail())
            {
                std::cout << "Invalid arguments." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                break;
            }
            m_shapes_list[m_index] = new rectangle(x1, y1, x2, y2);
            break;

        case 't':
            std::cout << "Set cordinates for Triangle(x1, y1, x2, y2, x3, y3) : ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            if (std::cin.fail())
            {
                std::cout << "Invalid arguments." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                break;
            }
            m_shapes_list[m_index] = new triangle(x1, y1, x2, y2, x3, y3);
            break;

        default:
            std::cout << "Invalid shape type." << std::endl;
    }

}

/* *** class create *** */
move::move (int index, int x, int y, shape ** sp)
    : m_index(index), m_x(x), m_y(y), m_shapes_list(sp) {}

void move::execute()
{
    m_shapes_list[m_index]->move(m_x, m_y);
    std::cout << "Shape has been moved." << std::endl;
}

/* *** class draw *** */
draw::draw (int index, shape ** sp)
    : m_index(index), m_shapes_list(sp) {}

void draw::execute()
{
    if (m_shapes_list[m_index] == 0)
        std::cout << "Empty index." << std::endl;
    else
        m_shapes_list[m_index]->draw();
}

/* *** class remove *** */
remove::remove (int index, shape ** sp)
    : m_index(index), m_shapes_list(sp) {}

void remove::execute()
{
    if (m_shapes_list[m_index] != 0)
    {
        delete m_shapes_list[m_index];
        m_shapes_list[m_index] = 0;
        std::cout << "Shape has been deleted." << std::endl;
    }
    else
        std::cout << "Index is already empty." << std::endl;
}
