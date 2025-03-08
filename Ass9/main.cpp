#include <fstream>
#include "parser.hpp"
#include "renderer.hpp"

using namespace std;

/* todo: * implement missing definitions
 *       * open the file data.txt
 *       * read all points using the Parser
 *       * draw the points with the Renderer
 */

int main()
{
    ifstream inFile("data.txt");
    Parser<ifstream> pars;
    PointContainer cont;
    pars.parse(inFile, cont);
    Renderer screen{120, 30};
    screen.draw(cont);
    inFile.close();
}
//Bearbeitet bei Abdelhalim Abdelhalim, Abdelrahman Abdelhalim, Mahadik Hannan Javed und Moayad Okal