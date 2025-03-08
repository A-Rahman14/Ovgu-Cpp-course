#pragma once

#include <string>
#include <iostream>
#include "point.hpp"

// Parser that can read Points from streams.
// The StreamT can be any iostream such as fstream or stringstream.
template <typename StreamT>
class Parser
{
public:

    /* Extracts the points from the given stream and puts them into the container.
     * todo: implement
     */
    void parse(StreamT& stream, PointContainer& container)
    {
        int x, y;
        std::string useless1, useless2;
        while (stream >> useless1 >> x >> y >> useless2) {
            Point p = {x, y};
            container.push_back(p);
        }
    }

    /* Parses a single point and puts it into the container.
     * todo: implement
     * hint: You can use formatted stream in operators (">>").
     *       Syntax errors do not need to be handled.
     */
    void parsePoint(StreamT& stream, PointContainer& container)
    {
        Point p;
        std::cin >> p.x;
        std::cin >> p.y;
        container.push_back(p);
    }
private:
};
//Bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Mahadik Hannan Javed und Moayad Okal