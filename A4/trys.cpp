#include <iostream>
#include <cstdio>
#include <ctime>


void work01()
{
    double numbers[10000];
    for(int i = 0; i < 10000; ++i)
    {
        numbers[i] = double(std::rand())/double(RAND_MAX);
    }
    for (int n = 10000; n > 1; n = n-1){
        for (int i = 0; i < n-1; i = i+1){
            if (numbers[i] > numbers[i+1]){
                double tmp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = tmp;
            }
        }
    }
    std::cout << "done??\n" ;
}


int main() {
    std::clock_t start;
    double duration;

    start = std::clock();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    work01();
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout << duration << '\n';
}