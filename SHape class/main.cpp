#include <iostream>
#include "Shapes.h"
#include "SHapeFactory.h"

int main()
{
    int range;
    int i = 0;
    int type = 0;

    std::cout << "Set range: ";
    std::cin >> range;

    if (range <= 0)
        return -1;

    shape **shapes_list = new shape*[range];

    std::cout << "\n";
    std::cout << "*********** | 1 - circle | 2 - rectangle | 3 - triangle | **********\n\n";

    while (i != range)
    {
        std::cout << "Set [" << i + 1 << "] type number: ";
        std::cin >> type;

        if (type <= 0)
            return -1;

        shapes_list[i] = ShapeFactory::createShape(type);

        if (shapes_list[i] == 0)
            continue;
        else
            ++i;
    }

    std::cout << "\n\n";
    for (int i = 0; i < range; ++i)
    {
        std::cout << "[" << i + 1 << "] ";
        shapes_list[i]->create();
    }

    std::cout << "\n\n";
    std::cout << "***** Deallocate memory *****\n\n";
    for (int i = 0; i < range; ++i)
        delete shapes_list[i];

    delete [] shapes_list;


    return 0;
}
