#include <iostream>
#include <sstream>
#include "CursorList copy.hpp"

int main(int argc, const char *argv[])
{
    List list;
    char letter;
    while (std::cin >> letter)
    {

        switch (letter)
        {
        case 'F':
            int number;
            std::cin >> number;
            std::cout << number << " " << std::endl;
            list.push_front(number);
            std::cout << number << " - pushed front" << std::endl;
            break;
        case 'B':
            int number2;
            std::cin >> number2;
            list.push_back(number2);
            std::cout << number2 << " - pushed back" << std::endl;
            break;
        case 'f':
            if (list.empty())
            {
                std::cout << "EMPTY" << std::endl;
            }
            else
            {
                std::cout << list.pop_front() << " - popped front" << std::endl;
            }
            break;
        case 'b':
            if (list.empty())
            {
                std::cout << "EMPTY" << std::endl;
            }
            else
            {
                std::cout << list.pop_back() << " - popped back" << std::endl;
            }
            break;
        case 'S':
            std::cout << list.getSize() << std::endl;
            break;
        case 'C':
            list.show();
            break;
        case 'Q':
            return 0;
            break;
        case 'E':
            int number5;
            std::cin >> number5;
            int pos;
            pos = list.find(number5);
            if (pos == -1)
            {
                std::cout << "FALSE" << std::endl;
            }
            else
            {
                list.erase(pos);
                std::cout << "TRUE" << std::endl;
            }
            break;
        case 'R':
            int number3, number4;
            std::cin >> number3;
            std::cin >> number4;
            int position = list.find(number3);
            if (position == -1)
            {
                std::cout << "FALSE" << std::endl;
            }
            else
            {
                list.erase(position);
                list.insert(position, number4);
                std::cout << "TRUE" << std::endl;
            }
            break;
        }
    }
    return 0;
}