#include "forwardlist.hpp"

#include <iostream>

using namespace a08;

int main()
{
    ForwardList<int> list;

    list.push_front(1);
    list.push_front(20);
    list.push_front(30);
    ForwardList<int> list2(list);
    for (int i : list)
    {
        std::cout << i << "\n";
    }

    // int i = 0;
    // while (i < 3) //(auto i : list)
    // {
    //     std::cout << i << "\n";
    //     i++;
    // }

    // ToDo: More tests!
}

//Bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Mahadik Hannan Javed und Moayad Okal