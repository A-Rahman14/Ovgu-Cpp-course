#include <iostream>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    for (int n=0; n != 50; n++) {
        int y;
        y = rand()% 3 + 1;
        std::cout << "y = " << y << ' ';
        int x;
        x = rand()% 3 + 1;
        std::cout << "x = " << x << ' ';
    }
    return 0;
}
