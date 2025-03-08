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
short insert(double arr[]) {
    short len = 0;
    std::cout << "Enter the length : ";
    std::cin >> len;
    for (int i=0; i<len; i++) {
        std::cout << "Enter a number : ";
        std::cin >> arr[i];
        if(std::cin.fail()) {
            arr[i] = 0;
        }
    }
    return len;
}
int main(int, char**) {
    int a[] = {0, 1};
    /*short len = insert(a);
    for (int i=0; i<len; i++) {
        std::cout << a[i] << " ";
    }*/
    if (isPermutation(a,2)) {
        std::cout << "Motherfucker what";
    }
    return 0;
}