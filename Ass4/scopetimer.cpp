#include "scopetimer.hpp"

ScopeTimer::ScopeTimer(const char* name) {
    start = std::clock();
    nme = name;
    std::cout << "Starting Timer now called " << nme << "\n";
}
ScopeTimer::~ScopeTimer() {
    double duration = 1000.0 * ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "Timer " << nme << " took " << duration << " ms" << "\n";
}