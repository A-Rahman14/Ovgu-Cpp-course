#include "utils.hpp"

#include <iostream>
#include <sstream>
#include <string>

/* todo:
 *      * read doubles from cin and put them into an array until something that
 *        is not a number is entered. (std::cin.fail() is true)
 *      * increase the array's size if necessary
 *      * reset cin (see clear() and ignore())
 *      * read in the same amount of integers
 *      * implement functions in utils.cpp
 *      * test given input with isPermutation() and isSorted()
 *      * clean up all dynamically allocated memory
 */

int main(int, char**) {
    double arr[5];
    int len = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<len; i++) {
        std::cout << "Enter a number : ";
        std::cin >> arr[i];
        if(std::cin.fail()) {
            arr[i] = 0;
        }
    }
    for (int i=0; i<len; i++) {
        std::cout << arr[i] << " ";
    }
    int s[] = {5, 7, 7, 9, 6};
    int* st = s;
    std::cout << isPermutation(st, 5);
    std::cout << "\nlength is " << len;
    return 0;
}