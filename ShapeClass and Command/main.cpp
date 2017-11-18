#include <iostream>
#include "Shapes.h"
#include "commands.h"

void commandController(shape **, int);
void deallocateMemory(shape **, int);

int main()
{

    int range(0);

    std::cout << "Set range: ";
    if (!(std::cin >> range))
        return -1;

    shape **shapes_list = new shape*[range];

    std::cout << "\n";
    std::cout << "*********** create[ c | r | t, index ] *** move[ index, x, y ] *** draw[ index ] *** delete[ index ]  *** exit **********\n\n";

    commandController(shapes_list, range);

    std::cout << std::endl;
    deallocateMemory(shapes_list, range);

    return 0;
}

void commandController(shape **shapes_list, int range)
{
    std::string cmd;
    char shape_type = '0';
    int index(0), x(0), y(0);

    while (true)
    {
        std::cout << "Set command |-> ";
        std::cin >> cmd;

        if (cmd == "create")
        {
            std::cin >> shape_type >> index;
            if (std::cin.fail())
            {
                std::cout << "Error: Invalid arguments." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            if ((index >= range) || (index < 0))
            {
                std::cout << "Error: Out of range." << std::endl;
                continue;
            }
            command *cp = new create(shape_type, index, shapes_list);
            cp->execute();
            delete cp;
        }
        else if (cmd == "move")
        {
            std::cin >> index >> x >> y;
            if (std::cin.fail())
            {
                std::cout << "Invalid arguments." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            if ((index >= range) || (index < 0))
            {
                std::cout << "Error: Out of range." << std::endl;
                continue;
            }
            command *cp = new move(index, x, y, shapes_list);
            cp->execute();
            delete cp;
        }
        else if (cmd == "draw")
        {
            std::cin >> index;
            if (std::cin.fail())
            {
                std::cout << "Invalid arguments." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            if ((index >= range) || (index < 0))
            {
                std::cout << "Error: Out of range." << std::endl;
                continue;
            }
            command *cp = new draw(index, shapes_list);
            cp->execute();
            delete cp;
        }
        else if (cmd == "delete")
        {
            std::cin >> index;
            if (std::cin.fail())
            {
                std::cout << "Invalid arguments." << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                continue;
            }
            if ((index >= range) || (index < 0))
            {
                std::cout << "Error: Out of range." << std::endl;
                continue;
            }
            command *cp = new remove(index, shapes_list);
            cp->execute();
            delete cp;

        }
        else if (cmd == "exit")
        {
            break;
        }
        else
        {
            std::cout << "Error: Command not found try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
}

void deallocateMemory(shape **shapes_list, int range)
{
    for (int i = 0; i < range; ++i)
        delete shapes_list[i];

    delete [] shapes_list;
}
