#include <iostream>
#include <algorithm>
#include "renderer.hpp"

/* Initialize the Renderer with the given console size.
 * To correctly display the example data it needs to be at least 120,30.
 * Add "terminal": "externalterminal" to launch.json to get a variable size console.
 */
Renderer::Renderer(int rows, int colums)
    : m_rows(rows), m_colums(colums)
{
}

/* Draws the given points to cout.
 * todo: implement
 * howto: Sort the points in order of drawing them line wise: (0,0) < (10,0) < (0,1)
 *        Utilize std::sort for this. This will require an operator overload for Point.
 *        Eliminate duplicates. This can be done with std::unique and std::erase,
 *        and requires another operator overload for Point.
 */
void Renderer::draw(PointContainer& points)
{
    
    struct {
        bool operator()(Point a, Point b) const
        {
            if (a.y == b.y) {
                return a.x < b.x;
            } else {
                return a.y < b.y;
            }
        }
    } custom;
    struct {
        bool operator()(Point a, Point b) const
        {
            if (a.x == b.x && a.y == b.y) {
                return true;
            } else {
                return false;
            }
        }
    } custom2;
    std::sort(points.begin(), points.end(), custom);
    auto uniq = std::unique(points.begin(), points.end(), custom2);
    points.erase(uniq, points.end());

    int curx=0, cury=0;
    for (Point p : points) {
        while (true) {
            if (cury == p.y) {
                for (; curx < p.x; curx++) {
                    std::cout << " ";
                }
                std::cout << "+";
                curx++;
                break;
            } else {
                std::cout << "\n";
                cury++;
                curx=0;
            }
        }
    }
}
//Bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Mahadik Hannan Javed und Moayad Okal